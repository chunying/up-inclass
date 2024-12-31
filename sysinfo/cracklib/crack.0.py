#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time;
from crypt import crypt

target = "$6$CaP7vQ/f$Puo5/OmR7P2lD0BvqEl5ZW4bqW4wPNKBGhj.kTUSwcfqj18wMdl36h2smX0ZUaT6buYKSeXhw13RR6oBpIfZv0" # hello
target = "$6$vl86EdHs$VMRCUzM9kzzCKgnN7xk/jhQoh9kNo8fNUOUC6sZ93ztSfcLwaHLGOMZg/KJpBxNMTCitDnuWh653ejL42gsrg0"; # aaa
target = "$6$t6vrgsty$Aa2FoMopYqliHRjZA/SPwHs4XWIMktGIy138XTCCBcJdyVuq0mhuLS/.gNs1MB9MzxmerRp2kYaSGvmuOkrDO."; # xyz

f = open("./cracklib-small", "rt");
t0 = time.time();
for l in f.readlines():
    l = l.strip();
    if crypt(l, target) == target:
        print("password = " + l);
        break;
t1 = time.time();
f.close();

print(t1 - t0);

# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
