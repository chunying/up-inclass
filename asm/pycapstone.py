#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
from pwn import *

if len(sys.argv) < 2: print(f'usage: {sys.argv[0]} elf-executable'), sys.exit(1)

context.update(arch='amd64', os='linux')
elf = ELF(sys.argv[1])
text = list(filter(lambda x: x.name == '.text', elf.sections))[0] # only the 1st obj
addr, off, sz = text.header['sh_addr'], text.header['sh_offset'], text.header['sh_size']

payload = b''
with open(sys.argv[1], 'rb') as f: payload = f.read()[off:off+sz]
print('--- pwntools'), print(disasm(payload))

import capstone
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
print('--- capstone')
for i in md.disasm(payload, addr):
    codes = ' '.join(f'{b:02x}' for b in i.bytes)
    print('0x{:6x}:   {:<23s} {} {}'.format(i.address, codes, i.mnemonic, i.op_str))

# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
