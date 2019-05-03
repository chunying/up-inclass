#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int s) { /* do nothing */ }

int main() {
	signal(SIGINT, handler);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("hello\n");
	pause();
	return 0;
}

