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

#define FiguresSet std::unordered_set<std::shared_ptr<AbstractFigure>, AbstractFigure::FigureHashFunction>
#define SquaresArray std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT>
/**
 * @brief Chessboar class.
 */
class Chessboard : public std::enable_shared_from_this<Chessboard> {
public:
  /**
   * @brief Defult constructor for new Chessboard object.
   */
  Chessboard();
  bool addFigure(const std::shared_ptr<AbstractFigure> &figurePtr) noexcept;
  void drawBoard() const noexcept;
  SquaresArray* squares() noexcept;
  FiguresSet* figures() noexcept;

private:
  SquaresArray squares_;
  FiguresSet figures_;
};

} // namespace crazy_chess_towers