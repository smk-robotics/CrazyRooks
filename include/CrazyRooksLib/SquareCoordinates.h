/**
 * @file SquareCoordinates.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Single chessboard square coordinates class declaration.
 * @date 2021-11-09
 * @copyright GNU General Public License v3.0.
 */
#pragma once

#include <cstdint>

namespace crazy_rooks {

constexpr uint8_t CHESS_BOARD_WIDTH  = 8;
constexpr uint8_t CHESS_BOARD_HEIGHT = 8;

/**
 * @brief Class for check and store single chess boards square coordinates. 
 */
class SquareCoordinates {
public:
  /**
   * @brief Construct a new Square Coordinates object
   * @param row Number of row from top of the chessboard {0..CHESS_BOARD_HEIGHT}. 
   * @param col Number of column from left side of the chessboard {0..CHESS_BOARD_WIDTH}.
   * @exception std::invalid_argument If given row or column coordinates is out of board. 
   */
  SquareCoordinates(const uint8_t row, const uint8_t col);
  /**
   * @brief Getter for square row coordinate.
   * @return uint8_t Number of rows from top of the chessboard {0..CHESS_BOARD_HEIGHT}.
   */
  uint8_t row() const noexcept;
  /**
   * @brief Getter for square column coordinate.
   * @return uint8_t Number of rows from left side of the chessboard {0..CHESS_BOARD_WIDTH}.
   */
  uint8_t column() const noexcept;

private:
  /**
   * @brief Square row coordinate (from top of the chessboard).
   */
  uint8_t row_ = 0;
  /**
   * @brief Square column coordinate (from left side of the chessboard).
   */
  uint8_t column_ = 0;
};

} // namespace crazy_chess_towers