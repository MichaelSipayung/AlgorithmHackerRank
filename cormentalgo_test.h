#ifndef CORMEN_ALGORITHM_TEST
#define CORMEN_ALGORITHM_TEST
#include "cormenalgo.h"
#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
using namespace std;
using namespace cormen;
TEST(InsertionSort, evensample) {
  vector<int> data = {9, 8, 7, 6, 5, 4};
  const vector<int> dest = {4, 5, 6, 7, 8, 9};
  insertion_sort(data);
  EXPECT_EQ(dest, data);
}
TEST(InsertionSort, oddsample) {
  vector<int> data = {10, 9, 8, 7, 6, 5, 4};
  const vector<int> dest = {4, 5, 6, 7, 8, 9, 10};
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
  vector<string> data = {"ad", "ac", "ab", "aa"};
  const vector<string> dest = {"aa", "ab", "ac", "ad"};
  insertion_sort(data);
  EXPECT_EQ(dest, data);
}
TEST(InsertionSort, lambdasample) {
  vector<int> data = {4, 5, 6, 7, 8, 9, 10};
  const vector<int> dest = {10, 9, 8, 7, 6, 5, 4};
  insertion_sort(data, [](const int i, const int j) { return i < j; });
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
TEST(LinkedList, callpoponemptylist) {
  const auto data = new linked_list<string>;
  // call will fail due to static assertion
  EXPECT_ANY_THROW(data->pop_front());
}
TEST(LinkedList, itematbackposition) {
  const auto data = new linked_list<string>;
  data->push_front(string("Michael"));
  data->push_front(string("Jonathan"));
  EXPECT_EQ(string("Michael"), data->back());
  EXPECT_EQ(string("Jonathan"), data->front());
}
TEST(LinkedList, itematfrontposition) {
  const auto data = new linked_list<string>;
  data->push_front(string("Michael"));
  data->push_front(string("Jonathan"));
  EXPECT_EQ(string("Jonathan"), data->front());
}
TEST(LinkedList, pushback) {
  const auto data = new linked_list<string>;
  data->push_front(string("Michael"));
  data->push_front(string("Jonathan"));
  data->push_back(string("Marlin"));
  EXPECT_EQ(string("Marlin"), data->back());
  data->push_back(string("Ling-ling"));
  EXPECT_EQ(string("Ling-ling"), data->back());
}
TEST(LinkedList, operloadoutoperator) {
  const stringstream buffer;
  std::streambuf *previous = std::cout.rdbuf(buffer.rdbuf());
  auto temp = linked_list<double>();
  temp.push_front(1.5);
  temp.push_front(2.5);
  temp.print();
  cout.rdbuf(previous);
  const auto output = buffer.str();
  EXPECT_EQ(string("2.5 1.5 "), output);
  EXPECT_EQ(2, temp.size());
}
TEST(LinkedList, sizefunction) {
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
TEST(LinkedList, gettail) {
  auto temp = linked_list<double>();
  temp.push_back(12.8);
  EXPECT_EQ(12.8, temp.back());
  EXPECT_EQ(1, temp.size());
  temp.push_back(90.98);
  EXPECT_EQ(90.98, temp.back());
  EXPECT_EQ(2, temp.size());
}
TEST(DoublyLinkedList, popbackempty) {
  d_linked_list<double> list;
  EXPECT_ANY_THROW(list.pop_back());
}
TEST(DoublyLinkedList, popfrontempty) {
  d_linked_list<int> list;
  EXPECT_ANY_THROW(list.pop_front());
}
TEST(DNode, defaultbehavior) {
  auto node = new d_node<double>(12.8);
  EXPECT_EQ(12.8, node->get_item());
  EXPECT_TRUE(node->get_prev() == nullptr);
  EXPECT_TRUE(node->get_next() == nullptr);
}
TEST(DoublyLinkedList, defaultbehavior) {
  d_linked_list<double> ls;
  EXPECT_TRUE(ls.size() == 0);
  EXPECT_ANY_THROW(ls.front());
  EXPECT_THROW(ls.front(), std::out_of_range);
  EXPECT_ANY_THROW(ls.back());
  EXPECT_THROW(ls.back(), std::out_of_range);
  EXPECT_ANY_THROW(ls.pop_back());
  EXPECT_THROW(ls.pop_back(), std::out_of_range);
  EXPECT_ANY_THROW(ls.pop_front());
  EXPECT_THROW(ls.pop_front(), std::out_of_range);
}
TEST(DoublyLinkedList, emptylist) {
  d_linked_list<double> ls;
  EXPECT_TRUE(ls.empty());
  EXPECT_TRUE(ls.get_head() != nullptr);
  EXPECT_TRUE(ls.get_tail() != nullptr);
}
TEST(DoublyLinkedList, addingatback) {
  d_linked_list<double> ls;
  ls.push_back(89.9);
  EXPECT_TRUE(!ls.empty());
  EXPECT_TRUE(ls.size() == 1);
}
TEST(DoublyLinkedList, contentatback) {
  d_linked_list<double> ls;
  ls.push_back(89.9);
  EXPECT_TRUE(ls.back() == 89.9);
  ls.push_back(980.8);
  EXPECT_TRUE(ls.back() == 980.8);
  EXPECT_TRUE(ls.size() == 2);
}
TEST(DoublyLinkedList, addingatfront) {
  d_linked_list<double> ls;
  ls.push_front(89.9);
  EXPECT_TRUE(!ls.empty());
  EXPECT_TRUE(ls.size() == 1);
}
TEST(DoublyLinkedList, contentatfront) {
  d_linked_list<double> ls;
  ls.push_front(89.9);
  EXPECT_TRUE(ls.front() == 89.9);
  ls.push_front(980.8);
  EXPECT_TRUE(ls.front() == 980.8);
  EXPECT_TRUE(ls.size() == 2);
}
TEST(DoublyLinkedList, mixingadditem) {
  d_linked_list<string> ls;
  EXPECT_TRUE(ls.empty());
  ls.push_back({"jackie"});
  EXPECT_FALSE(ls.empty());
  ls.push_front({"daniel"});
  EXPECT_TRUE(ls.size() == 2);
  EXPECT_TRUE(ls.back() == "jackie");
  EXPECT_TRUE(ls.front() == "daniel");
}
TEST(DoublyLinkedList, sizeafterpopback) {
  d_linked_list<string> ls;
  ls.push_back("donald");
  ls.push_back("dinar");
  EXPECT_TRUE(ls.size() == 2);
  ls.pop_back();
  EXPECT_TRUE(ls.size() == 1);
  ls.pop_back();
  EXPECT_TRUE(ls.size() == 0);
}
TEST(DoublyLinkedList, sizeafterpopfront) {
  d_linked_list<string> ls;
  ls.push_front("donald");
  ls.push_front("dinar");
  EXPECT_TRUE(ls.size() == 2);
  ls.pop_front();
  EXPECT_TRUE(ls.size() == 1);
  ls.pop_front();
  EXPECT_TRUE(ls.size() == 0);
}
TEST(DoublyLinkedList, reversing_doubly_linked_ls) {
  d_linked_list<string> ls;
  ls.push_front("donald");
  ls.push_front("dinar");
  EXPECT_EQ(string("dinar"), ls.front());
  rdoubly_linked_list(ls);
  EXPECT_EQ(string("donald"), ls.front());
}
TEST(merge, sample1) {
  vector<int> data = {2, 4, 5, 7, 1, 2, 3, 6};
  merge(data, 0, data.size() / 2 - 1, data.size() - 1);
  EXPECT_EQ(vector({1, 2, 2, 3, 4, 5, 6, 7}), data);
}
TEST(merge, sample2) {
  vector<int> data = {2, 4, 3, 6, 9};
  merge(data, 0, data.size() / 2 - 1, data.size() - 1);
  EXPECT_EQ(vector({2, 3, 4, 6, 9}), data);
}
TEST(merge, sample3) {
  vector<int> data = {2, 4, 5, 6, 1, 8, 11, 15};
  merge(data, 0, data.size() / 2 - 1, data.size() - 1);
  EXPECT_EQ(vector({1, 2, 4, 5, 6, 8, 11, 15}), data);
}
TEST(merge_sort, sample1) {
  vector<int> data = {8, 7, 6, 5, 4, 3, 2, 1};
  merge_sort(data, 0, data.size() - 1);
  EXPECT_EQ(vector({1, 2, 3, 4, 5, 6, 7, 8}), data);
}
TEST(merge_sort, sample2) {
  vector<int> data = {8, 7, 4, 3};
  merge_sort(data, 0, data.size() - 1);
  EXPECT_EQ(vector({3, 4, 7, 8}), data);
}
TEST(merge_sort, sample1_double) {
  vector<double> data = {80.8, 78.9, 48.8, 3.86};
  merge_sort(data, 0, data.size() - 1);
  EXPECT_EQ(vector({3.86, 48.8, 78.9, 80.8}), data);
}

TEST(merge_lambda, sample1) {
  vector<int> data = {3, 2, 1, 0, 8, 7, 6, 5};
  merge(data, 0, data.size() / 2 - 1, data.size() - 1,
        [](int a, int b) { return a > b; });
  EXPECT_EQ(vector({8, 7, 6, 5, 3, 2, 1, 0}), data);
}
TEST(merge_lambda, sample2) {
  vector<int> data = {-5, -6, -7, -1, -2, -3};
  merge(data, 0, data.size() / 2 - 1, data.size() - 1,
        [](int a, int b) { return a > b; });
  EXPECT_EQ(vector({-1, -2, -3, -5, -6, -7}), data);
}
TEST(merge_sort_lambda, sample1) {
  vector<double> data = {3.86, 48.8, 78.9, 80.8};
  merge_sort(data, 0, data.size() - 1,
             [](double a, double b) { return a > b; });
  EXPECT_EQ(vector({80.8, 78.9, 48.8, 3.86}), data);
}
TEST(merge_sort_lambda, sample2) {
  vector<int> data = {3, 4, 7, 8};
  merge_sort(data, 0, data.size() - 1, [](int a, int b) { return a > b; });
  EXPECT_EQ(vector({8, 7, 4, 3}), data);
}
TEST(merge_sort_lambda, sample3) {
  vector<int> data = {-9, -8, -7, -6, -5};
  merge_sort(data, 0, data.size() - 1, [](int a, int b) { return a > b; });
  EXPECT_EQ(vector({-5, -6, -7, -8, -9}), data);
}
TEST(merge_sort, sample_hundred) {
  vector<int> data;
  for (auto i = -1; i >= -100; --i)
    data.push_back(i);
  merge_sort(data, 0, data.size() - 1);
  vector<int> expected;
  for (auto i = -100; i <= -1; ++i)
    expected.push_back(i);
  EXPECT_EQ(data, expected);
}
TEST(merge_sort, sample_thousand) {
  vector<double> data;
  for (auto i = -1; i >= -1000; --i)
    data.push_back(i * 1.4);
  merge_sort(data, 0, data.size() - 1);
  vector<double> expected;
  for (auto i = -1000; i <= -1; ++i)
    expected.push_back(i * 1.4);
  EXPECT_EQ(data, expected);
}
TEST(merge_sort_lambda, sample_hundred) {
  vector<int> data;
  for (auto i = -100; i <= -1; ++i)
    data.push_back(i);
  merge_sort(data, 0, data.size() - 1,
             [](const int &a, const int &b) { return a > b; });
  vector<int> expected;
  for (auto i = -1; i >= -100; --i)
    expected.push_back(i);
  EXPECT_EQ(data, expected);
}
TEST(merge_sort_lambda, sample_thousand) {
  vector<double> data;
  for (auto i = -1000; i <= -1; ++i)
    data.push_back(i * 1.3);
  merge_sort(data, 0, data.size() - 1,
             [](const int &a, const int &b) { return a > b; });
  vector<double> expected;
  for (auto i = -1; i >= -1000; --i)
    expected.push_back(i * 1.3);
  EXPECT_EQ(data, expected);
}
TEST(node_circle, case1) {
  node_circle<int> node_a(15);
  EXPECT_EQ(15, node_a.get_item());
}
TEST(node_circle, case2) {
  node_circle<string> node_s("Michael");
  EXPECT_EQ(string("Michael"), node_s.get_item());
}
TEST(circle_list, adding_items) {
  circle_list<double> circle_a;
  circle_a.add(56.8);
  EXPECT_FALSE(circle_a.empty());
}
TEST(circle_list, calling_front_on_empty) {
  circle_list<double> circle_a;
  EXPECT_ANY_THROW(circle_a.front());
}
TEST(circle_list, calling_back_on_empty) {
  circle_list<double> circle_b;
  EXPECT_ANY_THROW(circle_b.back());
}
TEST(circle_list, calling_front) {
  circle_list<double> circle_a;
  circle_a.add(89.89);
  circle_a.add(89.99);
  circle_a.add(89.79);
  EXPECT_EQ(89.79, circle_a.front());
}
TEST(circle_list, calling_back) {
  circle_list<double> circle_a;
  circle_a.add(89.89);
  circle_a.add(89.99);
  circle_a.add(89.79);
  EXPECT_EQ(89.89, circle_a.back());
}
TEST(circle_list, calling_empty) {
  circle_list<double> circle_a;
  EXPECT_TRUE(circle_a.empty());
}
TEST(circle_list, calling_remove) {
  circle_list<double> circle_a;
  circle_a.add(89.98);
  EXPECT_FALSE(circle_a.empty());
  circle_a.remove();
  EXPECT_TRUE(circle_a.empty());
}
TEST(circle_list, calling_remove_on_empty) {
  circle_list<std::string> circle_a;
  EXPECT_ANY_THROW(circle_a.remove());
}
TEST(circle_list, calling_advance) {
  circle_list<double> circle_a;
  circle_a.add(89.9);
  circle_a.add(90.9);
  circle_a.add(100.9);
  circle_a.advance();
  EXPECT_EQ(100.9, circle_a.back());
  circle_a.advance();
  EXPECT_EQ(90.9, circle_a.back());
  circle_a.advance();
  EXPECT_EQ(89.9, circle_a.back());
}
TEST(recursive_sum, sample1_integer) {
  std::vector<int> data = {0, 1, 2, 4, 5, -199, 98};
  auto result = recursive_sum(data, data.size());
  EXPECT_EQ(result, std::accumulate(data.cbegin(), data.cend(), 0));
}
TEST(recursive_sum, sample1_double) {
  std::vector<double> data = {0.133, 1.32, 2.23, 4.3, 53.1, -199.23, 98.32};
  auto result = recursive_sum(data, data.size());
  EXPECT_EQ(result, std::accumulate(data.cbegin(), data.cend(), 0.0));
}
TEST(recursive_sum, empty_vector) {
  std::vector<int> data;
  EXPECT_ANY_THROW(recursive_sum(data, 0));
}
TEST(recursive_reverse_array, sample1_integer) {
  std::vector<double> ls = {90.4, 56.5, 78.7, 67.8};
  reverse_array(ls, 0, 3);
  EXPECT_EQ(vector({67.8, 78.7, 56.5, 90.4}), ls);
}
TEST(recursive_reverse_array, sample1_integer_odd) {
  std::vector<double> ls = {90.4, 56.5, 78.7};
  reverse_array(ls, 0, 2);
  EXPECT_EQ(vector({78.7, 56.5, 90.4}), ls);
}
TEST(recursive_reverse_array, largesample) {
  std::vector<double> ls;
  for (auto i = 0; i < 100; ++i)
    ls.push_back(i * 1.5);
  std::vector<double> des;
  for (auto i = 99; i >= 0; --i)
    des.push_back(i * 1.5);
  reverse_array(ls, 0, 99);
  EXPECT_EQ(des, ls);
}
TEST(binary_sum, sample1_integer){
	const vector<int> data = {0,1,2,3};
	EXPECT_EQ(6, binary_sum(data,0,4));
}
TEST(binary_sum, sample2_double){
	const vector<double> data = {0.1,1.1,2.1,3.1};
	EXPECT_EQ(6.4, binary_sum(data,0,4));
}
TEST(binary_sum, non_power_two){
	const vector<int> data = {0,1,2,3,4};
	EXPECT_EQ(10, binary_sum(data,0,5));
}
TEST(binary_sum, non_power_two_double){
	const vector<double> data = {0.1,1.1,2.1,3.1,4.1};
	EXPECT_EQ(10.5, binary_sum(data,0,5));
}
TEST(binary_fib, base_case){
	EXPECT_EQ(0, binary_fib(0));
	EXPECT_EQ(1, binary_fib(1));
}
TEST(binary_fib, sample1){
	EXPECT_EQ(1, binary_fib(2));
	EXPECT_EQ(2, binary_fib(3));
	EXPECT_EQ(3, binary_fib(4));
	EXPECT_EQ(5, binary_fib(5));
}
TEST(linear_fib, basecase) {
    std::pair<size_t, size_t> dest = make_pair(1, 0);
    EXPECT_EQ(dest, linear_fib(1));
}
TEST(linear_fib, fib3){
    std::pair<size_t, size_t> dest = make_pair(2, 1);
    EXPECT_EQ(dest, linear_fib(3));
}
TEST(linear_fib, fib6){
    std::pair<size_t, size_t> dest = make_pair(8, 5);
    EXPECT_EQ(dest, linear_fib(6));
}
TEST(linear_fib, fib7) {
    std::pair<size_t, size_t> dest = make_pair(13, 8);
    EXPECT_EQ(dest, linear_fib(7));
}
TEST(prefix_averages, case1){
	vector<int> data = {1,2,3};
	EXPECT_EQ(vector({1.0,1.5,2.0}), prefix_averages(data));
}
TEST(prefix_averages_lin, case1){
	vector<int> data = {1,2,3};
	EXPECT_EQ(vector({1.0,1.5,2.0}), prefix_averages_lin(data));
}
TEST(power_linear, case1){
	EXPECT_EQ(8, power_linear(2,3));
}
TEST(power_linear, case2){
	EXPECT_EQ(125, power_linear(5,3));
}
TEST(power_logarithm, case1){
	EXPECT_EQ(8, power_logarithm(2,3));
}
TEST(power_logarithm, case2){
	EXPECT_EQ(125, power_logarithm(5,3));
}
#endif