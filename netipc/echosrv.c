#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void serv_client(int fd, struct sockaddr_in *sin);

int main(int argc, char *argv[]) {
	pid_t pid;
	int fd, pfd;
	unsigned val;
	struct sockaddr_in sin, psin;
	if(argc < 2) {
		fprintf(stderr, "usage: %s port\n", argv[0]);
		return(-1);
	}
	signal(SIGCHLD, SIG_IGN);
	if((fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket");
		return(-1);
	}
	val = 1;
	if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) {
		perror("setsockopt");
		return(-1);
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(atoi(argv[1]));
	if(bind(fd, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
		perror("bind");
		return(-1);
	}
	if(listen(fd, SOMAXCONN) < 0) {
		perror("listen");
		return(-1);
	}
	while(1) {
		val = sizeof(psin);
		bzero(&psin, sizeof(psin));
		if((pfd = accept(fd, (struct sockaddr*) &psin, &val))<0) {
			perror("accept");
			return(-1);
		}
		if((pid = fork()) < 0) {
			perror("fork");
			return(-1);
		} else if(pid == 0) {	/* child */
			close(fd);
			serv_client(pfd, &psin);
			exit(0);
		}
		/* parent */
		close(pfd);
	}
}

void serv_client(int fd, struct sockaddr_in *sin) {
	int len;
	char buf[2048];
	printf("connected from %s:%d\n",
		inet_ntoa(sin->sin_addr), ntohs(sin->sin_port));
	while((len = recv(fd, buf, sizeof(buf), 0)) > 0) {
		if(send(fd, buf, len, 0) < 0) {
			perror("send");
			exit(-1);
		}
	}
	printf("disconnected from %s:%d\n",
		inet_ntoa(sin->sin_addr), ntohs(sin->sin_port));
	return;
}

