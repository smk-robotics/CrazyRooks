/**
 * @file Square.cpp
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Chessboard single square class implementation.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 * 
 */
#include "Square.h"
#include <iostream>

namespace {

constexpr const char* BLACK_SQUARE_STYLE = "\033[30;100m";
constexpr const char* WHITE_SQUARE_STYLE = "\033[30;107m";
constexpr const char* RESET_STYLE        = "\033[0m";

} // namespace 

namespace crazy_rooks {

uint8_t Square::row_ = 0;
uint8_t Square::col_ = 0;

Square::Square() {
  if (row_ > CHESS_BOARD_HEIGHT) {
    throw std::logic_error("[ERROR][Square] - Can't create square. It's out of chessboard!");
  }
  if (col_ > CHESS_BOARD_WIDTH - 1) {
    col_ = 0;
    ++row_;
  }
  coordinates_ = std::make_shared<SquareCoordinates>(row_, col_);
  
  if ((row_ + col_) % 2 == 0) {
    color_ = SquareColor::WHITE;
  } else {
    color_ = SquareColor::BLACK;
  }
  ++col_;
}

bool Square::isEmpty() const noexcept {
  return figure_ == nullptr;
}

bool Square::setFigure(const std::shared_ptr<AbstractFigure> &figurePtr) noexcept {
  if (figure_ != nullptr) {
    std::cerr << "[ERROR][Square]: Setting figure to square - [FAIL]. Square already has a figure." << std::endl;
    return false;
  }
  figure_ = figurePtr;
  return true;
}
 
SquareColor Square::color() const noexcept {
  return color_;
}

std::shared_ptr<SquareCoordinates> Square::coordinates() const noexcept {
  return coordinates_;
}

std::shared_ptr<AbstractFigure> Square::figure() noexcept {
  return figure_;
}

std::ostream& operator<<(std::ostream &os, const Square &square) {
  switch (square.color()) {
  case SquareColor::BLACK:
    os << BLACK_SQUARE_STYLE << " ";
    if (square.figure_) {
       os << square.figure_->symbol();
    } else {
      os << " ";
    }
    os << " " << RESET_STYLE;
    break;
  case SquareColor::WHITE:
    os << WHITE_SQUARE_STYLE << " ";
    if (square.figure_) {
       os << square.figure_->symbol();
    } else {
      os << " ";
    }
    os << " " << RESET_STYLE;
    break;
  default:
    throw std::invalid_argument("[ERROR][Square] - Square color is not set!");
    break;
  }  
}

} // namespace crazy_chess_towers