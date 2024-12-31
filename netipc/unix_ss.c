#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/wait.h>

#define	xerror(x) { perror(x); exit(-1); }

void cleanup(int s) {
	int st;
	while(waitpid(-1, &st, WNOHANG) > 0) ;
}

int worker(int fd) {
	const char *act[] = { "recv", "send" }, *cact = act[0];
	char buf[4096] = "ECHO: ";
	int rlen, pfxlen = 6;
	fprintf(stderr, "work #%d\n", getpid());
	while(1) {
		cact = act[0];
		if((rlen = recv(fd, buf+pfxlen, sizeof(buf)-pfxlen, 0)) <= 0) break;
		cact = act[1];
		if(send(fd, buf, rlen+pfxlen, 0) <= 0) break;
	}
	perror(cact);
	return -1;
}

int main(int argc, char *argv[]) {
	int s;
	struct sockaddr_un sun;

	if(argc < 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		return -1;
	}

	memset(&sun, 0, sizeof(sun));
	sun.sun_family = AF_UNIX;
	strncpy(sun.sun_path, argv[1], sizeof(sun.sun_path));

	unlink(argv[1]);
	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) { xerror("socket"); }
	if(bind(s, (struct sockaddr*) &sun, sizeof(sun)) < 0) { xerror("bind"); }
	if(listen(s, SOMAXCONN) < 0) { xerror("listen"); }
	signal(SIGCHLD, cleanup);

	while(1) {
		int pid;
		int c = accept(s, NULL, NULL);
		if(c < 0) { perror("accept"); continue; }
		if((pid = fork()) < 0) { perror("fork"); continue; }
		if(pid == 0) {
			exit(worker(c));
		} else {
			close(c);
		}
	}

	return 0;
}

