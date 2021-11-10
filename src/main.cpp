#include "Chessboard.h"
#include "RookFigure.h"
#include <ctime>

using namespace crazy_rooks;

int main() {
  Chessboard chessboard;
  chessboard.drawBoard();
  std::srand(std::time(nullptr));
  uint8_t c = std::rand() % 8;
  uint8_t r  = std::rand() % 8;
  chessboard.addFigure(std::make_shared<RookFigure>(&chessboard.squares()->at(c)[r]));
}