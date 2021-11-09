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

std::shared_ptr<Square> AbstractFigure::square() const noexcept {\
  return square_;
}

void AbstractFigure::setFigureToSquare(const std::shared_ptr<Square> squarePtr) noexcept {
  square_ = squarePtr;
}

bool operator==(const std::shared_ptr<AbstractFigure> &lhs, const std::shared_ptr<AbstractFigure>& rhs) {
  return lhs->id() == rhs->id();
}

} // namespace crazy_chess_towers