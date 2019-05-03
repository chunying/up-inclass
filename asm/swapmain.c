#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

extern void swap(int *, int *);

int main() {
	int i, j;
	srand(time(0) ^ getpid());
	i = rand() % 100;
	j = rand() % 100;
	printf("%d %d\n", i, j);
	swap(&i, &j);	// included from a customized header swapN.h
	printf("%d %d\n", i, j);
	return 0;
}

