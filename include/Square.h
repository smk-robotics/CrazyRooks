/**
 * @file Square.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Chessboard single square class declaration.
 * @date 2021-11-06
 * @copyright GNU General Public License v3.0.
 */
#pragma once

#include "AbstractFigure.h"
#include <iostream>

namespace crazy_chess_towers {

enum SquareColor {
  NONE = -1,
  BLACK = 0,
  WHITE = 1
};

class Square {
public:
  Square() = default;
  Square(const SquareColor &color);
  SquareColor color() const noexcept;
  bool isEmpty() const noexcept;
  bool setFigure(std::shared_ptr<AbstractFigure> &figure) noexcept;
  friend std::ostream& operator<<(std::ostream &os, const Square &square);
private:
  SquareColor color_ = NONE;
  std::shared_ptr<AbstractFigure> figure_;
};

} // namespace crazy_chess_towers