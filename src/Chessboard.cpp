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

namespace crazy_rooks {

Chessboard::Chessboard() {
  colorizeBoard_();
}

bool Chessboard::addFigure(Square &square, const std::shared_ptr<AbstractFigure> &figurePtr) noexcept {
  if (!square.isEmpty()) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Square is not empty." << std::endl;
    return false;
  }
  if (!square.setFigure(figurePtr)) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Can't set figure to square." << std::endl;
    return false;
  }
  if (figures_.find(figurePtr->id()) != figures_.end()) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Duplicate figure id." << std::endl;
    return false;
  }
  figures_.insert(std::make_pair(figurePtr->id(), figurePtr));
  return true;
}

std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT>*Chessboard::squares() noexcept {
  return &squares_;
}

std::unordered_map<uint8_t, std::shared_ptr<AbstractFigure>> *Chessboard::figures() noexcept {
  return &figures_;
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
        squares_[row][col] = Square(SquareColor::WHITE);
      } else {
        squares_[row][col] = Square(SquareColor::BLACK);
      }
    }
  }
} 

} // namespace crazy_chess_towers