#!/usr/bin/env bash

cd $HOME/Src/goldfish

if [[ -d build ]]; then
    cd build
else
    mkdir build
    cd build
fi

cmake -D CMAKE_C_COMPILER=gcc-10 -D CMAKE_CXX_COMPILER=g++-10 ..

