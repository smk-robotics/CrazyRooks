#include "AbstractFigure.h"

namespace crazy_rooks {

 uint8_t AbstractFigure::id_ = 0;

uint8_t AbstractFigure::id() const noexcept {
  return id_;
}

char AbstractFigure::symbol() const noexcept {
  return figureSymbol_;
}

FigureType AbstractFigure::type() const noexcept {
  return type_;
}

} // namespace crazy_chess_towers