#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/breakout 
else
    ./bin/debug/breakout 
fi