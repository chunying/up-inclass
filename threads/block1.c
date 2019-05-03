/* One does not block SIGUSR1, and signals are handled by a handler */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

void handler(int s) {
	printf("thread %lx received the signal.\n", pthread_self());
}

void block(int sig, sigset_t *oldset) {
	sigset_t set;
	if(sig != 0) {
		sigemptyset(&set);
		sigaddset(&set, sig);
		pthread_sigmask(SIG_BLOCK, &set, oldset);
	}
}

void unblock(int sig, sigset_t *oldset) {
	if(sig != 0 && oldset != NULL) {
		pthread_sigmask(SIG_SETMASK, oldset, NULL);
	}
}

void *worker(void *arg) {
	long sig = (long) arg;
	sigset_t oldset;

	block(sig, &oldset);
	printf("I am thread %lx, SIGUSR1 %sblocked.\n",
		pthread_self(), sig ? "" : "not ");
	while(1) { sleep(1); }
	unblock(sig, &oldset);

	return NULL;
}

int main() {
	int i;
	sigset_t oldset;
	pthread_t tid[3];

	signal(SIGUSR1, handler);

	for(i = 0; i < 3; i++) {
		long sig = (i == 1) ? 0 : SIGUSR1;

		if(pthread_create(&tid[i], NULL, worker, (void*) sig) != 0) {
			fprintf(stderr, "pthread_create failed.\n");
			return -1;
		}
	}

	block(SIGUSR1, &oldset);
	printf("I am main-thread %lx.\n", pthread_self());

	printf("Wait for SIGUSR1 ...\n");

	for(i = 0; i < 3; i++)	// never ends ...
		pthread_join(tid[i], NULL);

	unblock(SIGUSR1, &oldset);
	printf("The workers have terminated.\n");

	return 0;
}


