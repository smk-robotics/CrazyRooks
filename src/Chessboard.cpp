/**
 * @file Chessboard.cpp
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Full chessboard class implementation.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 * 
 */
#include "AbstractFigure.h"
#include "Chessboard.h"
#include <iostream>

namespace crazy_rooks {

bool Chessboard::addFigure(const SquareCoordinates &position, const std::shared_ptr<AbstractFigure> &figurePtr) noexcept {
  if (figures_.find(figurePtr) != figures_.end()) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Duplicate figure id." << std::endl;
    return false;
  }
  if (!squares_.at(position.column())[position.row()].isEmpty()) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Square is not empty." << std::endl;
    return false;
  }
  if (!squares_.at(position.column())[position.row()].setFigure(figurePtr)) {
    std::cerr << "[ERROR][Chessboard]: Adding figure to chessboard - [FAIL]. Can't set figure to square." << std::endl;
    return false;
  }
  figurePtr->setFigureToSquare(std::make_shared<Square>(squares_.at(position.column())[position.row()]));
  figures_.emplace(figurePtr);
  return true;
}

std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT> *Chessboard::squares() noexcept {
  return &squares_;
}

std::unordered_set<std::shared_ptr<AbstractFigure>,AbstractFigure::FigureHashFunction> *Chessboard::figures() noexcept {
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

} // namespace crazy_chess_towers