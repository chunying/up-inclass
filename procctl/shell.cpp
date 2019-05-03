#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <string>
#include <vector>
using namespace std;

void
handler(int s) {
	switch(s) {
	case SIGTTOU:
		break;
	}
}

int
myerror(const char *prefix) {
	fprintf(stderr, "*** %s: %s\n", prefix, strerror(errno));
	return -1;
}

void
prompt() {
	int s;
	char cwd[1024];
	if(getcwd(cwd, sizeof(cwd)) == NULL) {
		printf("> ");
	} else {
		s = strlen(cwd);
		s = (s > 16) ? (s - 16) : 0;
		printf("... %s> ", &cwd[s]);
	}
	return;
}

vector<string>
tokenize(string s, const char *delim) {
	char *token, *saveptr;
	char *input = strdup(s.c_str());
	vector<string> tok;
	if(!input) return tok;
	token = strtok_r(input, delim, &saveptr);
	while(token != NULL) {
		tok.push_back(token);
		token = strtok_r(NULL, delim, &saveptr);
	}
	free(input);
	return tok;
}

string
join(vector<string>& v, const char *delim) {
	string s;
	if(v.size() == 0) return "";
	s = v[0];
	for(unsigned i = 1; i < v.size(); i++) {
		s += delim;
		s += v[i];
	}
	return s;
}

pid_t
runcmd(const char *cmd, pid_t pgid, int infd, int outfd) {
	pid_t pid;
	char **argv;
	vector<string> token = tokenize(cmd, " \n\r");
	unsigned i;
	printf("RUN [%d, %d]: %s\n", infd, outfd, join(token, " ").c_str());
	pid = fork();
	if(pid < 0) {
		return myerror("fork");
	} else if(pid > 0) {
		setpgid(pid, pgid);
		if(pgid == 0)
			if(tcsetpgrp(0, pid) > 0)
				myerror("tcsetpgrp");
		return pid;
	}
	setpgid(0, pgid);
	// arguments
	argv = (char **) malloc(sizeof(char *) * (1 + token.size()));
	for(i = 0; i < token.size(); i++) {
		argv[i] = strdup(token[i].c_str());
	}
	argv[i] = NULL;
	//
	if(infd != 0) {
		dup2(infd, 0);
		close(infd);
	}
	if(outfd != 1) {
		dup2(outfd, 1);
		close(outfd);
	}
	//
	if(execvp(token[0].c_str(), argv) < 0) {
		exit(myerror("exec"));
	}
	return 0;
}

int
init() {
	sigset_t blocks, old;
	sigemptyset(&blocks);
	sigaddset(&blocks, SIGTTOU);
	sigprocmask(SIG_BLOCK, &blocks, &old);
	return 0;
}

int
main() {
	char cmd[8192];

	init();

	printf("simple pipe test\n");
	printf("usage: command {argument} [| commands ...]\n");
	prompt();
	while(fgets(cmd, sizeof(cmd), stdin) != NULL) {
		vector<string> cmds = tokenize(cmd, "|\n\r");
		vector<pid_t> pids;
		pid_t pid = 0, pgid = 0;
		int status;
		int infd = 0, outfd = 1, pfd[2] = { -1, -1 };
		if(cmds.size() == 0) goto nextcmd;
		for(unsigned i = 0; i < cmds.size(); i++) {
			// setup pipe
			if(i != cmds.size()-1) {
				if(pipe(pfd) < 0) {
					myerror("pipe");
					break;
				}
				outfd = pfd[1];
			} else {
				outfd = 1;
			}
			// run the command
			if((pid = runcmd(cmds[i].c_str(), pgid, infd, outfd)) < 0) {
				goto nextcmd;
			}
			if(outfd > 1) close(outfd);
			if(infd  > 0) close(infd);
			if(!pgid) pgid = pid;
			pids.push_back(pid);
			//
			infd = pfd[0];
		}
		waitpid(-pgid, &status, 0);
		if(tcsetpgrp(0, getpgid(0)) < 0)
			myerror("tcsetpgrp");
nextcmd:
		prompt();
	}
	return 0;
}

