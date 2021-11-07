cmake_minimum_required(VERSION 3.0.0)
project(CrazyChessTowers VERSION 1.0.0)

set(CRAZY_CHESS_TOWERS_LIB CrazyChessTowersLib)
file(GLOB CRAZY_CHESS_TOWERS_LIB_SRC CONFIGURE_DEPENDS src/*.cpp)

add_library(${CRAZY_CHESS_TOWERS_LIB} STATIC
  ${CRAZY_CHESS_TOWERS_LIB_SRC}
)

target_include_directories(${CRAZY_CHESS_TOWERS_LIB}
  PUBLIC
    include
)

if (BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
