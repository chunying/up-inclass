#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* worker(void *arg) {
	// overflow the stack
	worker(NULL);
	return NULL;
}

int main() {
	pthread_t tid;
	pthread_attr_t attr;
	size_t size;

	pthread_attr_init(&attr);
	pthread_attr_getguardsize(&attr, &size);
	printf("guard size = %ld\n", size);

	if(pthread_create(&tid, &attr, worker, NULL) != 0) {
		fprintf(stderr, "pthread_create");
		return -1;
	}

	pthread_attr_destroy(&attr);

	pause();

	return 0;
}

