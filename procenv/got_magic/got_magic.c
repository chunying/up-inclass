/*
 * Exam problem set for UNIX programming course
 * by Chun-Ying Huang <chuang@cs.nctu.edu.tw>
 * License: GPLv2
 */
#include <stdio.h>
#include <stdlib.h>
#include "tools.c"

void magic() {
	printf("Bingo!\n");
	readflag(1);
	_exit(0);
}

int main() {
	char buf[64];
	unsigned long addr, value;

	unbuffered();

	puts("Welcome!");
	printf("- main @ %p\n", main);
	printf("- puts @ %p\n", puts);
	puts("");

	puts("Where do you want to write? ");
	if(fgets(buf, sizeof(buf), stdin) == NULL)
		goto quit;
	addr = strtol(buf, NULL, 0);

	puts("What do you want to write? ");
	if(fgets(buf, sizeof(buf), stdin) == NULL)
		goto quit;
	value = strtol(buf, NULL, 0);
	*((unsigned long *) addr) = value;
quit:
	exit(0);
	return 0;
}

