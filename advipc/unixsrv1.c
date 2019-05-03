#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>

#define	PATH	"unix1.socket"
#define err_sys(m) { perror(m); exit(-1); }

static int fd = -1;

void cleanup(int s) {
	if(fd >= 0)	close(fd);
	unlink(PATH);
	exit(0);
}

void sigchld(int s) {
	int status;
	while(waitpid(-1, &status, WNOHANG) > 0)
		;
}

void handle(c) {
	int rlen;
	char buf[1024];
	pid_t pid = fork();
	if(pid < 0)	err_sys("fork");
	if(pid > 0)	return;
	signal(SIGCHLD, SIG_DFL);
	signal(SIGINT,  SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	while((rlen = read(c, buf, sizeof(buf))) > 0)
		fprintf(stderr, "unix1: %s\n", buf);
	exit(0);
}

int main() {
	int c;
	unsigned cslen;
	struct sockaddr_un sun, csun;
	sun.sun_family = AF_UNIX;
	sprintf(sun.sun_path, PATH);
	signal(SIGCHLD, sigchld);
	signal(SIGINT,  cleanup);
	signal(SIGTERM, cleanup);
	if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		err_sys("socket");
	if(bind(fd, (struct sockaddr*) &sun, sizeof(sun)) < 0)
		err_sys("bind");
	if(listen(fd, 16) < 0)
		err_sys("listen");
	memset(&csun, 0, sizeof(csun));
	cslen = sizeof(csun);
	while((c = accept(fd, (struct sockaddr*) &csun, &cslen)) >= 0) {
		handle(c);
	}
	return 0;
}

