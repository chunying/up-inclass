#include <stdio.h>

//static void myinit() __attribute__((constructor));

__attribute__((constructor))
void
myinit() {
	FILE *fp;
	fprintf(stderr, "injected: %p (" __FILE__ ")\n", myinit);
	if((fp = fopen("/tmp/yyy.txt", "wt")) != NULL) {
		fprintf(fp, "injected!\n");
		fclose(fp);
	}
}


