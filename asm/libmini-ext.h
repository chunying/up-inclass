#ifndef __LIBMINI_EXT_H__
#define __LIBMINI_EXT_H__

time_t time(time_t * unused);

void srand(unsigned int seed);
unsigned int grand();
int rand();

/* from /usr/include/asm-generic/signal-defs.h */
#define SIG_DFL	((sighandler_t) 0)	/* default signal handling */
#define SIG_IGN	((sighandler_t) 1)	/* ignore signal */
#define SIG_ERR	((sighandler_t) -1)	/* error return from signal */

typedef struct sigset_s {
	union {
		char c[8];
		long l[1];
	} mask;
} sigset_t;

typedef struct jmp_buf_s {
	long long reg[8];
	sigset_t mask;
} jmp_buf[1];

struct sigaction {
	void        (*sa_handler)(int);
	//void      (*sa_sigaction)(int, void /*siginfo_t*/ *, void *);
	unsigned long sa_flags;
	void        (*sa_restorer)(void);
	sigset_t      sa_mask;
};

typedef void (*sighandler_t)(int);

unsigned alarm(unsigned seconds);
int setjmp(jmp_buf jb);			/* must be done in assembly */
void longjmp(jmp_buf jb, int ret);	/* must be done in assembly */
sighandler_t signal(int signum, sighandler_t handler);
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
int sigpending(sigset_t *set);

int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);
int sigismember(const sigset_t *set, int signum);

int sys_rt_sigaction(int signum, const struct sigaction *act, struct sigaction *oldact, size_t sigsetsize);
int sys_rt_sigprocmask(int how, const sigset_t *set, sigset_t *oldset, size_t sigsetsize);
int sys_rt_sigpending(sigset_t *set, size_t sigsetsize);
int sys_rt_sigsuspend(const sigset_t *mask, size_t sigsetsize);

#endif
