	%include "libasm.inc"

	section .data
val1	dd	0x10000
val2	dd	0x40000
val3	dd	0x20000

	section	.bss
final	resd	1

	global _start:function
	section .text
_start:
	mov	eax, [val1]
	add	eax, [val2]
	sub	eax, [val3]
	mov	[final], eax
	call	_asm_dump_regs
	call	_asm_exit
	
