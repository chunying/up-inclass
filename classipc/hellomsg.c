#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define	err_sys(m) { perror(m); exit(-1); }
#define	MESSAGE	"hello, world!"

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
	char mtext[0];    /* message data */
};

int main() {
	int qid = -1, rlen, wlen;
	char buf[1024];
	pid_t pid;
	struct msgbuf *msg = (struct msgbuf*) buf;
	//
	if((qid = msgget(IPC_PRIVATE, IPC_CREAT|IPC_EXCL|0660)) < 0)
		err_sys("msgget");
	if((pid = fork()) < 0)
		err_sys("fork");
	if(pid == 0) {	/* child */
		msg->mtype = 0;
		if((rlen = msgrcv(qid, msg, sizeof(buf)-sizeof(*msg), 0, 0)) < 0)
			err_sys("msgrcv");
		printf("[%ld] %s (%u bytes)\n", msg->mtype, msg->mtext, rlen);
	} else {	/* parent */
		msg->mtype = 1024;
		wlen = snprintf(msg->mtext, sizeof(buf)-sizeof(*msg),
				"%s", MESSAGE);
		if(msgsnd(qid, msg, wlen+1, 0) < 0)
			perror("msgsnd");
		else if(wait(&wlen) < 1)
			perror("wait");
		if(qid >= 0)
			if(msgctl(qid, IPC_RMID, NULL) < 0)
				err_sys("msgctl(RMID)");
	}
	return 0;
}

