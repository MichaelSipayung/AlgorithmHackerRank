#pragma once
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "red_black.h"
namespace red_black {
class red_black_test : public ::testing::Test {
protected:
	red_black_tree<int, int> tree;
	void SetUp() override {
	}
};
TEST_F(red_black_test, calling_insert) {
	EXPECT_TRUE(tree.empty());
	tree.insert(1, 1);
	EXPECT_FALSE(tree.empty());
	EXPECT_EQ(tree.size(), 1);
	tree.insert(2, 2);
	EXPECT_EQ(tree.size(), 2);
	tree.insert(3, 3);
	EXPECT_EQ(tree.size(), 3);
}
TEST_F(red_black_test, calling_minimum) {
	EXPECT_THROW(tree.minimum(), std::out_of_range);
	tree.insert(1, 1);
	EXPECT_EQ(tree.minimum().first, 1);
	tree.insert(2, 2);
	EXPECT_EQ(tree.minimum().first, 1);
	tree.insert(3, 3);
	EXPECT_EQ(tree.minimum().first, 1);
}
TEST_F(red_black_test, calling_maximum) {
	EXPECT_THROW(tree.maximum(), std::out_of_range);
	tree.insert(1, 1);
	EXPECT_EQ(tree.maximum().first, 1);
	tree.insert(2, 2);
	EXPECT_EQ(tree.maximum().first, 2);
	tree.insert(3, 3);
	EXPECT_EQ(tree.maximum().first, 3);
}
} // namespace red_black
