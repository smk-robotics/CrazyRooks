#include "Chessboard.h"
#include "RookFigure.h"
#include <gtest/gtest.h>

using namespace crazy_rooks;

TEST(ChessBoardTest, BasicTest) {
  Chessboard board;
  for (auto col = 0; col < CHESS_BOARD_WIDTH; ++col) {
    for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
      bool squareEmpty = false;
      ASSERT_NO_THROW(squareEmpty = board.squares()->at(0)[0].isEmpty());
      ASSERT_TRUE(squareEmpty);
    }
  }
  ASSERT_EQ(board.figures()->size(), 0);
}

TEST(ChessBoardTest, AddFigureTest) {
  auto board = std::make_shared<Chessboard>();
  ASSERT_EQ(board->figures()->size(), 0);
  ASSERT_TRUE(board->addFigure({0, 0}, std::make_shared<RookFigure>(board)));
  ASSERT_EQ(board->figures()->size(), 1);
  ASSERT_FALSE(board->squares()->at(0)[0].isEmpty());
  ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->column(), 0);
  ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->row(), 0);
}

// TEST(ChessBoardTest, AddSameFigureTest) {
//   Chessboard board;
//   ASSERT_EQ(board.figures()->size(), 0);
//   auto rook = std::make_shared<RookFigure>(board);
//   ASSERT_TRUE(board.addFigure({0, 0}, rook));
//   ASSERT_EQ(board.figures()->size(), 1);
//   ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
//   ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->column(), 0);
//   ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->row(), 0);
//   ASSERT_FALSE(board.addFigure({3,3}, rook));
//   ASSERT_EQ(board.figures()->size(), 1);
// }

// TEST(ChessBoardTest, AddFigureToOccupiedSquareTest) {
//   Chessboard board;
//   ASSERT_EQ(board.figures()->size(), 0);
//   ASSERT_TRUE(board.addFigure({0, 0}, std::make_shared<RookFigure>(board)));
//   ASSERT_EQ(board.figures()->size(), 1);
//   ASSERT_FALSE(board.squares()->at(0)[0].isEmpty());
//   ASSERT_FALSE(board.addFigure({0, 0}, std::make_shared<RookFigure>(board)));
//   ASSERT_EQ(board.figures()->size(), 1);
// }

// TEST(ChessBoardTest, AddMultipleFiguresTest) {
//   Chessboard board;
//   ASSERT_EQ(board.figures()->size(), 0);
//   auto figuresIterator = board.figures();
//   for (uint8_t i = 0; i < 8; ++i) {
//     ASSERT_TRUE(board.addFigure({i, i}, std::make_shared<RookFigure>(board)));
//     ASSERT_EQ(board.figures()->size(), i + 1);
//     ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->column(), i);
//     ASSERT_EQ(board.figures()->begin()->get()->square()->coordinates()->row(), i);
//     ++figuresIterator;
//   }
//   board.drawBoard();
// }

TEST(ChessBoardTest, MoveFigureTest) {
  auto board = std::make_shared<Chessboard>();
  ASSERT_EQ(board->figures()->size(), 0);
  ASSERT_TRUE(board->addFigure({0, 0}, std::make_shared<RookFigure>(board)));
  ASSERT_FALSE(board->squares()->at(0)[0].isEmpty());
  ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->column(), 0);
  ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->row(), 0);
  // board->drawBoard();
  ASSERT_TRUE(board->figures()->begin()->get()->move());
  // ASSERT_TRUE(board->squares()->at(0)[0].isEmpty());
  // ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->column(), 3);
  // ASSERT_EQ(board->figures()->begin()->get()->square()->coordinates()->row(), 3);
  ASSERT_FALSE(board->squares()->at(3)[3].isEmpty());
  board->drawBoard();
}