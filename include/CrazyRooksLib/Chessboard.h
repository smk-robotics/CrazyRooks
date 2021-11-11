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
  /**
   * @brief Adds given figure to chessboard.
   * @param figurePtr Shared pointer of given figure that will be added to board.
   * @return true If figure successfully added to board. 
   * @return false If figure can't be added to board.
   */
  bool addFigure(const std::shared_ptr<AbstractFigure> &figurePtr) noexcept;
  /**
   * @brief Draw chessboard in console window.
   */
  void drawBoard() const noexcept;
  /**
   * @brief Getter for all chessboard squares.
   * @return SquaresArray* Array of all chessboard squares.
   */
  SquaresArray* squares() noexcept;
  /**
   * @brief Getter for all figures on chessboard.
   * @return FiguresSet* Set of all figures on chessboard. 
   */
  FiguresSet* figures() noexcept;

private:
  /**
   * @brief Array of all chessboard squares.
   */
  SquaresArray squares_;
  /**
   * @brief Set of all figures on chessboard.
   */
  FiguresSet figures_;
};

} // namespace crazy_chess_towers