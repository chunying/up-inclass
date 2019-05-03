#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#ifdef __linux__
#include <malloc.h>
#endif
#include <sys/types.h>

#define	MSIZE		(32*1024*1024)
#define	MMAP_THRESHOLD	(128*1024)

int global_inited = 1234;
int global;

void print_address();
void* small_alloc(int size);

int
main() {
	void *m;
#ifdef __linux__
	if(mallopt(M_MMAP_THRESHOLD, MMAP_THRESHOLD) == 1) {
		printf("**** MMAP_THRESHOLD = %d\n", MMAP_THRESHOLD);
	}
#endif
	printf("**** %dMB = 0x%x\n", MSIZE/1048576, MSIZE);

	print_address();
	/////////////////////////////////////
	m = small_alloc(MSIZE);
	printf("**** #1 allocate %dMB small chunks (%p--%p)\n",
		MSIZE/1048576, m, m + MSIZE);
	print_address();
	/////////////////////////////////////
	m = small_alloc(MSIZE);
	printf("**** #2 allocate %dMB small chunks (%p--%p)\n",
		MSIZE/1048576, m, m + MSIZE);
	print_address();
	/////////////////////////////////////
	m = malloc(MSIZE);
	printf("**** #3 allocate %dMB chunk (%p--%p)\n",
		MSIZE/1048576, m, m + MSIZE);
	print_address();
	/////////////////////////////////////
	m = alloca(1024);
	printf("**** #4 allocate 1KB chunk via alloca (%p--%p)\n",
		m, m + 1024);
	print_address();
	return 0;
}

void
print_address() {
	int s;
	int *m = malloc(sizeof(int)*64);
	void *hh = dlopen("libc.so.6", RTLD_LAZY);
	void *vv = dlopen("linux-vdso.so.1", RTLD_LAZY);
	void *bb = sbrk(0);
	static uid_t (*_getuid)(void) = NULL;
	//static int (*_gettimeofday)(struct timeval *, struct timezone *) = NULL;
	static int (*_gettimeofday)(void *, void *) = NULL;

	do if(hh && !_getuid) {
		if((_getuid = dlsym(hh, "getuid")) == NULL)
			perror("getuid");
	} while(0);

	do if(vv && !_gettimeofday) {
		if((_gettimeofday = dlsym(vv, "__vdso_gettimeofday")) != NULL)
			break;
		if((_gettimeofday = dlsym(vv, "__kernel_gettimeofday")) != NULL)
			break;
		perror("gettimeofday");
	} while(0);

	printf("        main@text: %p\n", main);
	printf("      global@data: %p\n", &global_inited);
	printf("       global@bss: %p\n", &global);
	printf("           m@heap: %p\n", m);
	printf("              brk: %p (global@bss+%ld)\n", bb, bb - (void*) &global);
	printf("   localvar@stack: %p\n", &s);
	printf("      getuid@libc: %p\n", _getuid);
	printf("gettimeofday@vdso: %p\n", _gettimeofday);
	printf("-------------------------------------------\n");

	return;
}

void*
small_alloc(int size) {
	void *m1 = NULL, *m = NULL;
	const int block = MMAP_THRESHOLD / 2;
	while(size > 0) {
		if((m = malloc(size > block ? block : size)) == NULL) {
			perror("malloc");
			return NULL;
		}
		if(m1 == NULL)
			m1 = m;
		size -= block;
	}
	return m1;
}

