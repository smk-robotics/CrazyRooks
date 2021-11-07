#include "TowerFigure.h"

namespace crazy_chess_towers {

TowerFigure::TowerFigure() {
  type_ = TOWER;
  figureSymbol_ = 'X';
}

bool TowerFigure::move() noexcept {
  [[maybe_unused]] int i = 0;
}

} // namespace crazy_chess_towers