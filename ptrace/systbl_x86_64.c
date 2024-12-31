#include <stdio.h>
#include <sys/ptrace.h>
#include "systbl.h"

static char * sys_dump_default(systbl_entry_t *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	int wlen;
	char *ptr = buf;
	wlen = snprintf(buf, bufsz, "%s(", e->name);
	bufsz -= wlen;
	ptr += wlen;
	/* rdi, rsi, rdx, r10, r8, r9 */
	if(e->narg > 0) { wlen = snprintf(ptr, bufsz,   "0x%llx", regs->rdi); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 1) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rsi); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 2) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rdx); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 3) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r10); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 4) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r8);  bufsz -= wlen; ptr += wlen; }
	if(e->narg > 5) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r9);  bufsz -= wlen; ptr += wlen; }
	snprintf(ptr, bufsz, ")");
	return buf;
}

static char * sys_get_string(pid_t child, void *addr, char *buf, int bufsz) {
	long value;
	char *ptr = buf, *ch = (char*) &value;
	void *base = (void*) (((long) addr) & 0xfffffffffffffff0);
	int i, offset = addr - base;
	if(addr == NULL || buf == NULL || bufsz < 1) return NULL;
	while(bufsz > 1) {
		value = ptrace(PTRACE_PEEKDATA, child, base, 0);
		for(i = offset; i < sizeof(long) && bufsz > 1; i++) {
			if(ch[i] == 0) { goto done; }
			*ptr++ = ch[i];
			bufsz--;
		}
		offset = 0;
		base += sizeof(long);
	}
done:
	*ptr = '\0';
	return buf;
}

static char *
sys_dump_str(systbl_entry_t *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	int wlen;
	char *ptr = buf;
	char fname[1024];
	wlen = snprintf(buf, bufsz, "%s(", e->name);
	bufsz -= wlen;
	ptr += wlen;
	/* rdi = string */
	wlen = snprintf(ptr, bufsz, "\"%s\"", sys_get_string(child, (void*) regs->rdi, fname, sizeof(fname)));
	bufsz -= wlen; ptr += wlen;
	// the rest
	if(e->narg > 1) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rsi); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 2) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rdx); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 3) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r10); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 4) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r8);  bufsz -= wlen; ptr += wlen; }
	if(e->narg > 5) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r9);  bufsz -= wlen; ptr += wlen; }
	//
	snprintf(ptr, bufsz, ")");
	return buf;
}

static char *
sys_dump_str_mode(systbl_entry_t *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	int wlen;
	char *ptr = buf;
	char fname[1024];
	wlen = snprintf(buf, bufsz, "%s(", e->name);
	bufsz -= wlen;
	ptr += wlen;
	/* rdi = string */
	wlen = snprintf(ptr, bufsz, "\"%s\"", sys_get_string(child, (void*) regs->rdi, fname, sizeof(fname)));
	bufsz -= wlen; ptr += wlen;
	/* rsi = mode */
	wlen = snprintf(ptr, bufsz, ", %05llo", regs->rsi);
	bufsz -= wlen; ptr += wlen;
	// the rest
	if(e->narg > 2) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rdx); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 3) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r10); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 4) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r8);  bufsz -= wlen; ptr += wlen; }
	if(e->narg > 5) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r9);  bufsz -= wlen; ptr += wlen; }
	snprintf(ptr, bufsz, ")");
	return buf;
}

static char *
sys_dump_str_raw(systbl_entry_t *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	int wlen;
	char *ptr = buf;
	char fname[1024];
	wlen = snprintf(buf, bufsz, "%s(", e->name);
	bufsz -= wlen;
	ptr += wlen;
	/* rdi = string */
	wlen = snprintf(ptr, bufsz, "\"%s\"", sys_get_string(child, (void*) regs->rdi, fname, sizeof(fname)));
	bufsz -= wlen; ptr += wlen;
	/* rsi = raw */
	wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rsi);
	bufsz -= wlen; ptr += wlen;
	//
	snprintf(ptr, bufsz, ")");
	return buf;
}

static char *
sys_dump_str_str(systbl_entry_t *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	int wlen;
	char *ptr = buf;
	char fname[1024];
	wlen = snprintf(buf, bufsz, "%s(", e->name);
	bufsz -= wlen;
	ptr += wlen;
	/* rdi = string */
	wlen = snprintf(ptr, bufsz, "\"%s\"", sys_get_string(child, (void*) regs->rdi, fname, sizeof(fname)));
	bufsz -= wlen; ptr += wlen;
	/* rsi = string */
	wlen = snprintf(ptr, bufsz, ", \"%s\"", sys_get_string(child, (void*) regs->rsi, fname, sizeof(fname)));
	bufsz -= wlen; ptr += wlen;
	// the rest
	if(e->narg > 2) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rdx); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 3) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r10); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 4) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r8);  bufsz -= wlen; ptr += wlen; }
	if(e->narg > 5) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r9);  bufsz -= wlen; ptr += wlen; }
	snprintf(ptr, bufsz, ")");
	return buf;
}

static char *
sys_dump_raw_str(systbl_entry_t *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	int wlen;
	char *ptr = buf;
	char fname[1024];
	wlen = snprintf(buf, bufsz, "%s(", e->name);
	bufsz -= wlen;
	ptr += wlen;
	/* rdi = raw */
	wlen = snprintf(ptr, bufsz, "0x%llx", regs->rdi);
	bufsz -= wlen; ptr += wlen;
	/* rsi = string */
	wlen = snprintf(ptr, bufsz, ", \"%s\"", sys_get_string(child, (void*) regs->rsi, fname, sizeof(fname)));
	bufsz -= wlen; ptr += wlen;
	// the rest
	if(e->narg > 2) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->rdx); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 3) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r10); bufsz -= wlen; ptr += wlen; }
	if(e->narg > 4) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r8);  bufsz -= wlen; ptr += wlen; }
	if(e->narg > 5) { wlen = snprintf(ptr, bufsz, ", 0x%llx", regs->r9);  bufsz -= wlen; ptr += wlen; }
	snprintf(ptr, bufsz, ")");
	return buf;
}

systbl_entry_t syscall_tbl[] = {
	{ 0,	3, "read",			sys_dump_default },
	{ 1,	3, "write",			sys_dump_default },
	{ 2,	3, "open",			sys_dump_default },
	{ 3,	1, "close",			sys_dump_default },
	{ 4,	2, "stat",			sys_dump_str_raw },
	{ 5,	2, "fstat",			sys_dump_default },
	{ 6,	2, "lstat",			sys_dump_str_raw },
	{ 7,	3, "poll",			sys_dump_default },
	{ 8,	3, "lseek",			sys_dump_default },
	{ 9,	6, "mmap",			sys_dump_default },
	{ 10,	3, "mprotect",			sys_dump_default },
	{ 11,	2, "munmap",			sys_dump_default },
	{ 12,	1, "brk",			sys_dump_default },
	{ 13,	4, "rt_sigaction",		sys_dump_default },
	{ 14,	4, "rt_sigprocmask",		sys_dump_default },
	{ 15,	1, "rt_sigreturn",		sys_dump_default },
	{ 16,	3, "ioctl",			sys_dump_default },
	{ 17,	4, "pread64",			sys_dump_default },
	{ 18,	4, "pwrite64",			sys_dump_default },
	{ 19,	3, "readv",			sys_dump_default },
	{ 20,	3, "writev",			sys_dump_default },
	{ 21,	2, "access",			sys_dump_str_mode },
	{ 22,	1, "pipe",			sys_dump_default },
	{ 23,	5, "select",			sys_dump_default },
	{ 24,	0, "sched_yield",		sys_dump_default },
	{ 25,	5, "mremap",			sys_dump_default },
	{ 26,	3, "msync",			sys_dump_default },
	{ 27,	3, "mincore",			sys_dump_default },
	{ 28,	3, "madvise",			sys_dump_default },
	{ 29,	3, "shmget",			sys_dump_default },
	{ 30,	3, "shmat",			sys_dump_default },
	{ 31,	3, "shmctl",			sys_dump_default },
	{ 32,	1, "dup",			sys_dump_default },
	{ 33,	2, "dup2",			sys_dump_default },
	{ 34,	0, "pause",			sys_dump_default },
	{ 35,	2, "nanosleep",			sys_dump_default },
	{ 36,	2, "getitimer",			sys_dump_default },
	{ 37,	1, "alarm",			sys_dump_default },
	{ 38,	3, "setitimer",			sys_dump_default },
	{ 39,	0, "getpid",			sys_dump_default },
	{ 40,	4, "sendfile",			sys_dump_default },
	{ 41,	3, "socket",			sys_dump_default },
	{ 42,	3, "connect",			sys_dump_default },
	{ 43,	3, "accept",			sys_dump_default },
	{ 44,	6, "sendto",			sys_dump_default },
	{ 45,	6, "recvfrom",			sys_dump_default },
	{ 46,	3, "sendmsg",			sys_dump_default },
	{ 47,	3, "recvmsg",			sys_dump_default },
	{ 48,	2, "shutdown",			sys_dump_default },
	{ 49,	3, "bind",			sys_dump_default },
	{ 50,	2, "listen",			sys_dump_default },
	{ 51,	3, "getsockname",		sys_dump_default },
	{ 52,	3, "getpeername",		sys_dump_default },
	{ 53,	4, "socketpair",		sys_dump_default },
	{ 54,	5, "setsockopt",		sys_dump_default },
	{ 55,	5, "getsockopt",		sys_dump_default },
	{ 56,	4, "clone",			sys_dump_default },
	{ 57,	0, "fork",			sys_dump_default },
	{ 58,	0, "vfork",			sys_dump_default },
	{ 59,	3, "execve",			sys_dump_default },
	{ 60,	1, "exit",			sys_dump_default },
	{ 61,	4, "wait4",			sys_dump_default },
	{ 62,	2, "kill",			sys_dump_default },
	{ 63,	1, "uname",			sys_dump_default },
	{ 64,	3, "semget",			sys_dump_default },
	{ 65,	3, "semop",			sys_dump_default },
	{ 66,	4, "semctl",			sys_dump_default },
	{ 67,	1, "shmdt",			sys_dump_default },
	{ 68,	2, "msgget",			sys_dump_default },
	{ 69,	4, "msgsnd",			sys_dump_default },
	{ 70,	5, "msgrcv",			sys_dump_default },
	{ 71,	3, "msgctl",			sys_dump_default },
	{ 72,	3, "fcntl",			sys_dump_default },
	{ 73,	2, "flock",			sys_dump_default },
	{ 74,	1, "fsync",			sys_dump_default },
	{ 75,	1, "fdatasync",			sys_dump_default },
	{ 76,	2, "truncate",			sys_dump_str_raw },
	{ 77,	2, "ftruncate",			sys_dump_default },
	{ 78,	3, "getdents",			sys_dump_default },
	{ 79,	2, "getcwd",			sys_dump_default },
	{ 80,	1, "chdir",			sys_dump_str },
	{ 81,	1, "fchdir",			sys_dump_default },
	{ 82,	2, "rename",			sys_dump_str_str },
	{ 83,	2, "mkdir",			sys_dump_str_mode },
	{ 84,	1, "rmdir",			sys_dump_str },
	{ 85,	2, "creat",			sys_dump_str_mode },
	{ 86,	2, "link",			sys_dump_str_str },
	{ 87,	1, "unlink",			sys_dump_str },
	{ 88,	2, "symlink",			sys_dump_str_str },
	{ 89,	3, "readlink",			sys_dump_str },
	{ 90,	2, "chmod",			sys_dump_str_mode },
	{ 91,	2, "fchmod",			sys_dump_default },
	{ 92,	3, "chown",			sys_dump_str },
	{ 93,	3, "fchown",			sys_dump_default },
	{ 94,	3, "lchown",			sys_dump_str },
	{ 95,	1, "umask",			sys_dump_default },
	{ 96,	2, "gettimeofday",		sys_dump_default },
	{ 97,	2, "getrlimit",			sys_dump_default },
	{ 98,	2, "getrusage",			sys_dump_default },
	{ 99,	1, "sysinfo",			sys_dump_default },
	{ 100,	1, "times",			sys_dump_default },
	{ 101,	4, "ptrace",			sys_dump_default },
	{ 102,	0, "getuid",			sys_dump_default },
	{ 103,	3, "syslog",			sys_dump_default },
	{ 104,	0, "getgid",			sys_dump_default },
	{ 105,	1, "setuid",			sys_dump_default },
	{ 106,	1, "setgid",			sys_dump_default },
	{ 107,	0, "geteuid",			sys_dump_default },
	{ 108,	0, "getegid",			sys_dump_default },
	{ 109,	2, "setpgid",			sys_dump_default },
	{ 110,	0, "getppid",			sys_dump_default },
	{ 111,	0, "getpgrp",			sys_dump_default },
	{ 112,	0, "setsid",			sys_dump_default },
	{ 113,	2, "setreuid",			sys_dump_default },
	{ 114,	2, "setregid",			sys_dump_default },
	{ 115,	2, "getgroups",			sys_dump_default },
	{ 116,	2, "setgroups",			sys_dump_default },
	{ 117,	3, "setresuid",			sys_dump_default },
	{ 118,	3, "getresuid",			sys_dump_default },
	{ 119,	3, "setresgid",			sys_dump_default },
	{ 120,	3, "getresgid",			sys_dump_default },
	{ 121,	1, "getpgid",			sys_dump_default },
	{ 122,	1, "setfsuid",			sys_dump_default },
	{ 123,	1, "setfsgid",			sys_dump_default },
	{ 124,	1, "getsid",			sys_dump_default },
	{ 125,	2, "capget",			sys_dump_default },
	{ 126,	2, "capset",			sys_dump_default },
	{ 127,	2, "rt_sigpending",		sys_dump_default },
	{ 128,	4, "rt_sigtimedwait",		sys_dump_default },
	{ 129,	3, "rt_sigqueueinfo",		sys_dump_default },
	{ 130,	2, "rt_sigsuspend",		sys_dump_default },
	{ 131,	2, "sigaltstack",		sys_dump_default },
	{ 132,	2, "utime",			sys_dump_str },
	{ 133,	3, "mknod",			sys_dump_str_mode },
	{ 134,	1, "uselib",			sys_dump_default },
	{ 135,	1, "personality",		sys_dump_default },
	{ 136,	2, "ustat",			sys_dump_default },
	{ 137,	2, "statfs",			sys_dump_str },
	{ 138,	2, "fstatfs",			sys_dump_default },
	{ 139,	3, "sysfs",			sys_dump_default },
	{ 140,	2, "getpriority",		sys_dump_default },
	{ 141,	3, "setpriority",		sys_dump_default },
	{ 142,	2, "sched_setparam",		sys_dump_default },
	{ 143,	2, "sched_getparam",		sys_dump_default },
	{ 144,	3, "sched_setscheduler",	sys_dump_default },
	{ 145,	1, "sched_getscheduler",	sys_dump_default },
	{ 146,	1, "sched_get_priority_max",	sys_dump_default },
	{ 147,	1, "sched_get_priority_min",	sys_dump_default },
	{ 148,	2, "sched_rr_get_interval",	sys_dump_default },
	{ 149,	2, "mlock",			sys_dump_default },
	{ 150,	2, "munlock",			sys_dump_default },
	{ 151,	1, "mlockall",			sys_dump_default },
	{ 152,	0, "munlockall",		sys_dump_default },
	{ 153,	0, "vhangup",			sys_dump_default },
	{ 154,	3, "modify_ldt",		sys_dump_default },
	{ 155,	2, "pivot_root",		sys_dump_str_str },
	{ 156,	1, "_sysctl",			sys_dump_default },
	{ 157,	6, "prctl",			sys_dump_default },
	{ 158,	3, "arch_prctl",		sys_dump_default },
	{ 159,	1, "adjtimex",			sys_dump_default },
	{ 160,	2, "setrlimit",			sys_dump_default },
	{ 161,	1, "chroot",			sys_dump_str },
	{ 162,	0, "sync",			sys_dump_default },
	{ 163,	1, "acct",			sys_dump_str },
	{ 164,	2, "settimeofday",		sys_dump_default },
	{ 165,	5, "mount",			sys_dump_str_str },
	{ 166,	2, "umount2",			sys_dump_str },
	{ 167,	2, "swapon",			sys_dump_str },
	{ 168,	1, "swapoff",			sys_dump_str },
	{ 169,	4, "reboot",			sys_dump_default },
	{ 170,	2, "sethostname",		sys_dump_str },
	{ 171,	2, "setdomainname",		sys_dump_str },
	{ 172,	2, "iopl",			sys_dump_default },
	{ 173,	3, "ioperm",			sys_dump_default },
	{ 174,	1, "create_module",		sys_dump_default },
	{ 175,	3, "init_module",		sys_dump_default },
	{ 176,	2, "delete_module",		sys_dump_str },
	{ 177,	1, "get_kernel_syms",		sys_dump_default },
	{ 178,	1, "query_module",		sys_dump_default },
	{ 179,	4, "quotactl",			sys_dump_default },
	{ 180,	1, "nfsservctl",		sys_dump_default },
	{ 181,	1, "getpmsg",			sys_dump_default },
	{ 182,	1, "putpmsg",			sys_dump_default },
	{ 183,	1, "afs_syscall",		sys_dump_default },
	{ 184,	1, "tuxcall",			sys_dump_default },
	{ 185,	1, "security",			sys_dump_default },
	{ 186,	0, "gettid",			sys_dump_default },
	{ 187,	3, "readahead",			sys_dump_default },
	{ 188,	5, "setxattr",			sys_dump_str_str },
	{ 189,	5, "lsetxattr",			sys_dump_str_str },
	{ 190,	5, "fsetxattr",			sys_dump_default }, // XXX
	{ 191,	4, "getxattr",			sys_dump_str_str },
	{ 192,	4, "lgetxattr",			sys_dump_str_str },
	{ 193,	4, "fgetxattr",			sys_dump_default }, // XXX
	{ 194,	3, "listxattr",			sys_dump_str }, // XXX
	{ 195,	3, "llistxattr",		sys_dump_str },	// XXX
	{ 196,	3, "flistxattr",		sys_dump_default }, // XXX
	{ 197,	2, "removexattr",		sys_dump_str_str },
	{ 198,	2, "lremovexattr",		sys_dump_str_str }, // XXX
	{ 199,	2, "fremovexattr",		sys_dump_default },
	{ 200,	2, "tkill",			sys_dump_default },
	{ 201,	1, "time",			sys_dump_default },
	{ 202,	6, "futex",			sys_dump_default },
	{ 203,	3, "sched_setaffinity",		sys_dump_default },
	{ 204,	3, "sched_getaffinity",		sys_dump_default },
	{ 205,	1, "set_thread_area",		sys_dump_default },
	{ 206,	2, "io_setup",			sys_dump_default },
	{ 207,	1, "io_destroy",		sys_dump_default },
	{ 208,	4, "io_getevents",		sys_dump_default },
	{ 209,	3, "io_submit",			sys_dump_default },
	{ 210,	3, "io_cancel",			sys_dump_default },
	{ 211,	1, "get_thread_area",		sys_dump_default },
	{ 212,	3, "lookup_dcookie",		sys_dump_default },
	{ 213,	1, "epoll_create",		sys_dump_default },
	{ 214,	1, "epoll_ctl_old",		sys_dump_default },
	{ 215,	1, "epoll_wait_old",		sys_dump_default },
	{ 216,	5, "remap_file_pages",		sys_dump_default },
	{ 217,	3, "getdents64",		sys_dump_default },
	{ 218,	1, "set_tid_address",		sys_dump_default },
	{ 219,	0, "restart_syscall",		sys_dump_default },
	{ 220,	4, "semtimedop",		sys_dump_default },
	{ 221,	4, "fadvise64",			sys_dump_default },
	{ 222,	3, "timer_create",		sys_dump_default },
	{ 223,	4, "timer_settime",		sys_dump_default },
	{ 224,	2, "timer_gettime",		sys_dump_default },
	{ 225,	1, "timer_getoverrun",		sys_dump_default },
	{ 226,	1, "timer_delete",		sys_dump_default },
	{ 227,	2, "clock_settime",		sys_dump_default },
	{ 228,	2, "clock_gettime",		sys_dump_default },
	{ 229,	2, "clock_getres",		sys_dump_default },
	{ 230,	4, "clock_nanosleep",		sys_dump_default },
	{ 231,	1, "exit_group",		sys_dump_default },
	{ 232,	4, "epoll_wait",		sys_dump_default },
	{ 233,	4, "epoll_ctl",			sys_dump_default },
	{ 234,	3, "tgkill",			sys_dump_default },
	{ 235,	2, "utimes",			sys_dump_default },
	{ 236,	1, "vserver",			sys_dump_default },
	{ 237,	6, "mbind",			sys_dump_default },
	{ 238,	3, "set_mempolicy",		sys_dump_default },
	{ 239,	5, "get_mempolicy",		sys_dump_default },
	{ 240,	4, "mq_open",			sys_dump_str }, // XXX
	{ 241,	1, "mq_unlink",			sys_dump_str },
	{ 242,	5, "mq_timedsend",		sys_dump_default }, // XXX
	{ 243,	5, "mq_timedreceive",		sys_dump_default }, // XXX
	{ 244,	2, "mq_notify",			sys_dump_default },
	{ 245,	3, "mq_getsetattr",		sys_dump_default },
	{ 246,	4, "kexec_load",		sys_dump_default },
	{ 247,	5, "waitid",			sys_dump_default },
	{ 248,	4, "add_key",			sys_dump_str_str },
	{ 249,	4, "request_key",		sys_dump_str_str },
	{ 250,	5, "keyctl",			sys_dump_default },
	{ 251,	3, "ioprio_set",		sys_dump_default },
	{ 252,	2, "ioprio_get",		sys_dump_default },
	{ 253,	0, "inotify_init",		sys_dump_default }, // XXX
	{ 254,	3, "inotify_add_watch",		sys_dump_default },
	{ 255,	2, "inotify_rm_watch",		sys_dump_default },
	{ 256,	4, "migrate_pages",		sys_dump_default },
	{ 257,	4, "openat",			sys_dump_raw_str },
	{ 258,	3, "mkdirat",			sys_dump_raw_str },
	{ 259,	4, "mknodat",			sys_dump_raw_str },
	{ 260,	5, "fchownat",			sys_dump_raw_str },
	{ 261,	3, "futimesat",			sys_dump_raw_str },
	{ 262,	4, "newfstatat",		sys_dump_raw_str },
	{ 263,	3, "unlinkat",			sys_dump_raw_str },
	{ 264,	4, "renameat",			sys_dump_default }, // XXX
	{ 265,	5, "linkat",			sys_dump_default }, // XXX
	{ 266,	3, "symlinkat",			sys_dump_default }, // XXX
	{ 267,	4, "readlinkat",		sys_dump_default }, // XXX
	{ 268,	3, "fchmodat",			sys_dump_raw_str },
	{ 269,	3, "faccessat",			sys_dump_raw_str },
	{ 270,	6, "pselect6",			sys_dump_default },
	{ 271,	5, "ppoll",			sys_dump_default },
	{ 272,	1, "unshare",			sys_dump_default },
	{ 273,	2, "set_robust_list",		sys_dump_default },
	{ 274,	3, "get_robust_list",		sys_dump_default },
	{ 275,	6, "splice",			sys_dump_default },
	{ 276,	4, "tee",			sys_dump_default },
	{ 277,	4, "sync_file_range",		sys_dump_default },
	{ 278,	4, "vmsplice",			sys_dump_default },
	{ 279,	6, "move_pages",		sys_dump_default },
	{ 280,	4, "utimensat",			sys_dump_raw_str },
	{ 281,	6, "epoll_pwait",		sys_dump_default },
	{ 282,	3, "signalfd",			sys_dump_default },
	{ 283,	2, "timerfd_create",		sys_dump_default },
	{ 284,	1, "eventfd",			sys_dump_default },
	{ 285,	4, "fallocate",			sys_dump_default },
	{ 286,	4, "timerfd_settime",		sys_dump_default },
	{ 287,	2, "timerfd_gettime",		sys_dump_default },
	{ 288,	4, "accept4",			sys_dump_default },
	{ 289,	4, "signalfd4",			sys_dump_default },
	{ 290,	2, "eventfd2",			sys_dump_default },
	{ 291,	1, "epoll_create1",		sys_dump_default },
	{ 292,	3, "dup3",			sys_dump_default },
	{ 293,	2, "pipe2",			sys_dump_default },
	{ 294,	1, "inotify_init1",		sys_dump_default },
	{ 295,	5, "preadv",			sys_dump_default },
	{ 296,	5, "pwritev",			sys_dump_default },
	{ 297,	4, "rt_tgsigqueueinfo",		sys_dump_default },
	{ 298,	5, "perf_event_open",		sys_dump_default },
	{ 299,	5, "recvmmsg",			sys_dump_default },
	{ 300,	2, "fanotify_init",		sys_dump_default },
	{ 301,	5, "fanotify_mark",		sys_dump_default },
	{ 302,	4, "prlimit64",			sys_dump_default },
	{ 303,	5, "name_to_handle_at",		sys_dump_raw_str },
	{ 304,	5, "open_by_handle_at",		sys_dump_raw_str },
	{ 305,	2, "clock_adjtime",		sys_dump_default },
	{ 306,	1, "syncfs",			sys_dump_default },
	{ 307,	4, "sendmmsg",			sys_dump_default },
	{ 308,	2, "setns",			sys_dump_default },
	{ 309,	3, "getcpu",			sys_dump_default },
	{ 310,	6, "process_vm_readv",		sys_dump_default },
	{ 311,	6, "process_vm_writev",		sys_dump_default },
	{ 312,	5, "kcmp",			sys_dump_default },
	{ 313,	3, "finit_module",		sys_dump_default },
	{ 314,	3, "sched_setattr",		sys_dump_default },
	{ 315,	4, "sched_getattr",		sys_dump_default },
	{ 316,	5, "renameat2",			sys_dump_default }, // XXX
	{ 317,	3, "seccomp",			sys_dump_default },
	{ 318,	3, "getrandom",			sys_dump_default },
	{ 319,	2, "memfd_create",		sys_dump_str },
	{ 320,	5, "kexec_file_load",		sys_dump_default },
	{ 321,	3, "bpf",			sys_dump_default },
	{ 322,	5, "stub_execveat",		sys_dump_default },
	{ 323,	1, "userfaultfd",		sys_dump_default },
	{ 324,	2, "membarrier",		sys_dump_default },
	{ 325,	3, "mlock2",			sys_dump_default },
	{ 326,	6, "copy_file_range",		sys_dump_default },
	{ 327,	6, "preadv2",			sys_dump_default },
	{ 328,	6, "pwritev2",			sys_dump_default },
	{ -1,	0, "<not_implemented>",		sys_dump_default }
};

