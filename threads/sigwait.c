#include <stdio.h>
#include <signal.h>
#include <pthread.h>

void handler(int s) {
	printf("SIGUSR1 delivered to handler\n");
	return;
}

int main() {
	int s;
	sigset_t sset;
	printf("wait for SIGUSR1\n");
	sigemptyset(&sset);
	sigaddset(&sset, SIGUSR1);
	sigprocmask(SIG_BLOCK, &sset, NULL);
	sigwait(&sset, &s);
	printf("SIGUSR1 delivered to sigwait.\n");
	return 0;
}
