#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	struct {
		char buf[16];
		int answer;
	} d;

	setvbuf(stdout, NULL, _IONBF, 0);
	srand(time(0) ^ getpid());

	d.answer = rand() % 10000;

	printf("Guess the number: ");
	if(fgets(d.buf, 20, stdin) != NULL) {
		int g = strtol(d.buf, NULL, 0);
		printf("Your guess is %d\n", g);
		if(g == d.answer) {
			printf("Bingo!\n");
		} else {
			printf("No no no ...\n");
		}
	}

	return 0;
}

