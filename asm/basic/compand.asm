	global _start:function

	section .data
a:	dw	11
b:	dw	22
c:	dw	0

	section .text

_start:
	; if (a > 1 and b > 2) { c = 10 } else { c = 20 }
	cmp	WORD [a], 1
	jle	L1
	cmp	WORD [b], 2
	jle	L1

	mov	WORD [c], 10
	jmp	L2
L1:
	mov	WORD [c], 20
L2:

	mov	rax, 60		; exit(0)
	xor	rdi, rdi
	syscall
