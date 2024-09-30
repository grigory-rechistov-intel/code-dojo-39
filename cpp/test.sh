#!/bin/sh

./build/Debug/song.exe | diff -U 3 -a --strip-trailing-cr - ref.txt
if [ $? != 0 ]
then
    echo FAIL
    exit 1
fi
