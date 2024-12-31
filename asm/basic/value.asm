	global _start:function

	section .data

a	db	0x55		; just the byte 0x55
b	db	0x55,0x56,0x57	; three bytes in succession
c	db	'a',0x55			; character constants are OK
d	db	'hello',13,10,'$'	 ; so are string constants
e	dw	0x1234		; 0x34 0x12
f	dw	'a'		 ; 0x41 0x00 (it's just a number)
g	dw	'ab'		; 0x41 0x42 (character constant)
h	dw	'abc'		 ; 0x41 0x42 0x43 0x00 (string)
i	dd	0x12345678		; 0x78 0x56 0x34 0x12
j	dq	0x1122334455667788	; 0x88 0x77 0x66 0x55 0x44 0x33 0x22 0x11
k	dt	0x112233445566778899aa
l	ddq	0x112233445566778899aabbccddeeff00
	; 0x00 0xff 0xee 0xdd 0xcc 0xbb 0xaa 0x99
	; 0x88 0x77 0x66 0x55 0x44 0x33 0x22 0x11
m	do	0x112233445566778899aabbccddeeff00 ; same as previous
n	dd	1.234567e20	 ; floating-point constant
o	dq	1.234567e20	 ; double-precision float
p	dt	1.234567e20	 ; extended-precision float
sz	equ	$-p

	; repetition
zerobuf	times 64 db 0x00
buffer	db	"hello, world!"
	times 64-$+buffer db 0x00

	; size of a list
dlist	dd	1, 2, 3, 4, 5
dsize	dd	($-dlist) / 4

	section	.bss

q	resb	32
r	resw	64
s	rest	128

	section .text

_start:	mov	rax, 60		; exit(87)
	mov	rdi, 87
	syscall

	push	QWORD [a]
	pop	QWORD [a]
