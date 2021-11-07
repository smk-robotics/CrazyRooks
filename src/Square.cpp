/**
 * @file Square.cpp
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Chessboard single square class implementation.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 * 
 */
#include "Square.h"
#include <string>

namespace {

constexpr const char* BLACK_SQUARE_STYLE = "\033[30;100m";
constexpr const char* WHITE_SQUARE_STYLE = "\033[30;107m";
constexpr const char* RESET_STYLE        = "\033[0m";

} // namespace 

namespace crazy_chess_towers {

Square::Square(const SquareColor &color) 
  : color_(color) {}

SquareColor Square::color() const noexcept {
  return color_;
}

bool Square::isEmpty() const noexcept {
  return figure_ == nullptr;
}

bool Square::setFigure(std::shared_ptr<AbstractFigure> &figure) noexcept {
  figure_ = figure;
}
 
std::ostream& operator<<(std::ostream &os, const Square &square) {
  switch (square.color()) {
  case BLACK:
    os << BLACK_SQUARE_STYLE << " ";
    if (square.figure_) {
       os << square.figure_->symbol();
    } else {
      os << " ";
    }
    os << " " << RESET_STYLE;
    break;
  case WHITE:
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