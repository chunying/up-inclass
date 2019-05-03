#include <stdio.h>
#include <setjmp.h>

jmp_buf jb;

int f1() {
	int a, b, c;
	a = 1;
	b = 2;
	c = 3;
	printf("f1: a=%d b=%d c=%d (befoer setjmp)\n", a, b, c);
	if(setjmp(jb) != 0) {
		printf("f1: a=%d b=%d c=%d (longjmp'ed)\n", a, b, c);
		return 1;
	}
	a = 101;
	b = 102;
	c = 103;
	printf("f1: a=%d b=%d c=%d (after setjmp)\n", a, b, c);
	return 0;
}

int f2(int p, int q, int r) {
	int a, b, c;
	a = 201;
	b = 202;
	c = 203;
	printf("f2: a=%d b=%d c=%d\n", a, b, c);
	//longjmp(jb, 1);
	return 0;
}

int f3() {
	int a, b;
	a = 301;
	b = 302;
	printf("f3: a=%d b=%d\n", a, b);
	longjmp(jb, 1);
	return 0;
}

int main() {
	if(f1() != 0) {
		return 0;
	}
	f2(901, 902, 903);
	f3();
	return 0;
}

