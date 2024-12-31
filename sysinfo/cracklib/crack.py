#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time;
from crypt import crypt

target = "$6$CaP7vQ/f$Puo5/OmR7P2lD0BvqEl5ZW4bqW4wPNKBGhj.kTUSwcfqj18wMdl36h2smX0ZUaT6buYKSeXhw13RR6oBpIfZv0" # hello

k = []
f = open("./cracklib-small", "rt");
for l in f.readlines():
    l = l.strip();
    k.append(l);
f.close();

print("read done.");
    
t0 = time.time();
for p in k:
    if crypt(p, target) == target:
        print("password = " + p);
        break;
t1 = time.time();

print(t1 - t0);

# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
