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

class AbstractFigure : public std::enable_shared_from_this<AbstractFigure> {
public:
  virtual void move() = 0;
  virtual void startRandomMove(int count) = 0;
  char symbol() const noexcept;
  FigureType type() const noexcept;
  uint8_t id() const noexcept;
  Square* square() const noexcept;
  virtual ~AbstractFigure() = default;
  friend bool operator==(const std::shared_ptr<AbstractFigure> &lhs, const std::shared_ptr<AbstractFigure> &rhs);
  struct FigureHashFunction {
    size_t operator()(const std::shared_ptr<AbstractFigure> &figure) const {
      return std::hash<int>()(int(figure->id()));
    }
  };
protected:
  static uint8_t id_;
  char figureSymbol_ = ' ';
  FigureType type_ = FigureType::NONE;
  Square* square_;
};

} // namespace crazy_chess_towers