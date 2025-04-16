#include "libmini.h"

int main() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	write_str("The current time is ");
	write_int(tv.tv_sec);
	write_str(" ");
	write_hex(tv.tv_sec);
	write_str("\n");
	return 0;
}

