#include <stdio.h>

extern int me_init();

int main() {
	me_init();
	printf("%p\n", me_init);
	return 0;
}
