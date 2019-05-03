/* send ping packets: with IPPROTO_ICMP,
   use customized IP header, #1 - setsockopt */
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

	do {
		int on = 1;
		if(setsockopt(s, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
			perror("setsockopt");
			return -1;
		}
	} while(0);

	while(1) {
		int wlen, msglen = 28 + strlen(MESSAGE);
		char buf[128];
		struct ip *iph = (struct ip *) buf;
		struct icmphdr *icmph = (struct icmphdr *) (buf+20);
		struct sockaddr_in sin;
		printf("ping: 0x%08x\n", htonl(target));
		bzero(buf, sizeof(buf));

		iph->ip_v = 4;
		iph->ip_hl = 5;
		iph->ip_len = htons(msglen);
		iph->ip_id = rand() & 0xffff;
		iph->ip_ttl = 0xff;
		iph->ip_p = IPPROTO_ICMP;
		iph->ip_sum = 0;
		iph->ip_src.s_addr = htonl(0x7f000001); // 127.0.0.1
		iph->ip_dst.s_addr = target;
		iph->ip_sum = cksum((unsigned char*) buf, 20);

		icmph->type = ICMP_ECHO;
		icmph->code = 0;
		icmph->checksum = 0;
		icmph->un.echo.id = rand() & 0xffff;
		icmph->un.echo.sequence = htons(++count);
		strcpy(buf + 28, MESSAGE);
		icmph->checksum = cksum((unsigned char*) buf+20, 8+strlen(MESSAGE));

		hexdump((unsigned char*) buf, msglen);
		bzero(&sin, sizeof(sin));
		sin.sin_family = AF_INET;
		sin.sin_addr.s_addr = target;
		if((wlen = sendto(s, buf, msglen, 0, (struct sockaddr*) &sin, sizeof(sin))) < 0) {
			perror("sendto");
		}

		sleep(1);
	}

	close(s);

	return 0;
}

