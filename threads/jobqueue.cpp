#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <list>

#include "job.h"

//#define	ASSIGNID	/* Assign thread id to jobs */
//#define	ORDERED		/* Ensure that jobs are processed in the order */
#define	N_WORKERS	3

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
std::list<Job> jobqueue;

int do_the_job(long id, int ch) {
	if(ch == -1)	/* terminate the worker */
		return -1;
	printf("worker-%ld: %c\n", id, ch);
	return 0;
}

void* worker_main(void *arg) {
	long id = (long) arg;
	printf("# worker-%ld created\n", id);
	while(1) {
		Job j;
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);
		// has at least one job
		j = jobqueue.front();
		if(j.getId() == 0
		|| pthread_equal(pthread_self(), j.getId())) {
			jobqueue.pop_front();
#ifdef	ORDERED
			// process the job: will follow the order
			if(do_the_job(id, j.getChar()) < 0) {
				pthread_mutex_unlock(&mutex);
				break;
			}
#endif
		} else {
			pthread_mutex_unlock(&mutex);
			continue;
		}
		pthread_mutex_unlock(&mutex);
#ifndef	ORDERED
		// process the job: may be out of order
		if(do_the_job(id, j.getChar()) < 0)
			break;
#endif
	}
	printf("# worker-%ld terminated\n", id);
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t workers[N_WORKERS];
	// check args
	if(argc < 2) {
		fprintf(stderr, "usage: %s input-string\n", argv[0]);
		return -1;
	}
	// create workers
	for(int i = 0; i < N_WORKERS; i++) {
		if(pthread_create(&workers[i], NULL, worker_main, (void *) (long) i) != 0) {
			fprintf(stderr, "create worker[%d] failed\n", i);
			exit(-1);
		}
	}
	// create jobs
	for(char *ptr = argv[1]; *ptr; ptr++) {
#ifdef	ASSIGNID
		Job j(*ptr, workers[(ptr - argv[1]) % N_WORKERS]);
#else
		Job j(*ptr);
#endif
		pthread_mutex_lock(&mutex);
		jobqueue.push_back(j);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	// terminate workers
	for(int i = 0; i < N_WORKERS; i++) {
#ifdef	ASSIGNID
		Job j(-1, workers[i]);
#else
		Job j(-1);
#endif
		pthread_mutex_lock(&mutex);
		jobqueue.push_back(j);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	// process all jobs
	size_t jobs;
	do {
		pthread_mutex_lock(&mutex);
		jobs = jobqueue.size();
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	} while(jobs > 0);
	// wait for all workers
	for(int i = 0; i < N_WORKERS; i++) {
		void *ret;
		pthread_join(workers[i], &ret);
	}
	//
	return 0;
}	/* end of main() */

