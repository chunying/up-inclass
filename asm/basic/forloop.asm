	global _start:function

	section .data
i:	dd	0
digit:	db	'0', 0x0a

	section .text

_start:
	mov	DWORD [i], 0
L1:
	cmp	DWORD [i], 10
	jge	L2

	and	BYTE [digit], 0xf0
	mov	al, BYTE [i];
	or	BYTE [digit], al

	mov	rax, 1		; write()
	mov	rdi, 1		; fd
	mov	rsi, digit	; buf
	mov	rdx, 2		; length
	syscall

	inc	DWORD [i]
	jmp	L1
L2:
	mov	rax, 60		; exit(0)
	xor	rdi, rdi
	syscall
