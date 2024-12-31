#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

void errquit(const char *msg) {
	perror(msg);
	exit(-1);
}

int main(int argc, char *argv[]) {
	pid_t child;
	char *p = strdup("./demo/hidden");
	if(argc > 1) p = argv[1];
	if((child = fork()) < 0) errquit("fork");
	if(child == 0) {
		if(ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) errquit("ptrace");
		execlp(p, p, NULL);
		errquit("execlp");
	} else {
		int status;
		long code;
		if(waitpid(child, &status, 0) < 0) errquit("waitpid");
		assert(WIFSTOPPED(status));
		ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_EXITKILL);
		code = ptrace(PTRACE_PEEKTEXT, child, 0x4000cd, 0);
		if(ptrace(PTRACE_POKETEXT, child, 0x4000cdL,
			  (code & 0xffffffffffff0000) | 0x9090) != 0) errquit("poketext");
		ptrace(PTRACE_CONT, child, 0, 0);
		waitpid(child, &status, 0);
		perror("done");
	}
	return 0;
}

