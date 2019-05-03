#include <stdio.h>
#include <netdb.h>

int main() {
	int i;
	struct protoent *p;
	while((p = getprotoent()) != NULL) {
		printf("name=%s (%d), ", p->p_name, p->p_proto);
		printf("alias={ ");
		for(i = 0; p->p_aliases[i] != NULL; i++)
			printf("%s ", p->p_aliases[i]);
		printf("}\n");
	}
	return(0);
}

