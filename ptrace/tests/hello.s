
./hello:     file format elf64-x86-64


Disassembly of section .text:

00000000004000b0 <_start>:
  4000b0:	48 c7 c0 01 00 00 00 	mov    $0x1,%rax
  4000b7:	48 31 ff             	xor    %rdi,%rdi
  4000ba:	48 c7 c6 dc 00 60 00 	mov    $0x6000dc,%rsi
  4000c1:	48 ba 0e 00 00 00 00 	movabs $0xe,%rdx
  4000c8:	00 00 00 
  4000cb:	0f 05                	syscall 
  4000cd:	48 c7 c0 3c 00 00 00 	mov    $0x3c,%rax
  4000d4:	48 31 ff             	xor    %rdi,%rdi
  4000d7:	0f 05                	syscall 
  4000d9:	c3                   	retq   
