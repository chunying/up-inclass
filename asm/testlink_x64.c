#include <stdio.h>
#include "libasm.h"

int a(int x, int y, int z) {
	asm_dump_regs();
	return 0;
}

int main() {
	int i;

	asm_write(2, "asm_write\n", 10);
	asm_write_str(0/*unused*/, "asm_write_str\n", 14);

	asm_write_char('c');
	asm_write_char('h');
	asm_write_char('a');
	asm_write_char('r');
	asm_write_char('\n');

	for(i = 0; i < 16; i++) {
		asm_write_hex(0x1234567890abcdefLL, i+1);
		asm_write_char('\n');
	}

	printf("function call: a(1, 2, 3)\n");
	printf("==========\n");
	a(1, 2, 3);
	printf("==========\n");

	asm_exit(123);

	return 0;
}

