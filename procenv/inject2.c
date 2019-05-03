#include <dlfcn.h>
#include <stdio.h>
#include <sys/types.h>

static uid_t (*old_getuid)(void) = NULL;

uid_t getuid(void) {
	if(old_getuid == NULL) {
		void *handle = dlopen("libc.so.6", RTLD_LAZY);
		if(handle != NULL) {
			old_getuid = dlsym(handle, "getuid");
		}
	}
	fprintf(stderr, "injected getuid, always return 0\n");
	if(old_getuid != NULL) {
		fprintf(stderr, "real uid = %d\n", old_getuid());
	}
	return 0;
}

