	global _start:function

	section .data
	section .code
_start:
	mov	rax, 60		; syscall:exit
	xor	rdi, rdi	; rdi (code) = 0
	syscall
