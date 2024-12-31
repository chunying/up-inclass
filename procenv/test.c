#include <stdlib.h>
#include <stdio.h>

int main() {
	char *p = (char*) puts;
	char *q = (char*) system;
	printf("%p %p %p\n", q, p, p-q);
	return 0;
}

