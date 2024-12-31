#include <stdio.h>
#include <stdlib.h>

int main() {

	char *a, *b, *c = NULL;

	a = malloc(64);
	b = malloc(64);

	printf("%p %p %p\n", a, b, c);

	free(a);
	free(b);
	free(a);

	a = malloc(64);
	b = malloc(64);
	c = malloc(64);

	printf("%p %p %p\n", a, b, c);

	return 0;
}

