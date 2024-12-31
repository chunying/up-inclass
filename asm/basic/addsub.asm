	%include "libasm.inc"

	global _start:function
	section .text
_start:
	mov	eax, 0x10000
	add	eax, 0x40000
	sub	eax, 0x20000
	call	_asm_dump_regs
	call	_asm_exit
	
