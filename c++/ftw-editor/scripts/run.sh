#!/bin/bash

if [ "$1" = "release" ]
then
    ./bin/release/op-ftw-editor 
else
    ./bin/debug/op-ftw-editor 
fi