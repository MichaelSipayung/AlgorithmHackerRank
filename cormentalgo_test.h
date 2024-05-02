#ifndef CORMEN_ALGORITHM_TEST
#define CORMEN_ALGORITHM_TEST
#include "cormenalgo.h"
#include <algorithm>
#include <iostream>
#include <gtest/gtest.h>
using namespace cormen;
TEST(InsertionSort, evensample) {
	vector<int> data = { 9,8,7,6,5,4 };
	const vector<int> dest = { 4,5,6,7,8,9 };
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, oddsample) {
	vector<int> data = { 10,9,8,7,6,5,4 };
	const vector<int> dest = { 4,5,6,7,8,9,10 };
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
	const vector<string> dest = { "aa","ab","ac","ad"};
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, lambdasample) {
	vector<int> data = { 4,5,6,7,8,9,10 };
	const vector<int> dest = { 10,9,8,7,6,5,4 };
	insertion_sort(data, [](const int i, const int j) {
		return i < j;
		});
	EXPECT_EQ(dest, data);
}
TEST(LinkedList, emptyitemlist) {
	const linked_list<int> *a = new linked_list<int>;
	const auto empty = a->empty();
	EXPECT_EQ(true, empty);
}
TEST(LinkedList, nonemptylist) {
	const auto a = new linked_list<int>;
	a->push_front(13);
	const auto empty = a->empty();
	EXPECT_EQ(false, empty);
}
TEST(LinkedList, clearitem) {
	const auto data = new linked_list<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(true, !data->empty());
	data->pop_front();
	data->pop_front();
	EXPECT_EQ(true, data->empty());
}
TEST(LinkedList, clearall) {
	const auto data = new linked_list<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(true, !data->empty());
	data->clear();
	EXPECT_EQ(true, data->empty());
}
TEST(LinkedList, countitem) {
	const auto data = new linked_list<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(2, data->size());
}
TEST(LinkedList,callpoponemptylist) {
	const auto data = new linked_list<string>;
	 //call will fail due to static assertion
	EXPECT_ANY_THROW(data->pop_front());
}
TEST(LinkedList, itematbackposition)
{
	const auto data = new linked_list<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(string("Michael"), data->back());
	EXPECT_EQ(string("Jonathan"), data->front());
}
TEST(LinkedList, itematfrontposition)
{
	const auto data = new linked_list<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	EXPECT_EQ(string("Jonathan"), data->front());
}
TEST(LinkedList, pushback)
{
	const auto data = new linked_list<string>;
	data->push_front(string("Michael"));
	data->push_front(string("Jonathan"));
	data->push_back(string("Marlin"));
	EXPECT_EQ(string("Marlin"), data->back());
	data->push_back(string("Ling-ling"));
	EXPECT_EQ(string("Ling-ling"), data->back());
}
TEST(LinkedList, operloadoutoperator)
{
	const stringstream buffer;
	std::streambuf* previous = std::cout.rdbuf(buffer.rdbuf());
	auto temp  = linked_list<double>();
	temp.push_front(1.5);
	temp.push_front(2.5);
	temp.print();
	cout.rdbuf(previous);
	const auto output = buffer.str();
	EXPECT_EQ(string("2.5 1.5 "), output);
	EXPECT_EQ(2, temp.size());
}
TEST(LinkedList, sizefunction)
{
	auto temp = linked_list<double>();
	temp.push_front(1.5);
	temp.push_front(2.5);
	EXPECT_EQ(2, temp.size());
	temp.push_back(34.5);
	EXPECT_EQ(3, temp.size());
	temp.pop_front();
	EXPECT_EQ(2, temp.size());
	temp.clear();
	EXPECT_EQ(0, temp.size());
}
#endif