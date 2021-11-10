/**
 * @file RookFigure.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Rook chess figure class declaration.
 * @date 2021-11-10
 * @copyright GNU General Public License v3.0.
 * 
 */
#pragma once

#include "AbstractFigure.h"

namespace crazy_rooks {
/**
 * @brief Rook chess figure class. 
 */
class RookFigure : public AbstractFigure {
public:
  RookFigure(Square *square);
  void move() noexcept override final;
  void startRandomMove(int count) noexcept override final;
  /**
   * @brief Default destructor the Rook Figure object.
   */
  ~RookFigure() = default;

private:
  void setupSquare_(const uint8_t row, const uint8_t col) noexcept;
};

} // namespace crazy_chess_towers