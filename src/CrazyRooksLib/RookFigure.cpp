#include "RookFigure.h"
#include "Chessboard.h"
#include <chrono>
#include <iostream>
#include <thread>

namespace crazy_rooks {

std::mutex boardMutex;

namespace {

constexpr int MOVING_DELAY = 200;  // [milliseconds]
constexpr int BLOCK_DELAY  = 5000; // [milliseconds]
} // namespace

enum class MoveDirection {
  VERTICAL = 0,
  HORIZONTAL = 1
};

RookFigure::RookFigure(Square *square) {
  if (!square->isEmpty()) {
    std::invalid_argument("[ERROR][RookFigure]: Adding figure to chessboard - [FAIL]. Square is not empty.");
  }
  square_ = square;
  figureSymbol_ = 'X';
  type_ = FigureType::TOWER;
  ++id_;
}

void RookFigure::move() noexcept {
  const auto current_column = square_->coordinates()->column();
  const auto current_row = square_->coordinates()->row();
  bool moveDone = false;
  while (!moveDone) {
    MoveDirection direction = static_cast<MoveDirection>(std::rand() % 2);
    uint8_t newCoordinate = std::rand() % 8;
    switch (direction) {
      case MoveDirection::VERTICAL:
        if (newCoordinate == current_row) {
          break;
        }
        if (!square_->chessboard()->squares()->at(newCoordinate)[current_column].isEmpty()) {
          break;
        }
        setupSquare_(newCoordinate, current_column);
        moveDone = true;
        break;
      case MoveDirection::HORIZONTAL:
        if (newCoordinate == current_column) {
          break;
        }
        if (!square_->chessboard()->squares()->at(current_row)[newCoordinate].isEmpty()) {
          break;
        }
        setupSquare_(current_row, newCoordinate);
        moveDone = true;
        break;
     }
  }
}

void RookFigure::setupSquare_(const uint8_t row, const uint8_t col) noexcept {
  square_->removeFigure();
  square_ = &square_->chessboard()->squares()->at(row)[col];
  square_->chessboard()->squares()->at(row)[col].setFigure(shared_from_this());
}

void RookFigure::startRandomMove(int count) noexcept {
  while (count > 0) {
    move();
    boardMutex.lock();
    square_->chessboard()->drawBoard();
    boardMutex.unlock();
    --count;
    std::this_thread::sleep_for(std::chrono::milliseconds(MOVING_DELAY));
  }
}

} // namespace crazy_chess_towers