#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

static int ptraced = 1;

void dump_status(pid_t pid, int status) {
	if(WIFEXITED(status)) {
		fprintf(stderr, "** child %d returned %d\n",
			pid, WEXITSTATUS(status));
	} else if(WIFSIGNALED(status)) {
		fprintf(stderr, "** child %d signalled %d [%s]%s\n",
			pid, WTERMSIG(status),
			strsignal(WTERMSIG(status)),
			WCOREDUMP(status) ? " (core dumped)" : "");
	} else if(WIFSTOPPED(status)) {
		fprintf(stderr, "** child %d stopped by signal %d [%s]\n",
			pid, WSTOPSIG(status),
			strsignal(WSTOPSIG(status)));
	} 
	return;
}

void sigchld(int s) {
	pid_t pid;
	int status;
	while((pid = waitpid(0, &status, WNOHANG)) > 0) {
		fprintf(stderr, "!! caught SIGCHLD for %d\n", pid);
		dump_status(pid, status);
		if(ptraced) ptrace(PTRACE_CONT, pid, 0, 0);
	}
	return;
}

int main(int argc, char *argv[]) {
	pid_t pid;

	signal(SIGCHLD, sigchld);

	if(argc < 2) {
		fprintf(stderr, "usage: %s cmd [args ...]\n", argv[0]);
		return -1;
	}

	if((pid = fork()) < 0) {
		perror("fork");
		return -1;
	}
	
	if(pid == 0) {
		signal(SIGCHLD, SIG_DFL);
		if(ptraced) ptrace(PTRACE_TRACEME, 0, 0, 0);
		execve(argv[1], argv+1, NULL);
		perror("execve");
		return -1;
	}

	while(1) pause();

	return 0;
}
