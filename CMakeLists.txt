cmake_minimum_required(VERSION 3.0.0)
project(CrazyRooks VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Werror -Wextra)

set(CRAZY_ROOKS_LIB CrazyRooksLib)
file(GLOB CRAZY_ROOKS_LIB_SRC CONFIGURE_DEPENDS src/${CRAZY_ROOKS_LIB}/*.cpp)

add_library(${CRAZY_ROOKS_LIB} SHARED
  ${CRAZY_ROOKS_LIB_SRC}
)

target_link_libraries(${CRAZY_ROOKS_LIB} 
  PUBLIC
    pthread
)

target_include_directories(${CRAZY_ROOKS_LIB}
  PUBLIC
    include/${CRAZY_ROOKS_LIB}
)

add_executable(${PROJECT_NAME}
  src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
  ${CRAZY_ROOKS_LIB}
)

if (BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
