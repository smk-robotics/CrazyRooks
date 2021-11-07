find_package(GTest REQUIRED)

set(DRAW_BOARD_TEST DrawBoardTest)
file(GLOB DRAW_BOARD_TEST_SRC CONFIGURE_DEPENDS *.cpp)


add_executable(${DRAW_BOARD_TEST}
  ${DRAW_BOARD_TEST_SRC}
)

target_link_libraries(${DRAW_BOARD_TEST}
  GTest::Main
  ${CRAZY_CHESS_TOWERS_LIB}
)

gtest_discover_tests(${DRAW_BOARD_TEST})