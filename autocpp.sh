#!/bin/bash

INPUT_FILE='input.txt'

# Check if arguments passed are OK
if [ $# -le 0 ]
then
    echo "Usage: ./autocpp.sh <Program File> [<input-file>]"
    echo "
✳️ This script will compile the given file
✳️ Take input from ./input.txt or <input-file> and save to ./output.txt
✳️ If <verify-file> is provided then it compares with ./output.txt
"
    GCC_VERSION=`g++ --version | head -n1`
    echo "NOTE: Program file should compile using ${GCC_VERSION}"
    exit 1
fi

if [ "$#" -eq "2" ]; then
    INPUT_FILE=$2
fi

if [ ! -f "$1" ]; then
    echo "Program File '$1' does not exist."
    exit 1
fi

if [ ! -f "$INPUT_FILE" ]; then
    echo "Input File '$INPUT_FILE' does not exist."
    exit 1
fi

EXTRA_ARGS="-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector"

g++ $EXTRA_ARGS -o program "$1" -DLOCAL
ans=`./program < $INPUT_FILE`
echo "$ans" > output.txt
cat output.txt
rm program

exit 0