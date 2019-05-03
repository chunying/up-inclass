#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <netinet/in.h>

#define	WORKERS	5

#define	err_sys(m) { perror(m); exit(-1); }

static int nworker = 0;
static int notification = 0;
static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
static pid_t workers[WORKERS];

void sigchld(int s) {
	int status;
	while(waitpid(-1, &status, WNOHANG) > 0)
		;
}

void notify(int s) {
	notification = 1;
}

void handle_client(int s) {
	int c, rlen;
	socklen_t slen;
	struct sockaddr_in sin;
	sigset_t zeromask;
	char buf[4096];
	//
	sigemptyset(&zeromask);
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	slen = sizeof(sin);
	while(notification == 0)
		sigsuspend(&zeromask);
	if((c = accept(s, (struct sockaddr*) &sin, &slen)) < 0)
		err_sys("accept");
	while((rlen = read(c, buf, sizeof(buf))) > 0)
		write(c, buf, rlen);
	return;
}

void *create_worker(void *arg) {
	long s = (long) arg;
	while(1) {
		pthread_mutex_lock(&m);
		if(nworker < WORKERS) {
			pid_t pid;
			sigset_t mask, oldmask;
			sigemptyset(&mask);
			sigaddset(&mask, SIGUSR1);
			sigprocmask(SIG_SETMASK, &mask, &oldmask);
			signal(SIGUSR1, notify);
			if((pid = fork()) < 0)
				err_sys("fork");
			if(pid == 0) {
				pthread_mutex_unlock(&m);
				handle_client(s);
				exit(0);
			}
			sigprocmask(SIG_SETMASK, &oldmask, NULL);
			signal(SIGUSR1, SIG_DFL);
			workers[nworker++] = pid;
		}
		pthread_mutex_unlock(&m);
		usleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	long s;
	struct sockaddr_in sin;
	pthread_t tid;
	//
	if(argc < 2) {
		fprintf(stderr, "usage: %s port\n", argv[0]);
		return -1;
	}
	//
	signal(SIGCHLD, sigchld);
	//
	if((s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		err_sys("socket");
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(strtol(argv[1], NULL, 0));
	if(bind(s, (struct sockaddr*) &sin, sizeof(sin)) < 0)
		err_sys("bind");
	if(listen(s, 256) < 0)
		err_sys("listen");
	// create workers
	if((errno = pthread_create(&tid, NULL, create_worker, (void*) s)) != 0)
		err_sys("pthread_create");
	// wait for incoming connections
	while(1) {
		fd_set rfds;
		FD_ZERO(&rfds);
		FD_SET(s, &rfds);
		if(select(s+1, &rfds, NULL, NULL, NULL) > 0) {
			pthread_mutex_lock(&m);
			if(nworker > 0) {
				kill(workers[0], SIGUSR1);
				workers[0] = workers[nworker-1];
				nworker--;
			}
			pthread_mutex_unlock(&m);
		}
	}
	//
	return 0;
}

