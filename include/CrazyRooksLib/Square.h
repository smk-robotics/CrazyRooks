/**
 * @file Square.h
 * @author Kirill Smirnov <smk.robotics@gmail.com>
 * @brief Chessboard single square class declaration.
 * @date 2021-11-06
 * @copyright GNU General Public License v3.0.
 */
#pragma once

#include "AbstractFigure.h"
#include "SquareCoordinates.h"

namespace crazy_rooks {
/**
 * @brief Class for single chessboard square color type definition.
 */
enum class SquareColor {
  NONE = -1,
  BLACK = 0,
  WHITE = 1
};
/**
 * @brief Forward declaraion for Chessboard class to resolve headers circular 
 * dependency.
 */
class Chessboard;
/**
 * @brief Single chessboard square class.
 */
class Square {
public:
  /**
 * @brief Constructor for new Square object.
 */
  Square() = default;
  /**
   * @brief Constructor for new Square object.
   * @param board Pointer to chessboard.
   */
  Square(Chessboard *board);
  /**
   * @brief Checks that square is no occupied by any figure.
   * @return true If square is empty.
   * @return false If square already occupied by figure.
   */
  bool isEmpty() const noexcept;
  /**
   * @brief Sets figure to this particular square.
   * @param figurePtr shred_ptr to figure that will be placed in square.
   * @return true If figure successfully occupied square.
   * @return false If square already occupied by another figure.
   */
  bool setFigure(const std::shared_ptr<AbstractFigure> &figurePtr) noexcept;
  /**
   * @brief Remove figure from square.
   * @details Set figure pointer to nullptr.
   */
  void removeFigure() noexcept;
  /**
   * @brief Getter for square color.
   * @return SquareColor Color of square - BLACK or WHITE.
   */
  SquareColor color() const noexcept;
  /**
   * @brief Getter for chessboard.
   * @return Chessboard* Pointer to chessboard.
   */
  Chessboard* chessboard() const noexcept;
  /**
   * @brief Getter for square coordinates on chessboard.
   * @return std::shared_ptr<SquareCoordinates> Pointer to object with square 
   * coordinates.
   */
  std::shared_ptr<SquareCoordinates> coordinates() const noexcept;
  /**
   * @brief Getter for figure that occupies this particular square.
   * @return std::shared_ptr<AbstractFigure> Pointer to figure that occupies 
   * this square.
   */
  std::shared_ptr<AbstractFigure> figure() noexcept;
  /**
   * @brief Overloading for string output operator.
   * @param os Output stream.
   * @param square Square that will be send to output stream.
   * @return std::ostream& Modified output stream. 
   */
  friend std::ostream& operator<<(std::ostream &os, const Square &square);
  
private:
  /**
   * @brief Square row coordinate from left side of the chessboard {0..7}.
   */
  static uint8_t row_;
  /**
   * @brief Square column coordinate from top of the chessboard {0..7}.
   */
  static uint8_t col_;
  /**
   * @brief Color of the square.
   */
  SquareColor color_ = SquareColor::NONE;
  /**
   * @brief Chessboard which contains this square.
   */
  Chessboard *chessboard_;
  /**
   * @brief Coordinates of this square.
   */
  std::shared_ptr<SquareCoordinates> coordinates_;
  /**
   * @brief Figure that currently occupied this square.
   */
  std::shared_ptr<AbstractFigure> figure_;
};

} // namespace crazy_chess_towers