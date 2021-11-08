#include "Chessboard.h"
#include <gtest/gtest.h>

using namespace crazy_rooks;

TEST(DrawBoardTest, BasicTest) {
  Chessboard board;
  board.drawBoard();
  // std::cout << "[TEST] - OK!" << std::endl;
  // std::cout << "\033[30;107m [WHITE] X \033[0m" << std::endl;
  // std::cout << "\033[30;100m [BLACK] X \033[0m" << std::endl;
}