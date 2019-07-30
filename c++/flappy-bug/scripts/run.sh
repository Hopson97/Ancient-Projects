#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/op-flappy-bug 
else
    ./bin/debug/op-flappy-bug 
fi