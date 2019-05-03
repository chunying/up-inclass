/* receive all IP packets: bad example */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void hexdump(unsigned char *s, int len);

int main() {
	int s, len;
	unsigned char buf[8192];
	struct sockaddr_in sin;
	socklen_t sinlen;

	/* a bad example: received nothing */
	s = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
	if(s < 0) {
		perror("socket");
		return -1;
	}

	while((len = recvfrom(s, buf, sizeof(buf), 0, (struct sockaddr*) &sin, &sinlen)) > 0) {
		hexdump(buf, len);
	}

	close(s);

	return 0;
}

