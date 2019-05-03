#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

int mydup_v1(int from) {
	return syscall(SYS_dup, from);
}

int mydup2_v1(int from, int to) {
	return syscall(SYS_dup2, from, to);
}

int mydup_v2(int from) {
	int ret;
	asm(	"mov rax, 32\n"
		"xor rdi, rdi\n"
		"mov edi, %1\n"
		"syscall\n"
		"mov %0, eax\n"
		: "=m"(ret)
		: "m"(from)
	);
	return ret;
}

int mydup2_v2(int from, int to) {
	int ret;
	asm(	"mov rax, 33\n"
		"xor rdi, rdi\n"
		"mov edi, %1\n"
		"xor rsi, rdi\n"
		"mov esi, %2\n"
		"syscall\n"
		"mov %0, eax\n"
		: "=m"(ret)
		: "m"(from), "m"(to)
	);
	return ret;
}


int main() {
	int fd;
	fd = dup(1);
	write(fd, "aaaaa\n", 6);
	fd = mydup_v1(1);
	write(fd, "bbbbb\n", 6);
	fd = mydup_v2(1);
	write(fd, "ccccc\n", 6);
	return 0;
}

