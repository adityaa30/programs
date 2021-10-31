#!/bin/bash
set -f
IFS=$'\n';

CHECK_DIR=`./`

if [ $# == 1 ]
then
    CHECK_DIR=$1
    if [ ! -d "$1" ]; then
        echo "Directory '$1' does not exist."
        exit 0
    fi
fi


CPP_FILES=`find $CHECK_DIR -name '*.cpp'`

if ! command -v uuidgen &> /dev/null
then
    TEST_PROG_FILE=`head /dev/urandom | tr -dc A-Za-z0-9 | head -c 10 ; echo ''`
else
    TEST_PROG_FILE=`uuidgen`
fi



TEST_EXIT_STATUS=0

echo "Checking if all *.cpp files compiles successfully 🙃 inside $CHECK_DIR directory"

for path in $CPP_FILES
do
    # To support programs using pthread we add flag
    # TODO: Use pthread flag only when required
    EXTRA_ARGS="-std=c++17"
    HEADER_PATH="-I$(pwd)/Templates"
    g++ $EXTRA_ARGS $HEADER_PATH -o $TEST_PROG_FILE $path -pthread

    
    if [ -f $TEST_PROG_FILE ];
    then
        echo "$path: ✅"
        rm $TEST_PROG_FILE
    else
        echo "$path: ❌"
        TEST_EXIT_STATUS=1
    fi
done

unset IFS; set +f

exit $TEST_EXIT_STATUS