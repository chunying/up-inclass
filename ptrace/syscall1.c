#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>

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
		int enter = 0x01; /* enter syscall (1) or exit from syscall (0) */
		int wait_status;
		if(waitpid(child, &wait_status, 0) < 0) errquit("waitpid");
		ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_EXITKILL|PTRACE_O_TRACESYSGOOD); /* ptrace sig has 0x80 bit marked */
		while (WIFSTOPPED(wait_status)) {
			struct user_regs_struct regs;
			if(ptrace(PTRACE_SYSCALL, child, 0, 0) != 0) errquit("ptrace@parent");
			if(waitpid(child, &wait_status, 0) < 0) errquit("waitpid");
			if(!WIFSTOPPED(wait_status) || !(WSTOPSIG(wait_status) & 0x80)) continue;
			if(ptrace(PTRACE_GETREGS, child, 0, &regs) != 0) errquit("ptrace@parent");
			if(enter) {	// syscall enter
				/* rip has to subtract 2 because machine code of 'syscall' = 0x0f 05 */
				fprintf(stderr, "0x%llx: rax=%llx rdi=%llx rsi=%llx rdx=%llx r10=%llx r8=%llx r9=%llx\n",
					regs.rip-2, regs.orig_rax, regs.rdi, regs.rsi, regs.rdx, regs.r10, regs.r8, regs.r9);
				if(regs.orig_rax == 0x3c || regs.orig_rax == 0xe7)
					fprintf(stderr, "\n"); /* exit || exit_group */
				counter++;
			} else {	// syscall exit
				fprintf(stderr, "0x%llx: ret = 0x%llx\n", regs.rip-2, regs.rax);
			}
			enter ^= 0x01;
		}
		fprintf(stderr, "## %lld syscall(s) executed\n", counter);
	}
	return 0;
}

