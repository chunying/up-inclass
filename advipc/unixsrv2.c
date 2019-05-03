#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>

#define	PATH	"unix2.socket"
#define err_sys(m) { perror(m); exit(-1); }

static int fd = -1;

void cleanup(int s) {
	if(fd >= 0)	close(fd);
	unlink(PATH);
	exit(0);
}

int main() {
	struct sockaddr_un sun;
	signal(SIGINT,  cleanup);
	signal(SIGTERM, cleanup);
	if((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
		err_sys("socket");
	sun.sun_family = AF_UNIX;
	sprintf(sun.sun_path, PATH);
	if(bind(fd, (struct sockaddr*) &sun, sizeof(sun)) < 0)
		err_sys("bind");
	while(1) {
		int rlen;
		char buf[1024];
		unsigned cslen;
		sun.sun_family = AF_UNIX;
		sprintf(sun.sun_path, PATH);
		cslen = sizeof(sun);
		if((rlen = recvfrom(fd, buf, sizeof(buf), 0,
				(struct sockaddr*) &sun, &cslen)) < 0)
			err_sys("recvfrom");
		fprintf(stderr, "unix2: %s\n", buf);
	}
	return 0;
}

