#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
	int converted = 0;
	struct in_addr  addr4;
	struct in6_addr addr6;
	if(argc < 2) {
		fprintf(stderr, "usage: %s address\n", argv[0]);
		return -1;
	}
	if(inet_pton(AF_INET, argv[1], &addr4) == 1) {
		printf("IPv4: 0x%08x\n", htonl(addr4.s_addr));
		converted++;
	}
	if(inet_pton(AF_INET6, argv[1], &addr6) == 1) {
		printf("IPv6: 0x%08x%08x%08x%08x\n",
			htonl(addr6.__in6_u.__u6_addr32[0]),
			htonl(addr6.__in6_u.__u6_addr32[1]),
			htonl(addr6.__in6_u.__u6_addr32[2]),
			htonl(addr6.__in6_u.__u6_addr32[3]));
		converted++;
	}
	if(!converted) {
		fprintf(stderr, "Invalid address: %s\n", argv[1]);
	}
	return 0;
}

