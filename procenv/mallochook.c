#include <malloc.h>
#include <stdio.h>

void* my_hook(size_t size, const void *caller) {
	printf("hook: size %zu caller %p\n", size, caller);
	return NULL;
}

extern void * (*__malloc_hook)(size_t size, const void *caller);

int main() {
	char *buf = NULL;
	
#if defined(__GLIBC__) && !defined(__UCLIBC__) && __GLIBC__ == 2 && __GLIBC_MINOR__ < 34
	__malloc_hook = my_hook;
#else
	fprintf(stderr, "__malloc_hook is only available before glibc 2.34 (exclusive)\n");
#endif
	buf = malloc(64);
	printf("hello %p\n", buf);

	return 0;
}

