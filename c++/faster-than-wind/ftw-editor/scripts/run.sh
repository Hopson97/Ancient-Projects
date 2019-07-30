#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/ftw-editor 
else
    ./bin/debug/ftw-editor 
fi