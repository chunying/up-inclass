#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time;
from crypt import crypt

#target = "$6$CaP7vQ/f$Puo5/OmR7P2lD0BvqEl5ZW4bqW4wPNKBGhj.kTUSwcfqj18wMdl36h2smX0ZUaT6buYKSeXhw13RR6oBpIfZv0" # hello
#target = "$6$vl86EdHs$VMRCUzM9kzzCKgnN7xk/jhQoh9kNo8fNUOUC6sZ93ztSfcLwaHLGOMZg/KJpBxNMTCitDnuWh653ejL42gsrg0"; # aaa
target = "$6$t6vrgsty$Aa2FoMopYqliHRjZA/SPwHs4XWIMktGIy138XTCCBcJdyVuq0mhuLS/.gNs1MB9MzxmerRp2kYaSGvmuOkrDO."; # xyz

def guess(password, curr, limit):
        global target;
        if curr >= limit:
            test = crypt(password, target);
            return password if test == target else None;
        for i in range(0, 26):
            ret = guess(password + chr(i + 0x61), curr+1, limit);
            if ret != None: return ret;
        return None;

t0 = time.time();
for i in range(1, 6):
    print("length = " + str(i));
    g = guess("", 0, i);
    if g != None:
        print("password = " + g);
        break;
t1 = time.time();
print(t1 - t0);


# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
