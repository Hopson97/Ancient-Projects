#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/doodle-jump 
else
    ./bin/debug/doodle-jump 
fi