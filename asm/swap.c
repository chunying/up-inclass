#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "rdtsc.h"

#define	SWAP1(a, b)	\
	asm(	"mov	eax, %0\n"		\
		"xchg	eax, %1\n"		\
		"mov	%0, eax\n"		\
		: "+m" (a), "+m" (b));

#define	SWAP2(a, b)	\
	asm(	"xchg	%0, %1\n"		\
		: "+r" (a), "+rm" (b));
		
int main() {
	int i, j;
	long long t0, t1;
	srand(time(0));
	i = rand();
	j = rand();
	printf("i = %d, j = %d\n", i, j);
	t0 = rdtsc();
	SWAP1(i, j);
	t1 = rdtsc();
	printf("i = %d, j = %d (%lld)\n", i, j, t1 - t0);
	t0 = rdtsc();
	SWAP2(i, j);
	t1 = rdtsc();
	printf("i = %d, j = %d (%lld)\n", i, j, t1 - t0);
	return 0;
}

