/* deadlock happens in the child process */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg) {
	pthread_mutex_lock(&lock);
	puts("worker: locked.");
	sleep(3);
	puts("worker: unlocked.");
	pthread_mutex_unlock(&lock);
	return(0);
}

int main(void) {
	pid_t pid;
	pthread_t tid;

	setlinebuf(stdout);
	pthread_create(&tid, NULL, worker, 0);
	sleep(1);
	puts("parent: The lock is held by the worker thread.");

	pid = fork();
	if (pid == 0) {
		puts("child: start.");
		pthread_mutex_lock(&lock);
		puts("child: locked.");	// never reach here
		pthread_mutex_unlock(&lock);
		puts("child: terminated.");
		return 0;
	}

	puts("parent: after fork.");
	pthread_join(tid, NULL);
	puts("parent: terminated.");

	return 0;
}
