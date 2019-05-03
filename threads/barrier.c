#include <stdio.h>
#include <pthread.h>

//#define	HAS_BARRIER
#define	N	5

#ifdef HAS_BARRIER
static pthread_barrier_t barrier;
#endif

void *worker(void *arg) {
	long i, id = (long) arg;
	for(i = 0; i < id+1; i++) {
		fprintf(stderr, "%ld", id+1);
	}
	fprintf(stderr, "[%ld/done]\n", id+1);
#ifdef HAS_BARRIER
	pthread_barrier_wait(&barrier);
#endif
	return NULL;
}

int main() {
	long i;
	pthread_t tid;
#ifdef HAS_BARRIER
	pthread_barrier_init(&barrier, NULL, N+1);
#endif
	for(i = 0; i < N; i++) {
		if(pthread_create(&tid, NULL, worker, (void*) i) != 0) {
			fprintf(stderr, "pthread_create failed.\n");
			return -1;
		}
	}
#ifdef HAS_BARRIER
	pthread_barrier_wait(&barrier);
	pthread_barrier_destroy(&barrier);
#endif
	fprintf(stderr, "all done.\n");
	return 0;
}

