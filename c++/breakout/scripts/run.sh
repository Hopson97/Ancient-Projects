#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/breakout-old 
else
    ./bin/debug/breakout-old 
fi