#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *worker(void *arg) {
	printf("I am the worker.\n");
	return NULL;
}

int main() {
	pthread_t tid;

	if(pthread_create(&tid, NULL, worker, NULL) != 0) {
		fprintf(stderr, "pthread_create failed.\n");
		return -1;
	}

	pthread_join(tid, NULL);
	printf("The worker has terminated.\n");

	return 0;
}


