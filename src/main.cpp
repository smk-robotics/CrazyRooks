#include "Chessboard.h"
#include "RookFigure.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <thread>
#include <stdexcept>
#include <stdio.h>
#include <vector>

using namespace crazy_rooks;

constexpr int ASCII_SHIFT = 97;
constexpr uint8_t FIGURES_NUMBER = 8;
constexpr uint8_t MOVES_NUMBER = 50;
constexpr const char* OUTPUT_FILE = "coordinates.csv";

bool writeCoordsToFile(const std::vector<std::shared_ptr<AbstractFigure>> &figures, const std::string &title) {
  std::ofstream fileWithCoords;
  fileWithCoords.open(OUTPUT_FILE, std::ios::app) ;
  fileWithCoords << title << "\n";
  for (const auto &figure : figures) {
    fileWithCoords << static_cast<int>(figure->id()) << "," 
      << static_cast<char>(static_cast<int>(figure->square()->coordinates()->column() + ASCII_SHIFT)) << "," 
      << static_cast<int>(figure->square()->coordinates()->row() + 1) << "\n";
  }
  fileWithCoords.close();
}

int main() {
  Chessboard chessboard;
  std::vector<std::shared_ptr<AbstractFigure>> figures;
  std::srand(std::time(nullptr));
  while (chessboard.figures()->size() < FIGURES_NUMBER) {
    uint8_t c = std::rand() % 8;
    uint8_t r = std::rand() % 8;
    try {
      auto rook = std::make_shared<RookFigure>(&chessboard.squares()->at(c)[r]);
      if (chessboard.addFigure(rook)) {
        figures.emplace_back(rook);
      }
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  remove(OUTPUT_FILE);
  writeCoordsToFile(figures, "Start figures coordinates:");

  std::vector<std::thread> threads;
  threads.reserve(FIGURES_NUMBER);

  for (auto &figure : *chessboard.figures()) {
    threads.push_back(std::thread(&AbstractFigure::startRandomMove, figure, MOVES_NUMBER));
  }

  for (auto &thread : threads) {
    thread.join();
  }

  writeCoordsToFile(figures, "Finish figures coordinates:");
  return 0;
}