#include <stdio.h>

#define	TYPELEN(x)	printf("sizeof(" #x ") = %zu\n", sizeof(x));

int main() {
	TYPELEN(char);
	TYPELEN(short);
	TYPELEN(int);
	TYPELEN(long);
	TYPELEN(long long);
	TYPELEN(float);
	TYPELEN(double);
	TYPELEN(long double);
	TYPELEN(size_t);
	return 0;
}
