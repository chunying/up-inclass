; this is Intel format, not AT&T format

	section .data
msg:	db	"hello, world!", 0

extern	puts	; int puts(const char *)

	section .text
	global main
main:
%ifdef NASM
	lea	rdi, [rel msg]
%else
	lea	rdi, [msg wrt rip]
%endif
	call	puts wrt ..plt

	mov	rax, 0
	ret
