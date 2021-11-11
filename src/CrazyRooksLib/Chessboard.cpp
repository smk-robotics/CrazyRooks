/**
 * @file Chessboard.cpp
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Full chessboard class implementation.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 */
#include "AbstractFigure.h"
#include "Chessboard.h"
#include <iostream>

namespace crazy_rooks {

Chessboard::Chessboard() {
  for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
    for (auto col = 0; col < CHESS_BOARD_HEIGHT; ++col) {
      squares_.at(row)[col] = Square(this);
    }
  }
}

bool Chessboard::addFigure(const std::shared_ptr<AbstractFigure> &figurePtr) noexcept {
  if (figurePtr.get() == nullptr) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. No figure provided!" << std::endl;
    return false;
  }
  if (figures_.find(figurePtr) != figures_.end()) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Duplicate figure id." << std::endl;
    return false;
  }
  if (!figurePtr->square()->setFigure(figurePtr)) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Can't set figure to square." << std::endl;
    return false;
  }
  figures_.emplace(figurePtr);
  return true;
}

void Chessboard::drawBoard() const noexcept {
  std::cout << "\033c" << std::endl; // Clear console.
  std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
  for (auto row = 0; row < CHESS_BOARD_WIDTH; ++row) {
    std::cout << row + 1<< " ";
    for (auto col = 0; col < CHESS_BOARD_HEIGHT; ++col) {
      std::cout << squares_.at(row)[col]; 
    }
    std::cout << " " << row + 1 << std::endl;
  }
  std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
}

SquaresArray* Chessboard::squares() noexcept {
  return &squares_;
}

FiguresSet* Chessboard::figures() noexcept {
  return &figures_;
}

} // namespace crazy_chess_towers