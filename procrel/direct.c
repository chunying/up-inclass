#include <unistd.h>
#include <stdio.h>

int main() {
	FILE *fp;
	if((fp = fopen("/dev/tty", "w")) == NULL) {
		fprintf(stdout, "cannot open the controlling terminal.\n");
		return(-1);
	}
	fprintf(fp, "write to /dev/tty\n");
	fprintf(stdout, "write to stdout\n");
	return(0);
}
