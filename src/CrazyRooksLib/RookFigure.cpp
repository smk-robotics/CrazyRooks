#include "RookFigure.h"
#include "Chessboard.h"
#include <chrono>
#include <thread>
#include <mutex>

#include <iostream>

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
  if (square->isEmpty()) {
    square_ = square;
    figureSymbol_ = 'X';
    type_ = FigureType::TOWER;
    id_ = ++totalFiguresID_;
  } else {
    throw std::logic_error("[ERROR][RookFigure]: Adding figure to chessboard - [FAIL]. Square is not empty.");
  }
}

void RookFigure::move() noexcept {
  const auto current_column = square_->coordinates()->column();
  const auto current_row    = square_->coordinates()->row();
  bool moveDone = false;
  while (!moveDone) {
    MoveDirection direction = static_cast<MoveDirection>(std::rand() % 2);
    uint8_t targetCoordinate = std::rand() % 8;
    auto timeLeft = BLOCK_DELAY;
    switch (direction) {
      case MoveDirection::VERTICAL:
        if (targetCoordinate == current_row) {
          break;
        }

        while (!verticalPathClear_(targetCoordinate) && (timeLeft > 0)) {
          std::this_thread::sleep_for(std::chrono::milliseconds(MOVING_DELAY));
          timeLeft -= MOVING_DELAY;
        }

        if (timeLeft < 0) {
          break;
        }

        if (setupSquare_(targetCoordinate, current_column)) {
          moveDone = true;
        }
        break;
      case MoveDirection::HORIZONTAL:
        if (targetCoordinate == current_column) {
          break;
        }

        auto timeLeft = BLOCK_DELAY;
        while (!horizontalPathClear_(targetCoordinate) && (timeLeft > 0)) {
          std::this_thread::sleep_for(std::chrono::milliseconds(MOVING_DELAY));
          timeLeft -= MOVING_DELAY;
        }

        if (timeLeft < 0) {
          break;
        }

        if (setupSquare_(current_row, targetCoordinate)) {
          moveDone = true;
        }
        break;
     }
  }
}

void RookFigure::startRandomMove(int count) noexcept {
  while (count > 0) {
    move();
    {
      std::lock_guard<std::mutex> guard(boardMutex);
      square_->chessboard()->drawBoard();
    }
    --count;
    std::this_thread::sleep_for(std::chrono::milliseconds(MOVING_DELAY));
  }
}

bool RookFigure::horizontalPathClear_(const uint8_t target) const noexcept {
  const auto current_row    = square_->coordinates()->row();
  auto diff = square_->coordinates()->column() - target; 
  auto direction = diff > 0 ? -1 : 1;
  for (auto i = 0; i < abs(diff); ++i) {
    std::lock_guard<std::mutex> guard(boardMutex);
    if (!square_->chessboard()->squares()->at(current_row)[target - i * direction].isEmpty()) {
      return false;
    }
  }
  return true;
}

bool RookFigure::verticalPathClear_(const uint8_t target) const noexcept {
  const auto current_column = square_->coordinates()->column();
  auto diff = square_->coordinates()->row() - target;
  auto direction = diff > 0 ? -1 : 1;
  for (auto i = 0; i < abs(diff); ++i) {
    std::lock_guard<std::mutex> guard(boardMutex);
    if (!square_->chessboard()->squares()->at(target - i * direction)[current_column].isEmpty()) {
      return false;
    }
  }
  return true;
}

bool RookFigure::setupSquare_(const uint8_t row, const uint8_t col) noexcept {
  std::lock_guard<std::mutex> guard(boardMutex);
  if (!square_->chessboard()->squares()->at(row)[col].setFigure(shared_from_this())) {
    return false;
  }
  square_->removeFigure();
  square_ = &square_->chessboard()->squares()->at(row)[col]; 
  return true;
}

} // namespace crazy_chess_towers