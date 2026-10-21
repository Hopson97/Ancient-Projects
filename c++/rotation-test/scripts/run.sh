#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/rotation-test
else
    ./build/debug/rotation-test
fi