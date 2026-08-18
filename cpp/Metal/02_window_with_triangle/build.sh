set -e

mkdir -p build

clang++ -g -O0 -std=c++17 -fno-exceptions -fno-rtti -Wno-deprecated -I "../includes/" \
  -framework Metal -framework MetalKit -framework Foundation \
  main.cpp \
  -o build/program
