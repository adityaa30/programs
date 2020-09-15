#!/bin/bash

# set -e

# Check if arguments passed are OK
if [ $# != 3 ]
then
    echo "Usage: ./check.sh <Program File> <Correct Program File> <Generator File>"
    echo "
✳️ Use this script with
    1) Original Algorithm Program C++ file
    2) Safe & Working Algorithm Program C++ file (Brute Force 🤔)
    3) Program which will be used to generate test case - Generator

✳️ Script will generate at most 500 test cases and stop whenever output
of (1) and (2) differ showing both the input & outputs.
"

    GCC_VERSION=`g++ --version | head -n1`
    echo "NOTE: All files should compile using ${GCC_VERSION}"
    exit 0
fi

if [ ! -f "$1" ]; then
    echo "Program File '$1' does not exist."
    exit 0
fi

if [ ! -f "$2" ]; then
    echo "Correct Program File '$2' does not exist."
    exit 0
fi

if [ ! -f "$3" ]; then
    echo "Generator File '$3' does not exist."
    exit 0
fi


HOME_DIR=`pwd`

# Create a new folder with random name to save generated data
TEST_DIR=`head /dev/urandom | tr -dc A-Za-z0-9 | head -c 10 ; echo ''`

mkdir -p $TEST_DIR
echo "Created folder $TEST_DIR 💿"

removeGeneratedFiles() {
    cd $HOME_DIR
    rm -rf $TEST_DIR

    echo "Deleted folder $TEST_DIR 📀"
    exit 0
}

# Set a trap so that we make sure generated files are always deleted
trap removeGeneratedFiles 0

g++ $1 -o $TEST_DIR/program
g++ $2 -o $TEST_DIR/safe
g++ $3 -o $TEST_DIR/generator

cd $TEST_DIR
for i in {1..5000}
do
  ./generator $i > input.txt
  ./program < input.txt > output_program.txt
  ./safe < input.txt > output_safe.txt
  DIFF=`diff -b output_program.txt output_safe.txt`

  if [ ! -z "${DIFF}" ]
  then
    echo -e "Wrong Answer on "
    echo -e "\n❌ Wrong answer on TEST CASE $i:\n"
    cat input.txt
    echo -e "\nOutput of $1:\n"
    cat output_program.txt
    echo -e "\nOutput of $2:\n"
    cat output_safe.txt
    break
  fi
  echo "$i ✅"
done

removeGeneratedFiles
