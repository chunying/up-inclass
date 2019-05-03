#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	struct sockaddr_in sin;
	char host[64], serv[64];
	int s;
	if (argc < 3) {
		fprintf(stderr, "usage: %s ip port\n", argv[0]);
		exit(-1);
	}
	bzero(&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr(argv[1]);
	sin.sin_port = htons(atoi(argv[2]));
	if((s = getnameinfo((struct sockaddr*) &sin, sizeof(sin),
		host, sizeof(host), serv, sizeof(serv), 0)) != 0) {
		fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
		exit(-1);
	}
	printf("%s:%s\n", host, serv);
	return(0);
}

