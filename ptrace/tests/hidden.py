#!/usr/bin/env python3
# -*- coding: utf-8 -*-

key = 0x87
msg = "<5ImPle_XOR_Ba5ed_3nc0dIn9_*^_^*_>\n";

print(", ".join(["{:d}".format(ord(m) ^ 0x87) for m in msg]));

# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
