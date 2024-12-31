#!/usr/bin/env python3
# -*- coding: utf-8 -*-

f = open('systbl_x86_64.txt', 'rt');
for l in f.readlines():
    l = l.strip().split('\t');
    print(l[0], l[1], len(l[2:]));

# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
