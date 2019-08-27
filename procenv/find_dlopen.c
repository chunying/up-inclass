#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/types.h>

#define __RTLD_DLOPEN	0x80000000
typedef void * (*__libc_dlopen_mode_t)(const char *, int);

__libc_dlopen_mode_t
find_dlopen(void *handle) {
	__libc_dlopen_mode_t fptr = NULL;
	if(handle == NULL) {
		perror("dlopen");
		return NULL;
	}
	fptr = dlsym(handle, "__libc_dlopen_mode");
	if(fptr == NULL) {
		perror("dlsym");
		return NULL;
	}
	return fptr;
}

long
find_libcbase(pid_t pid) {
	char buf[1024];
	FILE *fp;
	long base = 0;
	char perm[8], module[1024];

	snprintf(buf, sizeof(buf), "/proc/%d/maps", pid);
	if((fp = fopen(buf, "rt")) == NULL) return 0;
	while(fgets(buf, sizeof(buf), fp) != NULL) {
		long begin;
		sscanf(buf, "%lx-%*x %s %*s %*s %*d %s", &begin, perm, module);
		if(perm[2] != 'x') continue;
		if(strstr(module, "/lib/") == NULL)  continue;
		if(strstr(module, "/libc-") == NULL) continue;
		if(strstr(buf, ".so") == NULL)       continue;
		base = begin;
		break;
	}
	fclose(fp);
	return base;
}

int main(int argc, char *argv[]) {
	void *handle = dlopen("libc.so.6", RTLD_LAZY);
	__libc_dlopen_mode_t fptr = find_dlopen(handle);
	long base = 0, offset = 0;

	if(fptr == NULL) return -1;

	if((base = find_libcbase(getpid())) == 0) {
		fprintf(stderr, "cannot find base address of libc.\n");
		return -1;
	}
	offset = ((long) fptr) - base;

	fprintf(stderr, "__libc_dlopen_mode: %p (0x%lx)\n", fptr, offset);

	if(argc < 2)
		fptr("./inject3.so", RTLD_NOW | __RTLD_DLOPEN);
	else
		fptr(argv[1], RTLD_NOW | __RTLD_DLOPEN);

	dlclose(handle);
	return 0;
}

