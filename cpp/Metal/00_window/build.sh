#!/bin/bash
set -e

cd "$(dirname "$0")"
mkdir -p build


# echo "Compiling Shaders..."
# xcrun -sdk macosx metal -c src/shaders.metal -o build/shaders.air
# xcrun -sdk macosx metallib build/shaders.air -o build/shaders.metallib.tmp
# mv build/shaders.metallib.tmp build/shaders.metallib


clang++ -g -O0 \
    -std=c++17 -fno-exceptions -fno-rtti \
    -Wno-deprecated \
    -I ../includes/ \
    -framework MetalKit -framework Foundation -framework Metal  \
    main.cpp \
    -o build/program

