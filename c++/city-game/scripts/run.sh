#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/city-game 
else
    ./bin/debug/city-game 
fi