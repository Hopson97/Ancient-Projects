#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/stick-rpg 
else
    ./bin/debug/stick-rpg 
fi