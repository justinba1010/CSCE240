#!/bin/bash
# Simple quick script for easier debugging and playing around 
if [ "$#" -ne 2 ]; then
if [ "$#" -ne 3 ] ; then
echo "To compile program run ./compile.sh filename output run_arg";
echo "The executable will be in ./output, or you can put any argument in for run_arg, and it will run";
exit;
fi
fi
EXIT=0;
g++ -std=c++11 -Wall -o $2 $1

if [ "$#" -ne 2 ]; then
echo "Successfully compiled, now running."
"./$2"
else
echo "Successfully compiled, located at ./$2"
fi
