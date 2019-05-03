#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>

#define	PATH	"unix2.socket"
#define err_sys(m) { perror(m); exit(-1); }

int main(int argc, char *argv[]) {
	int s;
	struct sockaddr_un sun;
	if(argc < 2) {
		fprintf(stderr, "usage: %s message\n", argv[0]);
		return -1;
	}
	//
	sun.sun_family = AF_UNIX;
	sprintf(sun.sun_path, PATH);
	if((s = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
		err_sys("socket");
	if(sendto(s, argv[1], strlen(argv[1])+1, 0, // send \0 as well
			(struct sockaddr*) &sun, sizeof(sun)) < 0)
		err_sys("sendto");
	close(s);
	return 0;
}

