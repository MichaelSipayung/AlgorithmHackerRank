#ifndef TWOSUM_TEST
#define TWOSUM_TEST
#include "twosum.h"
#include <gtest/gtest.h>
TEST(TwoSumTest, RankTest) {
  std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
  TwoSum<double> ts(data);
  EXPECT_EQ(2, ts.rank(3.0, data));
  EXPECT_EQ(3, ts.rank(4.0, data));
}
TEST(TwoSumTest, RankTest2) {
  std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
  TwoSum<double> ts(data);
  EXPECT_EQ(-1, ts.rank(6.0, data));
  EXPECT_EQ(-1, ts.rank(0.0, data));
}
TEST(TwoSumTest, CountTest) {
  std::vector<double> data = {-1.0, -2.0, -3.0, -4.0, 1.0, 2.0, 3.0, 4.0, 5.0};
  TwoSum<double> ts(data);
  EXPECT_EQ(4, ts.count());
}
TEST(TwoSumTest, CountTest2) {
  std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
  TwoSum<double> ts(data);
  EXPECT_EQ(0, ts.count());
}
#endif