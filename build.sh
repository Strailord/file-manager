#!/bin/bash
mkdir -p build
cd build
cmake ..
make 
rm CMakeCache.txt
rm -r CMakeFiles
rm cmake_install.cmake
rm Makefile
