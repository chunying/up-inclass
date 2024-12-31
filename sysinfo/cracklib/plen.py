#!/usr/bin/env python3
# -*- coding: utf-8 -*-

f = open("cracklib-small.0", "rt");
for l in f.readlines():
    l = l.strip();
    print(len(l), l);
f.close();

# vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4 number cindent fileencoding=utf-8 :
