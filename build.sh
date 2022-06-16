#!/bin/bash

cd _build

cmake -DCMAKE_PREFIX_PATH=C:/Users/Johannes/home/Develop/lib/boost_1_76_0 \
      -DWLT_DIR=C:/Users/Johannes/home/Develop/lib/WTL10_10320_Release \
      -DLLVM_PREFIX=/mingw64 \
      -DCMAKE_TOOLCHAIN_FILE=../cmake/Toolchain-llvm-mingw.cmake \
      -DMSVC_BASE=C:/Users/Johannes/home/Develop/lib/msvc/14.29.30133 \
      -DWINSDK_BASE=C:/Users/Johannes/home/Develop/lib/winsdk \
      -DCMAKE_BUILD_TYPE=Release \
      -G "MinGW Makefiles" \
      ..

cmake --build .