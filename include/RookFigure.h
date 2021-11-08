#pragma once

#include "AbstractFigure.h"
#include "Square.h"

namespace crazy_rooks {

class RookFigure : public AbstractFigure {
public:
  RookFigure();
  bool move() noexcept override final;
  ~RookFigure() = default;
};

} // namespace crazy_chess_towers