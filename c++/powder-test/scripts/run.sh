#!/bin/bash

if [ "$1" = "release" ]
then
    ./build/release/powder-test
else
    ./build/debug/powder-test
fi