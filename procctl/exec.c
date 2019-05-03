#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* test of exec* functions */

#if 0
#define	ECHO_FILE	"echo.sh"
#define	ECHO_PATH	"./echo.sh"
#else
#define	ECHO_FILE	"echobin"
#define	ECHO_PATH	"./echobin"
#endif
#define	__CHILD_TASK__	if((pid = fork()) < 0)	{ perror("fork"); exit(-1); } \
			else if(pid > 0)	{ wait(&status); } \
			else

char myname[64] = "";
const char *myenvp1[]	= { "PATH=/bin:/usr/bin:.", NULL };
char *const myenvp2[]	= { "PATH=/bin:/usr/bin:.", NULL };
char *const myargv[]	= { "echo", myname, "hello,", "world!", NULL };

int main() {
	pid_t pid;
	int status;
	printf("======== execl(%s)\n", ECHO_PATH);
	__CHILD_TASK__ {
		if(execl(ECHO_PATH, "echo", " execl:", "hello,", "world!", NULL) < 0)
			perror("execl");
		exit(-1);
	}
	printf("======== execlp(%s): check PATH variable if error happens\n", ECHO_FILE);
	__CHILD_TASK__ {
		if(execlp(ECHO_FILE, "echo", "execlp:", "hello,", "world!", NULL) < 0)
			perror("execlp");
		exit(-1);
	}
	printf("======== execle(%s)\n", ECHO_PATH);
	__CHILD_TASK__ {
		if(execle(ECHO_PATH, "echo", "execle:", "hello,", "world!", NULL, myenvp1) < 0)
			perror("execle");
		exit(-1);
	}
	printf("======== execv(%s)\n", ECHO_PATH);
	__CHILD_TASK__ {
		strncpy(myname, " execv:", sizeof(myname));
		if(execv(ECHO_PATH, myargv) < 0)
			perror("execv");
		exit(-1);
	}
	printf("======== execvp(%s): check PATH variable if error happens\n", ECHO_FILE);
	__CHILD_TASK__ {
		strncpy(myname, "execvp:", sizeof(myname));
		if(execvp(ECHO_FILE, myargv) < 0)
			perror("execvp");
		exit(-1);
	}
	printf("======== execve(%s)\n", ECHO_PATH);
	__CHILD_TASK__ {
		strncpy(myname, "execve:", sizeof(myname));
		if(execve(ECHO_PATH, myargv, myenvp2) < 0)
			perror("execve");
		exit(-1);
	}
	return 0;
}

