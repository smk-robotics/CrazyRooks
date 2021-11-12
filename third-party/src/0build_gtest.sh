#!/bin/bash 
source environment

mkdir -p ${PREFIX}
cd ./gtest
mkdir -p BUILD_DIR
cd BUILD_DIR
cmake -DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
      -DBUILD_GTEST=ON \
      -DBUILD_SHARED_LIBS=ON \
      -Dgtest_build_tests=OFF \
      -Dgmock_build_tests=OFF  ..
      
make ${MAKEOPTS}
make install
cd ..
rm -fr BUILD_DIR
