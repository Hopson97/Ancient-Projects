#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/op-dive 
else
    ./bin/debug/op-dive 
fi