#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/breakout
else
    ./build/debug/breakout
fi