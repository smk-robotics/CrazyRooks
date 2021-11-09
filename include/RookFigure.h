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
  RookFigure(const Chessboard &board);
  bool move() noexcept override final;
  /**
   * @brief Default destructor the Rook Figure object.
   */
  ~RookFigure() = default;
};

} // namespace crazy_chess_towers