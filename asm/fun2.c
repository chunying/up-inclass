#include <stdio.h>

int a(int x, int y, int z) {
	int p = 0x111, q = 0x222, r = 0xccc;
	return x*p + y*q + z*r;
}

int main() {
	return a(1, 2, 3);
}
