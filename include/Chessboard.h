/**
 * @file ChessBoard.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Full chessboard class declaration.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 */
#pragma once

#include "Square.h"
#include <array>
#include <unordered_set>

namespace crazy_rooks {
/**
 * @brief Forward declaraion for AbstractFigure class to resolve headers 
 * circular dependency problem.
 */
class AbstractFigure;
/**
 * @brief Chessboar class.
 */
class Chessboard {
public:
  /**
   * @brief Defult constructor for new Chessboard object.
   */
  Chessboard() = default;
  bool addFigure(const SquareCoordinates &position, const std::shared_ptr<AbstractFigure> &figurePtr) noexcept;
  void drawBoard() const noexcept;
  std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT> *squares() noexcept;
  std::unordered_set<std::shared_ptr<AbstractFigure>, AbstractFigure::FigureHashFunction> *figures() noexcept;

private:
  std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT> squares_;
  std::unordered_set<std::shared_ptr<AbstractFigure>, AbstractFigure::FigureHashFunction> figures_;
};

} // namespace crazy_chess_towers