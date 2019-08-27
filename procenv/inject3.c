#include <stdio.h>

static void myinit() __attribute__((constructor));

void
myinit() {
	printf("injected: %p (%s)\n", myinit, __FILE__);
}


