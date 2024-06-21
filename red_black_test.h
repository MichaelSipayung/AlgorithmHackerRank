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
TEST_F(red_black_test, calling_random_behavior){
	std::set<int> temp;
	for(auto i =0; i<20; ++i)
		temp.insert(std::rand());
	EXPECT_TRUE(tree.empty());
	for(auto beg = temp.begin(); beg!= temp.end(); ++beg)
		tree.insert(*beg, 0);
	EXPECT_FALSE(tree.empty());
	EXPECT_EQ(temp.size(), tree.size());
	EXPECT_EQ(*temp.begin(), tree.minimum().first);
	auto temp_max = temp.end();
	--temp_max;
	EXPECT_EQ(*temp_max, tree.maximum().first);
}
} // namespace red_black
