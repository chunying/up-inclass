#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/un.h>

#define	xerror(x) { perror(x); exit(-1); }

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
	if((s = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) { xerror("socket"); }
	if(bind(s, (struct sockaddr*) &sun, sizeof(sun)) < 0) { xerror("bind"); }

	while(1) {
		char buf[4096] = "ECHO: ";
		int rlen, pfxlen = 6;
		socklen_t sunlen = sizeof(sun);

		memset(&sun, 0, sizeof(sun));

		if((rlen = recvfrom(s, buf+pfxlen, sizeof(buf)-pfxlen, 0,
				(struct sockaddr*) &sun, &sunlen)) <= 0) {
			perror("recvfrom");
			break;
		}

		fprintf(stderr, "read %d bytes from %s\n", rlen, sun.sun_path);
		if(sendto(s, buf, rlen+pfxlen, 0, (struct sockaddr*) &sun, sunlen) < 0) {
			perror("sendto");
			break;
		}
	}

	close(s);

	return 0;
}

