#pragma once 

#include <memory>

namespace crazy_rooks {

/**
 * @brief Class for chess figure type definition.
 */
enum class FigureType {
  NONE = -1,
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
  uint8_t id() const noexcept;
  virtual ~AbstractFigure() = default;
protected:
  static uint8_t id_;
  char figureSymbol_ = ' ';
  FigureType type_ = FigureType::NONE;
  std::shared_ptr<Square> square_;
};

} // namespace crazy_chess_towers