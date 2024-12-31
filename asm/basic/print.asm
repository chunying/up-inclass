	global _start:function

	section .data
hello:	db	"hello, world!", 0x0a
mlen:	equ	$-hello

	section .text
_start:
	mov	rax, 1		; syscall:write
	mov	rdi, 1		; rdi (fd)
	mov	rsi, hello	; rsi (buffer)
	mov	rdx, mlen	; rdx (size)
	syscall

	mov	rax, 60		; syscall:exit
	xor	rdi, rdi	; rdi (code)
	syscall
