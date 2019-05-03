#!/bin/sh

grep '	gensys' libsys64.asm | awk '{print "extern sys_"$3}'

