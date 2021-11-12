# Linking third party gtest, gmock and benchmark libraries.
set(GTEST_DIR ${PROJECT_SOURCE_DIR}/third-party/out/lib)
set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/third-party/out/lib)
set(GTEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/third-party/out/include)
include_directories(${PROJECT_SOURCE_DIR}/third-party/out/include)

find_package(GTest REQUIRED)

set(CRAZY_ROOKS_TEST CrazyRooksTest)
file(GLOB CRAZY_ROOKS_TEST_SRC CONFIGURE_DEPENDS *.cpp)


add_executable(${CRAZY_ROOKS_TEST}
  ${CRAZY_ROOKS_TEST_SRC}
)

target_link_libraries(${CRAZY_ROOKS_TEST}
  ${GTEST_LIBRARIES}
  ${CRAZY_ROOKS_LIB}
)

gtest_discover_tests(${CRAZY_ROOKS_TEST})