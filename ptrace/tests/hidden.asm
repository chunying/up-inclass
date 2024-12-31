
	section .data
msg	db	"Nothing is hidden in this program.", 10
mlen	equ	$-msg

secret  db	187, 178, 206, 234, 215, 235, 226, 216, 223, 200, 213, 216, 197, 230, 178, 226, 227, 216, 180, 233, 228, 183, 227, 206, 233, 190, 216, 173, 217, 216, 217, 173, 216, 185, 141
slen	equ	$-secret

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
	jmp	_quit

_hidden:
	mov	rbx, 0
	mov	rcx, slen
_loop1:
	lea	rdx, [rbx + secret];
	mov	al, [rdx]
	xor	al, 0x87
	mov	[rdx], al
	inc	rbx
	loop	_loop1

	mov	rax, 1		; sys_write
	xor	rdi, rdi	; fd = 0
	mov	rsi, secret
	mov	rdx, slen
	syscall

_quit:
	mov	rax, 60		; sys_exit
	xor	rdi, rdi	; retcode
	syscall

	ret
