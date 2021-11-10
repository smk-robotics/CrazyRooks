#include "RookFigure.h"
#include "Chessboard.h"
#include <ctime>

namespace crazy_rooks {

RookFigure::RookFigure(const std::shared_ptr<Chessboard> &board) {
  type_ = FigureType::TOWER;
  figureSymbol_ = 'X';
  chessboard_ = board;
  ++id_;
  std::srand(std::time(nullptr));
}

bool RookFigure::move() noexcept {
  // square_->coordinates()->column();
  // square_->coordinates()->row();
  square_->removeFigure();
  chessboard_->squares()->at(3)[3].setFigure(std::shared_ptr<AbstractFigure>(this));
  // uint8_t steps = 0;
  // while (steps = 0) {
  //   uint8_t direction = std::rand() % 5;
  //   steps = 1;
  // }
}

} // namespace crazy_chess_towers