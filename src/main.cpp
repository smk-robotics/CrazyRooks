#include "Chessboard.h"
#include "RookFigure.h"
#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>

using namespace crazy_rooks;

constexpr uint8_t FIGURES_NUMBER = 8;
constexpr uint8_t MOVES_NUMBER = 50;

int main() {
  Chessboard chessboard;
  
  while (chessboard.figures()->size() < FIGURES_NUMBER) {
    uint8_t c = std::rand() % 8;
    uint8_t r = std::rand() % 8;
    try {
      chessboard.addFigure(std::make_shared<RookFigure>(&chessboard.squares()->at(c)[r]));
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  std::vector<std::thread> threads;
  threads.reserve(FIGURES_NUMBER);

  for (auto &figure : *chessboard.figures()) {
    threads.push_back(std::thread(&AbstractFigure::startRandomMove, figure, MOVES_NUMBER));
  }

  for (auto &thread : threads) {
    thread.join();
  }
  
  return 0;
}