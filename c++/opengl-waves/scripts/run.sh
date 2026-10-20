#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/gl-waves
else
    ./build/debug/gl-waves
fi