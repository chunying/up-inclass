#include <stdio.h>

int c(int x, int y, int z) {
	int d = x + y + z;
	return d;
}

int b(int x, int y, int z) {
	return c(x, y, z);
}

int a(int x, int y, int z) {
	return b(x, y, z);
}

int main() {
	return 0 * a(1, 2, 3);
}

