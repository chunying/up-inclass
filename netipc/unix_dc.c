#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <sys/signal.h>

#define	xerror(x) { perror(x); exit(-1); }

static struct sockaddr_un sun;
static int quit = 0;

void handle_int(int s) { quit = 1; }

int from_peer(int s) {
	int rlen;
	char buf[4096];

	if((rlen = recvfrom(s, buf, sizeof(buf), 0, NULL, NULL)) <= 0) {
		perror("recvfrom");
		return -1;
	}
	if(write(1, buf, rlen) <= 0) {
		perror("write");
		return -1;
	}
	return 0;
}

int to_server(int s) {
	int rlen;
	char buf[4096];

	if((rlen = read(0, buf, sizeof(buf))) <= 0) {
		perror("read");
		return -1;
	}
	if(sendto(s, buf, rlen, 0,
			(struct sockaddr*) &sun, sizeof(sun)) <= 0) {
		perror("sendto");
		return -1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int s;

	if(argc < 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		return -1;
	}

	memset(&sun, 0, sizeof(sun));
	sun.sun_family = AF_UNIX;
	snprintf(sun.sun_path, sizeof(sun.sun_path), "%s.%d", argv[1], getpid());

	unlink(sun.sun_path);
	if((s = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) { xerror("socket"); }
	if(bind(s, (struct sockaddr*) &sun, sizeof(sun)) < 0) { xerror("bind"); }

	memset(&sun, 0, sizeof(sun));
	sun.sun_family = AF_UNIX;
	strncpy(sun.sun_path, argv[1], sizeof(sun.sun_path));

	signal(SIGINT, handle_int);

	while(!quit) {
		fd_set fds;
		struct timeval tv = { 1, 0 };
		FD_ZERO(&fds);
		FD_SET(0, &fds);
		FD_SET(s, &fds);
		if(select(s+1, &fds, NULL, NULL, &tv) > 0) {
			if(FD_ISSET(0, &fds)) { if(to_server(s) < 0) break; }
			if(FD_ISSET(s, &fds)) { if(from_peer(s) < 0) break; }
		}
	}

	close(s);

	snprintf(sun.sun_path, sizeof(sun.sun_path), "%s.%d", argv[1], getpid());
	unlink(sun.sun_path);

	return 0;
}

