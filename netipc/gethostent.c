#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
	int i;
	char buf[64];
	struct hostent *h;
	while((h = gethostent()) != NULL) {
		if(h->h_addrtype != AF_INET)
			continue;
		printf("name=%s, addr={ ", h->h_name);
		for(i = 0; h->h_addr_list[i] != NULL; i++) {
			printf("%s ", inet_ntop(AF_INET, h->h_addr_list[i], buf, sizeof(buf)));
		}
		printf("}\n");
	}
	return(0);
}

