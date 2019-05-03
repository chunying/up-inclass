#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>

double tvdiff(struct timeval t1, struct timeval t0) {
	t1.tv_sec -= t0.tv_sec;
	if(t1.tv_usec >= t0.tv_usec) {
		t1.tv_usec = t1.tv_usec - t0.tv_usec;
	} else {
		t1.tv_usec = t1.tv_usec + 1000000 - t0.tv_usec;
		t1.tv_sec--;
	}
	return 0.000001 * t1.tv_usec + t1.tv_sec;
}

int main() {
	struct rusage r0, r1;
	if(getrusage(RUSAGE_SELF, &r0) != 0) {
		perror("getrusage");
		return -1;
	}
	printf("Sleeping for 3 seconds ...\n");
	sleep(3);
	if(getrusage(RUSAGE_SELF, &r1) != 0) {
		perror("getrusage");
		return -1;
	}
	printf("r0.ru_utime = %ld.%06ld; .ru_stime = %ld.%06ld\n",
		r0.ru_utime.tv_sec, r0.ru_utime.tv_usec,
		r0.ru_stime.tv_sec, r0.ru_stime.tv_usec);
	printf("r1.ru_utime = %ld.%06ld; .ru_stime = %ld.%06ld\n",
		r1.ru_utime.tv_sec, r1.ru_utime.tv_usec,
		r1.ru_stime.tv_sec, r1.ru_stime.tv_usec);
	printf("user: %f\n", tvdiff(r1.ru_utime, r0.ru_utime));
	printf("system: %f\n", tvdiff(r1.ru_stime, r0.ru_stime));
	return 0;
}
