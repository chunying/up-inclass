#!/bin/sh

python3 -c 'print("0x1234\x00" + "\x00"*9 + "\x34\x12\x00\x00")' | hexdump -C
python3 -c 'print("0x1234\x00" + "\x00"*9 + "\x34\x12\x00\x00")' | ./guess

