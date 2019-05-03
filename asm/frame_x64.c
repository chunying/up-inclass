#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* XXX: assume no stack protector */

#define get_reg(r)	asm("mov %0, "#r : "=m"(r));

#ifdef __x86_64__
int64_t a(int64_t a, int64_t b, int64_t c) {
	int64_t x = 0x111, y = 0x222;
	int64_t *rbp;
	int64_t rdi, rsi, rdx;
	// RDI, RSI, RDX, RCX, R8, R9 
	get_reg(rbp);
	get_reg(rdi);
	get_reg(rsi);
	get_reg(rdx);
	printf("*** function call @ a(%ld, %ld, %ld), RBP = %p\n", a, b, c, rbp);
	printf("[ RBP+32 ] 0x%016lx\n", *(rbp+4));
	printf("[ RBP+24 ] 0x%016lx\n", *(rbp+3));
	printf("[ RBP+16 ] 0x%016lx\n", *(rbp+2));
	printf("------------------------------------------------------------\n");
	printf("[ RBP+08 ] 0x%016lx (return addr)\n", *(rbp+1));
	printf("[ RBP+00 ] 0x%016lx (preserved RBP)\n", *(rbp+0));
	printf("[ RBP-08 ] 0x%016lx (local var)\n", *(rbp-1));
	printf("[ RBP-16 ] 0x%016lx (local var)\n", *(rbp-2));
	printf("[ RBP-24 ] 0x%016lx (local var)\n", *(rbp-3));
	printf("[ RBP-32 ] 0x%016lx (local var)\n", *(rbp-4));
	printf("[ RBP-40 ] 0x%016lx (local var)\n", *(rbp-5));
	return 0;
}
#else
int32_t a(int32_t a, int32_t b, int32_t c) {
	int x = 0x111, y = 0x222;
	int32_t *ebp;
	get_reg(ebp);
	printf("*** function call @ a(%d, %d, %d), EBP = %p\n", a, b, c, ebp);
	printf("------------------------------------------------------------\n");
	printf("[ EBP+16 ] 0x%08x\n", *(ebp+4));
	printf("[ EBP+12 ] 0x%08x\n", *(ebp+3));
	printf("[ EBP+08 ] 0x%08x\n", *(ebp+2));
	printf("[ EBP+04 ] 0x%08x (return addr)\n", *(ebp+1));
	printf("[ EBP+00 ] 0x%08x (preserved EBP)\n", *(ebp+0));
	printf("[ EBP-04 ] 0x%08x (local var)\n", *(ebp-1));
	printf("[ EBP-08 ] 0x%08x (local var)\n", *(ebp-2));
	printf("[ EBP-12 ] 0x%08x (local var)\n", *(ebp-3));
	printf("[ EBP-16 ] 0x%08x (local var)\n", *(ebp-4));
	printf("[ EBP-20 ] 0x%08x (local var)\n", *(ebp-5));
	return 0;
}
#endif

int main(int argc, char *argv[]) {
	char buf[256];
#ifdef __x86_64__
	snprintf(buf, sizeof(buf), "objdump -d %s | grep -E -A2 'callq .*<a>$'", argv[0]);
#else
	snprintf(buf, sizeof(buf), "objdump -d %s | grep -E -A2 'call .*<a>$'", argv[0]);
#endif
	printf("================\n");
	system(buf);
	printf("================\n");
	a(1, 2, 3);
	return 0;
}

