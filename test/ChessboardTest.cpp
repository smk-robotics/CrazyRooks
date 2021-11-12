#include "Chessboard.h"
#include "RookFigure.h"
#include <gtest/gtest.h>

using namespace crazy_rooks;

TEST(ChessBoardTest, BasicTest) {
  Chessboard board;
  for (auto col = 0; col < CHESS_BOARD_WIDTH; ++col) {
    for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
      bool squareEmpty = false;
      ASSERT_NO_THROW(squareEmpty = board.squares()->at(col)[row].isEmpty());
      ASSERT_TRUE(squareEmpty);
    }
  }
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 0);
}

TEST(ChessBoardTest, AddFigureTest) {
  auto board = std::make_shared<Chessboard>();
  ASSERT_EQ(static_cast<int>(board->figures()->size()), 0);
  ASSERT_TRUE(board->addFigure(std::make_shared<RookFigure>(&board->squares()->at(0)[0])));
  ASSERT_EQ(static_cast<int>(board->figures()->size()), 1);
  ASSERT_FALSE(board->squares()->at(0)[0].isEmpty());
  ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->column(), 0);
  ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->row(), 0);
}

TEST(ChessBoardTest, AddSameFigureTest) {
  Chessboard board;
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 0);
  auto rook = std::make_shared<RookFigure>(&board.squares()->at(0)[0]);
  ASSERT_TRUE(board.addFigure(rook));
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 1);
  ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
  ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->column(), 0);
  ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->row(), 0);
  ASSERT_FALSE(board.addFigure(rook));
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 1);
}

TEST(ChessBoardTest, AddFigureToOccupiedSquareTest) {
  Chessboard board;
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 0);
  ASSERT_TRUE(board.addFigure(std::make_shared<RookFigure>(&board.squares()->at(0)[0])));
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 1);
  ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
  ASSERT_THROW(board.addFigure(std::make_shared<RookFigure>(&board.squares()->at(0)[0])), std::logic_error);
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 1);
}

TEST(ChessBoardTest, AddMultipleFiguresTest) {
  Chessboard board;
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 0);
  auto figuresIterator = board.figures();
  for (uint8_t i = 0; i < 8; ++i) {
    ASSERT_TRUE(board.addFigure(std::make_shared<RookFigure>(&board.squares()->at(i)[i])));
    ASSERT_EQ(static_cast<int>(board.figures()->size()), i + 1);
    ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->column(), i);
    ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->row(), i);
    ++figuresIterator;
  }
}

TEST(ChessBoardTest, MoveFigureTest) {
  Chessboard board;
  ASSERT_EQ(static_cast<int>(board.figures()->size()), 0);
  ASSERT_TRUE(board.addFigure(std::make_shared<RookFigure>(&board.squares()->at(0)[0])));
  ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
  ASSERT_NO_THROW(board.figures()->begin()->get()->move());
  ASSERT_TRUE(board.squares()->at(0)[0].isEmpty());
}

TEST(ChessBoardTest, MultipleMovementFigureTest) {
  Chessboard board;
  ASSERT_TRUE(board.addFigure(std::make_shared<RookFigure>(&board.squares()->at(0)[0])));
  for (auto i = 0; i < 10; ++i) {
    ASSERT_NO_THROW(board.figures()->begin()->get()->move());
  }
}

TEST(ChessBoardTest, RandomMovementFigureTest) {
  Chessboard board;
  ASSERT_TRUE(board.addFigure(std::make_shared<RookFigure>(&board.squares()->at(0)[0])));
  ASSERT_NO_THROW(board.figures()->begin()->get()->startRandomMove(50));
}