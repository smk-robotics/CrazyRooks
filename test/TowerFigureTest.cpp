#include "RookFigure.h"
#include <gtest/gtest.h>

using namespace crazy_rooks;

TEST(TowerFigureTest, BacisTest) {
  std::shared_ptr<AbstractFigure> tower;
  ASSERT_NO_THROW(tower = std::make_shared<RookFigure>());
  ASSERT_EQ(tower->type(), FigureType::TOWER);
  ASSERT_EQ(tower->symbol(), 'X');
  ASSERT_EQ(tower->id(), 1);
  auto tower2 = std::make_shared<RookFigure>();
  ASSERT_EQ(tower2->type(), FigureType::TOWER);
  ASSERT_EQ(tower2->symbol(), 'X');
  ASSERT_EQ(tower2->id(), 2);
}