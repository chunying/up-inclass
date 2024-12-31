#!/usr/bin/env python

import sys
import hashlib
import random
import crypt
import getpass

def salt(n):
	ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890./"
	salt = ""
	for i in range(0, n):
		s = random.randint(0,63)
		salt = salt + ch[s:s+1]
	return salt

print("Password Demo");
p = getpass.getpass("Enter your password: ");
print("Your password is [{}]".format(p));

if len(sys.argv) > 1:
	s_des = sys.argv[1][0:2]
	s_md5 = "$1$" + sys.argv[1][0:8] + "$";
	s_sha256 = "$5$" + sys.argv[1][0:8] + "$";
	s_sha512 = "$6$" + sys.argv[1][0:8] + "$";
else:
	s_des = salt(2);
	s_md5 = "$1$" + salt(8) + "$";
	s_sha256 = "$5$" + salt(8) + "$";
	s_sha512 = "$6$" + salt(8) + "$";

p_des = crypt.crypt(p, s_des)
p_md5 = crypt.crypt(p, s_md5)
p_sha256 = crypt.crypt(p, s_sha256)
p_sha512 = crypt.crypt(p, s_sha512)

print("    DES: {:<2d} {}".format(len(p_des) - 2, p_des));
print("    MD5: {:<2d} {}".format(len(p_md5) - 12, p_md5));
print(" SHA256: {:<2d} {}".format(len(p_sha256) - 12, p_sha256));
print(" SHA512: {:<2d} {}".format(len(p_sha512) - 12, p_sha512));

