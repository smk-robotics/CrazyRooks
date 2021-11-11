/**
 * @file SquareCoordinates.cpp
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Single chessboard square coordinates class declaration.
 * @date 2021-11-09
 * @copyright GNU General Public License v3.0.
 */
#include "SquareCoordinates.h"
#include <stdexcept>

namespace crazy_rooks {

SquareCoordinates::SquareCoordinates(const uint8_t row, const uint8_t col) {
  if (row > CHESS_BOARD_HEIGHT) {
    throw std::invalid_argument(
      "[ERROR][SquareCoordinates] - Given row coordinate for square is out of board.");
  }
  if (col > CHESS_BOARD_WIDTH) {
    throw std::invalid_argument(
      "[ERROR][SquareCoordinates] - Given column coordinate for square is out of board.");
  }
  row_ = row;
  column_ = col;
}

uint8_t SquareCoordinates::row() const noexcept {
  return row_;
}
  
uint8_t SquareCoordinates::column() const noexcept {
  return column_;
}

} // namespace crazy_chess_towers