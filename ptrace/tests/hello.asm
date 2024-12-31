
	section .data
msg	db	"hello, world!", 10
mlen	equ	$-msg

	section .text
	global _start
_start:
	; x86-64 syscall table
	; http://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

	mov	rax, 1		; sys_write
	xor	rdi, rdi	; fd = 0
	mov	rsi, msg
	mov	rdx, mlen
	syscall

	mov	rax, 60		; sys_exit
	xor	rdi, rdi	; retcode
	syscall

	ret
