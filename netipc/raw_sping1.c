/* send ping packets: with IPPROTO_ICMP */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <linux/icmp.h>

#define	MESSAGE "ABCDEFGHIJKL"

void hexdump(unsigned char *s, int len);
unsigned short cksum(unsigned char *data, int len);

int main(int argc, char *argv[]) {
	int s;
	in_addr_t target;
	struct hostent *h;
	unsigned short count = 0;

	srand(time(0) ^ getpid());

	if(argc < 2) {
		fprintf(stderr, "usage: %s [target-host]\n", argv[0]);
		return -1;
	}

	if((h = gethostbyname(argv[1])) == NULL) {
			fprintf(stderr, "unknown host: %s\n", argv[1]);
			return -1;
	}
	target = *((in_addr_t*) h->h_addr_list[0]);

	s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if(s < 0) {
		perror("socket");
		return -1;
	}

	while(1) {
		int wlen, msglen = 8+strlen(MESSAGE);
		char buf[128];
		struct icmphdr *icmph = (struct icmphdr *) buf;
		struct sockaddr_in sin;
		printf("**** ping: 0x%08x\n", htonl(target));
		bzero(buf, sizeof(buf));

		icmph->type = ICMP_ECHO;
		icmph->code = 0;
		icmph->checksum = 0;
		icmph->un.echo.id = rand() & 0xffff;
		icmph->un.echo.sequence = htons(++count);
		strcpy(buf+8, MESSAGE);

		icmph->checksum = cksum((unsigned char*) buf, msglen);

		hexdump((unsigned char*) buf, msglen);
		bzero(&sin, sizeof(sin));
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = target;
		if((wlen = sendto(s, buf, msglen, 0, (struct sockaddr*) &sin, sizeof(sin))) < 0) {
			perror("sendto");
			sleep(1);
		}

		sleep(1);
	}

	close(s);

	return 0;
}

