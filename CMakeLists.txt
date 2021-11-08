cmake_minimum_required(VERSION 3.0.0)
project(CrazyRooks VERSION 1.0.0)

set(CRAZY_ROOKS_LIB CrazyRooksLib)
file(GLOB CRAZY_ROOKS_LIB_SRC CONFIGURE_DEPENDS src/*.cpp)

add_library(${CRAZY_ROOKS_LIB} STATIC
  ${CRAZY_ROOKS_LIB_SRC}
)

target_include_directories(${CRAZY_ROOKS_LIB}
  PUBLIC
    include
)

if (BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
