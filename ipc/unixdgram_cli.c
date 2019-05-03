#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>

#ifndef UNIX_PATH_MAX
#define UNIX_PATH_MAX 108
#endif

#define err_sys(m)	{ perror(m); exit(-1); }

static int totallen = 0;

void cleanup(int s) {
	fprintf(stderr, "signal interrupted: %d\n", s);
	fprintf(stderr, "%d bytes written\n", totallen);
	exit(0);
}

int main(int argc, char *argv[]) {
	int fd, wlen, flag;
	struct sockaddr_un sun;
	char buf[1024];

	if(argc < 2) {
		fprintf(stderr, "usage: %s path\n", argv[0]);
		return -1;
	}

	if((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
		err_sys("socket");

	memset(&sun, 0, sizeof(sun));
	sun.sun_family = AF_UNIX;
	snprintf(sun.sun_path, UNIX_PATH_MAX, "%s", argv[1]);

	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGTERM, cleanup);

	if((flag = fcntl(fd, F_GETFL)) < 0)	err_sys("fcntl(GETFL)");
	flag |= O_NONBLOCK;
	if(fcntl(fd, F_SETFL, flag) < 0)	err_sys("fcntl(SETFL)");

	while((wlen = sendto(fd, buf, sizeof(buf), 0,
		(struct sockaddr*) &sun, sizeof(sun))) > 0) {
		totallen += wlen;
		usleep(10);
	}

	fprintf(stderr, "%d bytes written\n", totallen);

	if(wlen < 0)
		perror("sendto");

	return 0;
}

