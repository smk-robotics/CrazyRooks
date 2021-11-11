/**
 * @file AbstractFigure.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Abstract chess figure class declaration.
 * @date 2021-11-12
 * @copyright GNU General Public License v3.0.
 */
#pragma once 

#include <memory>

namespace crazy_rooks {

/**
 * @brief Class for chess figure type definition.
 */
enum class FigureType {
  UNDEFINED = -1,
  TOWER = 0
};

/**
 * @brief Forward declaraion for Square class to resolve headers circular 
 * dependency.
 */
class Square;
/**
 * @brief Abstract chess figure class.
 */
class AbstractFigure : public std::enable_shared_from_this<AbstractFigure> {
public:
  /**
   * @brief Moves figure to new position.
   */
  virtual void move() = 0;
  /**
   * @brief Move figure to new random position multiple times.
   * @param count Number of times that figure will be moved.
   */
  virtual void startRandomMove(int count) = 0;
  /**
   * @brief Getter for figure symbol that will be drawed on chessboard.
   * @return char Character that will be drawed on chessboard.
   */
  char symbol() const noexcept;
  /**
   * @brief Getter for figure type.
   * @return FigureType Type of chess figure.
   */
  FigureType type() const noexcept;
  /**
   * @brief Getter for figure ID.
   * @return uint8_t ID of figure.
   */
  uint8_t id() const noexcept;
  /**
   * @brief Getter for square which figure currently located.
   * @return Square* Pointer to chessboard square which figure currently located.
   */
  Square* square() const noexcept;
  /**
   * @brief Overloading for equality operator.
   * @param lhs Left abstract figure pointer.
   * @param rhs Right abstract figure pointer.
   * @return true If figures have same ids.
   * @return false If figures have different ids.
   */
  friend bool operator==(const std::shared_ptr<AbstractFigure> &lhs, const std::shared_ptr<AbstractFigure> &rhs);
  /**
   * @brief Structure for calculating hash for figure pointer.
   */
  struct FigureHashFunction {
    size_t operator()(const std::shared_ptr<AbstractFigure> &figure) const {
      return std::hash<int>()(int(figure->id()));
    }
  };
  /**
   * @brief Virtual destructor for the Abstract Figure object.
   */
  virtual ~AbstractFigure() = default;
  
protected:
  /**
   * @brief Common counter for all figures.
   */
  static uint8_t totalFiguresID_;
  /**
   * @brief Current figure ID.
   */
  uint8_t id_;
  /**
   * @brief Figure symbol that will be drawed on chessboard.
   */
  char figureSymbol_ = ' ';
  /**
   * @brief Chess figure type. 
   */
  FigureType type_ = FigureType::UNDEFINED;
  /**
   * @brief Pointer to chessboard square where figure is currently located.
   */
  Square* square_;
};

} // namespace crazy_chess_towers