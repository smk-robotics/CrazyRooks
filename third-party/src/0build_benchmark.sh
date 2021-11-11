#!/bin/bash 
source environment

mkdir -p ${PREFIX}
cd ./benchmark
mkdir -p BUILD_DIR
cd BUILD_DIR
cmake -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} -DBENCHMARK_ENABLE_GTEST_TESTS=NO -DBENCHMARK_ENABLE_TESTING=NO -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_LTO=true ..
      
make ${MAKEOPTS}
make install
cd ..
rm -fr BUILD_DIR
