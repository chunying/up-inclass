#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/un.h>

#if defined(__FreeBSD__)
typedef struct cmsgcred cred_t;
#define SCM_CREDTYPE	SCM_CREDS
#elif defined(__linux__)
typedef struct ucred	cred_t;
#define SCM_CREDTYPE	SCM_CREDENTIALS
#else
#error passing credentials is unsupported!
#endif

#define	PATH	"cmsg.socket"
#define	MAGIC	0xab
#define err_sys(m) { perror(m); exit(-1); }

int main() {
	int s, rlen, newfd = -1;
	struct sockaddr_un sun;
	char buf[8192];
	//
	char data[1] = { 0 };
	char cmsgbuf[CMSG_SPACE(sizeof(int))+CMSG_SPACE(sizeof(cred_t))];
	struct iovec io[1];
	struct msghdr m;
	struct cmsghdr *pcm = (struct cmsghdr*) cmsgbuf;
	//
	sun.sun_family = AF_UNIX;
	sprintf(sun.sun_path, PATH);
	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		err_sys("socket");
	if(connect(s, (struct sockaddr*) &sun, sizeof(sun)) < 0)
		err_sys("connect");
	//
	memset(&m, 0, sizeof(m));
	memset(cmsgbuf, 0, sizeof(cmsgbuf));
	io[0].iov_base = data;
	io[0].iov_len = 1;
	m.msg_iov = io;
	m.msg_iovlen = 1;
	m.msg_control = pcm;
	m.msg_controllen = sizeof(cmsgbuf);
#ifdef __linux__
	// enable pass credential
	do {
		int v = 1;
		setsockopt(s, SOL_SOCKET, SO_PASSCRED, &v, sizeof(v));
	} while(0);
#endif
	if(recvmsg(s, &m, 0) < 0)
		err_sys("recvmsg");
	if(data[0] != (char) MAGIC) {
		fprintf(stderr, "client: bad message (%x)\n", data[0]);
		exit(-1);
	}
	for(pcm = CMSG_FIRSTHDR(&m); pcm != NULL; pcm = CMSG_NXTHDR(&m, pcm)) {
		if(pcm->cmsg_type == SCM_RIGHTS) {
			newfd = * (int*) CMSG_DATA(pcm);
			fprintf(stderr, "client: descriptor %d received.\n", newfd);
		} else if(pcm->cmsg_type == SCM_CREDTYPE) {
			cred_t *pcred = (cred_t*) CMSG_DATA(pcm);
			fprintf(stderr, "client: received from pid %u, uid %u, gid %u\n",
#ifdef __FreeBSD__
				pcred->cmcred_pid,
				pcred->cmcred_uid,
				pcred->cmcred_gid
#elif defined(__linux__)
				pcred->pid, pcred->uid, pcred->gid
#endif
			);
		}
	}
	if(newfd < 0) {
		fprintf(stderr, "client: no descriptor received.\n");
		exit(-1);
	}
	//
	close(s);
	//
	while((rlen = read(0, buf, sizeof(buf))) > 0)
		if(write(newfd, buf, rlen) < 0)
			err_sys("write");
	//
	return 0;
}

