#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int n = 0;
	printf("Hello, World.\n");
	if(argc > 1) {
		n = strtol(argv[1], NULL, 0);
	}
	return n;
}
