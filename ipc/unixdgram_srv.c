#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>

#ifndef UNIX_PATH_MAX
#define UNIX_PATH_MAX 108
#endif

#define err_sys(m)	{ perror(m); exit(-1); }

static int fd = -1;
static char *unixpath = NULL;
static int totallen = 0;

void cleanup(int s) {
	if(fd >= 0)	close(fd);
	if(unixpath)	unlink(unixpath);
	fprintf(stderr, "%d bytes received\n", totallen);
	if(s != 0)	fprintf(stderr, "signal interrupted.\n");
	exit(-s);
}

int main(int argc, char *argv[]) {
	struct sockaddr_un sun, rsun;
	char buf[8192];
	socklen_t rslen;

	if(argc < 2) {
		fprintf(stderr, "usage: %s path\n", argv[0]);
		return -1;
	}

	if((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
		err_sys("socket");

	memset(&sun, 0, sizeof(sun));
	sun.sun_family = AF_UNIX;
	snprintf(sun.sun_path, UNIX_PATH_MAX, "%s", argv[1]);

	if(bind(fd, (struct sockaddr*) &sun, sizeof(sun)) < 0)
		err_sys("bind");
	unixpath = strdup(argv[1]);
 
	signal(SIGINT, cleanup);
	signal(SIGQUIT, cleanup);
	signal(SIGTERM, cleanup);

	while(1) {
		int rlen;
		memcpy(&rsun, &sun, sizeof(rsun));
		rslen = sizeof(rsun);
		if((rlen = recvfrom(fd, buf, sizeof(buf), 0,
			(struct sockaddr*) &rsun, &rslen)) <= 0)
			break;
		totallen += rlen;
	}

	cleanup(0);

	return 0;
}

