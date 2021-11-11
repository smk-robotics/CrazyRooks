#include "Chessboard.h"
#include "RookFigure.h"
#include <thread>
#include <vector>

using namespace crazy_rooks;

constexpr uint8_t FIGURES_NUMBER = 7;
constexpr uint8_t MOVES_NUMBER = 50;

int main() {
  Chessboard chessboard;
  
  for (auto i = 0; i < FIGURES_NUMBER; ++i) {
    uint8_t c = std::rand() % 8;
    uint8_t r  = std::rand() % 8;
    chessboard.addFigure(std::make_shared<RookFigure>(&chessboard.squares()->at(c)[r]));
  }

  std::vector<std::thread> threads;
  threads.reserve(7);

  for (auto &figure : *chessboard.figures()) {
    auto th = std::thread(&AbstractFigure::startRandomMove, *figure, MOVES_NUMBER);
    threads.emplace_back(th);
  }

  for (auto &thread : threads) {
    thread.join();
  }
  
  return 0;
}