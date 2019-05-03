#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	int i;
	//
	printf("Arguments");
	for(i = 0; i < argc; i++) {
		printf("%c [%d] '%s'", i == 0 ? ':' : ',', i, argv[i]);
	}
	printf("\n");
	//
	for(i = 0; envp[i] != NULL; i++) 
		;
	printf("Total %d environment variables.\n", i);
	return 0;
}

