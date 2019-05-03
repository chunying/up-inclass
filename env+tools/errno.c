#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
	FILE *fp;
	if((fp = fopen("/tmp/xyz", "r")) == NULL) {
		int z = errno;
		perror("fopen");
		fprintf(stderr, "fopen(%d): %s\n", z, strerror(z));
		return -1;
	}
	fclose(fp);
	return 0;
}


