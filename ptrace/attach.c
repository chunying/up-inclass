#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
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
	int status;

	if(argc < 2) {
		fprintf(stderr, "usage: %s pid\n", argv[0]);
		return -1;
	}

	child = strtol(argv[1], NULL, 0);
	assert(child > 0);

	if(ptrace(PTRACE_ATTACH, child, 0, 0) < 0) {
		perror("ptrace");
		return -1;
	}

	if(waitpid(child, &status, 0) < 0) errquit("waitpid");
	assert(WIFSTOPPED(status));
	//ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_EXITKILL);

	fprintf(stderr, "sleeping for 3s ...\n");
	sleep(3);

	ptrace(PTRACE_CONT, child, 0, 0);
	waitpid(child, &status, 0);
	perror("done");

	return 0;
}

