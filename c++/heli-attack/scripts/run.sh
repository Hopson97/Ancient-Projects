#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/heli-attack 
else
    ./bin/debug/heli-attack 
fi