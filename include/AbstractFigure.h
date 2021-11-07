#pragma once 

#include <memory>

namespace crazy_chess_towers {

enum FigureType {
  TOWER = 0
};

/**
 * @brief Forward declaraion for Square class to resolve headers circular 
 * dependency problem.
 */
class Square;

class AbstractFigure {
public:
  virtual bool move() = 0;
  char symbol() const noexcept;
  FigureType type() const noexcept;
  virtual ~AbstractFigure() = default;
protected:
  FigureType type_;
  char figureSymbol_ = ' ';
  std::shared_ptr<Square> square_;
};

} // namespace crazy_chess_towers