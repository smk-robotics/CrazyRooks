#include "RookFigure.h"
#include <ctime>

namespace crazy_rooks {

RookFigure::RookFigure(const Chessboard &board) {
  type_ = FigureType::TOWER;
  figureSymbol_ = 'X';
  ++id_;
  // chessboard_ = std::make_shared<Chessboard>(board);
  // auto tmp = std::shared_ptr<Chessboard>(board);
  std::srand(std::time(nullptr));
}

bool RookFigure::move() noexcept {
  uint8_t steps = 0;
  while (steps = 0) {
    uint8_t direction = std::rand() % 5;
    steps = 1;
  }
}

} // namespace crazy_chess_towers