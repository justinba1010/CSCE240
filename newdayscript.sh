#!/bin/bash
echo $1
mkdir $1
cp ./makefile ./$1
cp ./compile.sh ./$1
