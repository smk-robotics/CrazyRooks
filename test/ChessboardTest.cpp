#include "Chessboard.h"
#include "TowerFigure.h"
#include <gtest/gtest.h>

using namespace crazy_chess_towers;

TEST(ChessBoardTest, BasicTest) {
  Chessboard board;
  for (auto col = 0; col < CHESS_BOARD_WIDTH; ++col) {
    for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
      bool squareEmpty = false;
      ASSERT_NO_THROW(squareEmpty = board.squares().at(0)[0].isEmpty());
      ASSERT_TRUE(squareEmpty);
    }
  }
  ASSERT_EQ(board.figures().size(), 0);
}

TEST(ChessBoardTest, AddFigureTest) {
  Chessboard board;
  ASSERT_EQ(board.figures().size(), 0);
  std::shared_ptr<TowerFigure> tower;
  ASSERT_NO_THROW(board.addFigure(board.squares().at(0)[0], TOWER));
  ASSERT_EQ(board.figures().size(), 1);
}