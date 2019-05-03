#include <stdio.h>

int a() {
	printf("this is a\n");
	return 0;
}

void b() {
	printf("this is b\n");
	return;
}

int main() {
	a();
	b();
	return 0;
}

