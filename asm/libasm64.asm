
%macro	PUSH_ALL 0	; zero parameters
	push	rax
	push	rbx
	push	rcx
	push	rdx
	push	rsi
	push	rdi	; rdi must be the last
%endmacro

%macro	POP_ALL 0	; zero parameters
	pop	rdi	; rdi must be the first
	pop	rsi
	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
%endmacro

	; functoin call params: RDI, RSI, RDX, RCX, R8, R9 
	section .text

	; exit, rdi = exit code
	global asm_exit
asm_exit:
	mov	rax, 60
	syscall
	ret

	; exit with 0
	global _asm_exit
_asm_exit:
	mov	rdi, 0
	call	asm_exit
	ret

	; C language interface
	global asm_write_char
asm_write_char:
	call	_asm_write_char
	ret

	; output a char, rdi = char
	global _asm_write_char
_asm_write_char:
	PUSH_ALL
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, rsp	; because rdi is the last one in PUSH_ALL
	mov	rdx, 1
	syscall
	POP_ALL
	ret

	; C language interface
	global asm_write_str
asm_write_str:
	call _asm_write_str
	ret

	; output a string, rdx = length, rsi = pointer to string buffer
	global _asm_write_str
_asm_write_str:
	PUSH_ALL
	mov	rax, 1
	mov	rdi, 1
	syscall
	POP_ALL
	ret

	; C language interface
	global asm_write_hex
asm_write_hex:
	call _asm_write_hex
	ret

	; output a hexdecimal number
	; rdi = the number, rsi = length (max = 16)
	global _asm_write_hex
_asm_write_hex:
	PUSH_ALL
	;
	mov	rbx, rsp	; top address for buffer
	sub	rsp, 16		; allocate spaces
	mov	rdx, rdi	; number is stored in rdx
	; ensure that rsi is valid (1 -- 16)
	mov	rcx, rsi	; set the counter
	dec	rcx
	and	rcx, 0x0f
	inc	rcx
.loop:
	dec	rbx		; the space for a digit
	mov	al, dl
	and	al, 0x0f	; get the digit
	cmp	al, 10		; < 10?
	jb	.digit
	sub	al, 10		; >= 10, al = al - 10 + 'a'
	add	al, 'a'
	jmp	.write
.digit
	add	al, '0'		; <  10, al = al + '0'
.write:
	mov	[rbx], al	; write thr char
	shr	rdx, 4
	loop	.loop
	; output the string
	mov	rsi, rbx	; buffer addr
	mov	rdx, rsp	; length = rsp + 16 - rbx
	add	rdx, 16
	sub	rdx, rbx
	call	_asm_write_str
	add	rsp, 16		; free allocated spaces
	;
	POP_ALL
	ret

	section .data
dump_regs_text	db	"RAX=RBX=RCX=RDX=RSI=RDI=RSP=RBP= R8= R9=R10=R11=R12=R13=R14=R15=FLG=", 0
dump_regs_off	dq	104, 96, 88, 80, 72, 64, 120, 112
		dq	56, 48, 40, 32, 24, 16, 8, 0

	section .text
	global asm_dump_regs
asm_dump_regs:
	push	rsp
	push	rbp
	push	rax
	push	rbx
	push	rcx
	push	rdx
	push	rsi
	push	rdi
	push	r8
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13
	push	r14
	push	r15
	pushfq
	; ESP now points to r15
%ifdef  NASM
	lea	rax, [rel dump_regs_text]
	lea	rbx, [rel dump_regs_off]
%else	; YASM
	lea	rax, [dump_regs_text wrt rip]
	lea	rbx, [dump_regs_off wrt rip]
%endif
	mov	rcx, 17
.loop:
	mov	rsi, rax	; buffer
	mov	rdx, 4		; length
	call	_asm_write_str
	mov	rdx, rsp
	add	rdx, [rbx]
	mov	rdi, [rdx]	; number
	mov	rsi, 16		; length
	call	_asm_write_hex
	mov	rdi, ' '
	call	_asm_write_char
	add	rax, 4
	add	rbx, 8
	push	rcx
	and	rcx, 0x03
	cmp	rcx, 2
	jne	.continue
	mov	rdi, 0x0a
	call	_asm_write_char
.continue:
	pop	rcx
	loop	.loop
	mov	rdi, 0x0a
	call	_asm_write_char
	;
	pop	r15		; pop RFLAGS
	pop	r15
	pop	r14
	pop	r13
	pop	r12
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	pop	rdi
	pop	rsi
	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
	pop	rbp
	pop	rsp
	ret

;;;;;;;; syscalls demo

	global asm_write
asm_write:
	push	rbp
	mov	rbp, rsp
	mov	rax, 1
	; rdi, rsi, rdx is filled by caller (fd, buf, len)
	syscall
	leave
	ret

	global dump_stack
dump_stack:
	ret

