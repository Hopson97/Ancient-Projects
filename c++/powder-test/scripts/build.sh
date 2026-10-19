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
    if [ -d "$powder-test" ]
    then
        rm -rf -d powder-test
    fi

    mkdir -p powder-test
fi

# Creates the folder for the buildaries
mkdir -p powder-test 
mkdir -p powder-test/assets
mkdir -p build
mkdir -p build/release
mkdir -p build/debug
cd build

# Builds target
if [ "$1" = "release" ]
then
    target_release
    cp build/release/powder-test powder-test/powder-test
else
    target_debug
fi

cp -R assets powder-test/
