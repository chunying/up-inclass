#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	int s;struct addrinfo hints, *result, *rp;
	if (argc < 3) {
		fprintf(stderr, "usage: %s host port\n", argv[0]);
		exit(-1);
	}
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;       /* allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM; /* stream socket */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;           /* any protocol */
	if((s=getaddrinfo(argv[1], argv[2], &hints, &result))!=0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit(-1);
	}
	for(rp = result; rp != NULL; rp = rp->ai_next) {
		struct sockaddr_in *p = (struct sockaddr_in*) rp->ai_addr;
		printf( "%s:%d\n", inet_ntoa(p->sin_addr), ntohs(p->sin_port));
	}
	return(0);
}

