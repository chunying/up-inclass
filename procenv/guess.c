#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	char buf[16];
	int answer;

	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(0) ^ getpid());
	answer = rand() % 10000;

	printf("Guess the number: ");
	if(fgets(buf, 32, stdin) != NULL) {
			int g = strtol(buf, NULL, 0);
			printf("Your guess is %d\n", g);
			if(g == answer) {
					printf("Bingo!\n");
			} else {
					printf("No no no ...\n");
			}
	}

	return 0;
}

