#include "TowerFigure.h"
#include <gtest/gtest.h>

using namespace crazy_chess_towers;

TEST(TowerFigureTest, BacisTest) {
  std::shared_ptr<AbstractFigure> tower;
  ASSERT_NO_THROW(tower = std::make_shared<TowerFigure>());
  ASSERT_EQ(tower->type(), TOWER);
  ASSERT_EQ(tower->symbol(), 'X');
}