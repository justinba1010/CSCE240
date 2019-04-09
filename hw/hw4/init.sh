#! /usr/bin/bash

macflag=true
gcompiler=g++-8

if [ $macflag = true ]; then
  alias g++=$gcompiler;
  echo "Changing for Mac Compilation";
fi

