#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
	time_t t0 = time(NULL);
	while(1) {
		printf("[%u] ... %ld\n", getpid(), time(NULL) - t0);
		sleep(1);
	}
	return 0;
}

