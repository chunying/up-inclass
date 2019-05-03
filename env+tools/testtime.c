#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
	int n = 10;
	srand(time(0) ^ getpid());
	printf("CLOCKS_PER_SEC = %ld\n", CLOCKS_PER_SEC);
	while(n-- > 0) {
		struct timeval tv;
		clock_t c;
		int s = 5 + rand() % 10;
		gettimeofday(&tv, NULL);
		c = clock();
		printf("%ld.%06ld %ld sleep %d ms\n",
			tv.tv_sec, tv.tv_usec, c, s);
		usleep(s * 1000);
	}
	return 0;
}

