#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	void *ptr;

	ptr = malloc(4096);
	fprintf(stderr, "%p\n", ptr);
	free(ptr);

	ptr = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	fprintf(stderr, "%p\n", ptr);
	munmap(ptr, 4096);

	return 0;
}

