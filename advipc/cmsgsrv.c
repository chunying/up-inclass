#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>

#define	PATH	"cmsg.socket"
#define	MAGIC	0xab
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
	char data[1] = { MAGIC };
	char cmsgbuf[CMSG_SPACE(sizeof(int))];
	struct iovec io[1];
	struct msghdr m;
	struct cmsghdr *pcm = (struct cmsghdr*) cmsgbuf;
	//
	pid_t pid = fork();
	if(pid < 0)	err_sys("fork");
	if(pid > 0)	return;
	signal(SIGCHLD, SIG_DFL);
	signal(SIGINT,  SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	//
	memset(&m, 0, sizeof(m));
	memset(cmsgbuf, 0, sizeof(cmsgbuf));
	io[0].iov_base = data;
	io[0].iov_len = 1;
	m.msg_iov = io;
	m.msg_iovlen = 1;
	m.msg_control = pcm;
	m.msg_controllen = sizeof(cmsgbuf);
	//
	pcm = CMSG_FIRSTHDR(&m);
	pcm->cmsg_level = SOL_SOCKET;
	pcm->cmsg_type = SCM_RIGHTS;
	pcm->cmsg_len = CMSG_LEN(sizeof(int));
	* (int*) CMSG_DATA(pcm) = 1; /* descriptor to send */
	if(sendmsg(c, &m, 0) < 0)
		err_sys("sendmsg");
	fprintf(stderr, "descriptor sent\n");
	//
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

