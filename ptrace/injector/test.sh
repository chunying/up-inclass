#!/bin/sh

ARCH=64
if [ ! -z "$1" ]; then
	ARCH=$1
fi

./tick${ARCH} &
PID=$!
PWD=`pwd`

echo pid = $PID

cat /proc/$PID/maps | grep $PWD
sleep 3

./injector${ARCH} $PID ./sample${ARCH}.so

cat /proc/$PID/maps | grep $PWD
sleep 3
kill $PID

