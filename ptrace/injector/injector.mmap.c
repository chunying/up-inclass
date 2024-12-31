#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <limits.h>
#include <sys/mman.h>	// mmap
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

#define __RTLD_DLOPEN	0x80000000

// globals
static long off_dlopen;
static long off_malloc;
static long off_free;

void
dump_maps(pid_t pid) {
	char buf[1024];
	FILE *fp;
	snprintf(buf, sizeof(buf), "/proc/%d/maps", pid);
	if((fp = fopen(buf, "rt")) == NULL) {
		perror("dump_maps");
		return;
	}
	while(fgets(buf, sizeof(buf), fp) != NULL) {
		fprintf(stderr, "%s", buf);
	}
	fclose(fp);
	return;
}

void *
find_libcaddr(const char *name) {
	void *handle, *fptr;
	if((handle = dlopen("libc.so.6", RTLD_LAZY)) == NULL) {
		return NULL;
	}
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
		base = end - ((size/2) > 0x1000 ? 0x1000 : (size/2));
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
#ifdef __x86_64__
	fprintf(stderr, "[%s] rax=%-16llx rbx=%-16llx rcx=%-16llx rdx=%-16llx\n",
		pfx, regs.rax, regs.rbx, regs.rcx, regs.rdx);
	fprintf(stderr, "[%s]  r8=%-16llx  r9=%-16llx r10=%-16llx r11=%-16llx\n",
		pfx, regs.r8, regs.r9, regs.r10, regs.r11);
	fprintf(stderr, "[%s] r12=%-16llx r13=%-16llx r14=%-16llx r15=%-16llx\n",
		pfx, regs.r12, regs.r13, regs.r14, regs.r15);
	fprintf(stderr, "[%s] rip=%-16llx rbp=%-16llx rsp=%-16llx\n",
		pfx, regs.rip, regs.rbp, regs.rsp);
#endif
	return;
}

/*
https://stackoverflow.com/questions/38006277/weird-behavior-setting-rip-with-ptrace
*/
static unsigned char code_syscall[] = {
	0x90, 0x90,			// nop * 2: preventing rip-2 problem caused by interrupted syscalls
	0x0f, 0x05,			// syscall
	0x90,				// nop
	0xcc,				// int 3: return to ptrace
	0xeb, 0xfa,			// jmp 0x02
};

long
pt_syscall(pid_t pid, long addr, long errval, long idx, long argc, ...) {
	int status;
	long backup, ret;
	struct user_regs_struct oldregs, regs;
	va_list ap;
	// backup
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
	memcpy(&oldregs, &regs, sizeof(oldregs));
	backup = ptrace(PTRACE_PEEKTEXT, pid, addr, 0);
	// fill parameters and call it
	regs.rip = addr+2;
	regs.rax = idx;
	va_start(ap, argc);
	if(argc > 0) regs.rdi = va_arg(ap, long);
	if(argc > 1) regs.rsi = va_arg(ap, long);
	if(argc > 2) regs.rdx = va_arg(ap, long);
	if(argc > 3) regs.r10 = va_arg(ap, long);
	if(argc > 4) regs.r8  = va_arg(ap, long);
	if(argc > 5) regs.r9  = va_arg(ap, long);
	va_end(ap);
	if(ptrace(PTRACE_POKETEXT, pid, addr, *((long *) code_syscall)) < 0) return errval;
	if(ptrace(PTRACE_SETREGS, pid, 0, &regs) < 0) return errval;
again:
	if(ptrace(PTRACE_CONT, pid, 0, 0) < 0) return errval;
	waitpid(pid, &status, 0);
	// check & get results
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
	if(regs.rip != addr + 6) goto again; // rip should be right after 0xcc
	ret = regs.rax;
	// restore
	if(ptrace(PTRACE_POKETEXT, pid, addr, backup) < 0) return errval;
	if(ptrace(PTRACE_SETREGS, pid, 0, &oldregs) < 0) return errval;
	return ret;
}

static unsigned char code_callrbx[] = {
	0x90, 0x90,			// nop * 2: preventing rip-2 problem caused by interrupted syscalls
	0xff, 0xd3,			// call rbx: target address must be placed in rbx
	0x90,				// nop
	0xcc,				// int 3: return to ptrace
	0xeb, 0xfa,			// jmp 0x02
};

long
pt_ptrcall(pid_t pid, long addr, long errval, long func, long argc, ...) {
	int status;
	long backup, ret;
	struct user_regs_struct oldregs, regs;
	va_list ap;
	// backup
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
	memcpy(&oldregs, &regs, sizeof(oldregs));
	backup = ptrace(PTRACE_PEEKTEXT, pid, addr, 0);
	// fill parameters and call it
	regs.rip = addr+2;
	regs.rbx = func;
	va_start(ap, argc);
	if(argc > 0) regs.rdi = va_arg(ap, long);
	if(argc > 1) regs.rsi = va_arg(ap, long);
	if(argc > 2) regs.rdx = va_arg(ap, long);
	if(argc > 3) regs.rcx = va_arg(ap, long);
	if(argc > 4) regs.r8  = va_arg(ap, long);
	if(argc > 5) regs.r9  = va_arg(ap, long);
	va_end(ap);
	if(ptrace(PTRACE_POKETEXT, pid, addr, *((long *) code_callrbx)) < 0) return errval;
	if(ptrace(PTRACE_SETREGS, pid, 0, &regs) < 0) return errval;
again:
	if(ptrace(PTRACE_CONT, pid, 0, 0) < 0) return errval;
	waitpid(pid, &status, 0);
	// check & get results
	if(ptrace(PTRACE_GETREGS, pid, 0, &regs) < 0) return errval;
	if(regs.rip != addr + 6) goto again; // rip should be right after 0xcc
	ret = regs.rax;
	// restore
	if(ptrace(PTRACE_POKETEXT, pid, addr, backup) < 0) return errval;
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
	// 'push rbp', and then 'mov rbp, rsp'
	regs.rsp -= sizeof(long);
	ptrace(PTRACE_POKETEXT, pid, regs.rsp, regs.rbp);
	regs.rbp = regs.rsp;
	// allocate space (on stack), and write path into it
	pathsize = ((strlen(path) + 1 + sizeof(long))) / sizeof(long) * sizeof(long);
	regs.rsp -= pathsize;
	pathmem = regs.rsp;
	ptrace(PTRACE_SETREGS,pid, 0, &regs);

	fprintf(stderr, "[injector] >>>>> REMOTE (pid %u)\n", pid);
	fprintf(stderr, "[injector] libcbase @ 0x%lx\n", base);
	fprintf(stderr, "[injector]  execmem @ 0x%lx\n", execmem);
#if 0
#if 1
	mem = pt_syscall(pid, execmem, /*err*/ -1, /*mmap*/ 9, 6, 0, 4096, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if(mem == -1) { fprintf(stderr, "[injector] mmap failed.\n"); return -1; }
#else
	mem = pt_ptrcall(pid, execmem, /*err*/ 0, (long) (base+off_malloc), 4096, 0, 0, 0, 0, 0);
	if(mem == 0) { fprintf(stderr, "[injector] malloc failed.\n"); return -1; }
#endif
	fprintf(stderr, "[injector] memory allocated @ 0x%lx\n", mem);
#endif
	// write path
	fprintf(stderr, "[injector]  pathmem @ 0x%lx\n", pathmem);
	write_child_mem(pid, path, pathmem, strlen(path)+1);

	// call dlopen
	ret = pt_ptrcall(pid, execmem, /*err*/ 0, (long) (base+off_dlopen), 2, pathmem, RTLD_LAZY);
	if(ret == 0) { fprintf(stderr, "[injector] dlopen failed.\n"); return -1; }
#if 0
	// free space
	ret = pt_syscall(pid, execmem, /*err*/ -1, /*munmap*/ 11, 2, mem, 4096);
	if(ret != 0) { fprintf(stderr, "[injector] munmap failed.\n"); return -1; }
#endif
	//// RESTORE stack frame
	ptrace(PTRACE_SETREGS, pid, 0, &oldregs);

	fprintf(stderr, "[injector] done.\n");

	ptrace(PTRACE_CONT, pid, 0, 0);
	ptrace(PTRACE_DETACH, pid, 0, 0);

	return 0;
}

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

	/*
	fprintf(stderr, "injecting: %s\n", fullname);
	fptr(fullname, RTLD_NOW | __RTLD_DLOPEN);
	*/

	return 0;
}

