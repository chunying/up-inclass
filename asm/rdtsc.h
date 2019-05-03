
static long long rdtsc() {
	unsigned high = 0, low = 0;
	asm(	"rdtsc\n"	/* read cpu timestamp, in cycles */
		"mov %0, edx\n"
		"mov %1, eax\n":
		"=r" (high), "=r" (low) :
		/* no inputs */ :
		"eax", "edx");
	return ((long long) high)<<32 | low;
}

