#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/personality.h>	// for disabling ASLR

#include "systbl.h"

static int opt_disable_aslr = 0;

void errquit(const char *msg) {
	perror(msg);
	exit(-1);
}

int
usage(const char *progname) {
	fprintf(stderr, "usage: %s [-R] program [args ...]\n", progname);
	fprintf(stderr, "\t-R: disable ASLR\n");
	return -1;
}

int
main(int argc, char *argv[]) {
	char *progname = strdup(argv[0]);
	int ch;
	pid_t child;

	systbl_init(syscall_tbl);

	if(systbl_getcount() <= 0) {
		fprintf(stderr, "no syscall loaded.\n");
		return -1;
	}

	fprintf(stderr, "# %d syscalls loaded.\n", systbl_getcount());

	while((ch = getopt(argc, argv, "R")) != -1) {
		switch(ch) {
		case 'R':
			opt_disable_aslr = 1;
			fprintf(stderr, "# ASLR disabled.\n");
			break;
		default:
			return usage(progname);
		}
	}
	argc -= optind;
	argv += optind;
	
	if(argc < 1) { return usage(progname); }

	if((child = fork()) < 0) errquit("fork");
	if(child == 0) {
		if(opt_disable_aslr) {
			personality(ADDR_NO_RANDOMIZE);
		}
		if(ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) errquit("ptrace@child");
		execvp(argv[0], argv);
		errquit("execvp");
	} else {
		char buf[1024];
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
				fprintf(stderr, "0x%llx: %s", regs.rip-2, systbl_dump(regs.orig_rax, buf, sizeof(buf), child, &regs));
				if(regs.orig_rax == 0x3c || regs.orig_rax == 0xe7)
					fprintf(stderr, "\n"); /* exit || exit_group */
				counter++;
			} else {	// syscall exit
				fprintf(stderr, " = 0x%llx\n", regs.rax);
			}
			enter ^= 0x01;
		}
		fprintf(stderr, "## %lld syscall(s) executed\n", counter);
	}
	return 0;
}

