#ifndef CORMEN_ALGORITHM_TEST
#define CORMEN_ALGORITHM_TEST
#include "cormenalgo.h"
#include <algorithm>
#include <gtest/gtest.h>
using namespace cormen;
TEST(InsertionSort, evensample) {
	vector<int> data = { 9,8,7,6,5,4 };
	vector<int> dest = { 4,5,6,7,8,9 };
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, oddsample) {
	vector<int> data = { 10,9,8,7,6,5,4 };
	vector<int> dest = { 4,5,6,7,8,9,10 };
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, randsample) {
	vector<int> data;
	for (auto i = 0; i < 100; ++i)
		data.push_back(std::rand());
	auto temp = data;
	std::sort(temp.begin(), temp.end());
	insertion_sort(data);
	EXPECT_EQ(temp, data);
}
TEST(InsertionSort, stringsample) {
	vector<string> data = { "ad","ac","ab","aa"};
	vector<string> dest = { "aa","ab","ac","ad"};
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, lambdasample) {
	vector<int> data = { 4,5,6,7,8,9,10 };
	vector<int> dest = { 10,9,8,7,6,5,4 };
	insertion_sort(data, [](const int i, const int j) {
		return i < j;
		});
	EXPECT_EQ(dest, data);
}
#endif