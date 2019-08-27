	%include "libasm.inc"

	section .data
msg	db	'hello, world.', 0xa, 0
msglen	dq	msglen-msg-1

	section .text

	global _start
_start:
	mov	rdi, 'h'
	call	_asm_write_char

	mov	rdx, [msglen]
	mov	rsi, msg
	call	_asm_write_str

	mov	rsi, 16
	mov	rcx, 16
.loop_hex:
	mov	rdi, 0x1234567890abcdef
	call	_asm_write_hex
	mov	rdi, 0x0a
	call	_asm_write_char
	dec	rsi
	loop	.loop_hex

	call	asm_dump_regs

	call	_asm_exit

