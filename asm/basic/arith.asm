	global _start:function

	section .data
msg:	db	"a string", 0x0a, 0x00
a:	db	0x01

	section .text

_start:
	
	mov	ax, 0x0101
	xor	ax, 0x0002
	mov	ax, 0x0101
	xor	ax, 0x0200
	mov	rax, 60		; exit(87)
	mov	rdi, 87
	inc	BYTE [a]
	syscall


