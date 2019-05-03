#include <stdio.h>

#if defined(__x86_64__)
#error "Only work for x86 archtecture"
#endif

#define cdecl	__attribute__((cdecl))
#define stdcall	__attribute__((stdcall))

cdecl   int a(int, int, int);
stdcall int b(int, int, int);

cdecl int a(int x, int y, int z) {
	return x+y+z;
}

stdcall int b(int x, int y, int z) {
	return x+y+z;
}

int main() {
	printf("%d %d\n", a(1, 2, 3), b(4, 5, 6));
	return 0;
}

