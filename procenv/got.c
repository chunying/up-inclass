#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("main %p system %p\n", main, system);
	puts("hello");
	puts("world");
	return 0;
}

