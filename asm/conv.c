#include <stdio.h>
#include <stdint.h>

uint8_t  a(uint8_t  t, uint8_t  u, uint8_t  v, uint8_t  w, uint8_t  x, uint8_t  y, uint8_t  z) { return z-y+x-w-w+v-u+t; }
uint16_t b(uint16_t t, uint16_t u, uint16_t v, uint16_t w, uint16_t x, uint16_t y, uint16_t z) { return z-y+x-w-w+v-u+t; }
uint32_t c(uint32_t t, uint32_t u, uint32_t v, uint32_t w, uint32_t x, uint32_t y, uint32_t z) { return z-y+x-w-w+v-u+t; }
uint64_t d(uint64_t t, uint64_t u, uint64_t v, uint64_t w, uint64_t x, uint64_t y, uint64_t z) { return z-y+x-w-w+v-u+t; }

float    f(float    t, float    u, float    v, float    w, float    x, float    y, float    z) { return z-y+x-w-w+v-u+t; }
double   g(double   t, double   u, double   v, double   w, double   x, double   y, double   z) { return z-y+x-w-w+v-u+t; }

double   k(uint8_t  t, uint16_t u, uint32_t v, uint64_t w, float    x, double   y, double   z) { return z-y+x-w-w+v-u+t; }

int main() {
	printf("%u\n",   a( 1,  2,  3,  4,  5,  6,  7));
	printf("%u\n",   b(11, 12, 13, 14, 15, 16, 17));
	printf("%u\n",   c(21, 22, 23, 24, 25, 26, 27));
#ifdef __x86_64__
	printf("%lu\n",  d(31, 32, 33, 34, 35, 36, 37));
#else
	printf("%llu\n", d(31, 32, 33, 34, 35, 36, 37));
#endif
	printf("%.2f\n", f(41, 42, 43, 44, 45, 46, 47));
	printf("%.2f\n", g(51, 52, 53, 54, 55, 56, 57));
	printf("%.2f\n", k(61, 62, 63, 64, 65, 66, 67));
	return 0;
}

