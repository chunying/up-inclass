#include <malloc.h>
#include <stdio.h>

void my_hook(size_t size, const void *caller) {
	printf("hook: size %zu caller %p\n", size, caller);
}

//extern void *(*__malloc_hook)(size_t size, const void *caller);

int main() {
	char *buf = NULL;
	
	__malloc_hook = my_hook;
	buf = malloc(64);
	printf("hello %p\n", buf);

	return 0;
}

