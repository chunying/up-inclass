; this is Intel format, not AT&T format

	section .data
msg:	db	"hello, world!", 0x0a, 0

	section .text
	global _start
_start:
%ifdef __x86_64__
	; syscall ref for x64: http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
	mov	rax, 1
	mov 	rdi, 1		; stdout
	mov	rsi, msg	; buffer: "hello, world!"
	mov	rdx, 14		; length
	syscall			; syscall: write

	mov	rax, 60
	mov	rdi, 0		; code
	syscall			; syscall: exit
%else
	; syscall ref for x86: https://syscalls.kernelgrok.com/
	mov	eax, 4
	mov 	ebx, 1		; stdout
	mov	ecx, msg	; buffer: "hello, world!"
	mov	edx, 14		; length
	int	0x80		; syscall: write

	mov	eax, 1
	mov	ebx, 0		; code
	int	0x80		; syscall: exit
%endif
	ret
