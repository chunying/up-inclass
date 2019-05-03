/* receive all IP packets: correct example */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

void hexdump(unsigned char *s, int len);

int main() {
	int s, len;
	unsigned char buf[8192];
	struct sockaddr_in sin;
	socklen_t sinlen;

	s = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_IP));
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

