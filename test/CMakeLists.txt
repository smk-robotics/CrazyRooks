find_package(GTest REQUIRED)

set(CRAZY_ROOKS_TEST CrazyRooksTest)
file(GLOB CRAZY_ROOKS_TEST_SRC CONFIGURE_DEPENDS *.cpp)


add_executable(${CRAZY_ROOKS_TEST}
  ${CRAZY_ROOKS_TEST_SRC}
)

target_link_libraries(${CRAZY_ROOKS_TEST}
  GTest::Main
  ${CRAZY_ROOKS_LIB}
)

gtest_discover_tests(${CRAZY_ROOKS_TEST})