#include "RookFigure.h"
#include <ctime>

namespace crazy_rooks {

RookFigure::RookFigure() {
  type_ = FigureType::TOWER;
  figureSymbol_ = 'X';
  ++id_;
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