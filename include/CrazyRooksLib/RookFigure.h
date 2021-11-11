/**
 * @file RookFigure.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Rook chess figure class declaration.
 * @date 2021-11-10
 * @copyright GNU General Public License v3.0.
 */
#pragma once

#include "AbstractFigure.h"

namespace crazy_rooks {
/**
 * @brief Rook chess figure class. 
 */
class RookFigure : public AbstractFigure {
public:
  /**
   * @brief Constructor for new Rook Figure object.
   * @param square Pointer to chess board square where figure will be placed. 
   */
  RookFigure(Square *square);
  /**
   * @brief Moves rook to new position.
   */
  void move() noexcept override final;
  /**
   * @brief Move figure to new random position multiple times.
   * @param count Number of times that figure will be moved.
   */
  void startRandomMove(int count) noexcept override final;
  /**
   * @brief Default destructor the Rook Figure object.
   */
  ~RookFigure() = default;

private:
  /**
   * @brief Checks that rook can be moved in horizontal direction to target square.
   * @param targetColumn Column number of target square.
   * @return true If path to target square is clear.
   * @return false If there are some figures on path to target square.
   */
  bool horizontalPathClear_(const uint8_t targetColumn) const noexcept;
  /**
   * @brief Checks that rook can be moved in vertical direction to target square.
   * @param targetRow Row number of target square.
   * @return true If path to target square is clear.
   * @return false If there are some figures on path to target square.
   */
  bool verticalPathClear_(const uint8_t targetRow) const noexcept;
  /**
   * @brief Sets up square where figure is currently located, clear square where 
   * it was.
   * @param row New square row coordinate.
   * @param col New square column coordinate.
   * @return true If figure successfully moved set to new square.
   * @return false If target square already occupied by another figure.
   */
  bool setupSquare_(const uint8_t row, const uint8_t col) noexcept;
};

} // namespace crazy_chess_towers