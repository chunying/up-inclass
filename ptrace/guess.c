#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include <time.h>

static unsigned secret = 0;

int main() {
	char buf[16];
	srand(time(0) ^ getpid());
	secret = rand();
	setvbuf(stdin, NULL, _IONBF, 0);
	printf("Show me the key: ");
	fgets(buf, sizeof(buf), stdin);
	if(strtol(buf, NULL, 0) == secret) {
		printf("Bingo!\n");
		// do something secret ...
	} else {
		printf("No no no ...\n");
	}
	return 0;
}

