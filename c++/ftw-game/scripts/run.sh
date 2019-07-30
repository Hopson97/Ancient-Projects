#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/op-ftw-game 
else
    ./bin/debug/op-ftw-game 
fi