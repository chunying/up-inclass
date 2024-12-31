
_start:
	mov ebx, 0x12345678
l1:
	call ebx
	int 3
	jmp l1


