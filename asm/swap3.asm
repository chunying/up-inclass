	global swap
swap:
%ifdef __x86_64__
	; rdi = *a, rsi = *b
	mov	rax, [rdi]
	xchg	rax, [rsi]
	mov	[rdi], rax
%else
%endif
	ret
