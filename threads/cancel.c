#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#define	N	10000000000LL

static int printid = 0;
static int opt_test = 0;
static int opt_async = 0;
static int opt_disable = 0;

void *printer(void *arg) {
	int old_printid = printid;
	struct timeval tv;
	
	while(1) {
		if(old_printid != printid) {
			gettimeofday(&tv, NULL);
			printf("%ld.%06ld %d\n",
				tv.tv_sec, tv.tv_usec, printid);
			old_printid = printid;
		}
		usleep(100000);
	}

	return NULL;
}

void *worker(void *arg) {
	long long i, count = 0;
	if(opt_async)
		pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	else
		pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	if(opt_disable)
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	for(i = 0; i < N; i++) {
		sqrt(N);
		if(count % (N/100) == 0)
			printid++;
		count++;
		if(opt_test)
			pthread_testcancel();
	}
	if(opt_disable)
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	return NULL;
}

int main(int argc, char *argv[]) {
	int ch;
	pthread_t tid1, tid2;

	while((ch = getopt(argc, argv, "adth")) != -1) {
		switch(ch) {
		case 'a':
			opt_async = 1;
			printf("async type enabled.\n");
			break;
		case 'd':
			opt_disable = 1;
			printf("cancel state is set to 'disable'\n");
			break;
		case 't':
			opt_test = 1;
			printf("pthread_testcancel enabled.\n");
			break;
		case 'h':
		case '?':
		default:
			printf("options -a: enable asynchronous type\n");
			printf("        -d: set cancel state to disable\n");
			printf("        -t: use pthread_testcancel\n");
			exit(-1);
			break;
		}
	}

	if(pthread_create(&tid1, NULL, printer, NULL) != 0) {
		fprintf(stderr, "pthread_create(printer) failed.\n");
		return -1;
	}

	if(pthread_create(&tid2, NULL, worker, NULL) != 0) {
		fprintf(stderr, "pthread_create(worker) failed.\n");
		return -1;
	}

	sleep(3);
	printf("Attempt to cancel the worker thread ...\n");
	pthread_cancel(tid2);
	pthread_join(tid2, NULL);
	printf("The worker has been terminated.\n");

	pthread_cancel(tid1);
	pthread_join(tid1, NULL);

	return 0;
}


