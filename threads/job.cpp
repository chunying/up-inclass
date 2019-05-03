#include <stdio.h>
#include "job.h"

Job::Job(int ch, pthread_t tid) {
	this->ch = ch;
        this->tid = tid;
}
pthread_t Job::getId() {
	return tid;
}
void Job::setId(pthread_t tid) {
	this->tid = tid;
}
int  Job::getChar() {
	return ch;
}
void Job::setChar(int ch) {
	this->ch = ch;
}

