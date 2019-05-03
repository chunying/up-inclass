#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
	int i;
	struct servent *s;
	while((s = getservent()) != NULL) {
		printf("name=%s (%s/%d), ", s->s_name, s->s_proto, ntohs(s->s_port));
		printf("alias={ ");
		for(i = 0; s->s_aliases[i] != NULL; i++)
			printf("%s ", s->s_aliases[i]);
		printf("}\n");
	}
	return(0);
}

