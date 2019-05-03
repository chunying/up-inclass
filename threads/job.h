#include <pthread.h>

#ifndef __JOB_H__
#define	__JOB_H__

class Job {
private:
	pthread_t tid;
	int ch;
public:
	Job(int ch = 0, pthread_t tid = 0);
	pthread_t getId();
	void setId(pthread_t tid);
	int getChar();
	void setChar(int ch);
};

#endif
