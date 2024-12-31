	global _start:function

	section .data
	section .text
_start:
	mov	rax, 60		; syscall:exit
	xor	rdi, rdi	; rdi (code) = 0
	syscall
