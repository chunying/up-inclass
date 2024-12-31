#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

// globals
static long off_dlopen;
static long off_malloc;
static long off_free;

void *
find_libcaddr(const char *name) {
	void *handle, *fptr;
	if((handle = dlopen("libc.so.6", RTLD_LAZY)) == NULL) return NULL;
	fptr = dlsym(handle, name);
	dlclose(handle);
	return fptr;
}

long
find_libcbase(pid_t pid) {
	char buf[1024];
	FILE *fp;
	long base = 0;
	char perm[8], module[1024];

	snprintf(buf, sizeof(buf), "/proc/%d/maps", pid);
	if((fp = fopen(buf, "rt")) == NULL) return 0;
	while(fgets(buf, sizeof(buf), fp) != NULL) {
		long begin;
		sscanf(buf, "%lx-%*x %s %*s %*s %*d %s", &begin, perm, module);
		if(perm[2] != 'x') continue;
		if(strstr(module, "/lib/") == NULL)  continue;
		if(strstr(module, "/libc-") == NULL) continue;
		if(strstr(buf, ".so") == NULL)       continue;
		base = begin;
		break;
	}
	fclose(fp);
	return base;
}

long
find_libcoffset(long libcbase, const char *name) {
	void *addr = find_libcaddr(name);
	if(addr == NULL) { perror(name); exit(-1); }
	return addr ? (((long) addr) - libcbase) : -1;
}

long
find_execmem(pid_t pid) {
	char buf[1024];
	FILE *fp;
	long base = 0;
	char perm[8], module[1024];

	snprintf(buf, sizeof(buf), "/proc/%d/maps", pid);
	if((fp = fopen(buf, "rt")) == NULL) return 0;
	while(fgets(buf, sizeof(buf), fp) != NULL) {
		long begin, end, size;
		sscanf(buf, "%lx-%lx %s %*s %*s %*d %s", &begin, &end, perm, module);
		if(perm[2] != 'x') continue;
		if(module[0] == '[') continue;
		size = end - begin;
		//fprintf(stderr, "[execmem] %lx-%lx (%ld)\n", begin, end, size);
		base = end - ((size/2) > 0x100 ? 0x100 : (size/2));
		break;
	}
	fclose(fp);
	return base;
}

long
read_child_mem(pid_t pid, long src, void *dst, long size) {
	long rsize = 0;
	char *mem = dst;
	while(size > 0) {
		long word = ptrace(PTRACE_PEEKTEXT, pid, src, 0);
		*((long*) mem) = word;
		src += sizeof(long);
		mem += sizeof(long);
		rsize += sizeof(long);
		size -= (size > sizeof(long)) ? sizeof(long) : size;
	}
	return rsize;
}

long
write_child_mem(pid_t pid, const void *src, long dst, long size) {
	long wsize = 0;
	const char *mem = src;
	while(size > 0) {
		long dat;
		dat = *((long*) mem);
		ptrace(PTRACE_POKETEXT, pid, dst, dat);
		dst += sizeof(long);
		mem += sizeof(long);
		wsize += sizeof(long);
		size -= (size > sizeof(long)) ? sizeof(long) : size;
	}
	return wsize;
}

void
hexdump(long base, unsigned char *mem, long size) {
	long i, j, hexlen, asclen;
	char hex[64];
	char asc[32];
	for(i = 0; i < size; i += 16) {
		hexlen = asclen = 0;
		for(j = 0; j < 16 && i+j < size; j++) {
			hexlen += snprintf(hex+hexlen, sizeof(hex)-hexlen, "%2.2x ", mem[i+j]);
			asclen += snprintf(asc+asclen, sizeof(asc)-asclen, "%c", isprint(mem[i+j]) ? mem[i+j] : '.');
		}
		for(; j < 16; j++) {
			hexlen += snprintf(hex+hexlen, sizeof(hex)-hexlen, "   ");
			asclen += snprintf(asc+asclen, sizeof(asc)-asclen, " ");
		}
		fprintf(stderr, "%08lx: %s| %s\n", base+i, hex, asc);
	}
	return;
}

void
debug_regs(const char *pfx, pid_t pid) {
	struct user_regs_struct regs;
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return;
#if defined(__x86_64__)
	fprintf(stderr, "[%s] rax=%-16llx rbx=%-16llx rcx=%-16llx rdx=%-16llx\n",
		pfx, regs.rax, regs.rbx, regs.rcx, regs.rdx);
	fprintf(stderr, "[%s]  r8=%-16llx  r9=%-16llx r10=%-16llx r11=%-16llx\n",
		pfx, regs.r8, regs.r9, regs.r10, regs.r11);
	fprintf(stderr, "[%s] r12=%-16llx r13=%-16llx r14=%-16llx r15=%-16llx\n",
		pfx, regs.r12, regs.r13, regs.r14, regs.r15);
	fprintf(stderr, "[%s] rdi=%-16llx rsi=%-16llx rbp=%-16llx rsp=%-16llx\n",
		pfx, regs.rdi, regs.rsi, regs.rbp, regs.rsp);
	fprintf(stderr, "[%s] rip=%-16llx\n", pfx, regs.rip);
#elif defined(__i386__)
	fprintf(stderr, "[%s] eax=%-8lx ebx=%-8lx ecx=%-8lx edx=%-8lx\n",
		pfx, regs.eax, regs.ebx, regs.ecx, regs.edx);
	fprintf(stderr, "[%s] edi=%-8lx esi=%-8lx ebp=%-8lx esp=%-8lx\n",
		pfx, regs.edi, regs.esi, regs.ebp, regs.esp);
	fprintf(stderr, "[%s] eip=%-8lx\n", pfx, regs.eip);
#else
	fprintf(stderr, "platform not supported.\n");
#endif
	return;
}

/*
https://stackoverflow.com/questions/38006277/weird-behavior-setting-rip-with-ptrace
*/
#if defined(__x86_64__) || defined(__i386__)
static unsigned char code_syscall[] = {
	0x90, 0x90,			// nop * 2: preventing rip-2 problem caused by interrupted syscalls
#ifdef __x86_64__
	0x0f, 0x05,			// syscall
#else
	0xcd, 0x80,			// int 0x80
#endif
	0x90,				// nop
	0xcc,				// int 3: return to ptrace
	0xeb, 0xfa,			// jmp 0x02
};

long
pt_syscall(pid_t pid, long addr, long errval, long idx, long argc, ...) {
	int status;
	long backupsz, ret;
	long backup[1+sizeof(code_syscall)/sizeof(long)];
	struct user_regs_struct oldregs, regs;
	va_list ap;
	// backup
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
	memcpy(&oldregs, &regs, sizeof(oldregs));
	backupsz = read_child_mem(pid, addr, backup, sizeof(code_syscall));
	// fill parameters and call it
	va_start(ap, argc);
#ifdef __x86_64__
	regs.rip = addr+2;
	regs.rax = idx;
	if(argc > 0) regs.rdi = va_arg(ap, long);
	if(argc > 1) regs.rsi = va_arg(ap, long);
	if(argc > 2) regs.rdx = va_arg(ap, long);
	if(argc > 3) regs.r10 = va_arg(ap, long);
	if(argc > 4) regs.r8  = va_arg(ap, long);
	if(argc > 5) regs.r9  = va_arg(ap, long);
#else
	regs.eip = addr+2;
	regs.eax = idx;
	if(argc > 0) regs.ebx = va_arg(ap, long);
	if(argc > 1) regs.ecx = va_arg(ap, long);
	if(argc > 2) regs.edx = va_arg(ap, long);
	if(argc > 3) regs.esi = va_arg(ap, long);
	if(argc > 4) regs.edi = va_arg(ap, long);
#endif
	va_end(ap);
	write_child_mem(pid, code_syscall, addr, sizeof(code_syscall));
	if(ptrace(PTRACE_SETREGS, pid, 0, &regs) < 0) return errval;
again:
	if(ptrace(PTRACE_CONT, pid, 0, 0) < 0) return errval;
	waitpid(pid, &status, 0);
	// check & get results
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
#ifdef __x86_64__
	if(regs.rip != addr + 6) goto again; // rip should be right after 0xcc
	ret = regs.rax;
#else
	if(regs.eip != addr + 6) goto again; // eip should be right after 0xcc
	ret = regs.eax;
#endif
	// restore
	write_child_mem(pid, backup, addr, backupsz);
	if(ptrace(PTRACE_SETREGS, pid, 0, &oldregs) < 0) return errval;
	return ret;
}

static unsigned char code_callrbx[] = {
	0x90, 0x90,			// nop * 2: preventing rip-2 problem caused by interrupted syscalls
	0xff, 0xd3,			// call ebx/rbx: target address must be placed in rbx
	0x90,				// nop
	0xcc,				// int 3: return to ptrace
	0xeb, 0xfa,			// jmp 0x02
};

long
pt_ptrcall(pid_t pid, long addr, long errval, long func, long argc, ...) {
	int status;
	long backupsz, ret;
	long backup[1+sizeof(code_callrbx)/sizeof(long)];
	struct user_regs_struct oldregs, regs;
	va_list ap;
	// backup
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
	memcpy(&oldregs, &regs, sizeof(oldregs));
	backupsz = read_child_mem(pid, addr, backup, sizeof(code_callrbx));
	// fill parameters and call it
	va_start(ap, argc);
#ifdef __x86_64__
	regs.rip = addr+2;
	regs.rbx = func;
	if(argc > 0) regs.rdi = va_arg(ap, long);
	if(argc > 1) regs.rsi = va_arg(ap, long);
	if(argc > 2) regs.rdx = va_arg(ap, long);
	if(argc > 3) regs.rcx = va_arg(ap, long);
	if(argc > 4) regs.r8  = va_arg(ap, long);
	if(argc > 5) regs.r9  = va_arg(ap, long);
#else
	regs.eip = addr+2;
	regs.ebx = func;
	// parameters are placed on the stack
	do {
		long i, stacksize = sizeof(long) * argc;
		regs.esp -= stacksize;
		for(i = 0; i < argc; i++) {
			ptrace(PTRACE_POKETEXT, pid, regs.esp + i*sizeof(long), va_arg(ap, long));
		}
	} while(0);
#endif
	va_end(ap);
	write_child_mem(pid, code_callrbx, addr, sizeof(code_callrbx));
	if(ptrace(PTRACE_SETREGS, pid, 0, &regs) < 0) return errval;
again:
	if(ptrace(PTRACE_CONT, pid, 0, 0) < 0) return errval;
	waitpid(pid, &status, 0);
	// check & get results
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
#ifdef __x86_64__
	if(regs.rip != addr + 6) goto again; // rip should be right after 0xcc
	ret = regs.rax;
#else
	if(regs.eip != addr + 6) goto again; // eip should be right after 0xcc
	ret = regs.eax;
#endif
	// restore
	write_child_mem(pid, backup, addr, backupsz);
	if(ptrace(PTRACE_SETREGS, pid, 0, &oldregs) < 0) return errval;
	return ret;
}
int
dll_inject(pid_t pid, const char *path) {
	int status;
	long base, execmem;
	long ret, pathsize, pathmem;
	struct user_regs_struct oldregs, regs;

	//// attach to the target process
	if(ptrace(PTRACE_ATTACH, pid, NULL, NULL) < 0) return -1;
	if(waitpid(pid, &status, 0) < 0) return -1;
	if((base = find_libcbase(pid)) == 0) return -1;
	if((execmem = find_execmem(pid)) == 0) return -1;

	//// VERY IMPORTANT: preserve stack frame
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return -1;
	memcpy(&oldregs, &regs, sizeof(oldregs));
#ifdef __x86_64__
	// 'push rbp', and then 'mov rbp, rsp'
	regs.rsp -= sizeof(long);
	if(ptrace(PTRACE_POKETEXT, pid, regs.rsp, regs.rbp) < 0) return -1;
	regs.rbp = regs.rsp;
	// allocate space (on stack), and write path into it
	pathsize = ((strlen(path) + 1 + sizeof(long))) / sizeof(long) * sizeof(long);
	regs.rsp -= pathsize;
	pathmem = regs.rsp;
#else
	// 'push ebp', and then 'mov ebp, esp'
	regs.esp -= sizeof(long);
	if(ptrace(PTRACE_POKETEXT, pid, regs.esp, regs.ebp) < 0) return -1;
	regs.ebp = regs.esp;
	// allocate space (on stack), and write path into it
	pathsize = ((strlen(path) + 1 + sizeof(long))) / sizeof(long) * sizeof(long);
	regs.esp -= pathsize;
	pathmem = regs.esp;
#endif
	if(ptrace(PTRACE_SETREGS, pid, 0, &regs) < 0) return -1;

	fprintf(stderr, "[injector] >>>>> REMOTE (pid %u)\n", pid);
	fprintf(stderr, "[injector] libcbase @ 0x%lx\n", base);
	fprintf(stderr, "[injector]  execmem @ 0x%lx\n", execmem);

	// write path
	fprintf(stderr, "[injector]  pathmem @ 0x%lx\n", pathmem);
	write_child_mem(pid, path, pathmem, strlen(path)+1);

	// call dlopen
	ret = pt_ptrcall(pid, execmem, /*err*/ 0, (long) (base+off_dlopen), 2, pathmem, RTLD_LAZY);
	if(ret == 0) { fprintf(stderr, "[injector] dlopen failed.\n"); return -1; }

	//// RESTORE stack frame & everything
	if(ptrace(PTRACE_SETREGS, pid, 0, &oldregs) < 0) return -1;
	if(ptrace(PTRACE_DETACH, pid, 0, 0) < 0) return -1;

	fprintf(stderr, "[injector] done.\n");

	return 0;
}
#endif	// __x86_64__ || __i386__


int main(int argc, char *argv[]) {
	long base = 0;
	char fullname[PATH_MAX];
	pid_t target;

	if(argc < 3) {
		fprintf(stderr, "usage: %s pid injected.so\n", argv[0]);
		return -1;
	}

	target = strtol(argv[1], NULL, 0);

	if(realpath(argv[2], fullname) == NULL) {
		perror("realpath");
		return -1;
	}

	if((base = find_libcbase(getpid())) == 0) {
		fprintf(stderr, "cannot find base address of libc.\n");
		return -1;
	}

	off_dlopen = find_libcoffset(base, "__libc_dlopen_mode");
	off_malloc = find_libcoffset(base, "malloc");
	off_free   = find_libcoffset(base, "free");

	fprintf(stderr, "[injector] fullpath = %s\n", fullname);
	fprintf(stderr, "[injector] >>>>> LOCAL\n");
	fprintf(stderr, "[injector] __libc_dlopen_mode: 0x%lx (offset 0x%lx)\n", base + off_dlopen, off_dlopen);
	fprintf(stderr, "[injector]             malloc: 0x%lx (offset 0x%lx)\n", base + off_malloc, off_malloc);
	fprintf(stderr, "[injector]               free: 0x%lx (offset 0x%lx)\n", base + off_free,   off_free);

	if(dll_inject(target, fullname) < 0)
		perror("dll_inject");

	return 0;
}

