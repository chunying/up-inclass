#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>

#define	xerror(x) { perror(x); exit(-1); }

int forward(int from, int to) {
	int rlen;
	char buf[4096];
	if((rlen = read(from, buf, sizeof(buf))) <= 0) {
		perror("read");
		return -1;
	}
	if(write(to, buf, rlen) <= 0) {
		perror("write");
		return -1;
	}
	return 0;
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

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) { xerror("socket"); }
	if(connect(s, (struct sockaddr*) &sun, sizeof(sun)) < 0) { xerror("connect"); }

	while(1) {
		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(0, &fds);
		FD_SET(s, &fds);
		if(select(s+1, &fds, NULL, NULL, NULL) > 0) {
			if(FD_ISSET(0, &fds)) { if(forward(0, s) < 0) break; }
			if(FD_ISSET(s, &fds)) { if(forward(s, 0) < 0) break; }
		}
	}

	close(s);

	return 0;
}

