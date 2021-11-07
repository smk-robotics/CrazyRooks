/**
 * @file ChessBoard.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Full chessboard class declaration.
 * @date 2021-11-07
 * @copyright GNU General Public License v3.0.
 */
#pragma once

#include "AbstractFigure.h"
#include "Square.h"
#include <array>
#include <vector>
#include <memory>

constexpr uint8_t CHESS_BOARD_WIDTH  = 8;
constexpr uint8_t CHESS_BOARD_HEIGHT = 8;

namespace crazy_chess_towers {

class Chessboard {
public:
  Chessboard();
  bool addFigure(const Square &figurePosition, const FigureType figureType) noexcept;
  void drawBoard() const noexcept;
  std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT> squares() noexcept;
  std::vector<std::shared_ptr<AbstractFigure>> figures() noexcept;
private:  
  void colorizeBoard_() noexcept;

private:
  std::array<std::array<Square, CHESS_BOARD_WIDTH>, CHESS_BOARD_HEIGHT> squares_;
  std::vector<std::shared_ptr<AbstractFigure>> figures_;
};

} // namespace crazy_chess_towers