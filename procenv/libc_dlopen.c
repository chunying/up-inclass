#include <stdio.h>
#include <unistd.h>

#define RTLD_LAZY	0x00001	/* Lazy function call binding.  */
#define RTLD_NOW	0x00002
#define __RTLD_DLOPEN	0x80000000

extern void *__libc_dlopen_mode  (const char *__name, int __mode);

int main() {
#if defined(__GLIBC__) && !defined(__UCLIBC__) && __GLIBC__ == 2 && __GLIBC_MINOR__ < 34
	__libc_dlopen_mode("./inject3.so", RTLD_NOW | __RTLD_DLOPEN);
#else
	fprintf(stderr, "__libc_dlopen_mode is only available before glibc 2.34 (exclusive)\n");
#endif
	pause();
}

