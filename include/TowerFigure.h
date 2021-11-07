#pragma once

#include "AbstractFigure.h"
#include "Square.h"

namespace crazy_chess_towers {

class TowerFigure : public AbstractFigure {
public:
  TowerFigure();
  bool move() noexcept override final;
  ~TowerFigure() = default;
};

} // namespace crazy_chess_towers