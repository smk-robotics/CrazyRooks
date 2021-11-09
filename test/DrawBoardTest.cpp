#include "Chessboard.h"
#include <gtest/gtest.h>

using namespace crazy_rooks;

TEST(DrawBoardTest, BasicTest) {
  Chessboard board;
  board.drawBoard();
}