#include <stdio.h>
#include <sys/types.h>

uid_t getuid(void) {
	fprintf(stderr, "injected getuid, always return 0 (%s)\n", __FILE__);
	return 0;
}

