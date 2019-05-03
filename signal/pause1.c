#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void err_sys(const char *m) {
	perror(m);
	exit(-1);
}

static void sig_int(int s) {
	printf("caught SIGINT\n");
}

int main() {
	sigset_t newmask, oldmask;
	signal(SIGINT, sig_int);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);	/* block SIGINT and save current signal mask */
	if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	/* critical region of code */
	printf("sleep(5) ... Press Ctrl-C to quit.\n");
	sleep(5);
	printf("sleep done.\n");
	/* reset signal mask, which unblocks SIGINT */
	if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	/* window is open */
	pause();	/* wait for signal to occur */
	/* continue processing */ 

	return 0;
}

