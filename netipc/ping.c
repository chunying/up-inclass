/* send ping packets: with IPPROTO_ICMP */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <signal.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <linux/icmp.h>

#define	xerror(x) { perror(x); exit(-1); }

typedef struct ping_s {
	unsigned short seq;
	struct timeval tv;
}	ping_t;

#define	NRECORD	4
static int rec_id= 0;
static ping_t pingrec[NRECORD];

static char *host = NULL;

static int quit = 0;
void handle_int(int s) { quit = 1; }

// Ref: http://www.faqs.org/rfcs/rfc1071.html
unsigned short cksum(unsigned char *data, int len) {
	int sum = 0;  /* assume 32 bit long, 16 bit short */

	while(len > 1) {
		sum += *((unsigned short*) data);
		if(sum & 0x80000000)   /* if high order bit set, fold */
			sum = (sum & 0xFFFF) + (sum >> 16);
		data += 2;
		len -= 2;
	}

	if(len)       /* take care of left over byte */
		sum += (unsigned short) *data;

	while(sum>>16)
		sum = (sum & 0xFFFF) + (sum >> 16);

	return ~sum;
}

long tvdiff(struct timeval tv1, struct timeval tv2) {
	long sign = 1;
	struct timeval *pv1, *pv2;

	if((tv2.tv_sec > tv1.tv_sec)
	|| (tv2.tv_sec == tv1.tv_sec && tv2.tv_usec > tv1.tv_usec)) {
		sign = -1;
		pv1 = &tv2;
		pv2 = &tv1;
	} else {
		pv1 = &tv1;
		pv2 = &tv2;
	}

	if(pv1->tv_usec < pv2->tv_usec) {
		pv1->tv_sec--;
		pv1->tv_usec += 1000000L;
	}
	pv1->tv_sec -= pv2->tv_sec;
	pv1->tv_usec -= pv2->tv_usec;
	return sign * (pv1->tv_sec * 1000000L + pv1->tv_usec);
}

int resolve_host(const char *host) {
	in_addr_t target;
	struct hostent *h;

	if((h = gethostbyname(host)) == NULL) {
		fprintf(stderr, "unknown host: %s\n", host);
		return -1;
	}
	target = *((in_addr_t*) h->h_addr_list[0]);

	return target;
}

int send_ping(int s, in_addr_t target, unsigned short id, unsigned short seq, const char *msg, int msglen) {
	char buf[128];
	struct icmphdr *icmph = (struct icmphdr *) buf;
	struct sockaddr_in sin;

	memset(buf, 0, sizeof(buf));

	icmph->type = ICMP_ECHO;
	icmph->code = 0;
	icmph->checksum = 0;
	icmph->un.echo.id = htons(id);
	icmph->un.echo.sequence = htons(seq);
	
	if(msg && msglen > 0) {
		if(msglen > sizeof(buf) - 8) msglen = sizeof(buf) - 8;
		memcpy(buf+8, msg, msglen);
	} else {
		msg = NULL;
		msglen = 0;
	}

	icmph->checksum = cksum((unsigned char*) buf, 8+msglen);

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = target;

	pingrec[rec_id].seq = icmph->un.echo.sequence;
	gettimeofday(&pingrec[rec_id++].tv, NULL);
	rec_id %= NRECORD;
	return sendto(s, buf, 8+msglen, MSG_DONTWAIT, (struct sockaddr*) &sin, sizeof(sin));
}

void recv_ping(int s, in_addr_t target, unsigned short id) {
	int i, len, updated = 0;
	struct sockaddr_in sin;
	char buf[4096], daddr[64];
	struct timeval tv;
	struct iphdr *iph = (struct iphdr *) buf;
	struct icmphdr *icmph; 
	ping_t removed[NRECORD];

	id = htons(id);
	memcpy(removed, pingrec, sizeof(pingrec));

	while(1) {
		socklen_t sinlen = sizeof(sin);

		gettimeofday(&tv, NULL);
		len = recvfrom(s, buf, sizeof(buf), MSG_DONTWAIT, (struct sockaddr*) &sin, &sinlen);

		if(len <= 0) break;

		if(iph->version != 4) continue;
		if(iph->protocol != IPPROTO_ICMP) continue;
		if(iph->saddr != target) continue;

		icmph = (struct icmphdr *) (buf + (iph->ihl * 4));

		if(sin.sin_addr.s_addr != target) continue;
		if(icmph->type != ICMP_ECHOREPLY) continue;
		if(icmph->code != 0) continue;
		if(icmph->un.echo.id != id) continue;

		for(i = 0; i < NRECORD; i++) {
			if(icmph->un.echo.sequence != pingrec[i].seq) continue;
			printf("%lu.%06lu: %d bytes from %s (%s): icmp_seq=%d ttl=%d time=%.03fms\n",
				tv.tv_sec, tv.tv_usec,
				len,
				host,
				inet_ntop(AF_INET, &iph->saddr, daddr, sizeof(daddr)),
				ntohs(icmph->un.echo.sequence),
				iph->ttl,
				tvdiff(tv, pingrec[i].tv) * 0.001);
			memset(&removed[i], 0, sizeof(ping_t));
			updated = 1;
			break;
		}
	}

	if(updated) memcpy(pingrec, removed, sizeof(removed));
}

int main(int argc, char *argv[]) {
	int s, token;
	in_addr_t target;
	unsigned short id, count = 0;
	char buf[32];
	struct timeval last, curr;

	srand(time(0) ^ getpid());
	signal(SIGINT, handle_int);

	if(argc < 2) {
		fprintf(stderr, "usage: %s [target-host]\n", argv[0]);
		return -1;
	}

	host = strdup(argv[1]);
	if((s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) { xerror("socket"); }
	if((target = resolve_host(argv[1])) == -1) {
		fprintf(stderr, "bad target: %s\n", argv[1]);
		return -1;
	}
	
	printf("PING %s (%s)\n", argv[1], inet_ntop(AF_INET, &target, buf, sizeof(buf)));

	token = 1000000;
	id = rand() & 0xffff;

	gettimeofday(&last, NULL);
	curr = last;

	while(!quit) {
		int len;
		fd_set fds;
		struct timeval tv = { 0, 1000 }; /* 0.001ms */

		token += tvdiff(curr, last);
		last = curr;

#define	MESSAGE "ABCDEFGHIJKL"
		if(token >= 1000000) {
			if((len = send_ping(s, target, id, ++count, MESSAGE, 13)) < 0)
				perror("ping");
			token -= 1000000;
		}

		FD_ZERO(&fds);
		FD_SET(s, &fds);
		if(select(s+1, &fds, NULL, NULL, &tv) > 0) {
			recv_ping(s, target, id);
		}

		gettimeofday(&curr, NULL);
	}

	close(s);

	return 0;
}

