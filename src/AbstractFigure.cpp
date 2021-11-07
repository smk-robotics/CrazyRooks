#include "AbstractFigure.h"

namespace crazy_chess_towers {

char AbstractFigure::symbol() const noexcept {
  return figureSymbol_;
}

FigureType AbstractFigure::type() const noexcept {
  return type_;
}


} // namespace crazy_chess_towers