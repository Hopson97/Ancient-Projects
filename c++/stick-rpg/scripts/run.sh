#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/stick-rpg
else
    ./build/debug/stick-rpg
fi