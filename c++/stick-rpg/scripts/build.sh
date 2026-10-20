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
    if [ -d "$stick-rpg" ]
    then
        rm -rf -d stick-rpg
    fi

    mkdir -p stick-rpg
fi

# Creates the folder for the buildaries
mkdir -p stick-rpg 
mkdir -p stick-rpg/assets
mkdir -p build
mkdir -p build/release
mkdir -p build/debug
cd build

# Builds target
if [ "$1" = "release" ]
then
    target_release
    cp build/release/stick-rpg stick-rpg/stick-rpg
else
    target_debug
fi

cp -R assets stick-rpg/
