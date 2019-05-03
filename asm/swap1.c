
void swap(int *a, int *b) {
#ifdef __x86_64__
	asm(	/* rdi = *a, rsi = *b */
		"mov	eax, [rdi]\n"
		"xchg	eax, [rsi]\n"
		"mov	[rdi], eax\n"
		: /* no additional outputs */
		: /* no additional inputs */
		: "rax" );
#else
	asm(	"mov	eax, %0\n"
		"mov	ebx, %1\n"
		"mov	esi, [eax]\n"
		"xchg	esi, [ebx]\n"
		"mov	[eax], esi\n"
		: /* no outputs */
		: "rm" (a), "rm" (b)
		: /*"rax", "rbx", "rsi", "memory"*/ );
#endif
}

