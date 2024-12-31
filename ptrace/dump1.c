#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

#define USE_PEEKUSER	1

void errquit(const char *msg) {
	perror(msg);
	exit(-1);
}

int
main(int argc, char *argv[]) {
	pid_t child;
	if(argc < 2) {
		fprintf(stderr, "usage: %s program [args ...]\n", argv[0]);
		return -1;
	}
	if((child = fork()) < 0) errquit("fork");
	if(child == 0) {
		if(ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) errquit("ptrace@child");
		execvp(argv[1], argv+1);
		errquit("execvp");
	} else {
		long long counter = 0LL;
		int wait_status;
		if(waitpid(child, &wait_status, 0) < 0) errquit("waitpid");
		ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_EXITKILL);
		while (WIFSTOPPED(wait_status)) {
			long ret;
			unsigned long long rip;
			struct user_regs_struct regs;
			unsigned char *ptr = (unsigned char *) &ret;
			counter++;
#if USE_PEEKUSER
			if((rip = ptrace(PTRACE_PEEKUSER, child, ((unsigned char *) &regs.rip) - ((unsigned char *) &regs), 0)) != 0) {
#else
			if(ptrace(PTRACE_GETREGS, child, 0, &regs) == 0) {
				rip = regs.rip;
#endif
				ret = ptrace(PTRACE_PEEKTEXT, child, rip, 0);
				fprintf(stderr, "0x%llx: %2.2x %2.2x %2.2x %2.2x %2.2x %2.2x %2.2x %2.2x\n",
					rip,
					ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7]);
			}
			if(ptrace(PTRACE_SINGLESTEP, child, 0, 0) < 0) errquit("ptrace@parent");
			if(waitpid(child, &wait_status, 0) < 0) errquit("waitpid");
		}
		fprintf(stderr, "## %lld instruction(s) executed\n", counter);
	}
	return 0;
}

