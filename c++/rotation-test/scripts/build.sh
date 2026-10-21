#!/bin/bash

target_release() {
    cd release
    cmake -DCMAKE_BUILD_TYPE=Release ../..
    make
    echo "Built target in build/release/"
    cd ../..
}

target_debug() {
    cd debug 
    cmake -DCMAKE_BUILD_TYPE=Debug ../..
    make
    echo "Built target in build/debug/"
    cd ../..
}

# Create folder for distribution
if [ "$1" = "release" ]
then
    if [ -d "$rotation-test" ]
    then
        rm -rf -d rotation-test
    fi

    mkdir -p rotation-test
fi

# Creates the folder for the buildaries
mkdir -p rotation-test 
mkdir -p rotation-test/assets
mkdir -p build
mkdir -p build/release
mkdir -p build/debug
cd build

# Builds target
if [ "$1" = "release" ]
then
    target_release
    cp build/release/rotation-test rotation-test/rotation-test
else
    target_debug
fi

cp -R assets rotation-test/
