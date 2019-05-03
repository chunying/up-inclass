#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>

#define	CHILDS		3
#define err_sys(m)	{ perror(m); exit(-1); }

static int sem_flag = 0;

union semun {
	unsigned short array[1];
};

void child_proc(int id, int semid) {
	struct sembuf ops[1] = {{ 0, -1, sem_flag }};
	semop(semid, ops, 1);
	printf("child #%d: enter (sem -1), sleeping (%d)...\n", id, id+1);
	if(id == 0) {
		printf("child #%d: abort\n", id);
		abort();
	}
	sleep(id+1);
	ops[0].sem_op = +1;
	semop(semid, ops, 1);
	printf("child #%d: leave (sem +1)\n", id);
	exit(0);
}

int main(int argc, char *argv[]) {
	int i, semid;
	pid_t pid;
	union semun ctlarg;
	if(argc > 1 && strcmp(argv[1], "undo") == 0) {
		printf("enable UNDO feature\n");
		sem_flag = SEM_UNDO;
	}
	if((semid = semget(IPC_PRIVATE, 1, IPC_CREAT|IPC_EXCL|0600)) < 0)
		err_sys("semget");
	ctlarg.array[0] = CHILDS-1;
	printf("sem initial value %d\n", ctlarg.array[0]);
	if(semctl(semid, 0, SETALL, &ctlarg) < 0)
		err_sys("semctl(SETALL)");
	for(i = 0; i < CHILDS; i++) {
		if((pid = fork()) < 0)
			err_sys("fork");
		if(pid == 0) {
			child_proc(i, semid);
		}
	}
	for(i = 0; i < CHILDS; i++) {
		int status;
		wait(&status);
	}
	if(semctl(semid, 0, GETALL, &ctlarg) < 0)
		err_sys("semctl(GETALL)");
	printf("sem current value %d\n", ctlarg.array[0]);
	//
	if(semctl(semid, 0, IPC_RMID) < 0)
		err_sys("semctl(IPC_RMID)");
	return 0;
}

