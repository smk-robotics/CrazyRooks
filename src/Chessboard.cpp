/**
 * @file Chessboard.cpp
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Full chessboard class implementation.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 * 
 */
#include <iostream>
#include "Chessboard.h"
#include "AbstractFigure.h"

namespace crazy_chess_towers {

Chessboard::Chessboard() {
  colorizeBoard_();
}

bool Chessboard::addFigure(const Square &square, const FigureType figureType) noexcept {
  if (square.isEmpty()) {
    // figures_.emplace_back(std::make_shared<figure>);
  }
}

std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT> Chessboard::squares() noexcept {
  return squares_;
}

std::vector<std::shared_ptr<AbstractFigure>> Chessboard::figures() noexcept {
  return figures_;
}

void Chessboard::drawBoard() const noexcept {
  std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
  for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
    std::cout << CHESS_BOARD_HEIGHT - row << " ";
    for (auto col = 0; col < CHESS_BOARD_HEIGHT; ++col) {
      std::cout << squares_[row][col]; 
    }
    std::cout << " " << CHESS_BOARD_HEIGHT - row << std::endl;
  }
  std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
}

void Chessboard::colorizeBoard_() noexcept {
  for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
    for (auto col = 0; col < CHESS_BOARD_HEIGHT; ++col) {
      if ((col + row) % 2 == 0) {
        squares_[row][col] = Square(WHITE);
      } else {
        squares_[row][col] = Square(BLACK);
      }
    }
  }
} 

} // namespace crazy_chess_towers