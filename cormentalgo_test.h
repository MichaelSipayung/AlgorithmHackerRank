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
	for (auto i = 0; i < 15; ++i)
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
TEST(LinkedList, emptyitemlist) {
	LinkedList<int> *a = new LinkedList<int>;
	auto empty = a->empty();
	EXPECT_EQ(true, empty);
}
TEST(LinkedList, nonemptylist) {
	LinkedList<int>* a = new LinkedList<int>;
	a->push_front(13);
	auto empty = a->empty();
	EXPECT_EQ(false, empty);
}
TEST(LinkedList, clearitem) {
	auto data = new LinkedList<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(true, !data->empty());
	data->pop_front();
	data->pop_front();
	EXPECT_EQ(true, data->empty());
}
TEST(LinkedList, clearall) {
	auto data = new LinkedList<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(true, !data->empty());
	data->clear();
	EXPECT_EQ(true, data->empty());
}
TEST(LinkedList, countitem) {
	auto data = new LinkedList<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(2, data->size());
}
TEST(LinkedList,callpoponemptylist) {
	auto data = new LinkedList<string>;
	 //call will fail due to static assertion
	EXPECT_ANY_THROW(data->pop_front());
}
TEST(LinkedList, itematbackposition)
{
	auto data = new LinkedList<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(string("Michael"), data->back());
	EXPECT_EQ(string("Jonathan"), data->front());
}
TEST(LinkedList, itematfrontposition)
{
	auto data = new LinkedList<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(string("Jonathan"), data->front());
}
#endif