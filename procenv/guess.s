
guess:     file format elf64-x86-64


Disassembly of section .interp:

0000000000000318 <.interp>:
 318:	2f                   	(bad)
 319:	6c                   	ins    BYTE PTR es:[rdi],dx
 31a:	69 62 36 34 2f 6c 64 	imul   esp,DWORD PTR [rdx+0x36],0x646c2f34
 321:	2d 6c 69 6e 75       	sub    eax,0x756e696c
 326:	78 2d                	js     355 <__abi_tag-0x27>
 328:	78 38                	js     362 <__abi_tag-0x1a>
 32a:	36 2d 36 34 2e 73    	ss sub eax,0x732e3436
 330:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 331:	2e 32 00             	cs xor al,BYTE PTR [rax]

Disassembly of section .note.gnu.property:

0000000000000338 <.note.gnu.property>:
 338:	04 00                	add    al,0x0
 33a:	00 00                	add    BYTE PTR [rax],al
 33c:	10 00                	adc    BYTE PTR [rax],al
 33e:	00 00                	add    BYTE PTR [rax],al
 340:	05 00 00 00 47       	add    eax,0x47000000
 345:	4e 55                	rex.WRX push rbp
 347:	00 02                	add    BYTE PTR [rdx],al
 349:	80 00 c0             	add    BYTE PTR [rax],0xc0
 34c:	04 00                	add    al,0x0
 34e:	00 00                	add    BYTE PTR [rax],al
 350:	01 00                	add    DWORD PTR [rax],eax
 352:	00 00                	add    BYTE PTR [rax],al
 354:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .note.gnu.build-id:

0000000000000358 <.note.gnu.build-id>:
 358:	04 00                	add    al,0x0
 35a:	00 00                	add    BYTE PTR [rax],al
 35c:	14 00                	adc    al,0x0
 35e:	00 00                	add    BYTE PTR [rax],al
 360:	03 00                	add    eax,DWORD PTR [rax]
 362:	00 00                	add    BYTE PTR [rax],al
 364:	47                   	rex.RXB
 365:	4e 55                	rex.WRX push rbp
 367:	00 9a ed 8c 96 30    	add    BYTE PTR [rdx+0x30968ced],bl
 36d:	27                   	(bad)
 36e:	c7                   	(bad)
 36f:	f7 f5                	div    ebp
 371:	97                   	xchg   edi,eax
 372:	ea                   	(bad)
 373:	27                   	(bad)
 374:	2f                   	(bad)
 375:	87 37                	xchg   DWORD PTR [rdi],esi
 377:	36 3b c5             	ss cmp eax,ebp
 37a:	4c d5                	rex.WR (bad)

Disassembly of section .note.ABI-tag:

000000000000037c <__abi_tag>:
 37c:	04 00                	add    al,0x0
 37e:	00 00                	add    BYTE PTR [rax],al
 380:	10 00                	adc    BYTE PTR [rax],al
 382:	00 00                	add    BYTE PTR [rax],al
 384:	01 00                	add    DWORD PTR [rax],eax
 386:	00 00                	add    BYTE PTR [rax],al
 388:	47                   	rex.RXB
 389:	4e 55                	rex.WRX push rbp
 38b:	00 00                	add    BYTE PTR [rax],al
 38d:	00 00                	add    BYTE PTR [rax],al
 38f:	00 03                	add    BYTE PTR [rbx],al
 391:	00 00                	add    BYTE PTR [rax],al
 393:	00 02                	add    BYTE PTR [rdx],al
 395:	00 00                	add    BYTE PTR [rax],al
 397:	00 00                	add    BYTE PTR [rax],al
 399:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .gnu.hash:

00000000000003a0 <.gnu.hash>:
 3a0:	03 00                	add    eax,DWORD PTR [rax]
 3a2:	00 00                	add    BYTE PTR [rax],al
 3a4:	0e                   	(bad)
 3a5:	00 00                	add    BYTE PTR [rax],al
 3a7:	00 01                	add    BYTE PTR [rcx],al
 3a9:	00 00                	add    BYTE PTR [rax],al
 3ab:	00 06                	add    BYTE PTR [rsi],al
 3ad:	00 00                	add    BYTE PTR [rax],al
 3af:	00 00                	add    BYTE PTR [rax],al
 3b1:	00 a1 00 80 01 10    	add    BYTE PTR [rcx+0x10018000],ah
 3b7:	00 0e                	add    BYTE PTR [rsi],cl
 3b9:	00 00                	add    BYTE PTR [rax],al
 3bb:	00 10                	add    BYTE PTR [rax],dl
 3bd:	00 00                	add    BYTE PTR [rax],al
 3bf:	00 00                	add    BYTE PTR [rax],al
 3c1:	00 00                	add    BYTE PTR [rax],al
 3c3:	00 28                	add    BYTE PTR [rax],ch
 3c5:	1d 8c 1c d1 65       	sbb    eax,0x65d11c8c
 3ca:	ce                   	(bad)
 3cb:	6d                   	ins    DWORD PTR es:[rdi],dx
 3cc:	67 55                	addr32 push rbp
 3ce:	61                   	(bad)
 3cf:	10                   	.byte 0x10

Disassembly of section .dynsym:

00000000000003d0 <.dynsym>:
	...
 3e8:	34 00                	xor    al,0x0
 3ea:	00 00                	add    BYTE PTR [rax],al
 3ec:	12 00                	adc    al,BYTE PTR [rax]
	...
 3fe:	00 00                	add    BYTE PTR [rax],al
 400:	83 00 00             	add    DWORD PTR [rax],0x0
 403:	00 20                	add    BYTE PTR [rax],ah
	...
 415:	00 00                	add    BYTE PTR [rax],al
 417:	00 15 00 00 00 12    	add    BYTE PTR [rip+0x12000000],dl        # 1200041d <_end+0x11ffc39d>
	...
 42d:	00 00                	add    BYTE PTR [rax],al
 42f:	00 26                	add    BYTE PTR [rsi],ah
 431:	00 00                	add    BYTE PTR [rax],al
 433:	00 12                	add    BYTE PTR [rdx],dl
	...
 445:	00 00                	add    BYTE PTR [rax],al
 447:	00 5b 00             	add    BYTE PTR [rbx+0x0],bl
 44a:	00 00                	add    BYTE PTR [rax],al
 44c:	12 00                	adc    al,BYTE PTR [rax]
	...
 45e:	00 00                	add    BYTE PTR [rax],al
 460:	46 00 00             	rex.RX add BYTE PTR [rax],r8b
 463:	00 12                	add    BYTE PTR [rdx],dl
	...
 475:	00 00                	add    BYTE PTR [rax],al
 477:	00 01                	add    BYTE PTR [rcx],al
 479:	00 00                	add    BYTE PTR [rax],al
 47b:	00 12                	add    BYTE PTR [rdx],dl
	...
 48d:	00 00                	add    BYTE PTR [rax],al
 48f:	00 9f 00 00 00 20    	add    BYTE PTR [rdi+0x20000000],bl
	...
 4a5:	00 00                	add    BYTE PTR [rax],al
 4a7:	00 1a                	add    BYTE PTR [rdx],bl
 4a9:	00 00                	add    BYTE PTR [rax],al
 4ab:	00 12                	add    BYTE PTR [rdx],dl
	...
 4bd:	00 00                	add    BYTE PTR [rax],al
 4bf:	00 21                	add    BYTE PTR [rcx],ah
 4c1:	00 00                	add    BYTE PTR [rax],al
 4c3:	00 12                	add    BYTE PTR [rdx],dl
	...
 4d5:	00 00                	add    BYTE PTR [rax],al
 4d7:	00 07                	add    BYTE PTR [rdi],al
 4d9:	00 00                	add    BYTE PTR [rax],al
 4db:	00 12                	add    BYTE PTR [rdx],dl
	...
 4ed:	00 00                	add    BYTE PTR [rax],al
 4ef:	00 ae 00 00 00 20    	add    BYTE PTR [rsi+0x20000000],ch
	...
 505:	00 00                	add    BYTE PTR [rax],al
 507:	00 47 00             	add    BYTE PTR [rdi+0x0],al
 50a:	00 00                	add    BYTE PTR [rax],al
 50c:	12 00                	adc    al,BYTE PTR [rax]
	...
 51e:	00 00                	add    BYTE PTR [rax],al
 520:	2d 00 00 00 11       	sub    eax,0x11000000
 525:	00 1a                	add    BYTE PTR [rdx],bl
 527:	00 60 40             	add    BYTE PTR [rax+0x40],ah
 52a:	00 00                	add    BYTE PTR [rax],al
 52c:	00 00                	add    BYTE PTR [rax],al
 52e:	00 00                	add    BYTE PTR [rax],al
 530:	08 00                	or     BYTE PTR [rax],al
 532:	00 00                	add    BYTE PTR [rax],al
 534:	00 00                	add    BYTE PTR [rax],al
 536:	00 00                	add    BYTE PTR [rax],al
 538:	4c 00 00             	rex.WR add BYTE PTR [rax],r8b
 53b:	00 22                	add    BYTE PTR [rdx],ah
	...
 54d:	00 00                	add    BYTE PTR [rax],al
 54f:	00 0f                	add    BYTE PTR [rdi],cl
 551:	00 00                	add    BYTE PTR [rax],al
 553:	00 11                	add    BYTE PTR [rcx],dl
 555:	00 1a                	add    BYTE PTR [rdx],bl
 557:	00 70 40             	add    BYTE PTR [rax+0x40],dh
 55a:	00 00                	add    BYTE PTR [rax],al
 55c:	00 00                	add    BYTE PTR [rax],al
 55e:	00 00                	add    BYTE PTR [rax],al
 560:	08 00                	or     BYTE PTR [rax],al
 562:	00 00                	add    BYTE PTR [rax],al
 564:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .dynstr:

0000000000000568 <.dynstr>:
 568:	00 66 67             	add    BYTE PTR [rsi+0x67],ah
 56b:	65 74 73             	gs je  5e1 <__abi_tag+0x265>
 56e:	00 73 65             	add    BYTE PTR [rbx+0x65],dh
 571:	74 76                	je     5e9 <__abi_tag+0x26d>
 573:	62 75 66 00 73       	(bad)
 578:	74 64                	je     5de <__abi_tag+0x262>
 57a:	69 6e 00 70 75 74 73 	imul   ebp,DWORD PTR [rsi+0x0],0x73747570
 581:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
 584:	72 74                	jb     5fa <__abi_tag+0x27e>
 586:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 587:	6c                   	ins    BYTE PTR es:[rdi],dx
 588:	00 74 69 6d          	add    BYTE PTR [rcx+rbp*2+0x6d],dh
 58c:	65 00 67 65          	add    BYTE PTR gs:[rdi+0x65],ah
 590:	74 70                	je     602 <__abi_tag+0x286>
 592:	69 64 00 73 74 64 6f 	imul   esp,DWORD PTR [rax+rax*1+0x73],0x756f6474
 599:	75 
 59a:	74 00                	je     59c <__abi_tag+0x220>
 59c:	5f                   	pop    rdi
 59d:	5f                   	pop    rdi
 59e:	6c                   	ins    BYTE PTR es:[rdi],dx
 59f:	69 62 63 5f 73 74 61 	imul   esp,DWORD PTR [rdx+0x63],0x6174735f
 5a6:	72 74                	jb     61c <__abi_tag+0x2a0>
 5a8:	5f                   	pop    rdi
 5a9:	6d                   	ins    DWORD PTR es:[rdi],dx
 5aa:	61                   	(bad)
 5ab:	69 6e 00 73 72 61 6e 	imul   ebp,DWORD PTR [rsi+0x0],0x6e617273
 5b2:	64 00 5f 5f          	add    BYTE PTR fs:[rdi+0x5f],bl
 5b6:	63 78 61             	movsxd edi,DWORD PTR [rax+0x61]
 5b9:	5f                   	pop    rdi
 5ba:	66 69 6e 61 6c 69    	imul   bp,WORD PTR [rsi+0x61],0x696c
 5c0:	7a 65                	jp     627 <__abi_tag+0x2ab>
 5c2:	00 70 72             	add    BYTE PTR [rax+0x72],dh
 5c5:	69 6e 74 66 00 6c 69 	imul   ebp,DWORD PTR [rsi+0x74],0x696c0066
 5cc:	62 63 2e 73 6f       	(bad)
 5d1:	2e 36 00 47 4c       	cs ss add BYTE PTR [rdi+0x4c],al
 5d6:	49                   	rex.WB
 5d7:	42                   	rex.X
 5d8:	43 5f                	rex.XB pop r15
 5da:	32 2e                	xor    ch,BYTE PTR [rsi]
 5dc:	32 2e                	xor    ch,BYTE PTR [rsi]
 5de:	35 00 47 4c 49       	xor    eax,0x494c4700
 5e3:	42                   	rex.X
 5e4:	43 5f                	rex.XB pop r15
 5e6:	32 2e                	xor    ch,BYTE PTR [rsi]
 5e8:	33 34 00             	xor    esi,DWORD PTR [rax+rax*1]
 5eb:	5f                   	pop    rdi
 5ec:	49 54                	rex.WB push r12
 5ee:	4d 5f                	rex.WRB pop r15
 5f0:	64 65 72 65          	fs gs jb 659 <__abi_tag+0x2dd>
 5f4:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
 5fb:	4d 
 5fc:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
 5fe:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 5ff:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 600:	65 54                	gs push rsp
 602:	61                   	(bad)
 603:	62                   	(bad)
 604:	6c                   	ins    BYTE PTR es:[rdi],dx
 605:	65 00 5f 5f          	add    BYTE PTR gs:[rdi+0x5f],bl
 609:	67 6d                	ins    DWORD PTR es:[edi],dx
 60b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 60c:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 60d:	5f                   	pop    rdi
 60e:	73 74                	jae    684 <__abi_tag+0x308>
 610:	61                   	(bad)
 611:	72 74                	jb     687 <__abi_tag+0x30b>
 613:	5f                   	pop    rdi
 614:	5f                   	pop    rdi
 615:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 618:	54                   	push   rsp
 619:	4d 5f                	rex.WRB pop r15
 61b:	72 65                	jb     682 <__abi_tag+0x306>
 61d:	67 69 73 74 65 72 54 	imul   esi,DWORD PTR [ebx+0x74],0x4d547265
 624:	4d 
 625:	43 6c                	rex.XB ins BYTE PTR es:[rdi],dx
 627:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 628:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 629:	65 54                	gs push rsp
 62b:	61                   	(bad)
 62c:	62                   	.byte 0x62
 62d:	6c                   	ins    BYTE PTR es:[rdi],dx
 62e:	65                   	gs
	...

Disassembly of section .gnu.version:

0000000000000630 <.gnu.version>:
 630:	00 00                	add    BYTE PTR [rax],al
 632:	02 00                	add    al,BYTE PTR [rax]
 634:	01 00                	add    DWORD PTR [rax],eax
 636:	03 00                	add    eax,DWORD PTR [rax]
 638:	03 00                	add    eax,DWORD PTR [rax]
 63a:	03 00                	add    eax,DWORD PTR [rax]
 63c:	03 00                	add    eax,DWORD PTR [rax]
 63e:	03 00                	add    eax,DWORD PTR [rax]
 640:	01 00                	add    DWORD PTR [rax],eax
 642:	03 00                	add    eax,DWORD PTR [rax]
 644:	03 00                	add    eax,DWORD PTR [rax]
 646:	03 00                	add    eax,DWORD PTR [rax]
 648:	01 00                	add    DWORD PTR [rax],eax
 64a:	03 00                	add    eax,DWORD PTR [rax]
 64c:	03 00                	add    eax,DWORD PTR [rax]
 64e:	03 00                	add    eax,DWORD PTR [rax]
 650:	03 00                	add    eax,DWORD PTR [rax]

Disassembly of section .gnu.version_r:

0000000000000658 <.gnu.version_r>:
 658:	01 00                	add    DWORD PTR [rax],eax
 65a:	02 00                	add    al,BYTE PTR [rax]
 65c:	62                   	(bad)
 65d:	00 00                	add    BYTE PTR [rax],al
 65f:	00 10                	add    BYTE PTR [rax],dl
 661:	00 00                	add    BYTE PTR [rax],al
 663:	00 00                	add    BYTE PTR [rax],al
 665:	00 00                	add    BYTE PTR [rax],al
 667:	00 75 1a             	add    BYTE PTR [rbp+0x1a],dh
 66a:	69 09 00 00 03 00    	imul   ecx,DWORD PTR [rcx],0x30000
 670:	6c                   	ins    BYTE PTR es:[rdi],dx
 671:	00 00                	add    BYTE PTR [rax],al
 673:	00 10                	add    BYTE PTR [rax],dl
 675:	00 00                	add    BYTE PTR [rax],al
 677:	00 b4 91 96 06 00 00 	add    BYTE PTR [rcx+rdx*4+0x696],dh
 67e:	02 00                	add    al,BYTE PTR [rax]
 680:	78 00                	js     682 <__abi_tag+0x306>
 682:	00 00                	add    BYTE PTR [rax],al
 684:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .rela.dyn:

0000000000000688 <.rela.dyn>:
 688:	d0 3d 00 00 00 00    	sar    BYTE PTR [rip+0x0],1        # 68e <__abi_tag+0x312>
 68e:	00 00                	add    BYTE PTR [rax],al
 690:	08 00                	or     BYTE PTR [rax],al
 692:	00 00                	add    BYTE PTR [rax],al
 694:	00 00                	add    BYTE PTR [rax],al
 696:	00 00                	add    BYTE PTR [rax],al
 698:	b0 11                	mov    al,0x11
 69a:	00 00                	add    BYTE PTR [rax],al
 69c:	00 00                	add    BYTE PTR [rax],al
 69e:	00 00                	add    BYTE PTR [rax],al
 6a0:	d8 3d 00 00 00 00    	fdivr  DWORD PTR [rip+0x0]        # 6a6 <__abi_tag+0x32a>
 6a6:	00 00                	add    BYTE PTR [rax],al
 6a8:	08 00                	or     BYTE PTR [rax],al
 6aa:	00 00                	add    BYTE PTR [rax],al
 6ac:	00 00                	add    BYTE PTR [rax],al
 6ae:	00 00                	add    BYTE PTR [rax],al
 6b0:	70 11                	jo     6c3 <__abi_tag+0x347>
 6b2:	00 00                	add    BYTE PTR [rax],al
 6b4:	00 00                	add    BYTE PTR [rax],al
 6b6:	00 00                	add    BYTE PTR [rax],al
 6b8:	50                   	push   rax
 6b9:	40 00 00             	rex add BYTE PTR [rax],al
 6bc:	00 00                	add    BYTE PTR [rax],al
 6be:	00 00                	add    BYTE PTR [rax],al
 6c0:	08 00                	or     BYTE PTR [rax],al
 6c2:	00 00                	add    BYTE PTR [rax],al
 6c4:	00 00                	add    BYTE PTR [rax],al
 6c6:	00 00                	add    BYTE PTR [rax],al
 6c8:	50                   	push   rax
 6c9:	40 00 00             	rex add BYTE PTR [rax],al
 6cc:	00 00                	add    BYTE PTR [rax],al
 6ce:	00 00                	add    BYTE PTR [rax],al
 6d0:	c0 3f 00             	sar    BYTE PTR [rdi],0x0
 6d3:	00 00                	add    BYTE PTR [rax],al
 6d5:	00 00                	add    BYTE PTR [rax],al
 6d7:	00 06                	add    BYTE PTR [rsi],al
 6d9:	00 00                	add    BYTE PTR [rax],al
 6db:	00 01                	add    BYTE PTR [rcx],al
	...
 6e5:	00 00                	add    BYTE PTR [rax],al
 6e7:	00 c8                	add    al,cl
 6e9:	3f                   	(bad)
 6ea:	00 00                	add    BYTE PTR [rax],al
 6ec:	00 00                	add    BYTE PTR [rax],al
 6ee:	00 00                	add    BYTE PTR [rax],al
 6f0:	06                   	(bad)
 6f1:	00 00                	add    BYTE PTR [rax],al
 6f3:	00 02                	add    BYTE PTR [rdx],al
	...
 6fd:	00 00                	add    BYTE PTR [rax],al
 6ff:	00 d0                	add    al,dl
 701:	3f                   	(bad)
 702:	00 00                	add    BYTE PTR [rax],al
 704:	00 00                	add    BYTE PTR [rax],al
 706:	00 00                	add    BYTE PTR [rax],al
 708:	06                   	(bad)
 709:	00 00                	add    BYTE PTR [rax],al
 70b:	00 08                	add    BYTE PTR [rax],cl
	...
 715:	00 00                	add    BYTE PTR [rax],al
 717:	00 d8                	add    al,bl
 719:	3f                   	(bad)
 71a:	00 00                	add    BYTE PTR [rax],al
 71c:	00 00                	add    BYTE PTR [rax],al
 71e:	00 00                	add    BYTE PTR [rax],al
 720:	06                   	(bad)
 721:	00 00                	add    BYTE PTR [rax],al
 723:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
	...
 72e:	00 00                	add    BYTE PTR [rax],al
 730:	e0 3f                	loopne 771 <__abi_tag+0x3f5>
 732:	00 00                	add    BYTE PTR [rax],al
 734:	00 00                	add    BYTE PTR [rax],al
 736:	00 00                	add    BYTE PTR [rax],al
 738:	06                   	(bad)
 739:	00 00                	add    BYTE PTR [rax],al
 73b:	00 0f                	add    BYTE PTR [rdi],cl
	...
 745:	00 00                	add    BYTE PTR [rax],al
 747:	00 60 40             	add    BYTE PTR [rax+0x40],ah
 74a:	00 00                	add    BYTE PTR [rax],al
 74c:	00 00                	add    BYTE PTR [rax],al
 74e:	00 00                	add    BYTE PTR [rax],al
 750:	05 00 00 00 0e       	add    eax,0xe000000
	...
 75d:	00 00                	add    BYTE PTR [rax],al
 75f:	00 70 40             	add    BYTE PTR [rax+0x40],dh
 762:	00 00                	add    BYTE PTR [rax],al
 764:	00 00                	add    BYTE PTR [rax],al
 766:	00 00                	add    BYTE PTR [rax],al
 768:	05 00 00 00 10       	add    eax,0x10000000
	...

Disassembly of section .rela.plt:

0000000000000778 <.rela.plt>:
 778:	00 40 00             	add    BYTE PTR [rax+0x0],al
 77b:	00 00                	add    BYTE PTR [rax],al
 77d:	00 00                	add    BYTE PTR [rax],al
 77f:	00 07                	add    BYTE PTR [rdi],al
 781:	00 00                	add    BYTE PTR [rax],al
 783:	00 03                	add    BYTE PTR [rbx],al
	...
 78d:	00 00                	add    BYTE PTR [rax],al
 78f:	00 08                	add    BYTE PTR [rax],cl
 791:	40 00 00             	rex add BYTE PTR [rax],al
 794:	00 00                	add    BYTE PTR [rax],al
 796:	00 00                	add    BYTE PTR [rax],al
 798:	07                   	(bad)
 799:	00 00                	add    BYTE PTR [rax],al
 79b:	00 04 00             	add    BYTE PTR [rax+rax*1],al
	...
 7a6:	00 00                	add    BYTE PTR [rax],al
 7a8:	10 40 00             	adc    BYTE PTR [rax+0x0],al
 7ab:	00 00                	add    BYTE PTR [rax],al
 7ad:	00 00                	add    BYTE PTR [rax],al
 7af:	00 07                	add    BYTE PTR [rdi],al
 7b1:	00 00                	add    BYTE PTR [rax],al
 7b3:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 7b9 <__abi_tag+0x43d>
 7b9:	00 00                	add    BYTE PTR [rax],al
 7bb:	00 00                	add    BYTE PTR [rax],al
 7bd:	00 00                	add    BYTE PTR [rax],al
 7bf:	00 18                	add    BYTE PTR [rax],bl
 7c1:	40 00 00             	rex add BYTE PTR [rax],al
 7c4:	00 00                	add    BYTE PTR [rax],al
 7c6:	00 00                	add    BYTE PTR [rax],al
 7c8:	07                   	(bad)
 7c9:	00 00                	add    BYTE PTR [rax],al
 7cb:	00 06                	add    BYTE PTR [rsi],al
	...
 7d5:	00 00                	add    BYTE PTR [rax],al
 7d7:	00 20                	add    BYTE PTR [rax],ah
 7d9:	40 00 00             	rex add BYTE PTR [rax],al
 7dc:	00 00                	add    BYTE PTR [rax],al
 7de:	00 00                	add    BYTE PTR [rax],al
 7e0:	07                   	(bad)
 7e1:	00 00                	add    BYTE PTR [rax],al
 7e3:	00 07                	add    BYTE PTR [rdi],al
	...
 7ed:	00 00                	add    BYTE PTR [rax],al
 7ef:	00 28                	add    BYTE PTR [rax],ch
 7f1:	40 00 00             	rex add BYTE PTR [rax],al
 7f4:	00 00                	add    BYTE PTR [rax],al
 7f6:	00 00                	add    BYTE PTR [rax],al
 7f8:	07                   	(bad)
 7f9:	00 00                	add    BYTE PTR [rax],al
 7fb:	00 09                	add    BYTE PTR [rcx],cl
	...
 805:	00 00                	add    BYTE PTR [rax],al
 807:	00 30                	add    BYTE PTR [rax],dh
 809:	40 00 00             	rex add BYTE PTR [rax],al
 80c:	00 00                	add    BYTE PTR [rax],al
 80e:	00 00                	add    BYTE PTR [rax],al
 810:	07                   	(bad)
 811:	00 00                	add    BYTE PTR [rax],al
 813:	00 0a                	add    BYTE PTR [rdx],cl
	...
 81d:	00 00                	add    BYTE PTR [rax],al
 81f:	00 38                	add    BYTE PTR [rax],bh
 821:	40 00 00             	rex add BYTE PTR [rax],al
 824:	00 00                	add    BYTE PTR [rax],al
 826:	00 00                	add    BYTE PTR [rax],al
 828:	07                   	(bad)
 829:	00 00                	add    BYTE PTR [rax],al
 82b:	00 0b                	add    BYTE PTR [rbx],cl
	...
 835:	00 00                	add    BYTE PTR [rax],al
 837:	00 40 40             	add    BYTE PTR [rax+0x40],al
 83a:	00 00                	add    BYTE PTR [rax],al
 83c:	00 00                	add    BYTE PTR [rax],al
 83e:	00 00                	add    BYTE PTR [rax],al
 840:	07                   	(bad)
 841:	00 00                	add    BYTE PTR [rax],al
 843:	00 0d 00 00 00 00    	add    BYTE PTR [rip+0x0],cl        # 849 <__abi_tag+0x4cd>
 849:	00 00                	add    BYTE PTR [rax],al
 84b:	00 00                	add    BYTE PTR [rax],al
 84d:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init:

0000000000001000 <_init>:
    1000:	48 83 ec 08          	sub    rsp,0x8
    1004:	48 8b 05 c5 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fc5]        # 3fd0 <__gmon_start__@Base>
    100b:	48 85 c0             	test   rax,rax
    100e:	74 02                	je     1012 <_init+0x12>
    1010:	ff d0                	call   rax
    1012:	48 83 c4 08          	add    rsp,0x8
    1016:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <puts@plt-0x10>:
    1020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000001030 <puts@plt>:
    1030:	ff 25 ca 2f 00 00    	jmp    QWORD PTR [rip+0x2fca]        # 4000 <puts@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001040 <getpid@plt>:
    1040:	ff 25 c2 2f 00 00    	jmp    QWORD PTR [rip+0x2fc2]        # 4008 <getpid@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001050 <printf@plt>:
    1050:	ff 25 ba 2f 00 00    	jmp    QWORD PTR [rip+0x2fba]        # 4010 <printf@GLIBC_2.2.5>
    1056:	68 02 00 00 00       	push   0x2
    105b:	e9 c0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001060 <srand@plt>:
    1060:	ff 25 b2 2f 00 00    	jmp    QWORD PTR [rip+0x2fb2]        # 4018 <srand@GLIBC_2.2.5>
    1066:	68 03 00 00 00       	push   0x3
    106b:	e9 b0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001070 <fgets@plt>:
    1070:	ff 25 aa 2f 00 00    	jmp    QWORD PTR [rip+0x2faa]        # 4020 <fgets@GLIBC_2.2.5>
    1076:	68 04 00 00 00       	push   0x4
    107b:	e9 a0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001080 <strtol@plt>:
    1080:	ff 25 a2 2f 00 00    	jmp    QWORD PTR [rip+0x2fa2]        # 4028 <strtol@GLIBC_2.2.5>
    1086:	68 05 00 00 00       	push   0x5
    108b:	e9 90 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001090 <time@plt>:
    1090:	ff 25 9a 2f 00 00    	jmp    QWORD PTR [rip+0x2f9a]        # 4030 <time@GLIBC_2.2.5>
    1096:	68 06 00 00 00       	push   0x6
    109b:	e9 80 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010a0 <setvbuf@plt>:
    10a0:	ff 25 92 2f 00 00    	jmp    QWORD PTR [rip+0x2f92]        # 4038 <setvbuf@GLIBC_2.2.5>
    10a6:	68 07 00 00 00       	push   0x7
    10ab:	e9 70 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010b0 <rand@plt>:
    10b0:	ff 25 8a 2f 00 00    	jmp    QWORD PTR [rip+0x2f8a]        # 4040 <rand@GLIBC_2.2.5>
    10b6:	68 08 00 00 00       	push   0x8
    10bb:	e9 60 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .plt.got:

00000000000010c0 <__cxa_finalize@plt>:
    10c0:	ff 25 1a 2f 00 00    	jmp    QWORD PTR [rip+0x2f1a]        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c6:	66 90                	xchg   ax,ax

Disassembly of section .text:

00000000000010d0 <_start>:
    10d0:	31 ed                	xor    ebp,ebp
    10d2:	49 89 d1             	mov    r9,rdx
    10d5:	5e                   	pop    rsi
    10d6:	48 89 e2             	mov    rdx,rsp
    10d9:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    10dd:	50                   	push   rax
    10de:	54                   	push   rsp
    10df:	45 31 c0             	xor    r8d,r8d
    10e2:	31 c9                	xor    ecx,ecx
    10e4:	48 8d 3d ce 00 00 00 	lea    rdi,[rip+0xce]        # 11b9 <main>
    10eb:	ff 15 cf 2e 00 00    	call   QWORD PTR [rip+0x2ecf]        # 3fc0 <__libc_start_main@GLIBC_2.34>
    10f1:	f4                   	hlt
    10f2:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    10f9:	00 00 00 
    10fc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000001100 <deregister_tm_clones>:
    1100:	48 8d 3d 51 2f 00 00 	lea    rdi,[rip+0x2f51]        # 4058 <__TMC_END__>
    1107:	48 8d 05 4a 2f 00 00 	lea    rax,[rip+0x2f4a]        # 4058 <__TMC_END__>
    110e:	48 39 f8             	cmp    rax,rdi
    1111:	74 15                	je     1128 <deregister_tm_clones+0x28>
    1113:	48 8b 05 ae 2e 00 00 	mov    rax,QWORD PTR [rip+0x2eae]        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    111a:	48 85 c0             	test   rax,rax
    111d:	74 09                	je     1128 <deregister_tm_clones+0x28>
    111f:	ff e0                	jmp    rax
    1121:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1128:	c3                   	ret
    1129:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001130 <register_tm_clones>:
    1130:	48 8d 3d 21 2f 00 00 	lea    rdi,[rip+0x2f21]        # 4058 <__TMC_END__>
    1137:	48 8d 35 1a 2f 00 00 	lea    rsi,[rip+0x2f1a]        # 4058 <__TMC_END__>
    113e:	48 29 fe             	sub    rsi,rdi
    1141:	48 89 f0             	mov    rax,rsi
    1144:	48 c1 ee 3f          	shr    rsi,0x3f
    1148:	48 c1 f8 03          	sar    rax,0x3
    114c:	48 01 c6             	add    rsi,rax
    114f:	48 d1 fe             	sar    rsi,1
    1152:	74 14                	je     1168 <register_tm_clones+0x38>
    1154:	48 8b 05 7d 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e7d]        # 3fd8 <_ITM_registerTMCloneTable@Base>
    115b:	48 85 c0             	test   rax,rax
    115e:	74 08                	je     1168 <register_tm_clones+0x38>
    1160:	ff e0                	jmp    rax
    1162:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1168:	c3                   	ret
    1169:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001170 <__do_global_dtors_aux>:
    1170:	f3 0f 1e fa          	endbr64
    1174:	80 3d fd 2e 00 00 00 	cmp    BYTE PTR [rip+0x2efd],0x0        # 4078 <completed.0>
    117b:	75 2b                	jne    11a8 <__do_global_dtors_aux+0x38>
    117d:	55                   	push   rbp
    117e:	48 83 3d 5a 2e 00 00 	cmp    QWORD PTR [rip+0x2e5a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1185:	00 
    1186:	48 89 e5             	mov    rbp,rsp
    1189:	74 0c                	je     1197 <__do_global_dtors_aux+0x27>
    118b:	48 8b 3d be 2e 00 00 	mov    rdi,QWORD PTR [rip+0x2ebe]        # 4050 <__dso_handle>
    1192:	e8 29 ff ff ff       	call   10c0 <__cxa_finalize@plt>
    1197:	e8 64 ff ff ff       	call   1100 <deregister_tm_clones>
    119c:	c6 05 d5 2e 00 00 01 	mov    BYTE PTR [rip+0x2ed5],0x1        # 4078 <completed.0>
    11a3:	5d                   	pop    rbp
    11a4:	c3                   	ret
    11a5:	0f 1f 00             	nop    DWORD PTR [rax]
    11a8:	c3                   	ret
    11a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000011b0 <frame_dummy>:
    11b0:	f3 0f 1e fa          	endbr64
    11b4:	e9 77 ff ff ff       	jmp    1130 <register_tm_clones>

00000000000011b9 <main>:
    11b9:	55                   	push   rbp
    11ba:	48 89 e5             	mov    rbp,rsp
    11bd:	53                   	push   rbx
    11be:	48 83 ec 28          	sub    rsp,0x28
    11c2:	48 8b 05 97 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e97]        # 4060 <stdout@GLIBC_2.2.5>
    11c9:	b9 00 00 00 00       	mov    ecx,0x0
    11ce:	ba 02 00 00 00       	mov    edx,0x2
    11d3:	be 00 00 00 00       	mov    esi,0x0
    11d8:	48 89 c7             	mov    rdi,rax
    11db:	e8 c0 fe ff ff       	call   10a0 <setvbuf@plt>
    11e0:	bf 00 00 00 00       	mov    edi,0x0
    11e5:	e8 a6 fe ff ff       	call   1090 <time@plt>
    11ea:	89 c3                	mov    ebx,eax
    11ec:	e8 4f fe ff ff       	call   1040 <getpid@plt>
    11f1:	31 d8                	xor    eax,ebx
    11f3:	89 c7                	mov    edi,eax
    11f5:	e8 66 fe ff ff       	call   1060 <srand@plt>
    11fa:	e8 b1 fe ff ff       	call   10b0 <rand@plt>
    11ff:	48 63 d0             	movsxd rdx,eax
    1202:	48 69 d2 ad 8b db 68 	imul   rdx,rdx,0x68db8bad
    1209:	48 c1 ea 20          	shr    rdx,0x20
    120d:	c1 fa 0c             	sar    edx,0xc
    1210:	89 c1                	mov    ecx,eax
    1212:	c1 f9 1f             	sar    ecx,0x1f
    1215:	29 ca                	sub    edx,ecx
    1217:	89 55 ec             	mov    DWORD PTR [rbp-0x14],edx
    121a:	8b 55 ec             	mov    edx,DWORD PTR [rbp-0x14]
    121d:	69 d2 10 27 00 00    	imul   edx,edx,0x2710
    1223:	29 d0                	sub    eax,edx
    1225:	89 45 ec             	mov    DWORD PTR [rbp-0x14],eax
    1228:	48 8d 05 d5 0d 00 00 	lea    rax,[rip+0xdd5]        # 2004 <_IO_stdin_used+0x4>
    122f:	48 89 c7             	mov    rdi,rax
    1232:	b8 00 00 00 00       	mov    eax,0x0
    1237:	e8 14 fe ff ff       	call   1050 <printf@plt>
    123c:	48 8b 15 2d 2e 00 00 	mov    rdx,QWORD PTR [rip+0x2e2d]        # 4070 <stdin@GLIBC_2.2.5>
    1243:	48 8d 45 d0          	lea    rax,[rbp-0x30]
    1247:	be 20 00 00 00       	mov    esi,0x20
    124c:	48 89 c7             	mov    rdi,rax
    124f:	e8 1c fe ff ff       	call   1070 <fgets@plt>
    1254:	48 85 c0             	test   rax,rax
    1257:	74 5a                	je     12b3 <main+0xfa>
    1259:	48 8d 45 d0          	lea    rax,[rbp-0x30]
    125d:	ba 00 00 00 00       	mov    edx,0x0
    1262:	be 00 00 00 00       	mov    esi,0x0
    1267:	48 89 c7             	mov    rdi,rax
    126a:	e8 11 fe ff ff       	call   1080 <strtol@plt>
    126f:	89 45 e8             	mov    DWORD PTR [rbp-0x18],eax
    1272:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
    1275:	89 c6                	mov    esi,eax
    1277:	48 8d 05 99 0d 00 00 	lea    rax,[rip+0xd99]        # 2017 <_IO_stdin_used+0x17>
    127e:	48 89 c7             	mov    rdi,rax
    1281:	b8 00 00 00 00       	mov    eax,0x0
    1286:	e8 c5 fd ff ff       	call   1050 <printf@plt>
    128b:	8b 45 e8             	mov    eax,DWORD PTR [rbp-0x18]
    128e:	3b 45 ec             	cmp    eax,DWORD PTR [rbp-0x14]
    1291:	75 11                	jne    12a4 <main+0xeb>
    1293:	48 8d 05 8f 0d 00 00 	lea    rax,[rip+0xd8f]        # 2029 <_IO_stdin_used+0x29>
    129a:	48 89 c7             	mov    rdi,rax
    129d:	e8 8e fd ff ff       	call   1030 <puts@plt>
    12a2:	eb 0f                	jmp    12b3 <main+0xfa>
    12a4:	48 8d 05 85 0d 00 00 	lea    rax,[rip+0xd85]        # 2030 <_IO_stdin_used+0x30>
    12ab:	48 89 c7             	mov    rdi,rax
    12ae:	e8 7d fd ff ff       	call   1030 <puts@plt>
    12b3:	b8 00 00 00 00       	mov    eax,0x0
    12b8:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
    12bc:	c9                   	leave
    12bd:	c3                   	ret

Disassembly of section .fini:

00000000000012c0 <_fini>:
    12c0:	48 83 ec 08          	sub    rsp,0x8
    12c4:	48 83 c4 08          	add    rsp,0x8
    12c8:	c3                   	ret

Disassembly of section .rodata:

0000000000002000 <_IO_stdin_used>:
    2000:	01 00                	add    DWORD PTR [rax],eax
    2002:	02 00                	add    al,BYTE PTR [rax]
    2004:	47 75 65             	rex.RXB jne 206c <__GNU_EH_FRAME_HDR+0x2c>
    2007:	73 73                	jae    207c <__GNU_EH_FRAME_HDR+0x3c>
    2009:	20 74 68 65          	and    BYTE PTR [rax+rbp*2+0x65],dh
    200d:	20 6e 75             	and    BYTE PTR [rsi+0x75],ch
    2010:	6d                   	ins    DWORD PTR es:[rdi],dx
    2011:	62 65                	(bad)
    2013:	72 3a                	jb     204f <__GNU_EH_FRAME_HDR+0xf>
    2015:	20 00                	and    BYTE PTR [rax],al
    2017:	59                   	pop    rcx
    2018:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    2019:	75 72                	jne    208d <__GNU_EH_FRAME_HDR+0x4d>
    201b:	20 67 75             	and    BYTE PTR [rdi+0x75],ah
    201e:	65 73 73             	gs jae 2094 <__GNU_EH_FRAME_HDR+0x54>
    2021:	20 69 73             	and    BYTE PTR [rcx+0x73],ch
    2024:	20 25 64 0a 00 42    	and    BYTE PTR [rip+0x42000a64],ah        # 42002a8e <_end+0x41ffea0e>
    202a:	69 6e 67 6f 21 00 4e 	imul   ebp,DWORD PTR [rsi+0x67],0x4e00216f
    2031:	6f                   	outs   dx,DWORD PTR ds:[rsi]
    2032:	20 6e 6f             	and    BYTE PTR [rsi+0x6f],ch
    2035:	20 6e 6f             	and    BYTE PTR [rsi+0x6f],ch
    2038:	20 2e                	and    BYTE PTR [rsi],ch
    203a:	2e                   	cs
    203b:	2e                   	cs
	...

Disassembly of section .eh_frame_hdr:

0000000000002040 <__GNU_EH_FRAME_HDR>:
    2040:	01 1b                	add    DWORD PTR [rbx],ebx
    2042:	03 3b                	add    edi,DWORD PTR [rbx]
    2044:	2c 00                	sub    al,0x0
    2046:	00 00                	add    BYTE PTR [rax],al
    2048:	04 00                	add    al,0x0
    204a:	00 00                	add    BYTE PTR [rax],al
    204c:	e0 ef                	loopne 203d <_IO_stdin_used+0x3d>
    204e:	ff                   	(bad)
    204f:	ff                   	(bad)
    2050:	78 00                	js     2052 <__GNU_EH_FRAME_HDR+0x12>
    2052:	00 00                	add    BYTE PTR [rax],al
    2054:	80 f0 ff             	xor    al,0xff
    2057:	ff a0 00 00 00 90    	jmp    QWORD PTR [rax-0x70000000]
    205d:	f0 ff                	lock (bad)
    205f:	ff 48 00             	dec    DWORD PTR [rax+0x0]
    2062:	00 00                	add    BYTE PTR [rax],al
    2064:	79 f1                	jns    2057 <__GNU_EH_FRAME_HDR+0x17>
    2066:	ff                   	(bad)
    2067:	ff                   	(bad)
    2068:	b8                   	.byte 0xb8
    2069:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .eh_frame:

0000000000002070 <__FRAME_END__-0xac>:
    2070:	14 00                	adc    al,0x0
    2072:	00 00                	add    BYTE PTR [rax],al
    2074:	00 00                	add    BYTE PTR [rax],al
    2076:	00 00                	add    BYTE PTR [rax],al
    2078:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
    207b:	00 01                	add    BYTE PTR [rcx],al
    207d:	78 10                	js     208f <__GNU_EH_FRAME_HDR+0x4f>
    207f:	01 1b                	add    DWORD PTR [rbx],ebx
    2081:	0c 07                	or     al,0x7
    2083:	08 90 01 07 10 14    	or     BYTE PTR [rax+0x14100701],dl
    2089:	00 00                	add    BYTE PTR [rax],al
    208b:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
    208e:	00 00                	add    BYTE PTR [rax],al
    2090:	40                   	rex
    2091:	f0 ff                	lock (bad)
    2093:	ff 22                	jmp    QWORD PTR [rdx]
	...
    209d:	00 00                	add    BYTE PTR [rax],al
    209f:	00 14 00             	add    BYTE PTR [rax+rax*1],dl
    20a2:	00 00                	add    BYTE PTR [rax],al
    20a4:	00 00                	add    BYTE PTR [rax],al
    20a6:	00 00                	add    BYTE PTR [rax],al
    20a8:	01 7a 52             	add    DWORD PTR [rdx+0x52],edi
    20ab:	00 01                	add    BYTE PTR [rcx],al
    20ad:	78 10                	js     20bf <__GNU_EH_FRAME_HDR+0x7f>
    20af:	01 1b                	add    DWORD PTR [rbx],ebx
    20b1:	0c 07                	or     al,0x7
    20b3:	08 90 01 00 00 24    	or     BYTE PTR [rax+0x24000001],dl
    20b9:	00 00                	add    BYTE PTR [rax],al
    20bb:	00 1c 00             	add    BYTE PTR [rax+rax*1],bl
    20be:	00 00                	add    BYTE PTR [rax],al
    20c0:	60                   	(bad)
    20c1:	ef                   	out    dx,eax
    20c2:	ff                   	(bad)
    20c3:	ff a0 00 00 00 00    	jmp    QWORD PTR [rax+0x0]
    20c9:	0e                   	(bad)
    20ca:	10 46 0e             	adc    BYTE PTR [rsi+0xe],al
    20cd:	18 4a 0f             	sbb    BYTE PTR [rdx+0xf],cl
    20d0:	0b 77 08             	or     esi,DWORD PTR [rdi+0x8]
    20d3:	80 00 3f             	add    BYTE PTR [rax],0x3f
    20d6:	1a 3b                	sbb    bh,BYTE PTR [rbx]
    20d8:	2a 33                	sub    dh,BYTE PTR [rbx]
    20da:	24 22                	and    al,0x22
    20dc:	00 00                	add    BYTE PTR [rax],al
    20de:	00 00                	add    BYTE PTR [rax],al
    20e0:	14 00                	adc    al,0x0
    20e2:	00 00                	add    BYTE PTR [rax],al
    20e4:	44 00 00             	add    BYTE PTR [rax],r8b
    20e7:	00 d8                	add    al,bl
    20e9:	ef                   	out    dx,eax
    20ea:	ff                   	(bad)
    20eb:	ff 08                	dec    DWORD PTR [rax]
	...
    20f5:	00 00                	add    BYTE PTR [rax],al
    20f7:	00 20                	add    BYTE PTR [rax],ah
    20f9:	00 00                	add    BYTE PTR [rax],al
    20fb:	00 5c 00 00          	add    BYTE PTR [rax+rax*1+0x0],bl
    20ff:	00 b9 f0 ff ff 05    	add    BYTE PTR [rcx+0x5fffff0],bh
    2105:	01 00                	add    DWORD PTR [rax],eax
    2107:	00 00                	add    BYTE PTR [rax],al
    2109:	41 0e                	rex.B (bad)
    210b:	10 86 02 43 0d 06    	adc    BYTE PTR [rsi+0x60d4302],al
    2111:	45 83 03 02          	rex.RB add DWORD PTR [r11],0x2
    2115:	fb                   	sti
    2116:	0c 07                	or     al,0x7
    2118:	08 00                	or     BYTE PTR [rax],al
	...

000000000000211c <__FRAME_END__>:
    211c:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .init_array:

0000000000003dd0 <__frame_dummy_init_array_entry>:
    3dd0:	b0 11                	mov    al,0x11
    3dd2:	00 00                	add    BYTE PTR [rax],al
    3dd4:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .fini_array:

0000000000003dd8 <__do_global_dtors_aux_fini_array_entry>:
    3dd8:	70 11                	jo     3deb <_DYNAMIC+0xb>
    3dda:	00 00                	add    BYTE PTR [rax],al
    3ddc:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .dynamic:

0000000000003de0 <_DYNAMIC>:
    3de0:	01 00                	add    DWORD PTR [rax],eax
    3de2:	00 00                	add    BYTE PTR [rax],al
    3de4:	00 00                	add    BYTE PTR [rax],al
    3de6:	00 00                	add    BYTE PTR [rax],al
    3de8:	62                   	(bad)
    3de9:	00 00                	add    BYTE PTR [rax],al
    3deb:	00 00                	add    BYTE PTR [rax],al
    3ded:	00 00                	add    BYTE PTR [rax],al
    3def:	00 0c 00             	add    BYTE PTR [rax+rax*1],cl
    3df2:	00 00                	add    BYTE PTR [rax],al
    3df4:	00 00                	add    BYTE PTR [rax],al
    3df6:	00 00                	add    BYTE PTR [rax],al
    3df8:	00 10                	add    BYTE PTR [rax],dl
    3dfa:	00 00                	add    BYTE PTR [rax],al
    3dfc:	00 00                	add    BYTE PTR [rax],al
    3dfe:	00 00                	add    BYTE PTR [rax],al
    3e00:	0d 00 00 00 00       	or     eax,0x0
    3e05:	00 00                	add    BYTE PTR [rax],al
    3e07:	00 c0                	add    al,al
    3e09:	12 00                	adc    al,BYTE PTR [rax]
    3e0b:	00 00                	add    BYTE PTR [rax],al
    3e0d:	00 00                	add    BYTE PTR [rax],al
    3e0f:	00 19                	add    BYTE PTR [rcx],bl
    3e11:	00 00                	add    BYTE PTR [rax],al
    3e13:	00 00                	add    BYTE PTR [rax],al
    3e15:	00 00                	add    BYTE PTR [rax],al
    3e17:	00 d0                	add    al,dl
    3e19:	3d 00 00 00 00       	cmp    eax,0x0
    3e1e:	00 00                	add    BYTE PTR [rax],al
    3e20:	1b 00                	sbb    eax,DWORD PTR [rax]
    3e22:	00 00                	add    BYTE PTR [rax],al
    3e24:	00 00                	add    BYTE PTR [rax],al
    3e26:	00 00                	add    BYTE PTR [rax],al
    3e28:	08 00                	or     BYTE PTR [rax],al
    3e2a:	00 00                	add    BYTE PTR [rax],al
    3e2c:	00 00                	add    BYTE PTR [rax],al
    3e2e:	00 00                	add    BYTE PTR [rax],al
    3e30:	1a 00                	sbb    al,BYTE PTR [rax]
    3e32:	00 00                	add    BYTE PTR [rax],al
    3e34:	00 00                	add    BYTE PTR [rax],al
    3e36:	00 00                	add    BYTE PTR [rax],al
    3e38:	d8 3d 00 00 00 00    	fdivr  DWORD PTR [rip+0x0]        # 3e3e <_DYNAMIC+0x5e>
    3e3e:	00 00                	add    BYTE PTR [rax],al
    3e40:	1c 00                	sbb    al,0x0
    3e42:	00 00                	add    BYTE PTR [rax],al
    3e44:	00 00                	add    BYTE PTR [rax],al
    3e46:	00 00                	add    BYTE PTR [rax],al
    3e48:	08 00                	or     BYTE PTR [rax],al
    3e4a:	00 00                	add    BYTE PTR [rax],al
    3e4c:	00 00                	add    BYTE PTR [rax],al
    3e4e:	00 00                	add    BYTE PTR [rax],al
    3e50:	f5                   	cmc
    3e51:	fe                   	(bad)
    3e52:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3e55:	00 00                	add    BYTE PTR [rax],al
    3e57:	00 a0 03 00 00 00    	add    BYTE PTR [rax+0x3],ah
    3e5d:	00 00                	add    BYTE PTR [rax],al
    3e5f:	00 05 00 00 00 00    	add    BYTE PTR [rip+0x0],al        # 3e65 <_DYNAMIC+0x85>
    3e65:	00 00                	add    BYTE PTR [rax],al
    3e67:	00 68 05             	add    BYTE PTR [rax+0x5],ch
    3e6a:	00 00                	add    BYTE PTR [rax],al
    3e6c:	00 00                	add    BYTE PTR [rax],al
    3e6e:	00 00                	add    BYTE PTR [rax],al
    3e70:	06                   	(bad)
    3e71:	00 00                	add    BYTE PTR [rax],al
    3e73:	00 00                	add    BYTE PTR [rax],al
    3e75:	00 00                	add    BYTE PTR [rax],al
    3e77:	00 d0                	add    al,dl
    3e79:	03 00                	add    eax,DWORD PTR [rax]
    3e7b:	00 00                	add    BYTE PTR [rax],al
    3e7d:	00 00                	add    BYTE PTR [rax],al
    3e7f:	00 0a                	add    BYTE PTR [rdx],cl
    3e81:	00 00                	add    BYTE PTR [rax],al
    3e83:	00 00                	add    BYTE PTR [rax],al
    3e85:	00 00                	add    BYTE PTR [rax],al
    3e87:	00 c8                	add    al,cl
    3e89:	00 00                	add    BYTE PTR [rax],al
    3e8b:	00 00                	add    BYTE PTR [rax],al
    3e8d:	00 00                	add    BYTE PTR [rax],al
    3e8f:	00 0b                	add    BYTE PTR [rbx],cl
    3e91:	00 00                	add    BYTE PTR [rax],al
    3e93:	00 00                	add    BYTE PTR [rax],al
    3e95:	00 00                	add    BYTE PTR [rax],al
    3e97:	00 18                	add    BYTE PTR [rax],bl
    3e99:	00 00                	add    BYTE PTR [rax],al
    3e9b:	00 00                	add    BYTE PTR [rax],al
    3e9d:	00 00                	add    BYTE PTR [rax],al
    3e9f:	00 15 00 00 00 00    	add    BYTE PTR [rip+0x0],dl        # 3ea5 <_DYNAMIC+0xc5>
	...
    3ead:	00 00                	add    BYTE PTR [rax],al
    3eaf:	00 03                	add    BYTE PTR [rbx],al
    3eb1:	00 00                	add    BYTE PTR [rax],al
    3eb3:	00 00                	add    BYTE PTR [rax],al
    3eb5:	00 00                	add    BYTE PTR [rax],al
    3eb7:	00 e8                	add    al,ch
    3eb9:	3f                   	(bad)
    3eba:	00 00                	add    BYTE PTR [rax],al
    3ebc:	00 00                	add    BYTE PTR [rax],al
    3ebe:	00 00                	add    BYTE PTR [rax],al
    3ec0:	02 00                	add    al,BYTE PTR [rax]
    3ec2:	00 00                	add    BYTE PTR [rax],al
    3ec4:	00 00                	add    BYTE PTR [rax],al
    3ec6:	00 00                	add    BYTE PTR [rax],al
    3ec8:	d8 00                	fadd   DWORD PTR [rax]
    3eca:	00 00                	add    BYTE PTR [rax],al
    3ecc:	00 00                	add    BYTE PTR [rax],al
    3ece:	00 00                	add    BYTE PTR [rax],al
    3ed0:	14 00                	adc    al,0x0
    3ed2:	00 00                	add    BYTE PTR [rax],al
    3ed4:	00 00                	add    BYTE PTR [rax],al
    3ed6:	00 00                	add    BYTE PTR [rax],al
    3ed8:	07                   	(bad)
    3ed9:	00 00                	add    BYTE PTR [rax],al
    3edb:	00 00                	add    BYTE PTR [rax],al
    3edd:	00 00                	add    BYTE PTR [rax],al
    3edf:	00 17                	add    BYTE PTR [rdi],dl
    3ee1:	00 00                	add    BYTE PTR [rax],al
    3ee3:	00 00                	add    BYTE PTR [rax],al
    3ee5:	00 00                	add    BYTE PTR [rax],al
    3ee7:	00 78 07             	add    BYTE PTR [rax+0x7],bh
    3eea:	00 00                	add    BYTE PTR [rax],al
    3eec:	00 00                	add    BYTE PTR [rax],al
    3eee:	00 00                	add    BYTE PTR [rax],al
    3ef0:	07                   	(bad)
    3ef1:	00 00                	add    BYTE PTR [rax],al
    3ef3:	00 00                	add    BYTE PTR [rax],al
    3ef5:	00 00                	add    BYTE PTR [rax],al
    3ef7:	00 88 06 00 00 00    	add    BYTE PTR [rax+0x6],cl
    3efd:	00 00                	add    BYTE PTR [rax],al
    3eff:	00 08                	add    BYTE PTR [rax],cl
    3f01:	00 00                	add    BYTE PTR [rax],al
    3f03:	00 00                	add    BYTE PTR [rax],al
    3f05:	00 00                	add    BYTE PTR [rax],al
    3f07:	00 f0                	add    al,dh
    3f09:	00 00                	add    BYTE PTR [rax],al
    3f0b:	00 00                	add    BYTE PTR [rax],al
    3f0d:	00 00                	add    BYTE PTR [rax],al
    3f0f:	00 09                	add    BYTE PTR [rcx],cl
    3f11:	00 00                	add    BYTE PTR [rax],al
    3f13:	00 00                	add    BYTE PTR [rax],al
    3f15:	00 00                	add    BYTE PTR [rax],al
    3f17:	00 18                	add    BYTE PTR [rax],bl
    3f19:	00 00                	add    BYTE PTR [rax],al
    3f1b:	00 00                	add    BYTE PTR [rax],al
    3f1d:	00 00                	add    BYTE PTR [rax],al
    3f1f:	00 fb                	add    bl,bh
    3f21:	ff                   	(bad)
    3f22:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f25:	00 00                	add    BYTE PTR [rax],al
    3f27:	00 00                	add    BYTE PTR [rax],al
    3f29:	00 00                	add    BYTE PTR [rax],al
    3f2b:	08 00                	or     BYTE PTR [rax],al
    3f2d:	00 00                	add    BYTE PTR [rax],al
    3f2f:	00 fe                	add    dh,bh
    3f31:	ff                   	(bad)
    3f32:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f35:	00 00                	add    BYTE PTR [rax],al
    3f37:	00 58 06             	add    BYTE PTR [rax+0x6],bl
    3f3a:	00 00                	add    BYTE PTR [rax],al
    3f3c:	00 00                	add    BYTE PTR [rax],al
    3f3e:	00 00                	add    BYTE PTR [rax],al
    3f40:	ff                   	(bad)
    3f41:	ff                   	(bad)
    3f42:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f45:	00 00                	add    BYTE PTR [rax],al
    3f47:	00 01                	add    BYTE PTR [rcx],al
    3f49:	00 00                	add    BYTE PTR [rax],al
    3f4b:	00 00                	add    BYTE PTR [rax],al
    3f4d:	00 00                	add    BYTE PTR [rax],al
    3f4f:	00 f0                	add    al,dh
    3f51:	ff                   	(bad)
    3f52:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f55:	00 00                	add    BYTE PTR [rax],al
    3f57:	00 30                	add    BYTE PTR [rax],dh
    3f59:	06                   	(bad)
    3f5a:	00 00                	add    BYTE PTR [rax],al
    3f5c:	00 00                	add    BYTE PTR [rax],al
    3f5e:	00 00                	add    BYTE PTR [rax],al
    3f60:	f9                   	stc
    3f61:	ff                   	(bad)
    3f62:	ff 6f 00             	jmp    FWORD PTR [rdi+0x0]
    3f65:	00 00                	add    BYTE PTR [rax],al
    3f67:	00 03                	add    BYTE PTR [rbx],al
	...

Disassembly of section .got:

0000000000003fc0 <.got>:
	...

Disassembly of section .got.plt:

0000000000003fe8 <_GLOBAL_OFFSET_TABLE_>:
    3fe8:	e0 3d                	loopne 4027 <_GLOBAL_OFFSET_TABLE_+0x3f>
	...
    3ffe:	00 00                	add    BYTE PTR [rax],al
    4000:	36 10 00             	ss adc BYTE PTR [rax],al
    4003:	00 00                	add    BYTE PTR [rax],al
    4005:	00 00                	add    BYTE PTR [rax],al
    4007:	00 46 10             	add    BYTE PTR [rsi+0x10],al
    400a:	00 00                	add    BYTE PTR [rax],al
    400c:	00 00                	add    BYTE PTR [rax],al
    400e:	00 00                	add    BYTE PTR [rax],al
    4010:	56                   	push   rsi
    4011:	10 00                	adc    BYTE PTR [rax],al
    4013:	00 00                	add    BYTE PTR [rax],al
    4015:	00 00                	add    BYTE PTR [rax],al
    4017:	00 66 10             	add    BYTE PTR [rsi+0x10],ah
    401a:	00 00                	add    BYTE PTR [rax],al
    401c:	00 00                	add    BYTE PTR [rax],al
    401e:	00 00                	add    BYTE PTR [rax],al
    4020:	76 10                	jbe    4032 <_GLOBAL_OFFSET_TABLE_+0x4a>
    4022:	00 00                	add    BYTE PTR [rax],al
    4024:	00 00                	add    BYTE PTR [rax],al
    4026:	00 00                	add    BYTE PTR [rax],al
    4028:	86 10                	xchg   BYTE PTR [rax],dl
    402a:	00 00                	add    BYTE PTR [rax],al
    402c:	00 00                	add    BYTE PTR [rax],al
    402e:	00 00                	add    BYTE PTR [rax],al
    4030:	96                   	xchg   esi,eax
    4031:	10 00                	adc    BYTE PTR [rax],al
    4033:	00 00                	add    BYTE PTR [rax],al
    4035:	00 00                	add    BYTE PTR [rax],al
    4037:	00 a6 10 00 00 00    	add    BYTE PTR [rsi+0x10],ah
    403d:	00 00                	add    BYTE PTR [rax],al
    403f:	00 b6 10 00 00 00    	add    BYTE PTR [rsi+0x10],dh
    4045:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .data:

0000000000004048 <__data_start>:
	...

0000000000004050 <__dso_handle>:
    4050:	50                   	push   rax
    4051:	40 00 00             	rex add BYTE PTR [rax],al
    4054:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .bss:

0000000000004060 <stdout@GLIBC_2.2.5>:
	...

0000000000004070 <stdin@GLIBC_2.2.5>:
	...

0000000000004078 <completed.0>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp spl,BYTE PTR [r8]
   5:	28 44 65 62          	sub    BYTE PTR [rbp+riz*2+0x62],al
   9:	69 61 6e 20 31 32 2e 	imul   esp,DWORD PTR [rcx+0x6e],0x2e323120
  10:	32 2e                	xor    ch,BYTE PTR [rsi]
  12:	30 2d 31 34 29 20    	xor    BYTE PTR [rip+0x20293431],ch        # 20293449 <_end+0x2028f3c9>
  18:	31 32                	xor    DWORD PTR [rdx],esi
  1a:	2e 32 2e             	cs xor ch,BYTE PTR [rsi]
  1d:	30 00                	xor    BYTE PTR [rax],al

Disassembly of section .debug_aranges:

0000000000000000 <.debug_aranges>:
   0:	2c 00                	sub    al,0x0
   2:	00 00                	add    BYTE PTR [rax],al
   4:	02 00                	add    al,BYTE PTR [rax]
   6:	00 00                	add    BYTE PTR [rax],al
   8:	00 00                	add    BYTE PTR [rax],al
   a:	08 00                	or     BYTE PTR [rax],al
   c:	00 00                	add    BYTE PTR [rax],al
   e:	00 00                	add    BYTE PTR [rax],al
  10:	b9 11 00 00 00       	mov    ecx,0x11
  15:	00 00                	add    BYTE PTR [rax],al
  17:	00 05 01 00 00 00    	add    BYTE PTR [rip+0x1],al        # 1e <__abi_tag-0x35e>
	...

Disassembly of section .debug_info:

0000000000000000 <.debug_info>:
   0:	f7 03 00 00 05 00    	test   DWORD PTR [rbx],0x50000
   6:	01 08                	add    DWORD PTR [rax],ecx
   8:	00 00                	add    BYTE PTR [rax],al
   a:	00 00                	add    BYTE PTR [rax],al
   c:	0f 00 00             	sldt   WORD PTR [rax]
   f:	00 00                	add    BYTE PTR [rax],al
  11:	1d 00 00 00 00       	sbb    eax,0x0
  16:	08 00                	or     BYTE PTR [rax],al
  18:	00 00                	add    BYTE PTR [rax],al
  1a:	b9 11 00 00 00       	mov    ecx,0x11
  1f:	00 00                	add    BYTE PTR [rax],al
  21:	00 05 01 00 00 00    	add    BYTE PTR [rip+0x1],al        # 28 <__abi_tag-0x354>
  27:	00 00                	add    BYTE PTR [rax],al
  29:	00 00                	add    BYTE PTR [rax],al
  2b:	00 00                	add    BYTE PTR [rax],al
  2d:	00 05 81 00 00 00    	add    BYTE PTR [rip+0x81],al        # b4 <__abi_tag-0x2c8>
  33:	02 d6                	add    dl,dh
  35:	17                   	(bad)
  36:	3a 00                	cmp    al,BYTE PTR [rax]
  38:	00 00                	add    BYTE PTR [rax],al
  3a:	03 08                	add    ecx,DWORD PTR [rax]
  3c:	07                   	(bad)
  3d:	30 01                	xor    BYTE PTR [rcx],al
  3f:	00 00                	add    BYTE PTR [rax],al
  41:	03 04 07             	add    eax,DWORD PTR [rdi+rax*1]
  44:	35 01 00 00 10       	xor    eax,0x10000001
  49:	08 03                	or     BYTE PTR [rbx],al
  4b:	01 08                	add    DWORD PTR [rax],ecx
  4d:	1d 01 00 00 03       	sbb    eax,0x3000001
  52:	02 07                	add    al,BYTE PTR [rdi]
  54:	bf 01 00 00 03       	mov    edi,0x3000001
  59:	01 06                	add    DWORD PTR [rsi],eax
  5b:	1f                   	(bad)
  5c:	01 00                	add    DWORD PTR [rax],eax
  5e:	00 03                	add    BYTE PTR [rbx],al
  60:	02 05 77 00 00 00    	add    al,BYTE PTR [rip+0x77]        # dd <__abi_tag-0x29f>
  66:	11 04 05 69 6e 74 00 	adc    DWORD PTR [rax*1+0x746e69],eax
  6d:	03 08                	add    ecx,DWORD PTR [rax]
  6f:	05 e8 00 00 00       	add    eax,0xe8
  74:	05 0c 02 00 00       	add    eax,0x20c
  79:	03 98 19 6d 00 00    	add    ebx,DWORD PTR [rax+0x6d19]
  7f:	00 05 5e 01 00 00    	add    BYTE PTR [rip+0x15e],al        # 1e3 <__abi_tag-0x199>
  85:	03 99 1b 6d 00 00    	add    ebx,DWORD PTR [rcx+0x6d1b]
  8b:	00 05 88 00 00 00    	add    BYTE PTR [rip+0x88],al        # 119 <__abi_tag-0x263>
  91:	03 9a 19 66 00 00    	add    ebx,DWORD PTR [rdx+0x6619]
  97:	00 05 e0 01 00 00    	add    BYTE PTR [rip+0x1e0],al        # 27d <__abi_tag-0xff>
  9d:	03 a0 1a 6d 00 00    	add    esp,DWORD PTR [rax+0x6d1a]
  a3:	00 04 ae             	add    BYTE PTR [rsi+rbp*4],al
  a6:	00 00                	add    BYTE PTR [rax],al
  a8:	00 06                	add    BYTE PTR [rsi],al
  aa:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
  ab:	00 00                	add    BYTE PTR [rax],al
  ad:	00 03                	add    BYTE PTR [rbx],al
  af:	01 06                	add    DWORD PTR [rsi],eax
  b1:	26 01 00             	es add DWORD PTR [rax],eax
  b4:	00 12                	add    BYTE PTR [rdx],dl
  b6:	ae                   	scas   al,BYTE PTR es:[rdi]
  b7:	00 00                	add    BYTE PTR [rax],al
  b9:	00 13                	add    BYTE PTR [rbx],dl
  bb:	61                   	(bad)
  bc:	00 00                	add    BYTE PTR [rax],al
  be:	00 d8                	add    al,bl
  c0:	04 31                	add    al,0x31
  c2:	08 24 02             	or     BYTE PTR [rdx+rax*1],ah
  c5:	00 00                	add    BYTE PTR [rax],al
  c7:	01 9e 00 00 00 33    	add    DWORD PTR [rsi+0x33000000],ebx
  cd:	07                   	(bad)
  ce:	66 00 00             	data16 add BYTE PTR [rax],al
  d1:	00 00                	add    BYTE PTR [rax],al
  d3:	01 7c 01 00          	add    DWORD PTR [rcx+rax*1+0x0],edi
  d7:	00 36                	add    BYTE PTR [rsi],dh
  d9:	09 a4 00 00 00 08 01 	or     DWORD PTR [rax+rax*1+0x1080000],esp
  e0:	bb 00 00 00 37       	mov    ebx,0x37000000
  e5:	09 a4 00 00 00 10 01 	or     DWORD PTR [rax+rax*1+0x1100000],esp
  ec:	3e 02 00             	ds add al,BYTE PTR [rax]
  ef:	00 38                	add    BYTE PTR [rax],bh
  f1:	09 a4 00 00 00 18 01 	or     DWORD PTR [rax+rax*1+0x1180000],esp
  f8:	68 01 00 00 39       	push   0x39000001
  fd:	09 a4 00 00 00 20 01 	or     DWORD PTR [rax+rax*1+0x1200000],esp
 104:	90                   	nop
 105:	00 00                	add    BYTE PTR [rax],al
 107:	00 3a                	add    BYTE PTR [rdx],bh
 109:	09 a4 00 00 00 28 01 	or     DWORD PTR [rax+rax*1+0x1280000],esp
 110:	d2 01                	rol    BYTE PTR [rcx],cl
 112:	00 00                	add    BYTE PTR [rax],al
 114:	3b 09                	cmp    ecx,DWORD PTR [rcx]
 116:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 117:	00 00                	add    BYTE PTR [rax],al
 119:	00 30                	add    BYTE PTR [rax],dh
 11b:	01 a5 00 00 00 3c    	add    DWORD PTR [rbp+0x3c000000],esp
 121:	09 a4 00 00 00 38 01 	or     DWORD PTR [rax+rax*1+0x1380000],esp
 128:	89 01                	mov    DWORD PTR [rcx],eax
 12a:	00 00                	add    BYTE PTR [rax],al
 12c:	3d 09 a4 00 00       	cmp    eax,0xa409
 131:	00 40 01             	add    BYTE PTR [rax+0x1],al
 134:	5b                   	pop    rbx
 135:	02 00                	add    al,BYTE PTR [rax]
 137:	00 40 09             	add    BYTE PTR [rax+0x9],al
 13a:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 13b:	00 00                	add    BYTE PTR [rax],al
 13d:	00 48 01             	add    BYTE PTR [rax+0x1],cl
 140:	14 02                	adc    al,0x2
 142:	00 00                	add    BYTE PTR [rax],al
 144:	41 09 a4 00 00 00 50 	or     DWORD PTR [r8+rax*1+0x1500000],esp
 14b:	01 
 14c:	6a 00                	push   0x0
 14e:	00 00                	add    BYTE PTR [rax],al
 150:	42 09 a4 00 00 00 58 	or     DWORD PTR [rax+r8*1+0x1580000],esp
 157:	01 
 158:	b2 00                	mov    dl,0x0
 15a:	00 00                	add    BYTE PTR [rax],al
 15c:	44 16                	rex.R (bad)
 15e:	3d 02 00 00 60       	cmp    eax,0x60000002
 163:	01 f1                	add    ecx,esi
 165:	01 00                	add    DWORD PTR [rax],eax
 167:	00 46 14             	add    BYTE PTR [rsi+0x14],al
 16a:	42 02 00             	rex.X add al,BYTE PTR [rax]
 16d:	00 68 01             	add    BYTE PTR [rax+0x1],ch
 170:	e9 01 00 00 48       	jmp    48000176 <_end+0x47ffc0f6>
 175:	07                   	(bad)
 176:	66 00 00             	data16 add BYTE PTR [rax],al
 179:	00 70 01             	add    BYTE PTR [rax+0x1],dh
 17c:	2a 02                	sub    al,BYTE PTR [rdx]
 17e:	00 00                	add    BYTE PTR [rax],al
 180:	49 07                	rex.WB (bad)
 182:	66 00 00             	data16 add BYTE PTR [rax],al
 185:	00 74 01 11          	add    BYTE PTR [rcx+rax*1+0x11],dh
 189:	01 00                	add    DWORD PTR [rax],eax
 18b:	00 4a 0b             	add    BYTE PTR [rdx+0xb],cl
 18e:	74 00                	je     190 <__abi_tag-0x1ec>
 190:	00 00                	add    BYTE PTR [rax],al
 192:	78 01                	js     195 <__abi_tag-0x1e7>
 194:	05 01 00 00 4d       	add    eax,0x4d000001
 199:	12 51 00             	adc    dl,BYTE PTR [rcx+0x0]
 19c:	00 00                	add    BYTE PTR [rax],al
 19e:	80 01 4c             	add    BYTE PTR [rcx],0x4c
 1a1:	02 00                	add    al,BYTE PTR [rax]
 1a3:	00 4e 0f             	add    BYTE PTR [rsi+0xf],cl
 1a6:	58                   	pop    rax
 1a7:	00 00                	add    BYTE PTR [rax],al
 1a9:	00 82 01 42 01 00    	add    BYTE PTR [rdx+0x14201],al
 1af:	00 4f 08             	add    BYTE PTR [rdi+0x8],cl
 1b2:	47 02 00             	rex.RXB add r8b,BYTE PTR [r8]
 1b5:	00 83 01 f1 00 00    	add    BYTE PTR [rbx+0xf101],al
 1bb:	00 51 0f             	add    BYTE PTR [rcx+0xf],dl
 1be:	57                   	push   rdi
 1bf:	02 00                	add    al,BYTE PTR [rax]
 1c1:	00 88 01 15 01 00    	add    BYTE PTR [rax+0x11501],cl
 1c7:	00 59 0d             	add    BYTE PTR [rcx+0xd],bl
 1ca:	80 00 00             	add    BYTE PTR [rax],0x0
 1cd:	00 90 01 35 02 00    	add    BYTE PTR [rax+0x23501],dl
 1d3:	00 5b 17             	add    BYTE PTR [rbx+0x17],bl
 1d6:	61                   	(bad)
 1d7:	02 00                	add    al,BYTE PTR [rax]
 1d9:	00 98 01 fb 01 00    	add    BYTE PTR [rax+0x1fb01],bl
 1df:	00 5c 19 6b          	add    BYTE PTR [rcx+rbx*1+0x6b],bl
 1e3:	02 00                	add    al,BYTE PTR [rax]
 1e5:	00 a0 01 9a 01 00    	add    BYTE PTR [rax+0x19a01],ah
 1eb:	00 5d 14             	add    BYTE PTR [rbp+0x14],bl
 1ee:	42 02 00             	rex.X add al,BYTE PTR [rax]
 1f1:	00 a8 01 c8 00 00    	add    BYTE PTR [rax+0xc801],ch
 1f7:	00 5e 09             	add    BYTE PTR [rsi+0x9],bl
 1fa:	48 00 00             	rex.W add BYTE PTR [rax],al
 1fd:	00 b0 01 b8 01 00    	add    BYTE PTR [rax+0x1b801],dh
 203:	00 5f 0a             	add    BYTE PTR [rdi+0xa],bl
 206:	2e 00 00             	cs add BYTE PTR [rax],al
 209:	00 b8 01 06 02 00    	add    BYTE PTR [rax+0x20601],bh
 20f:	00 60 07             	add    BYTE PTR [rax+0x7],ah
 212:	66 00 00             	data16 add BYTE PTR [rax],al
 215:	00 c0                	add    al,al
 217:	01 af 01 00 00 62    	add    DWORD PTR [rdi+0x62000001],ebp
 21d:	08 70 02             	or     BYTE PTR [rax+0x2],dh
 220:	00 00                	add    BYTE PTR [rax],al
 222:	c4                   	(bad)
 223:	00 05 65 00 00 00    	add    BYTE PTR [rip+0x65],al        # 28e <__abi_tag-0xee>
 229:	05 07 19 ba 00       	add    eax,0xba1907
 22e:	00 00                	add    BYTE PTR [rax],al
 230:	14 76                	adc    al,0x76
 232:	02 00                	add    al,BYTE PTR [rax]
 234:	00 04 2b             	add    BYTE PTR [rbx+rbp*1],al
 237:	0e                   	(bad)
 238:	07                   	(bad)
 239:	4c 01 00             	add    QWORD PTR [rax],r8
 23c:	00 04 38             	add    BYTE PTR [rax+rdi*1],al
 23f:	02 00                	add    al,BYTE PTR [rax]
 241:	00 04 ba             	add    BYTE PTR [rdx+rdi*4],al
 244:	00 00                	add    BYTE PTR [rax],al
 246:	00 0a                	add    BYTE PTR [rdx],cl
 248:	ae                   	scas   al,BYTE PTR es:[rdi]
 249:	00 00                	add    BYTE PTR [rax],al
 24b:	00 57 02             	add    BYTE PTR [rdi+0x2],dl
 24e:	00 00                	add    BYTE PTR [rax],al
 250:	08 3a                	or     BYTE PTR [rdx],bh
 252:	00 00                	add    BYTE PTR [rax],al
 254:	00 00                	add    BYTE PTR [rax],al
 256:	00 04 30             	add    BYTE PTR [rax+rsi*1],al
 259:	02 00                	add    al,BYTE PTR [rax]
 25b:	00 07                	add    BYTE PTR [rdi],al
 25d:	32 02                	xor    al,BYTE PTR [rdx]
 25f:	00 00                	add    BYTE PTR [rax],al
 261:	04 5c                	add    al,0x5c
 263:	02 00                	add    al,BYTE PTR [rax]
 265:	00 07                	add    BYTE PTR [rdi],al
 267:	f8                   	clc
 268:	01 00                	add    DWORD PTR [rax],eax
 26a:	00 04 66             	add    BYTE PTR [rsi+riz*2],al
 26d:	02 00                	add    al,BYTE PTR [rax]
 26f:	00 0a                	add    BYTE PTR [rdx],cl
 271:	ae                   	scas   al,BYTE PTR es:[rdi]
 272:	00 00                	add    BYTE PTR [rax],al
 274:	00 80 02 00 00 08    	add    BYTE PTR [rax+0x8000002],al
 27a:	3a 00                	cmp    al,BYTE PTR [rax]
 27c:	00 00                	add    BYTE PTR [rax],al
 27e:	13 00                	adc    eax,DWORD PTR [rax]
 280:	0b 24 02             	or     esp,DWORD PTR [rdx+rax*1]
 283:	00 00                	add    BYTE PTR [rax],al
 285:	8f 8a 02 00          	(bad)
 289:	00 04 24             	add    BYTE PTR [rsp],al
 28c:	02 00                	add    al,BYTE PTR [rax]
 28e:	00 06                	add    BYTE PTR [rsi],al
 290:	8a 02                	mov    al,BYTE PTR [rdx]
 292:	00 00                	add    BYTE PTR [rax],al
 294:	0b 6f 02             	or     ebp,DWORD PTR [rdi+0x2]
 297:	00 00                	add    BYTE PTR [rax],al
 299:	90                   	nop
 29a:	8a 02                	mov    al,BYTE PTR [rdx]
 29c:	00 00                	add    BYTE PTR [rax],al
 29e:	03 08                	add    ecx,DWORD PTR [rax]
 2a0:	05 e3 00 00 00       	add    eax,0xe3
 2a5:	05 e2 01 00 00       	add    eax,0x1e2
 2aa:	07                   	(bad)
 2ab:	0a 12                	or     dl,BYTE PTR [rdx]
 2ad:	98                   	cwde
 2ae:	00 00                	add    BYTE PTR [rax],al
 2b0:	00 03                	add    BYTE PTR [rbx],al
 2b2:	08 07                	or     BYTE PTR [rdi],al
 2b4:	2b 01                	sub    eax,DWORD PTR [rcx]
 2b6:	00 00                	add    BYTE PTR [rax],al
 2b8:	04 b5                	add    al,0xb5
 2ba:	00 00                	add    BYTE PTR [rax],al
 2bc:	00 06                	add    BYTE PTR [rsi],al
 2be:	b8 02 00 00 04       	mov    eax,0x4000002
 2c3:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 2c4:	00 00                	add    BYTE PTR [rax],al
 2c6:	00 06                	add    BYTE PTR [rsi],al
 2c8:	c2 02 00             	ret    0x2
 2cb:	00 0c fe             	add    BYTE PTR [rsi+rdi*8],cl
 2ce:	00 00                	add    BYTE PTR [rax],al
 2d0:	00 08                	add    BYTE PTR [rax],cl
 2d2:	b1 11                	mov    cl,0x11
 2d4:	6d                   	ins    DWORD PTR es:[rdi],dx
 2d5:	00 00                	add    BYTE PTR [rax],al
 2d7:	00 ec                	add    ah,ch
 2d9:	02 00                	add    al,BYTE PTR [rax]
 2db:	00 02                	add    BYTE PTR [rdx],al
 2dd:	bd 02 00 00 02       	mov    ebp,0x2000002
 2e2:	c7 02 00 00 02 66    	mov    DWORD PTR [rdx],0x66020000
 2e8:	00 00                	add    BYTE PTR [rax],al
 2ea:	00 00                	add    BYTE PTR [rax],al
 2ec:	09 d5                	or     ebp,edx
 2ee:	00 00                	add    BYTE PTR [rax],al
 2f0:	00 50 02             	add    BYTE PTR [rax+0x2],dl
 2f3:	0e                   	(bad)
 2f4:	a4                   	movs   BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
 2f5:	00 00                	add    BYTE PTR [rax],al
 2f7:	00 0c 03             	add    BYTE PTR [rbx+rax*1],cl
 2fa:	00 00                	add    BYTE PTR [rax],al
 2fc:	02 a9 00 00 00 02    	add    ch,BYTE PTR [rcx+0x2000000]
 302:	66 00 00             	data16 add BYTE PTR [rax],al
 305:	00 02                	add    BYTE PTR [rdx],al
 307:	8f 02                	pop    QWORD PTR [rdx]
 309:	00 00                	add    BYTE PTR [rax],al
 30b:	00 09                	add    BYTE PTR [rcx],cl
 30d:	f7 00 00 00 64 01    	test   DWORD PTR [rax],0x1640000
 313:	0c 66                	or     al,0x66
 315:	00 00                	add    BYTE PTR [rax],al
 317:	00 23                	add    BYTE PTR [rbx],ah
 319:	03 00                	add    eax,DWORD PTR [rax]
 31b:	00 02                	add    BYTE PTR [rdx],al
 31d:	b8 02 00 00 15       	mov    eax,0x15000002
 322:	00 0d 6a 02 00 00    	add    BYTE PTR [rip+0x26a],cl        # 592 <__abi_tag+0x216>
 328:	08 c6                	or     dh,al
 32a:	01 0c 66             	add    DWORD PTR [rsi+riz*2],ecx
 32d:	00 00                	add    BYTE PTR [rax],al
 32f:	00 16                	add    BYTE PTR [rsi],dl
 331:	69 02 00 00 08 c8    	imul   eax,DWORD PTR [rdx],0xc8080000
 337:	01 0d 43 03 00 00    	add    DWORD PTR [rip+0x343],ecx        # 680 <__abi_tag+0x304>
 33d:	02 41 00             	add    al,BYTE PTR [rcx+0x0]
 340:	00 00                	add    BYTE PTR [rax],al
 342:	00 0d 57 01 00 00    	add    BYTE PTR [rip+0x157],cl        # 49f <__abi_tag+0x123>
 348:	09 8a 02 10 8c 00    	or     DWORD PTR [rdx+0x8c1002],ecx
 34e:	00 00                	add    BYTE PTR [rax],al
 350:	0c 77                	or     al,0x77
 352:	01 00                	add    DWORD PTR [rax],eax
 354:	00 0a                	add    BYTE PTR [rdx],cl
 356:	4c 0f a5 02          	shld   QWORD PTR [rdx],r8,cl
 35a:	00 00                	add    BYTE PTR [rax],al
 35c:	66 03 00             	add    ax,WORD PTR [rax]
 35f:	00 02                	add    BYTE PTR [rdx],al
 361:	66 03 00             	add    ax,WORD PTR [rax]
 364:	00 00                	add    BYTE PTR [rax],al
 366:	04 a5                	add    al,0xa5
 368:	02 00                	add    al,BYTE PTR [rax]
 36a:	00 09                	add    BYTE PTR [rcx],cl
 36c:	db 00                	fild   DWORD PTR [rax]
 36e:	00 00                	add    BYTE PTR [rax],al
 370:	4c 01 0c 66          	add    QWORD PTR [rsi+riz*2],r9
 374:	00 00                	add    BYTE PTR [rax],al
 376:	00 90 03 00 00 02    	add    BYTE PTR [rax+0x2000003],dl
 37c:	8f 02                	pop    QWORD PTR [rdx]
 37e:	00 00                	add    BYTE PTR [rax],al
 380:	02 a9 00 00 00 02    	add    ch,BYTE PTR [rcx+0x2000000]
 386:	66 00 00             	data16 add BYTE PTR [rax],al
 389:	00 02                	add    BYTE PTR [rdx],al
 38b:	2e 00 00             	cs add BYTE PTR [rax],al
 38e:	00 00                	add    BYTE PTR [rax],al
 390:	17                   	(bad)
 391:	95                   	xchg   ebp,eax
 392:	01 00                	add    DWORD PTR [rax],eax
 394:	00 01                	add    BYTE PTR [rcx],al
 396:	07                   	(bad)
 397:	05 66 00 00 00       	add    eax,0x66
 39c:	b9 11 00 00 00       	mov    ecx,0x11
 3a1:	00 00                	add    BYTE PTR [rax],al
 3a3:	00 05 01 00 00 00    	add    BYTE PTR [rip+0x1],al        # 3aa <__abi_tag+0x2e>
 3a9:	00 00                	add    BYTE PTR [rax],al
 3ab:	00 01                	add    BYTE PTR [rcx],al
 3ad:	9c                   	pushf
 3ae:	ee                   	out    dx,al
 3af:	03 00                	add    eax,DWORD PTR [rax]
 3b1:	00 0e                	add    BYTE PTR [rsi],cl
 3b3:	62 75 66 00 08       	(bad)
 3b8:	07                   	(bad)
 3b9:	ee                   	out    dx,al
 3ba:	03 00                	add    eax,DWORD PTR [rax]
 3bc:	00 02                	add    BYTE PTR [rdx],al
 3be:	91                   	xchg   ecx,eax
 3bf:	40 18 a8 01 00 00 01 	sbb    BYTE PTR [rax+0x1000001],bpl
 3c6:	09 06                	or     DWORD PTR [rsi],eax
 3c8:	66 00 00             	data16 add BYTE PTR [rax],al
 3cb:	00 02                	add    BYTE PTR [rdx],al
 3cd:	91                   	xchg   ecx,eax
 3ce:	5c                   	pop    rsp
 3cf:	19 59 12             	sbb    DWORD PTR [rcx+0x12],ebx
 3d2:	00 00                	add    BYTE PTR [rax],al
 3d4:	00 00                	add    BYTE PTR [rax],al
 3d6:	00 00                	add    BYTE PTR [rax],al
 3d8:	5a                   	pop    rdx
 3d9:	00 00                	add    BYTE PTR [rax],al
 3db:	00 00                	add    BYTE PTR [rax],al
 3dd:	00 00                	add    BYTE PTR [rax],al
 3df:	00 0e                	add    BYTE PTR [rsi],cl
 3e1:	67 00 11             	add    BYTE PTR [ecx],dl
 3e4:	08 66 00             	or     BYTE PTR [rsi+0x0],ah
 3e7:	00 00                	add    BYTE PTR [rax],al
 3e9:	02 91 58 00 00 1a    	add    dl,BYTE PTR [rcx+0x1a000058]
 3ef:	ae                   	scas   al,BYTE PTR es:[rdi]
 3f0:	00 00                	add    BYTE PTR [rax],al
 3f2:	00 08                	add    BYTE PTR [rax],cl
 3f4:	3a 00                	cmp    al,BYTE PTR [rax]
 3f6:	00 00                	add    BYTE PTR [rax],al
 3f8:	0f 00 00             	sldt   WORD PTR [rax]

Disassembly of section .debug_abbrev:

0000000000000000 <.debug_abbrev>:
   0:	01 0d 00 03 0e 3a    	add    DWORD PTR [rip+0x3a0e0300],ecx        # 3a0e0306 <_end+0x3a0dc286>
   6:	21 04 3b             	and    DWORD PTR [rbx+rdi*1],eax
   9:	0b 39                	or     edi,DWORD PTR [rcx]
   b:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
   e:	38 0b                	cmp    BYTE PTR [rbx],cl
  10:	00 00                	add    BYTE PTR [rax],al
  12:	02 05 00 49 13 00    	add    al,BYTE PTR [rip+0x134900]        # 134918 <_end+0x130898>
  18:	00 03                	add    BYTE PTR [rbx],al
  1a:	24 00                	and    al,0x0
  1c:	0b 0b                	or     ecx,DWORD PTR [rbx]
  1e:	3e 0b 03             	ds or  eax,DWORD PTR [rbx]
  21:	0e                   	(bad)
  22:	00 00                	add    BYTE PTR [rax],al
  24:	04 0f                	add    al,0xf
  26:	00 0b                	add    BYTE PTR [rbx],cl
  28:	21 08                	and    DWORD PTR [rax],ecx
  2a:	49 13 00             	adc    rax,QWORD PTR [r8]
  2d:	00 05 16 00 03 0e    	add    BYTE PTR [rip+0xe030016],al        # e030049 <_end+0xe02bfc9>
  33:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  35:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  37:	39 0b                	cmp    DWORD PTR [rbx],ecx
  39:	49 13 00             	adc    rax,QWORD PTR [r8]
  3c:	00 06                	add    BYTE PTR [rsi],al
  3e:	37                   	(bad)
  3f:	00 49 13             	add    BYTE PTR [rcx+0x13],cl
  42:	00 00                	add    BYTE PTR [rax],al
  44:	07                   	(bad)
  45:	13 00                	adc    eax,DWORD PTR [rax]
  47:	03 0e                	add    ecx,DWORD PTR [rsi]
  49:	3c 19                	cmp    al,0x19
  4b:	00 00                	add    BYTE PTR [rax],al
  4d:	08 21                	or     BYTE PTR [rcx],ah
  4f:	00 49 13             	add    BYTE PTR [rcx+0x13],cl
  52:	2f                   	(bad)
  53:	0b 00                	or     eax,DWORD PTR [rax]
  55:	00 09                	add    BYTE PTR [rcx],cl
  57:	2e 01 3f             	cs add DWORD PTR [rdi],edi
  5a:	19 03                	sbb    DWORD PTR [rbx],eax
  5c:	0e                   	(bad)
  5d:	3a 21                	cmp    ah,BYTE PTR [rcx]
  5f:	06                   	(bad)
  60:	3b 05 39 0b 27 19    	cmp    eax,DWORD PTR [rip+0x19270b39]        # 19270b9f <_end+0x1926cb1f>
  66:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
  6a:	01 13                	add    DWORD PTR [rbx],edx
  6c:	00 00                	add    BYTE PTR [rax],al
  6e:	0a 01                	or     al,BYTE PTR [rcx]
  70:	01 49 13             	add    DWORD PTR [rcx+0x13],ecx
  73:	01 13                	add    DWORD PTR [rbx],edx
  75:	00 00                	add    BYTE PTR [rax],al
  77:	0b 34 00             	or     esi,DWORD PTR [rax+rax*1]
  7a:	03 0e                	add    ecx,DWORD PTR [rsi]
  7c:	3a 21                	cmp    ah,BYTE PTR [rcx]
  7e:	06                   	(bad)
  7f:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  81:	39 21                	cmp    DWORD PTR [rcx],esp
  83:	0e                   	(bad)
  84:	49 13 3f             	adc    rdi,QWORD PTR [r15]
  87:	19 3c 19             	sbb    DWORD PTR [rcx+rbx*1],edi
  8a:	00 00                	add    BYTE PTR [rax],al
  8c:	0c 2e                	or     al,0x2e
  8e:	01 3f                	add    DWORD PTR [rdi],edi
  90:	19 03                	sbb    DWORD PTR [rbx],eax
  92:	0e                   	(bad)
  93:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  95:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
  97:	39 0b                	cmp    DWORD PTR [rbx],ecx
  99:	27                   	(bad)
  9a:	19 49 13             	sbb    DWORD PTR [rcx+0x13],ecx
  9d:	3c 19                	cmp    al,0x19
  9f:	01 13                	add    DWORD PTR [rbx],edx
  a1:	00 00                	add    BYTE PTR [rax],al
  a3:	0d 2e 00 3f 19       	or     eax,0x193f002e
  a8:	03 0e                	add    ecx,DWORD PTR [rsi]
  aa:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  ac:	3b 05 39 0b 27 19    	cmp    eax,DWORD PTR [rip+0x19270b39]        # 19270beb <_end+0x1926cb6b>
  b2:	49 13 3c 19          	adc    rdi,QWORD PTR [r9+rbx*1]
  b6:	00 00                	add    BYTE PTR [rax],al
  b8:	0e                   	(bad)
  b9:	34 00                	xor    al,0x0
  bb:	03 08                	add    ecx,DWORD PTR [rax]
  bd:	3a 21                	cmp    ah,BYTE PTR [rcx]
  bf:	01 3b                	add    DWORD PTR [rbx],edi
  c1:	0b 39                	or     edi,DWORD PTR [rcx]
  c3:	0b 49 13             	or     ecx,DWORD PTR [rcx+0x13]
  c6:	02 18                	add    bl,BYTE PTR [rax]
  c8:	00 00                	add    BYTE PTR [rax],al
  ca:	0f 11 01             	movups XMMWORD PTR [rcx],xmm0
  cd:	25 0e 13 0b 03       	and    eax,0x30b130e
  d2:	1f                   	(bad)
  d3:	1b 1f                	sbb    ebx,DWORD PTR [rdi]
  d5:	11 01                	adc    DWORD PTR [rcx],eax
  d7:	12 07                	adc    al,BYTE PTR [rdi]
  d9:	10 17                	adc    BYTE PTR [rdi],dl
  db:	00 00                	add    BYTE PTR [rax],al
  dd:	10 0f                	adc    BYTE PTR [rdi],cl
  df:	00 0b                	add    BYTE PTR [rbx],cl
  e1:	0b 00                	or     eax,DWORD PTR [rax]
  e3:	00 11                	add    BYTE PTR [rcx],dl
  e5:	24 00                	and    al,0x0
  e7:	0b 0b                	or     ecx,DWORD PTR [rbx]
  e9:	3e 0b 03             	ds or  eax,DWORD PTR [rbx]
  ec:	08 00                	or     BYTE PTR [rax],al
  ee:	00 12                	add    BYTE PTR [rdx],dl
  f0:	26 00 49 13          	es add BYTE PTR [rcx+0x13],cl
  f4:	00 00                	add    BYTE PTR [rax],al
  f6:	13 13                	adc    edx,DWORD PTR [rbx]
  f8:	01 03                	add    DWORD PTR [rbx],eax
  fa:	0e                   	(bad)
  fb:	0b 0b                	or     ecx,DWORD PTR [rbx]
  fd:	3a 0b                	cmp    cl,BYTE PTR [rbx]
  ff:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 101:	39 0b                	cmp    DWORD PTR [rbx],ecx
 103:	01 13                	add    DWORD PTR [rbx],edx
 105:	00 00                	add    BYTE PTR [rax],al
 107:	14 16                	adc    al,0x16
 109:	00 03                	add    BYTE PTR [rbx],al
 10b:	0e                   	(bad)
 10c:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 10e:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 110:	39 0b                	cmp    DWORD PTR [rbx],ecx
 112:	00 00                	add    BYTE PTR [rax],al
 114:	15 18 00 00 00       	adc    eax,0x18
 119:	16                   	(bad)
 11a:	2e 01 3f             	cs add DWORD PTR [rdi],edi
 11d:	19 03                	sbb    DWORD PTR [rbx],eax
 11f:	0e                   	(bad)
 120:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 122:	3b 05 39 0b 27 19    	cmp    eax,DWORD PTR [rip+0x19270b39]        # 19270c61 <_end+0x1926cbe1>
 128:	3c 19                	cmp    al,0x19
 12a:	01 13                	add    DWORD PTR [rbx],edx
 12c:	00 00                	add    BYTE PTR [rax],al
 12e:	17                   	(bad)
 12f:	2e 01 3f             	cs add DWORD PTR [rdi],edi
 132:	19 03                	sbb    DWORD PTR [rbx],eax
 134:	0e                   	(bad)
 135:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 137:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 139:	39 0b                	cmp    DWORD PTR [rbx],ecx
 13b:	49 13 11             	adc    rdx,QWORD PTR [r9]
 13e:	01 12                	add    DWORD PTR [rdx],edx
 140:	07                   	(bad)
 141:	40 18 7c 19 01       	sbb    BYTE PTR [rcx+rbx*1+0x1],dil
 146:	13 00                	adc    eax,DWORD PTR [rax]
 148:	00 18                	add    BYTE PTR [rax],bl
 14a:	34 00                	xor    al,0x0
 14c:	03 0e                	add    ecx,DWORD PTR [rsi]
 14e:	3a 0b                	cmp    cl,BYTE PTR [rbx]
 150:	3b 0b                	cmp    ecx,DWORD PTR [rbx]
 152:	39 0b                	cmp    DWORD PTR [rbx],ecx
 154:	49 13 02             	adc    rax,QWORD PTR [r10]
 157:	18 00                	sbb    BYTE PTR [rax],al
 159:	00 19                	add    BYTE PTR [rcx],bl
 15b:	0b 01                	or     eax,DWORD PTR [rcx]
 15d:	11 01                	adc    DWORD PTR [rcx],eax
 15f:	12 07                	adc    al,BYTE PTR [rdi]
 161:	00 00                	add    BYTE PTR [rax],al
 163:	1a 01                	sbb    al,BYTE PTR [rcx]
 165:	01 49 13             	add    DWORD PTR [rcx+0x13],ecx
 168:	00 00                	add    BYTE PTR [rax],al
	...

Disassembly of section .debug_line:

0000000000000000 <.debug_line>:
   0:	bf 00 00 00 05       	mov    edi,0x5000000
   5:	00 08                	add    BYTE PTR [rax],cl
   7:	00 67 00             	add    BYTE PTR [rdi+0x0],ah
   a:	00 00                	add    BYTE PTR [rax],al
   c:	01 01                	add    DWORD PTR [rcx],eax
   e:	01 fb                	add    ebx,edi
  10:	0e                   	(bad)
  11:	0d 00 01 01 01       	or     eax,0x1010100
  16:	01 00                	add    DWORD PTR [rax],eax
  18:	00 00                	add    BYTE PTR [rax],al
  1a:	01 00                	add    DWORD PTR [rax],eax
  1c:	00 01                	add    BYTE PTR [rcx],al
  1e:	01 01                	add    DWORD PTR [rcx],eax
  20:	1f                   	(bad)
  21:	05 08 00 00 00       	add    eax,0x8
  26:	32 00                	xor    al,BYTE PTR [rax]
  28:	00 00                	add    BYTE PTR [rax],al
  2a:	5b                   	pop    rbx
  2b:	00 00                	add    BYTE PTR [rax],al
  2d:	00 7e 00             	add    BYTE PTR [rsi+0x0],bh
  30:	00 00                	add    BYTE PTR [rax],al
  32:	a7                   	cmps   DWORD PTR ds:[rsi],DWORD PTR es:[rdi]
  33:	00 00                	add    BYTE PTR [rax],al
  35:	00 02                	add    BYTE PTR [rdx],al
  37:	01 1f                	add    DWORD PTR [rdi],ebx
  39:	02 0f                	add    cl,BYTE PTR [rdi]
  3b:	0b 00                	or     eax,DWORD PTR [rax]
	...
  45:	00 b4 00 00 00 01 bd 	add    BYTE PTR [rax+rax*1-0x42ff0000],dh
  4c:	00 00                	add    BYTE PTR [rax],al
  4e:	00 02                	add    BYTE PTR [rdx],al
  50:	c5 00 00             	(bad)
  53:	00 03                	add    BYTE PTR [rbx],al
  55:	cc                   	int3
  56:	00 00                	add    BYTE PTR [rax],al
  58:	00 03                	add    BYTE PTR [rbx],al
  5a:	d3 00                	rol    DWORD PTR [rax],cl
  5c:	00 00                	add    BYTE PTR [rax],al
  5e:	04 db                	add    al,0xdb
  60:	00 00                	add    BYTE PTR [rax],al
  62:	00 03                	add    BYTE PTR [rbx],al
  64:	e4 00                	in     al,0x0
  66:	00 00                	add    BYTE PTR [rax],al
  68:	04 ed                	add    al,0xed
  6a:	00 00                	add    BYTE PTR [rax],al
  6c:	00 04 f6             	add    BYTE PTR [rsi+rsi*8],al
  6f:	00 00                	add    BYTE PTR [rax],al
  71:	00 04 05 0c 00 09 02 	add    BYTE PTR [rax*1+0x209000c],al
  78:	b9 11 00 00 00       	mov    ecx,0x11
  7d:	00 00                	add    BYTE PTR [rax],al
  7f:	00 18                	add    BYTE PTR [rax],bl
  81:	05 02 94 05 08       	add    eax,0x8059402
  86:	08 c9                	or     cl,cl
  88:	05 10 9e 05 12       	add    eax,0x12059e10
  8d:	2e 05 10 58 05 02    	cs add eax,0x2055810
  93:	2e 05 0b 75 05 09    	cs add eax,0x905750b
  99:	58                   	pop    rax
  9a:	05 02 02 29 14       	add    eax,0x14290202
  9f:	05 05 08 3d 05       	add    eax,0x53d0805
  a4:	04 08                	add    al,0x8
  a6:	74 05                	je     ad <__abi_tag-0x2cf>
  a8:	0c 59                	or     al,0x59
  aa:	05 08 08 58 05       	add    eax,0x5580808
  af:	04 3d                	add    al,0x3d
  b1:	05 06 08 83 83       	add    eax,0x83830806
  b6:	08 14 05 09 e8 05 01 	or     BYTE PTR [rax*1+0x105e809],dl
  bd:	59                   	pop    rcx
  be:	02 06                	add    al,BYTE PTR [rsi]
  c0:	00 01                	add    BYTE PTR [rcx],al
  c2:	01                   	.byte 0x1

Disassembly of section .debug_str:

0000000000000000 <.debug_str>:
   0:	47                   	rex.RXB
   1:	4e 55                	rex.WRX push rbp
   3:	20 43 31             	and    BYTE PTR [rbx+0x31],al
   6:	37                   	(bad)
   7:	20 31                	and    BYTE PTR [rcx],dh
   9:	32 2e                	xor    ch,BYTE PTR [rsi]
   b:	32 2e                	xor    ch,BYTE PTR [rsi]
   d:	30 20                	xor    BYTE PTR [rax],ah
   f:	2d 6d 74 75 6e       	sub    eax,0x6e75746d
  14:	65 3d 67 65 6e 65    	gs cmp eax,0x656e6567
  1a:	72 69                	jb     85 <__abi_tag-0x2f7>
  1c:	63 20                	movsxd esp,DWORD PTR [rax]
  1e:	2d 6d 61 72 63       	sub    eax,0x6372616d
  23:	68 3d 78 38 36       	push   0x3638783d
  28:	2d 36 34 20 2d       	sub    eax,0x2d203436
  2d:	67 20 2d 66 6e 6f 2d 	and    BYTE PTR [eip+0x2d6f6e66],ch        # 2d6f6e9a <_end+0x2d6f2e1a>
  34:	73 74                	jae    aa <__abi_tag-0x2d2>
  36:	61                   	(bad)
  37:	63 6b 2d             	movsxd ebp,DWORD PTR [rbx+0x2d]
  3a:	70 72                	jo     ae <__abi_tag-0x2ce>
  3c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  3d:	74 65                	je     a4 <__abi_tag-0x2d8>
  3f:	63 74 6f 72          	movsxd esi,DWORD PTR [rdi+rbp*2+0x72]
  43:	20 2d 66 61 73 79    	and    BYTE PTR [rip+0x79736166],ch        # 797361af <_end+0x7973212f>
  49:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  4a:	63 68 72             	movsxd ebp,DWORD PTR [rax+0x72]
  4d:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  4e:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  4f:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  50:	75 73                	jne    c5 <__abi_tag-0x2b7>
  52:	2d 75 6e 77 69       	sub    eax,0x69776e75
  57:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  58:	64 2d 74 61 62 6c    	fs sub eax,0x6c626174
  5e:	65 73 00             	gs jae 61 <__abi_tag-0x31b>
  61:	5f                   	pop    rdi
  62:	49                   	rex.WB
  63:	4f 5f                	rex.WRXB pop r15
  65:	46                   	rex.RX
  66:	49                   	rex.WB
  67:	4c                   	rex.WR
  68:	45 00 5f 49          	add    BYTE PTR [r15+0x49],r11b
  6c:	4f 5f                	rex.WRXB pop r15
  6e:	73 61                	jae    d1 <__abi_tag-0x2ab>
  70:	76 65                	jbe    d7 <__abi_tag-0x2a5>
  72:	5f                   	pop    rdi
  73:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  75:	64 00 73 68          	add    BYTE PTR fs:[rbx+0x68],dh
  79:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  7a:	72 74                	jb     f0 <__abi_tag-0x28c>
  7c:	20 69 6e             	and    BYTE PTR [rcx+0x6e],ch
  7f:	74 00                	je     81 <__abi_tag-0x2fb>
  81:	73 69                	jae    ec <__abi_tag-0x290>
  83:	7a 65                	jp     ea <__abi_tag-0x292>
  85:	5f                   	pop    rdi
  86:	74 00                	je     88 <__abi_tag-0x2f4>
  88:	5f                   	pop    rdi
  89:	5f                   	pop    rdi
  8a:	70 69                	jo     f5 <__abi_tag-0x287>
  8c:	64 5f                	fs pop rdi
  8e:	74 00                	je     90 <__abi_tag-0x2ec>
  90:	5f                   	pop    rdi
  91:	49                   	rex.WB
  92:	4f 5f                	rex.WRXB pop r15
  94:	77 72                	ja     108 <__abi_tag-0x274>
  96:	69 74 65 5f 70 74 72 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x727470
  9d:	00 
  9e:	5f                   	pop    rdi
  9f:	66 6c                	data16 ins BYTE PTR es:[rdi],dx
  a1:	61                   	(bad)
  a2:	67 73 00             	addr32 jae a5 <__abi_tag-0x2d7>
  a5:	5f                   	pop    rdi
  a6:	49                   	rex.WB
  a7:	4f 5f                	rex.WRXB pop r15
  a9:	62 75 66 5f 62       	(bad)
  ae:	61                   	(bad)
  af:	73 65                	jae    116 <__abi_tag-0x266>
  b1:	00 5f 6d             	add    BYTE PTR [rdi+0x6d],bl
  b4:	61                   	(bad)
  b5:	72 6b                	jb     122 <__abi_tag-0x25a>
  b7:	65 72 73             	gs jb  12d <__abi_tag-0x24f>
  ba:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
  bd:	4f 5f                	rex.WRXB pop r15
  bf:	72 65                	jb     126 <__abi_tag-0x256>
  c1:	61                   	(bad)
  c2:	64 5f                	fs pop rdi
  c4:	65 6e                	outs   dx,BYTE PTR gs:[rsi]
  c6:	64 00 5f 66          	add    BYTE PTR fs:[rdi+0x66],bl
  ca:	72 65                	jb     131 <__abi_tag-0x24b>
  cc:	65 72 65             	gs jb  134 <__abi_tag-0x248>
  cf:	73 5f                	jae    130 <__abi_tag-0x24c>
  d1:	62 75 66 00 66       	(bad)
  d6:	67 65 74 73          	addr32 gs je 14d <__abi_tag-0x22f>
  da:	00 73 65             	add    BYTE PTR [rbx+0x65],dh
  dd:	74 76                	je     155 <__abi_tag-0x227>
  df:	62 75 66 00 6c       	(bad)
  e4:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  e5:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  e6:	67 20 6c 6f 6e       	and    BYTE PTR [edi+ebp*2+0x6e],ch
  eb:	67 20 69 6e          	and    BYTE PTR [ecx+0x6e],ch
  ef:	74 00                	je     f1 <__abi_tag-0x28b>
  f1:	5f                   	pop    rdi
  f2:	6c                   	ins    BYTE PTR es:[rdi],dx
  f3:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  f4:	63 6b 00             	movsxd ebp,DWORD PTR [rbx+0x0]
  f7:	70 72                	jo     16b <__abi_tag-0x211>
  f9:	69 6e 74 66 00 73 74 	imul   ebp,DWORD PTR [rsi+0x74],0x74730066
 100:	72 74                	jb     176 <__abi_tag-0x206>
 102:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 103:	6c                   	ins    BYTE PTR es:[rdi],dx
 104:	00 5f 63             	add    BYTE PTR [rdi+0x63],bl
 107:	75 72                	jne    17b <__abi_tag-0x201>
 109:	5f                   	pop    rdi
 10a:	63 6f 6c             	movsxd ebp,DWORD PTR [rdi+0x6c]
 10d:	75 6d                	jne    17c <__abi_tag-0x200>
 10f:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 110:	00 5f 6f             	add    BYTE PTR [rdi+0x6f],bl
 113:	6c                   	ins    BYTE PTR es:[rdi],dx
 114:	64 5f                	fs pop rdi
 116:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 117:	66 66 73 65          	data16 data16 jae 180 <__abi_tag-0x1fc>
 11b:	74 00                	je     11d <__abi_tag-0x25f>
 11d:	75 6e                	jne    18d <__abi_tag-0x1ef>
 11f:	73 69                	jae    18a <__abi_tag-0x1f2>
 121:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 123:	65 64 20 63 68       	gs and BYTE PTR fs:[rbx+0x68],ah
 128:	61                   	(bad)
 129:	72 00                	jb     12b <__abi_tag-0x251>
 12b:	6c                   	ins    BYTE PTR es:[rdi],dx
 12c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 12d:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 12e:	67 20 6c 6f 6e       	and    BYTE PTR [edi+ebp*2+0x6e],ch
 133:	67 20 75 6e          	and    BYTE PTR [ebp+0x6e],dh
 137:	73 69                	jae    1a2 <__abi_tag-0x1da>
 139:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 13b:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 140:	74 00                	je     142 <__abi_tag-0x23a>
 142:	5f                   	pop    rdi
 143:	73 68                	jae    1ad <__abi_tag-0x1cf>
 145:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 146:	72 74                	jb     1bc <__abi_tag-0x1c0>
 148:	62 75 66 00 5f 49 4f 	vmaxsh xmm9,xmm19,WORD PTR [rcx+0x9e]
 14f:	5f                   	pop    rdi
 150:	6d                   	ins    DWORD PTR es:[rdi],dx
 151:	61                   	(bad)
 152:	72 6b                	jb     1bf <__abi_tag-0x1bd>
 154:	65 72 00             	gs jb  157 <__abi_tag-0x225>
 157:	67 65 74 70          	addr32 gs je 1cb <__abi_tag-0x1b1>
 15b:	69 64 00 5f 5f 6f 66 	imul   esp,DWORD PTR [rax+rax*1+0x5f],0x66666f5f
 162:	66 
 163:	36 34 5f             	ss xor al,0x5f
 166:	74 00                	je     168 <__abi_tag-0x214>
 168:	5f                   	pop    rdi
 169:	49                   	rex.WB
 16a:	4f 5f                	rex.WRXB pop r15
 16c:	77 72                	ja     1e0 <__abi_tag-0x19c>
 16e:	69 74 65 5f 62 61 73 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x65736162
 175:	65 
 176:	00 74 69 6d          	add    BYTE PTR [rcx+rbp*2+0x6d],dh
 17a:	65 00 5f 49          	add    BYTE PTR gs:[rdi+0x49],bl
 17e:	4f 5f                	rex.WRXB pop r15
 180:	72 65                	jb     1e7 <__abi_tag-0x195>
 182:	61                   	(bad)
 183:	64 5f                	fs pop rdi
 185:	70 74                	jo     1fb <__abi_tag-0x181>
 187:	72 00                	jb     189 <__abi_tag-0x1f3>
 189:	5f                   	pop    rdi
 18a:	49                   	rex.WB
 18b:	4f 5f                	rex.WRXB pop r15
 18d:	62 75 66 5f 65       	(bad)
 192:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 193:	64 00 6d 61          	add    BYTE PTR fs:[rbp+0x61],ch
 197:	69 6e 00 5f 66 72 65 	imul   ebp,DWORD PTR [rsi+0x0],0x6572665f
 19e:	65 72 65             	gs jb  206 <__abi_tag-0x176>
 1a1:	73 5f                	jae    202 <__abi_tag-0x17a>
 1a3:	6c                   	ins    BYTE PTR es:[rdi],dx
 1a4:	69 73 74 00 61 6e 73 	imul   esi,DWORD PTR [rbx+0x74],0x736e6100
 1ab:	77 65                	ja     212 <__abi_tag-0x16a>
 1ad:	72 00                	jb     1af <__abi_tag-0x1cd>
 1af:	5f                   	pop    rdi
 1b0:	75 6e                	jne    220 <__abi_tag-0x15c>
 1b2:	75 73                	jne    227 <__abi_tag-0x155>
 1b4:	65 64 32 00          	gs xor al,BYTE PTR fs:[rax]
 1b8:	5f                   	pop    rdi
 1b9:	5f                   	pop    rdi
 1ba:	70 61                	jo     21d <__abi_tag-0x15f>
 1bc:	64 35 00 73 68 6f    	fs xor eax,0x6f687300
 1c2:	72 74                	jb     238 <__abi_tag-0x144>
 1c4:	20 75 6e             	and    BYTE PTR [rbp+0x6e],dh
 1c7:	73 69                	jae    232 <__abi_tag-0x14a>
 1c9:	67 6e                	outs   dx,BYTE PTR ds:[esi]
 1cb:	65 64 20 69 6e       	gs and BYTE PTR fs:[rcx+0x6e],ch
 1d0:	74 00                	je     1d2 <__abi_tag-0x1aa>
 1d2:	5f                   	pop    rdi
 1d3:	49                   	rex.WB
 1d4:	4f 5f                	rex.WRXB pop r15
 1d6:	77 72                	ja     24a <__abi_tag-0x132>
 1d8:	69 74 65 5f 65 6e 64 	imul   esi,DWORD PTR [rbp+riz*2+0x5f],0x646e65
 1df:	00 
 1e0:	5f                   	pop    rdi
 1e1:	5f                   	pop    rdi
 1e2:	74 69                	je     24d <__abi_tag-0x12f>
 1e4:	6d                   	ins    DWORD PTR es:[rdi],dx
 1e5:	65 5f                	gs pop rdi
 1e7:	74 00                	je     1e9 <__abi_tag-0x193>
 1e9:	5f                   	pop    rdi
 1ea:	66 69 6c 65 6e 6f 00 	imul   bp,WORD PTR [rbp+riz*2+0x6e],0x6f
 1f1:	5f                   	pop    rdi
 1f2:	63 68 61             	movsxd ebp,DWORD PTR [rax+0x61]
 1f5:	69 6e 00 5f 49 4f 5f 	imul   ebp,DWORD PTR [rsi+0x0],0x5f4f495f
 1fc:	77 69                	ja     267 <__abi_tag-0x115>
 1fe:	64 65 5f             	fs gs pop rdi
 201:	64 61                	fs (bad)
 203:	74 61                	je     266 <__abi_tag-0x116>
 205:	00 5f 6d             	add    BYTE PTR [rdi+0x6d],bl
 208:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 209:	64 65 00 5f 5f       	fs add BYTE PTR gs:[rdi+0x5f],bl
 20e:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 20f:	66 66 5f             	data16 pop di
 212:	74 00                	je     214 <__abi_tag-0x168>
 214:	5f                   	pop    rdi
 215:	49                   	rex.WB
 216:	4f 5f                	rex.WRXB pop r15
 218:	62 61                	(bad)
 21a:	63 6b 75             	movsxd ebp,DWORD PTR [rbx+0x75]
 21d:	70 5f                	jo     27e <__abi_tag-0xfe>
 21f:	62 61                	(bad)
 221:	73 65                	jae    288 <__abi_tag-0xf4>
 223:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
 226:	64 69 6e 00 5f 66 6c 	imul   ebp,DWORD PTR fs:[rsi+0x0],0x616c665f
 22d:	61 
 22e:	67 73 32             	addr32 jae 263 <__abi_tag-0x119>
 231:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 234:	4f 5f                	rex.WRXB pop r15
 236:	63 6f 64             	movsxd ebp,DWORD PTR [rdi+0x64]
 239:	65 63 76 74          	movsxd esi,DWORD PTR gs:[rsi+0x74]
 23d:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 240:	4f 5f                	rex.WRXB pop r15
 242:	72 65                	jb     2a9 <__abi_tag-0xd3>
 244:	61                   	(bad)
 245:	64 5f                	fs pop rdi
 247:	62 61                	(bad)
 249:	73 65                	jae    2b0 <__abi_tag-0xcc>
 24b:	00 5f 76             	add    BYTE PTR [rdi+0x76],bl
 24e:	74 61                	je     2b1 <__abi_tag-0xcb>
 250:	62                   	(bad)
 251:	6c                   	ins    BYTE PTR es:[rdi],dx
 252:	65 5f                	gs pop rdi
 254:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 255:	66 66 73 65          	data16 data16 jae 2be <__abi_tag-0xbe>
 259:	74 00                	je     25b <__abi_tag-0x121>
 25b:	5f                   	pop    rdi
 25c:	49                   	rex.WB
 25d:	4f 5f                	rex.WRXB pop r15
 25f:	73 61                	jae    2c2 <__abi_tag-0xba>
 261:	76 65                	jbe    2c8 <__abi_tag-0xb4>
 263:	5f                   	pop    rdi
 264:	62 61                	(bad)
 266:	73 65                	jae    2cd <__abi_tag-0xaf>
 268:	00 73 72             	add    BYTE PTR [rbx+0x72],dh
 26b:	61                   	(bad)
 26c:	6e                   	outs   dx,BYTE PTR ds:[rsi]
 26d:	64 00 73 74          	add    BYTE PTR fs:[rbx+0x74],dh
 271:	64 6f                	outs   dx,DWORD PTR fs:[rsi]
 273:	75 74                	jne    2e9 <__abi_tag-0x93>
 275:	00 5f 49             	add    BYTE PTR [rdi+0x49],bl
 278:	4f 5f                	rex.WRXB pop r15
 27a:	6c                   	ins    BYTE PTR es:[rdi],dx
 27b:	6f                   	outs   dx,DWORD PTR ds:[rsi]
 27c:	63 6b 5f             	movsxd ebp,DWORD PTR [rbx+0x5f]
 27f:	74 00                	je     281 <__abi_tag-0xfb>

Disassembly of section .debug_line_str:

0000000000000000 <.debug_line_str>:
   0:	67 75 65             	addr32 jne 68 <__abi_tag-0x314>
   3:	73 73                	jae    78 <__abi_tag-0x304>
   5:	2e 63 00             	cs movsxd eax,DWORD PTR [rax]
   8:	2f                   	(bad)
   9:	68 6f 6d 65 2f       	push   0x2f656d6f
   e:	68 75 61 6e 67       	push   0x676e6175
  13:	61                   	(bad)
  14:	6e                   	outs   dx,BYTE PTR ds:[rsi]
  15:	74 2f                	je     46 <__abi_tag-0x336>
  17:	6d                   	ins    DWORD PTR es:[rdi],dx
  18:	79 70                	jns    8a <__abi_tag-0x2f2>
  1a:	72 6f                	jb     8b <__abi_tag-0x2f1>
  1c:	67 2f                	addr32 (bad)
  1e:	78 2f                	js     4f <__abi_tag-0x32d>
  20:	75 6e                	jne    90 <__abi_tag-0x2ec>
  22:	69 78 5f 70 72 6f 67 	imul   edi,DWORD PTR [rax+0x5f],0x676f7270
  29:	2f                   	(bad)
  2a:	70 72                	jo     9e <__abi_tag-0x2de>
  2c:	6f                   	outs   dx,DWORD PTR ds:[rsi]
  2d:	63 65 6e             	movsxd esp,DWORD PTR [rbp+0x6e]
  30:	76 00                	jbe    32 <__abi_tag-0x34a>
  32:	2f                   	(bad)
  33:	75 73                	jne    a8 <__abi_tag-0x2d4>
  35:	72 2f                	jb     66 <__abi_tag-0x316>
  37:	6c                   	ins    BYTE PTR es:[rdi],dx
  38:	69 62 2f 67 63 63 2f 	imul   esp,DWORD PTR [rdx+0x2f],0x2f636367
  3f:	78 38                	js     79 <__abi_tag-0x303>
  41:	36 5f                	ss pop rdi
  43:	36 34 2d             	ss xor al,0x2d
  46:	6c                   	ins    BYTE PTR es:[rdi],dx
  47:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  4e:	75 2f                	jne    7f <__abi_tag-0x2fd>
  50:	31 32                	xor    DWORD PTR [rdx],esi
  52:	2f                   	(bad)
  53:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  5a:	00 2f                	add    BYTE PTR [rdi],ch
  5c:	75 73                	jne    d1 <__abi_tag-0x2ab>
  5e:	72 2f                	jb     8f <__abi_tag-0x2ed>
  60:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  67:	2f                   	(bad)
  68:	78 38                	js     a2 <__abi_tag-0x2da>
  6a:	36 5f                	ss pop rdi
  6c:	36 34 2d             	ss xor al,0x2d
  6f:	6c                   	ins    BYTE PTR es:[rdi],dx
  70:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  77:	75 2f                	jne    a8 <__abi_tag-0x2d4>
  79:	62                   	(bad)
  7a:	69 74 73 00 2f 75 73 	imul   esi,DWORD PTR [rbx+rsi*2+0x0],0x7273752f
  81:	72 
  82:	2f                   	(bad)
  83:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  8a:	2f                   	(bad)
  8b:	78 38                	js     c5 <__abi_tag-0x2b7>
  8d:	36 5f                	ss pop rdi
  8f:	36 34 2d             	ss xor al,0x2d
  92:	6c                   	ins    BYTE PTR es:[rdi],dx
  93:	69 6e 75 78 2d 67 6e 	imul   ebp,DWORD PTR [rsi+0x75],0x6e672d78
  9a:	75 2f                	jne    cb <__abi_tag-0x2b1>
  9c:	62                   	(bad)
  9d:	69 74 73 2f 74 79 70 	imul   esi,DWORD PTR [rbx+rsi*2+0x2f],0x65707974
  a4:	65 
  a5:	73 00                	jae    a7 <__abi_tag-0x2d5>
  a7:	2f                   	(bad)
  a8:	75 73                	jne    11d <__abi_tag-0x25f>
  aa:	72 2f                	jb     db <__abi_tag-0x2a1>
  ac:	69 6e 63 6c 75 64 65 	imul   ebp,DWORD PTR [rsi+0x63],0x6564756c
  b3:	00 73 74             	add    BYTE PTR [rbx+0x74],dh
  b6:	64 64 65 66 2e 68 00 	fs fs gs cs pushw 0x7400
  bd:	74 
  be:	79 70                	jns    130 <__abi_tag-0x24c>
  c0:	65 73 2e             	gs jae f1 <__abi_tag-0x28b>
  c3:	68 00 73 74 72       	push   0x72747300
  c8:	75 63                	jne    12d <__abi_tag-0x24f>
  ca:	74 5f                	je     12b <__abi_tag-0x251>
  cc:	46                   	rex.RX
  cd:	49                   	rex.WB
  ce:	4c                   	rex.WR
  cf:	45                   	rex.RB
  d0:	2e 68 00 73 74 64    	cs push 0x64747300
  d6:	69 6f 2e 68 00 74 69 	imul   ebp,DWORD PTR [rdi+0x2e],0x69740068
  dd:	6d                   	ins    DWORD PTR es:[rdi],dx
  de:	65 5f                	gs pop rdi
  e0:	74 2e                	je     110 <__abi_tag-0x26c>
  e2:	68 00 73 74 64       	push   0x64747300
  e7:	6c                   	ins    BYTE PTR es:[rdi],dx
  e8:	69 62 2e 68 00 75 6e 	imul   esp,DWORD PTR [rdx+0x2e],0x6e750068
  ef:	69 73 74 64 2e 68 00 	imul   esi,DWORD PTR [rbx+0x74],0x682e64
  f6:	74 69                	je     161 <__abi_tag-0x21b>
  f8:	6d                   	ins    DWORD PTR es:[rdi],dx
  f9:	65                   	gs
  fa:	2e                   	cs
  fb:	68                   	.byte 0x68
	...
