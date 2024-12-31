#if 1
#include "libmini.h"
#else
#include <stdio.h>
#include <errno.h>
#endif

int main() {
		errno = 1;
		return 0;
}
