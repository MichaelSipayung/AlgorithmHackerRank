#ifndef CORMEN_ALGORITHM_TEST
#define CORMEN_ALGORITHM_TEST
#include "cormenalgo.h"
#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <random>
using namespace std;
using namespace cormen;
TEST(InsertionSort, evensample) {
	vector<int> data = { 9, 8, 7, 6, 5, 4 };
	const vector<int> dest = { 4, 5, 6, 7, 8, 9 };
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, oddsample) {
	vector<int> data = { 10, 9, 8, 7, 6, 5, 4 };
	const vector<int> dest = { 4, 5, 6, 7, 8, 9, 10 };
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
	vector<string> data = { "ad", "ac", "ab", "aa" };
	const vector<string> dest = { "aa", "ab", "ac", "ad" };
	insertion_sort(data);
	EXPECT_EQ(dest, data);
}
TEST(InsertionSort, lambdasample) {
	vector<int> data = { 4, 5, 6, 7, 8, 9, 10 };
	const vector<int> dest = { 10, 9, 8, 7, 6, 5, 4 };
	insertion_sort(data, [](const int i, const int j) { return i < j; });
	EXPECT_EQ(dest, data);
}
TEST(LinkedList, emptyitemlist) {
	const linked_list<int>* a = new linked_list<int>;
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
	std::streambuf* previous = std::cout.rdbuf(buffer.rdbuf());
	auto temp = linked_list<double>();
	temp.push_front(1.5);
	temp.push_front(2.5);
	// temp.print();
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
	ls.push_back({ "jackie" });
	EXPECT_FALSE(ls.empty());
	ls.push_front({ "daniel" });
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
	vector<int> data = { 2, 4, 5, 7, 1, 2, 3, 6 };
	merge(data, 0, data.size() / 2 - 1, data.size() - 1);
	EXPECT_EQ(vector({ 1, 2, 2, 3, 4, 5, 6, 7 }), data);
}
TEST(merge, sample2) {
	vector<int> data = { 2, 4, 3, 6, 9 };
	merge(data, 0, data.size() / 2 - 1, data.size() - 1);
	EXPECT_EQ(vector({ 2, 3, 4, 6, 9 }), data);
}
TEST(merge, sample3) {
	vector<int> data = { 2, 4, 5, 6, 1, 8, 11, 15 };
	merge(data, 0, data.size() / 2 - 1, data.size() - 1);
	EXPECT_EQ(vector({ 1, 2, 4, 5, 6, 8, 11, 15 }), data);
}
TEST(merge_sort, sample1) {
	vector<int> data = { 8, 7, 6, 5, 4, 3, 2, 1 };
	merge_sort(data, 0, data.size() - 1);
	EXPECT_EQ(vector({ 1, 2, 3, 4, 5, 6, 7, 8 }), data);
}
TEST(merge_sort, sample2) {
	vector<int> data = { 8, 7, 4, 3 };
	merge_sort(data, 0, data.size() - 1);
	EXPECT_EQ(vector({ 3, 4, 7, 8 }), data);
}
TEST(merge_sort, sample1_double) {
	vector<double> data = { 80.8, 78.9, 48.8, 3.86 };
	merge_sort(data, 0, data.size() - 1);
	EXPECT_EQ(vector({ 3.86, 48.8, 78.9, 80.8 }), data);
}

TEST(merge_lambda, sample1) {
	vector<int> data = { 3, 2, 1, 0, 8, 7, 6, 5 };
	merge(data, 0, data.size() / 2 - 1, data.size() - 1,
		[](int a, int b) { return a > b; });
	EXPECT_EQ(vector({ 8, 7, 6, 5, 3, 2, 1, 0 }), data);
}
TEST(merge_lambda, sample2) {
	vector<int> data = { -5, -6, -7, -1, -2, -3 };
	merge(data, 0, data.size() / 2 - 1, data.size() - 1,
		[](int a, int b) { return a > b; });
	EXPECT_EQ(vector({ -1, -2, -3, -5, -6, -7 }), data);
}
TEST(merge_sort_lambda, sample1) {
	vector<double> data = { 3.86, 48.8, 78.9, 80.8 };
	merge_sort(data, 0, data.size() - 1,
		[](double a, double b) { return a > b; });
	EXPECT_EQ(vector({ 80.8, 78.9, 48.8, 3.86 }), data);
}
TEST(merge_sort_lambda, sample2) {
	vector<int> data = { 3, 4, 7, 8 };
	merge_sort(data, 0, data.size() - 1, [](int a, int b) { return a > b; });
	EXPECT_EQ(vector({ 8, 7, 4, 3 }), data);
}
TEST(merge_sort_lambda, sample3) {
	vector<int> data = { -9, -8, -7, -6, -5 };
	merge_sort(data, 0, data.size() - 1, [](int a, int b) { return a > b; });
	EXPECT_EQ(vector({ -5, -6, -7, -8, -9 }), data);
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
		[](const int& a, const int& b) { return a > b; });
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
		[](const int& a, const int& b) { return a > b; });
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
	std::vector<int> data = { 0, 1, 2, 4, 5, -199, 98 };
	auto result = recursive_sum(data, data.size());
	EXPECT_EQ(result, std::accumulate(data.cbegin(), data.cend(), 0));
}
TEST(recursive_sum, sample1_double) {
	std::vector<double> data = { 0.133, 1.32, 2.23, 4.3, 53.1, -199.23, 98.32 };
	auto result = recursive_sum(data, data.size());
	EXPECT_EQ(result, std::accumulate(data.cbegin(), data.cend(), 0.0));
}
TEST(recursive_sum, empty_vector) {
	std::vector<int> data;
	EXPECT_ANY_THROW(recursive_sum(data, 0));
}
TEST(recursive_reverse_array, sample1_integer) {
	std::vector<double> ls = { 90.4, 56.5, 78.7, 67.8 };
	reverse_array(ls, 0, 3);
	EXPECT_EQ(vector({ 67.8, 78.7, 56.5, 90.4 }), ls);
}
TEST(recursive_reverse_array, sample1_integer_odd) {
	std::vector<double> ls = { 90.4, 56.5, 78.7 };
	reverse_array(ls, 0, 2);
	EXPECT_EQ(vector({ 78.7, 56.5, 90.4 }), ls);
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
TEST(binary_sum, sample1_integer) {
	const vector<int> data = { 0, 1, 2, 3 };
	EXPECT_EQ(6, binary_sum(data, 0, 4));
}
TEST(binary_sum, sample2_double) {
	const vector<double> data = { 0.1, 1.1, 2.1, 3.1 };
	EXPECT_EQ(6.4, binary_sum(data, 0, 4));
}
TEST(binary_sum, non_power_two) {
	const vector<int> data = { 0, 1, 2, 3, 4 };
	EXPECT_EQ(10, binary_sum(data, 0, 5));
}
TEST(binary_sum, non_power_two_double) {
	const vector<double> data = { 0.1, 1.1, 2.1, 3.1, 4.1 };
	EXPECT_EQ(10.5, binary_sum(data, 0, 5));
}
TEST(binary_fib, base_case) {
	EXPECT_EQ(0, binary_fib(0));
	EXPECT_EQ(1, binary_fib(1));
}
TEST(binary_fib, sample1) {
	EXPECT_EQ(1, binary_fib(2));
	EXPECT_EQ(2, binary_fib(3));
	EXPECT_EQ(3, binary_fib(4));
	EXPECT_EQ(5, binary_fib(5));
}
TEST(linear_fib, basecase) {
	std::pair<size_t, size_t> dest = make_pair(1, 0);
	EXPECT_EQ(dest, linear_fib(1));
}
TEST(linear_fib, fib3) {
	std::pair<size_t, size_t> dest = make_pair(2, 1);
	EXPECT_EQ(dest, linear_fib(3));
}
TEST(linear_fib, fib6) {
	std::pair<size_t, size_t> dest = make_pair(8, 5);
	EXPECT_EQ(dest, linear_fib(6));
}
TEST(linear_fib, fib7) {
	std::pair<size_t, size_t> dest = make_pair(13, 8);
	EXPECT_EQ(dest, linear_fib(7));
}
TEST(prefix_averages, case1) {
	vector<int> data = { 1, 2, 3 };
	EXPECT_EQ(vector({ 1.0, 1.5, 2.0 }), prefix_averages(data));
}
TEST(prefix_averages_lin, case1) {
	vector<int> data = { 1, 2, 3 };
	EXPECT_EQ(vector({ 1.0, 1.5, 2.0 }), prefix_averages_lin(data));
}
TEST(power_linear, case1) { EXPECT_EQ(8, power_linear(2, 3)); }
TEST(power_linear, case2) { EXPECT_EQ(125, power_linear(5, 3)); }
TEST(power_logarithm, case1) { EXPECT_EQ(8, power_logarithm(2, 3)); }
TEST(power_logarithm, case2) { EXPECT_EQ(125, power_logarithm(5, 3)); }
TEST(stack_array, calling_push) {
	stack_array<int> data;
	data.push(12);
	EXPECT_EQ(12, data.top());
}
TEST(stack_array, calling_push_onfull) {
	stack_array<int> data(1);
	data.push(13);
	EXPECT_ANY_THROW(data.push(34));
}
TEST(stack_array, calling_pop) {
	stack_array<double> data;
	data.push(45.6);
	EXPECT_FALSE(data.empty());
	data.pop();
	EXPECT_TRUE(data.empty());
}
TEST(stack_array, calling_pop_empty) {
	stack_array<double> data;
	EXPECT_ANY_THROW(data.pop());
}
TEST(stack_array, calling_size) {
	stack_array<double> data;
	EXPECT_EQ(0, data.size());
	data.push(23.2);
	EXPECT_EQ(1, data.size());
}
TEST(stack_array, calling_empty) {
	stack_array<int> data;
	EXPECT_TRUE(data.empty());
}
TEST(stack_array, calling_top) {
	stack_array<std::string> data;
	data.push(string("michael"));
	data.push(string("jack"));
	EXPECT_EQ(string("jack"), data.top());
}
TEST(stack_array, calling_top_onempty) {
	stack_array<std::string> data;
	EXPECT_ANY_THROW(data.top());
}
TEST(stack_linked, calling_push) {
	stack_linked<double> data;
	data.push(23.23);
	EXPECT_EQ(23.23, data.top());
}
TEST(stack_linked, calling_pop) {
	stack_linked<int> data;
	data.push(8);
	data.push(18);
	EXPECT_EQ(18, data.top());
	data.pop();
	EXPECT_EQ(8, data.top());
}
TEST(stack_linked, calling_pop_empty) {
	stack_linked<size_t> data;
	EXPECT_ANY_THROW(data.pop());
}
TEST(stack_linked, calling_top) {
	stack_linked<int> data;
	data.push(8);
	data.push(9);
	data.push(89);
	EXPECT_EQ(89, data.top());
}
TEST(stack_linked, calling_top_empty) {
	stack_linked<int> data;
	EXPECT_ANY_THROW(data.top());
}
TEST(stack_linked, calling_empty) {
	stack_linked<int> data;
	EXPECT_TRUE(data.empty());
	data.push(89);
	EXPECT_FALSE(data.empty());
}
TEST(stack_linked, calling_size) {
	stack_linked<int> data;
	EXPECT_EQ(0, data.size());
	data.push(89);
	data.push(87);
	EXPECT_EQ(2, data.size());
}
TEST(parent_pair, sample1) {
	EXPECT_TRUE(parent_pair(string("()(()){([()])}")));
}
TEST(parent_pair, sample2) {
	EXPECT_TRUE(parent_pair(string("((()(()){([()])}))")));
}
TEST(parent_pair, sample3) {
	EXPECT_FALSE(parent_pair(string(")(()){([()])}")));
}
TEST(parent_pair, sampe4) { EXPECT_FALSE(parent_pair(string("({[])}"))); }
TEST(queue_array, calling_empty) {
	queue_array<int> data;
	EXPECT_TRUE(data.empty());
	data.enqueue(13);
	EXPECT_FALSE(data.empty());
}
TEST(queue_array, calling_front) {
	queue_array<double> data;
	data.enqueue(98.8);
	data.enqueue(198.8);
	data.enqueue(298.8);
	EXPECT_EQ(98.8, data.front());
}
TEST(queue_array, calling_front_empty) {
	queue_array<std::string> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(queue_array, calling_dequeue) {
	queue_array<std::string> data(1);
	data.enqueue(std::string("six"));
	EXPECT_EQ(string("six"), data.front());
	data.dequeue();
	EXPECT_TRUE(data.empty());
}
TEST(queue_array, calling_dequeue_empty) {
	queue_array<int> data(1);
	data.enqueue(789);
	data.dequeue();
	EXPECT_ANY_THROW(data.dequeue());
}
TEST(queue_array, calling_size) {
	queue_array<int> data;
	data.enqueue(87);
	data.enqueue(98);
	EXPECT_EQ(2, data.size());
}
TEST(queue_array, calling_enqueue) {
	queue_array<int> data;
	for (auto i = 0; i < 10; ++i)
		data.enqueue(i);
	EXPECT_EQ(10, data.size());
	EXPECT_EQ(0, data.front());
}
TEST(queue_array, calling_enqueue_full) {
	queue_array<int> data(10);
	for (auto i = 0; i < 10; ++i)
		data.enqueue(i);
	EXPECT_ANY_THROW(data.enqueue(98));
}
TEST(queue_linked, calling_empty) {
	queue_linked<int> data;
	EXPECT_TRUE(data.empty());
	data.enqueue(89);
	EXPECT_FALSE(data.empty());
}
TEST(queue_linked, calling_size) {
	queue_linked<int> data;
	EXPECT_EQ(0, data.size());
	data.enqueue(89);
	EXPECT_EQ(1, data.size());
}
TEST(queue_linked, calling_front) {
	queue_linked<double> data;
	data.enqueue(90);
	data.enqueue(78);
	EXPECT_EQ(90, data.front());
}
TEST(queue_linked, calling_front_on_empty) {
	queue_linked<std::string> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(queue_linked, calling_enqueue) {
	queue_linked<int> data;
	for (auto i = 0; i < 10; ++i)
		data.enqueue(i + 8);
	EXPECT_EQ(10, data.size());
	EXPECT_EQ(8, data.front());
}
TEST(queue_linked, calling_dequeue) {
	queue_linked<int> data;
	for (auto i = 0; i < 10; ++i)
		data.enqueue(i + 8);
	data.dequeue();
	EXPECT_EQ(9, data.size());
	EXPECT_EQ(9, data.front());
}
TEST(queue_linked, calling_dequeue_empty) {
	queue_linked<int> data;
	EXPECT_ANY_THROW(data.dequeue());
}
TEST(queue_doubly_linked, calling_empty) {
	queue_doubly_linked<double> data;
	EXPECT_TRUE(data.empty());
	data.push_back(89);
	EXPECT_FALSE(data.empty());
}
TEST(queue_doubly_linked, calling_size) {
	queue_doubly_linked<int> data;
	EXPECT_EQ(0, data.size());
	for (auto i = 0; i < 10; ++i)
		data.push_back(i);
	EXPECT_EQ(10, data.size());
}
TEST(queue_doubly_linked, calling_front) {
	queue_doubly_linked<double> data;
	data.push_front(89);
	data.push_back(78);
	EXPECT_EQ(89, data.front());
}
TEST(queue_doubly_linked, calling_front_empty) {
	queue_doubly_linked<int> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(queue_doubly_linked, calling_back) {
	queue_doubly_linked<size_t> data;
	for (auto i = 1; i <= 5; ++i)
		data.push_back(i);
	EXPECT_EQ(5, data.back());
}
TEST(queue_doubly_linked, calling_back_empty) {
	queue_doubly_linked<int> data;
	EXPECT_ANY_THROW(data.back());
}
TEST(queue_doubly_linked, calling_pop_front) {
	queue_doubly_linked<int> data;
	data.push_back(89);
	data.push_back(890);
	data.pop_front();
	EXPECT_EQ(1, data.size());
	data.pop_front();
	EXPECT_EQ(0, data.size());
}
TEST(queue_doubly_linked, calling_pop_front_empty) {
	queue_doubly_linked<int> data;
	EXPECT_ANY_THROW(data.pop_front());
}
TEST(queue_doubly_linked, calling_pop_back) {
	queue_doubly_linked<int> data;
	data.push_back(98);
	data.push_back(77);
	data.pop_back();
	EXPECT_EQ(98, data.back());
	data.pop_back();
	EXPECT_TRUE(data.empty());
}
TEST(queue_doubly_linked, calling_pop_back_empty) {
	queue_doubly_linked<int> data;
	EXPECT_ANY_THROW(data.pop_back());
}
TEST(queue_doubly_linked, calling_push_back) {
	queue_doubly_linked<int> data;
	data.push_back(89);
	data.push_back(8);
	EXPECT_EQ(8, data.back());
}
TEST(queue_doubly_linked, calling_push_front) {
	queue_doubly_linked<int> data;
	data.push_front(889);
	data.push_front(766);
	EXPECT_EQ(766, data.front());
}
TEST(vector_arr, calling_empty) {
	vector_arr<int> data;
	EXPECT_TRUE(data.empty());
	data.push_back(78);
	EXPECT_FALSE(data.empty());
}
TEST(vector_arr, calling_size) {
	vector_arr<int> data;
	EXPECT_TRUE(data.empty());
	data.push_back(90);
	EXPECT_FALSE(data.empty());
	data.push_back(920);
	EXPECT_EQ(2, data.size());
}
TEST(vector_arr, using_subscript) {
	vector_arr<double> data;
	data.push_back(90.9);
	EXPECT_EQ(90.9, data[0]);
}
TEST(vector_arr, using_subscript_invalid_pos) {
	vector_arr<double> data;
	data.push_back(90.9);
	EXPECT_ANY_THROW(data[1]);
}
TEST(vector_arr, calling_push_back) {
	vector_arr<size_t> data;
	for (size_t i = 0; i < 100; ++i)
		data.push_back(i);
	EXPECT_EQ(100, data.size());
	EXPECT_EQ(99, data[99]);
}
TEST(vector_arr, calling_pop_back) {
	vector_arr<int> data;
	data.push_back(34);
	EXPECT_FALSE(data.empty());
	data.pop_back();
	EXPECT_TRUE(data.empty());
}
TEST(vector_arr, calling_pop_back_empty) {
	vector_arr<int> data;
	EXPECT_ANY_THROW(data.pop_back());
}
TEST(vector_arr, calling_back) {
	vector_arr<int> data;
	data.push_back(90);
	data.push_back(77);
	EXPECT_EQ(77, data.back());
}
TEST(vector_arr, calling_front) {
	vector_arr<int> data;
	data.push_back(78);
	data.push_back(76);
	EXPECT_EQ(78, data.front());
}
TEST(vector_arr, calling_front_empty) {
	vector_arr<int> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(vector_arr, calling_back_empty) {
	vector_arr<int> data;
	EXPECT_ANY_THROW(data.back());
}
TEST(list_adt, calling_size) {
	list_adt<int> data;
	EXPECT_EQ(0, data.size());
	data.push_back(78);
	EXPECT_EQ(1, data.size());
	data.pop_back();
	EXPECT_EQ(0, data.size());
}
TEST(list_adt, calling_empty) {
	list_adt<int> data;
	EXPECT_TRUE(data.empty());
	data.push_front(34);
	EXPECT_FALSE(data.empty());
}
TEST(list_adt, calling_back) {
	list_adt<int> data;
	data.push_back(8);
	data.push_back(87);
	EXPECT_EQ(87, data.back());
}
TEST(list_adt, calling_back_empty) {
	list_adt<int> data;
	EXPECT_ANY_THROW(data.back());
}
TEST(list_adt, calling_front) {
	list_adt<int> data;
	data.push_front(8);
	data.push_front(87);
	EXPECT_EQ(87, data.front());
}
TEST(list_adt, calling_front_empty) {
	list_adt<int> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(list_adt, calling_pop_back) {
	list_adt<size_t> data;
	data.push_back(89);
	data.pop_back();
	EXPECT_TRUE(data.empty());
}
TEST(list_adt, calling_pop_back_empty) {
	list_adt<int> data;
	EXPECT_ANY_THROW(data.pop_back());
}
TEST(list_adt, calling_pop_front) {
	list_adt<int> data;
	data.push_back(90);
	data.pop_front();
	EXPECT_TRUE(data.empty());
}
TEST(list_adt, calling_pop_front_empty) {
	list_adt<int> data;
	EXPECT_ANY_THROW(data.pop_front());
}
TEST(list_adt, calling_begin) {
	list_adt<int> data;
	data.push_back(89);
	auto begin = data.begin();
	EXPECT_EQ(89, *begin);
}
TEST(list_adt, calling_end) {
	list_adt<int> data;
	data.push_back(89);
	data.push_back(78);
	EXPECT_EQ(78, *(--data.end()));
}
TEST(list_adt, calling_push_back) {
	list_adt<int> data;
	for (size_t i = 0; i < 10; ++i)
		data.push_back(i);
	EXPECT_EQ(10, data.size());
}
TEST(list_adt, calling_push_front) {
	list_adt<int> data;
	for (size_t i = 0; i < 10; ++i)
		data.push_front(i);
	EXPECT_EQ(10, data.size());
}
TEST(list_adt, calling_insert) {
	list_adt<int> data;
	data.insert(data.begin(), 34);
	EXPECT_EQ(34, data.back());
}
TEST(list_adt, calling_erase) {
	list_adt<int> data;
	for (size_t i = 0; i < 10; ++i)
		data.push_back(i);
	EXPECT_EQ(10, data.size());
	for (size_t i = 0; i < 10; ++i)
		data.pop_back();
	EXPECT_TRUE(data.empty());
}
TEST(list_adt, calling_erase_empty) {
	list_adt<int> data;
	EXPECT_ANY_THROW(data.erase(data.begin()));
}
TEST(buble_sort, simplecase) {
	vector<int> data = { 4,3,1,2 };
	buble_sort(data);
	EXPECT_EQ(vector({ 1,2,3,4 }), data);
}
TEST(buble_sort, anothercase) {
	vector<int> data = { 7,8,4,3,1,2 };
	buble_sort(data);
	EXPECT_EQ(vector({ 1,2,3,4,7,8}), data);
}
TEST(buble_sort, largesample) {
	vector<double> data;
	for (auto i = 100; i > 1; --i)
		data.push_back((i + 1.0) * i);
	vector<double> temp(data.begin(), data.end());
	std::sort(temp.begin(), temp.end());
	buble_sort(data);
	EXPECT_EQ(data, temp);
}
TEST(binary_tree, calling_size){
	binary_tree<int> data;
	EXPECT_EQ(0, data.size());
	data.add_root(14);
	EXPECT_EQ(1, data.size());
}
TEST(binary_tree, calling_expand_external){
	binary_tree<double> data;
	data.add_root(34.4);
	EXPECT_EQ(1, data.size());
	auto pos = data.root();
	data.expand_external(pos,45.5,545.43);
	EXPECT_EQ(3, data.size());
}
TEST(binary_tree, calling_dereference_operator){
	binary_tree<double> data;
	data.add_root(56.34);
	EXPECT_EQ(1, data.size());
	auto pos = data.root();
	EXPECT_EQ(56.34, *pos);
	// data.expand_external(pos,45.5,545.43);
}
TEST(binary_tree, calling_left_right) {
	binary_tree<double> data;
	data.add_root(89.5);
	auto pos = data.root();
	data.expand_external(pos,45.5,545.43);
	EXPECT_EQ(45.5, *pos.left());
	EXPECT_EQ(545.43, *pos.right());
}
TEST(binary_tree, calling_positions) {
	binary_tree<size_t> data;
	data.add_root(89);
	auto pos = data.root();
	data.expand_external(pos, 78, 90);
	auto pos_right = pos.right();
	auto pos_left = pos.left();
	data.expand_external(pos_right, 88, 98);
	EXPECT_EQ(5, data.size());
	EXPECT_EQ(88, *pos_right.left());
	EXPECT_EQ(98, *pos_right.right());
	data.expand_external(pos_left, 32, 45);
	EXPECT_EQ(7, data.size());
	EXPECT_EQ(32, *pos_left.left());
	EXPECT_EQ(45, *pos_left.right());
}
TEST(binary_tree, calling_remove_ab_ext_nograndfa) {
	binary_tree<size_t> data;
	data.add_root(89);
	auto pos = data.root();
	data.expand_external(pos, 78, 90);
	data.remove_above_external(pos.left());
	EXPECT_EQ(1, data.size());
	EXPECT_EQ(90, *data.root());
}
TEST(binary_tree, calling_remove_ab_ext_withgrandfa) {
	binary_tree<double> data;
	data.add_root(78.9);
	auto pos = data.root();
	data.expand_external(pos,89.9,90.7);
	data.expand_external(pos.left(), 100.23, 200.23);
	data.remove_above_external(pos.left().left());
	EXPECT_EQ(3, data.size());
	EXPECT_EQ(78.9, *data.root());
	EXPECT_EQ(200.23, *pos.left());
}
TEST(binary_tree, calling_parent) {
	binary_tree<double> data;
	data.add_root(78.9);
	auto pos = data.root();
	data.expand_external(pos, 89.9, 90.7);
	EXPECT_EQ(78.9, *data.root().left().parent());
}
TEST(binary_tree, calling_positions_traverse) {
	binary_tree<double> data;
	data.add_root(78.9);
	auto pos = data.root();
	data.expand_external(pos, 89.9, 90.7);
	data.expand_external(pos.right(), 43.1, 67.1);
	vector<double> result;
	auto temp = data.positions();
	for (auto begin = temp.begin(); begin != temp.end(); ++begin)
		result.push_back(begin->value());
	EXPECT_EQ(5, temp.size());
	EXPECT_EQ(vector({ 78.9,89.9,90.7,43.1,67.1 }), result);
}
TEST(binary_tree, removing_on_empty) {
	binary_tree<int> data;
	auto pos = data.root();
	EXPECT_ANY_THROW(data.remove_above_external(pos));
}
TEST(binary_tree, removing_on_root) {
	binary_tree<int> data;
	data.add_root(23);
	EXPECT_ANY_THROW(data.remove_above_external(data.root()));
}
TEST(binary_tree, removing_on_nonexternal) {
	binary_tree<size_t> data;
	data.add_root(89);
	data.expand_external(data.root(), 43, 45);
	auto pos = data.root().left();
	data.expand_external(pos, 819, 32);
	EXPECT_ANY_THROW(data.remove_above_external(pos));
}
TEST(binary_tree, adding_on_exist_root) {
	binary_tree<int> data;
	data.add_root(78);
	EXPECT_ANY_THROW(data.add_root(78));
}
TEST(binary_tree, expand_for_non_external) {
	binary_tree<int> data;
	data.add_root(78);
	auto pos = data.root();
	data.expand_external(pos, 432, 433);
	EXPECT_ANY_THROW(data.expand_external(pos, 34, 21));
}
TEST(binary_tree, calling_dereference_on_invalid) {
	binary_tree<int> data;
	EXPECT_ANY_THROW(*data.root());
}
TEST(binary_tree, calling_value_on_invalid) {
	binary_tree<int> data;
	EXPECT_ANY_THROW(data.root().value());
}
TEST(binary_tree, calling_erase) {
	binary_tree<double> data;
	data.add_root(78.9);
	auto pos = data.root();
	data.expand_external(pos, 89.9, 90.7);
	EXPECT_TRUE(pos.left().value() == 89.9);
	EXPECT_TRUE(pos.right().value() == 90.7);

	data.expand_external(pos.right(), 43.1, 67.1);
	EXPECT_TRUE(pos.right().left().value() == 43.1);
	EXPECT_TRUE(pos.right().right().value() == 67.1);

	data.expand_external(pos.left(), 413.1, 167.1);
	EXPECT_TRUE(pos.left().left().value() == 413.1);
	EXPECT_TRUE(pos.left().right().value() == 167.1);

	EXPECT_EQ(7, data.positions().size());
	data.erase();
	
	EXPECT_FALSE(pos.left().value() == 89.9);
	EXPECT_FALSE(pos.right().value() == 90.7);

	EXPECT_EQ(0, data.positions().size());
	EXPECT_EQ(0, data.size());
}
TEST(binary_tree, calling_erase_default_behavior) {
	binary_tree<double> data;
	data.add_root(89.009181);
	//EXPECT_EQ(89.009181, data.root().value());
	EXPECT_TRUE(data.size() == 1);
	EXPECT_TRUE(data.positions().size() == 1);
	data.erase();
	// EXPECT_ANY_THROW(data.root().value());
	EXPECT_TRUE(data.size() == 0);
	EXPECT_TRUE(data.positions().size() == 0);
    data.add_root(89);
	data.expand_external(data.root(), 900.23, 897.23);
	EXPECT_TRUE(data.size() == 3);
	EXPECT_TRUE(data.positions().size() == 3);
	EXPECT_TRUE(data.root().left().value()==900.23);
	EXPECT_TRUE(data.root().right().value()==897.23);
	data.erase();
	EXPECT_TRUE(data.size() == 0);
	EXPECT_TRUE(data.positions().size() == 0);
    EXPECT_ANY_THROW(data.root().value());
    EXPECT_ANY_THROW(data.root().value());
}
TEST(binary_tree, calling_positions_default_behavior) {
	binary_tree<int> data;
	data.add_root(34);
	EXPECT_EQ(1, data.positions().size()); //default behavior is 1
	data.erase();
	EXPECT_EQ(0, data.size());
	EXPECT_TRUE(data.positions().size() == 0);
}
TEST(binary_tree, left_most_test) {
	binary_tree<double> data;
	data.add_root(78.9);
	auto pos = data.root();
	data.expand_external(pos, 89.9, 90.7);
	data.expand_external(pos.right(), 43.1, 67.1);
	data.expand_external(pos.left(), 413.1, 167.1);
	EXPECT_EQ(413.1, *data.left_most());
	EXPECT_FALSE(data.left_most().is_root());
}
TEST(binary_tree, right_most_test) {
	binary_tree<double> data;
	data.add_root(78.9);
	auto pos = data.root();
	data.expand_external(pos, 89.9, 90.7);
	data.expand_external(pos.right(), 43.1, 67.1);
	data.expand_external(pos.left(), 413.1, 167.1);
	EXPECT_EQ(67.1, *data.right_most());
	EXPECT_FALSE(data.right_most().is_root());
}
TEST(binary_tree, left_most_after_deleted){
    binary_tree<char> data;
    data.add_root('A');
    data.expand_external(data.root(),'B','C');
    data.expand_external(data.root().left(),'1','2');
    data.expand_external(data.root().right(),'3','4');
    EXPECT_EQ(char('1'),data.left_most().value());
    data.remove_above_external(data.left_most());
    EXPECT_EQ(char('2'),data.left_most().value());
    data.erase();
    EXPECT_TRUE(data.empty());
    EXPECT_ANY_THROW(data.root().value());
}
TEST(binary_tree,right_most_after_deleted){
    binary_tree<char> data;
    data.add_root('A');
    data.expand_external(data.root(),'B','C');
    data.expand_external(data.root().left(),'1','2');
    data.expand_external(data.root().right(),'3','4');
    EXPECT_EQ(char('4'),data.right_most().value());
    data.remove_above_external(data.right_most());
    EXPECT_EQ(char('3'),data.right_most().value());
    data.erase();
    EXPECT_TRUE(data.empty());
    EXPECT_ANY_THROW(data.root().value());
}
TEST(priority_queue_list, calling_empty) {
	priority_queue_list<int, std::less<>> data;
	EXPECT_TRUE(data.empty());
}
TEST(priority_queue_list, calling_size) {
	priority_queue_list<double, std::greater<>> data;
	for (size_t i = 0; i < 15; ++i)
		data.insert(i + 1 * 1.23);
	EXPECT_EQ(15, data.size());
	data.remove_min();
	EXPECT_EQ(14, data.size());
}
TEST(priority_queue_list, calling_min) {
	priority_queue_list<size_t, std::greater<>> data;
	data.insert(89);
	data.insert(78);
	EXPECT_EQ(89, data.min_element());
	priority_queue_list<int, std::less<>> data_1;
	data_1.insert(98);
	data_1.insert(65);
	EXPECT_EQ(65, data_1.min_element());
}
TEST(priority_queue_list, calling_remove_min) {
	priority_queue_list<size_t, std::greater<>> data;
	data.insert(89);
	data.insert(78);
	EXPECT_EQ(2, data.size());
	data.remove_min();
	EXPECT_EQ(1, data.size());
}
TEST(priority_queue_list, calling_insert) {
	priority_queue_list<int, std::less<>> data;
	data.insert(89);
	EXPECT_EQ(1, data.size());
	data.insert(97);
	EXPECT_EQ(2, data.size());
}
TEST(priority_queue_list, calling_selection_sort) {
	std::list<int> data = { 5,4,3,2,1,0 };
	selection_sort(data);
	EXPECT_EQ(std::list({ 0,1,2,3,4,5 }), data);
}
TEST(binary_heap, calling_empty) {
	binary_heap<int> data(100);
	EXPECT_TRUE(data.empty());
}
TEST(binary_heap, calling_insert) {
	binary_heap<char> data(100);
	vector<char> temp = { 'T','N','R','P','H','O','A','E','I','G'};
	for (const auto& i : temp)
		data.insert(i);
	data.insert('S');
	EXPECT_EQ(data.front(), 'A');
}
TEST(binary_heap, calling_insert_worst_case) {
	binary_heap<char> data(100);
	vector<char> temp = { 'T','N','R','P','H','O','A','E','I','G' };
	for (const auto& i : temp)
		data.insert(i);
	data.insert('S');
	data.insert('V');
	EXPECT_EQ(data.front(), 'A');
}
TEST(binary_heap, calling_pop_front) {
	binary_heap<char> data(100);
	vector<char> temp = { 'T','N','R','P','H','O','A','E','I','G' };
	for (const auto& i : temp)
		data.insert(i);
	data.insert('S');
	data.insert('V');
	EXPECT_EQ(data.front(), 'A');
	data.pop_front();
	EXPECT_EQ(data.front(), 'E');
}
TEST(binary_heap, calling_pop_front_sample) {
	binary_heap<char> data;
	std::vector<char> temp = { 'P','P','A','M','L','E','E' };
	for (const auto& i : temp)
		data.insert(i);
	EXPECT_EQ('A', data.front());
	data.pop_front();
	EXPECT_EQ('E', data.front());
	data.pop_front();
	EXPECT_EQ('E', data.front());
	data.pop_front();
	EXPECT_EQ('L', data.front());

}
TEST(binary_heap, calling_pop_front_empty) {
	binary_heap<char> data;
	EXPECT_ANY_THROW(data.pop_front());
}
TEST(binary_heap, calling_front_on_empty) {
	binary_heap<int> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(binary_heap, calling_clear) {
	binary_heap<char> data;
	std::vector<char> temp = { 'P','P','A','M','L','E','E' };
	for (const auto& i : temp)
		data.insert(i);
	EXPECT_EQ('A', data.front());
	data.clear();
	EXPECT_ANY_THROW(data.front());
}
TEST(binary_heap, calling_empty_vmin) {
	binary_heap<int> data;
	EXPECT_TRUE(data.empty());
}
TEST(binary_heap, calling_insert_odds) {
	binary_heap<char> data;
	std::vector<char> temp = { 'P','P','F','M','L','E','E' };
	for (const auto& i : temp)
		data.insert(i);
	EXPECT_EQ(data.front(), 'E');
	data.insert('A');
	EXPECT_EQ(data.front(), 'A');
}
TEST(binary_heap, calling_insert_even) {
	binary_heap<char> data;
	std::vector<char> temp = { 'P','P','K','F','M','L','E','E' };
	for (const auto& i : temp)
		data.insert(i);
	EXPECT_EQ(data.front(), 'E');
	data.insert('A');
	EXPECT_EQ(data.front(), 'A');
}
TEST(binary_heap, calling_pop_front_odds) {
	binary_heap<char> data;
	std::vector<char> temp = { 'P','P','F','M','L','E','E' };
	for (const auto& i : temp)
		data.insert(i);
	data.pop_front();
	EXPECT_EQ('E', data.front());
	data.pop_front();
	EXPECT_EQ('F', data.front());
	data.pop_front();
	EXPECT_EQ('L', data.front());
}
TEST(binary_heap, calling_pop_front_even) {
	binary_heap<char> data;
	std::vector<char> temp = { 'P','P','F','M','L','E','E', 'A', 'B','C'};
	for (const auto& i : temp)
		data.insert(i);
	EXPECT_EQ('A', data.front());
	std::sort(temp.begin(), temp.end());
	for (auto i = 0; i < temp.size(); ++i) {
		EXPECT_EQ(temp[i], data.front());
		data.pop_front();
	}
}
TEST(binary_heap, bugs_on_minimum) {
	std::vector<char> temp = { 'P','P','F','M','L','E','E', 'A', 'B','C' };
	binary_heap<char> data(temp);
	EXPECT_EQ('A', data.front());
}
TEST(binary_heap, build_heap_from_ctor) {
	vector<int> data = 
		{150,80,40,30,10,70,110,100,20,90,60,50,120,140,130};
	binary_heap<int> build_from_collection(data);
	std::sort(data.begin(), data.end());
	for (const auto& item : data) {
		EXPECT_EQ(build_from_collection.front(), item);
		build_from_collection.pop_front();
	}
}
TEST(heap_sort, heap_sort_sample1) {
	std::vector<char> temp = { 'P','P','F','M','L','E','E', 'A', 'B','C' };
	auto temp_min = temp;
	std::sort(temp_min.begin(), temp_min.end());
	heap_sort_min(temp);
	EXPECT_EQ(temp_min, temp);
}
TEST(heap_sort, heap_sort_sample2) {
	vector<int> data = { 150,80,40,30,10,70,110,100,20,90,60,50,120,140,130 };
	auto temp = data;
	std::sort(temp.begin(), temp.end());
	heap_sort_min(data);
	EXPECT_EQ(temp, data);
}

TEST(heap_sort, heap_sort_ascending_example) {
	std::vector<char> data = { 'S','O','R','T','E','X','A','M','P','L','E' };
	auto temp = data;
	std::sort(temp.begin(), temp.end());
	heap_sort_min(data);
	EXPECT_EQ(temp, data);
}
// heap sort for double, large number of elements
TEST(heap_sort, heap_sort_ascending_large) {
	std::vector<double> data;
	for (auto i = 100; i > 0; --i)
		data.push_back(i * 1.5);
	auto temp = data;
	std::sort(temp.begin(), temp.end());
	heap_sort_min(data);
	EXPECT_EQ(temp, data);
}

TEST(binary_heap_max, calling_insert) {
	std::vector<int> temp;
	for (size_t i = 0; i < 200; ++i)
		temp.push_back(i);
	binary_heap_max<int> heap_max(temp);
	EXPECT_EQ(199,heap_max.max());
}

TEST(binary_heap, calling_pop_max) {
	std::vector<int> temp;
	for (size_t i = 0; i < 200; ++i)
		temp.push_back(i);
	binary_heap_max<int> heap_max(temp);
	std::reverse(temp.begin(), temp.end());
	for (const auto& item : temp) {
		EXPECT_EQ(item, heap_max.max());
		heap_max.pop_max();
	}
}

TEST(binary_heap_max, calling_empty) {
	binary_heap_max<int> data;
	EXPECT_TRUE(data.empty());
}

TEST(binary_heap, calling_size_on_insert) {
	binary_heap_max<int> data;
	for (int i = 0; i < 100; ++i)
		data.insert(i);
	EXPECT_EQ(100, data.size());
}

TEST(binary_heap, calling_size_on_clear) {
	binary_heap_max<int> data;
	for (int i = 0; i < 100; ++i)
		data.insert(i);
	EXPECT_EQ(100, data.size());
	data.clear();
	EXPECT_EQ(0, data.size());
}

TEST(binary_heap_max, calling_max_on_empty) {
	binary_heap_max<int> data;
	EXPECT_ANY_THROW(data.max());
}

TEST(binary_heap_max, calling_pop_max_on_empty) {
	binary_heap_max<int> data;
	EXPECT_ANY_THROW(data.pop_max());
}

TEST(binary_heap_max, calling_heap_sort_sample1) {
	std::vector<int> data;
	for (auto i = 0; i < 100; ++i)
		data.push_back(i);
	auto temp = data;
	std::reverse(temp.begin(), temp.end());
	heap_sort_max(data);
	EXPECT_EQ(data, temp);
}

TEST(binary_heap_max, calling_heap_sort_sample2) {
	std::vector<char> data;
	for (auto i = 65; i < 91; ++i)
		data.push_back(i);
	auto temp = data;
	std::reverse(temp.begin(), temp.end());
	heap_sort_max(data);
	EXPECT_EQ(data, temp);
}

TEST(binary_heap_max, random_sample) {
	vector<int> data;
	for (size_t i = 0; i < 100; ++i)
		data.push_back(std::rand());
	auto temp = data;
	std::sort(temp.begin(), temp.end(), std::greater<>());
	binary_heap_max<int> heap_max(data);
	for (size_t i = 0; i < 100; ++i) {
		EXPECT_EQ(temp[i], heap_max.max());
		heap_max.pop_max();
	}
}
TEST(binary_heap_max, random_heap_sort) {
	vector<int> data;
	for (size_t i = 0; i < 100; ++i)
		data.push_back(std::rand());
	auto temp = data;
	std::sort(temp.begin(), temp.end(), std::greater<>());
	heap_sort_max(data);
	EXPECT_EQ(data, temp);
}
TEST(binary_heap, random_heap_sort) {
	vector<int> data;
	for (size_t i = 0; i < 100; ++i)
		data.push_back(std::rand());
	auto temp = data;
	std::sort(temp.begin(), temp.end());
	heap_sort_min(data);
	EXPECT_EQ(data, temp);
}
TEST(generic_binary_heap, priority_minimum_callsize) {
	binaryheap<int> data;
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(10, data.size());
}
TEST(generic_binary_heap, priority_minimum_callinsert) {
	binaryheap<int> data;
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(data.size(), 10);
}
TEST(generic_binary_heap, priority_minimum_callpopfront) {
	binaryheap<int> data;
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(data.size(), 10);
	data.pop_front();
	EXPECT_EQ(data.size(), 9);
	data.pop_front();
	EXPECT_EQ(data.size(), 8);
}
TEST(generic_binary_heap, priority_minimum_callempty) {
	binaryheap<int> data;
	EXPECT_TRUE(data.empty());
}
TEST(generic_binary_heap, priority_minimum_callfront) {
	binaryheap<int> data;
	std::vector<int> temp;
	for (size_t i = 0; i < 10; ++i) {
		auto item = std::rand();
		temp.push_back(item);
		data.insert(item);
	}
	std::sort(temp.begin(), temp.end());
	for (const auto& i : temp) {
		EXPECT_EQ(i, data.front());
		data.pop_front();
	}
	EXPECT_TRUE(data.empty());
}
TEST(generic_binary_heap, priority_minimum_callfront_empty) {
	binaryheap<int> data;
	EXPECT_ANY_THROW(data.front());
}
TEST(generic_binary_heap, priority_minimum_call_popfront_empty) {
	binaryheap<int> data;
	EXPECT_ANY_THROW(data.pop_front());
}
TEST(generic_binary_heap, priority_minimum_call_erase) {
	binaryheap<int> data(100);
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(data.size(), 10);
	data.clear();
	EXPECT_TRUE(data.empty());
}
// test case for maximum as priority
TEST(generic_binary_heap, priority_maximum_callinsert) {
	binaryheap<int> data(100, false);
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(data.size(), 10);
}
TEST(generic_binary_heap, priority_maximum_callpopfront) {
	binaryheap<int> data(100, false);
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(data.size(), 10);
	data.pop_front();
	EXPECT_EQ(data.size(), 9);
	data.pop_front();
	EXPECT_EQ(data.size(), 8);
}
TEST(generic_binary_heap, priority_maximum_callempty) {
	binaryheap<int> data(100, false);
	EXPECT_TRUE(data.empty());
}
TEST(generic_binary_heap, priority_maximum_callfront) {
	binaryheap<int> data(100, false);
	std::vector<int> temp;
	for (size_t i = 0; i < 10; ++i) {
		auto item = std::rand();
		temp.push_back(item);
		data.insert(item);
	}
	std::sort(temp.begin(), temp.end(), std::greater<>());
	for (const auto& i : temp) {
		EXPECT_EQ(i, data.front());
		data.pop_front();
	}
	EXPECT_TRUE(data.empty());
}
TEST(generic_binary_heap, priority_maximum_callfront_empty) {
	binaryheap<int> data(100, false);
	EXPECT_ANY_THROW(data.front());
}
TEST(generic_binary_heap, priority_maximum_call_popfront_empty) {
	binaryheap<int> data(100,false);
	EXPECT_ANY_THROW(data.pop_front());
}
TEST(generic_binary_heap, priority_maximum_call_erase) {
	binaryheap<int> data(100, false);
	for (size_t i = 0; i < 10; ++i)
		data.insert(std::rand());
	EXPECT_EQ(data.size(), 10);
	data.clear();
	EXPECT_TRUE(data.empty());
}
TEST(generic_binary_heap, priority_minimum_usingcollections) {
	std::vector<int> data;
	for (auto i = 0; i < 20; ++i)
		data.push_back(std::rand());
	binaryheap<int> heap(data);
	std::sort(data.begin(), data.end());
	EXPECT_EQ(data.front(), heap.front());
	EXPECT_EQ(20, heap.size());
	heap.pop_front();
	EXPECT_EQ(19, heap.size());
}
TEST(generic_binary_heap, priority_maximum_usingcollections) {
	std::vector<int> data;
	for (auto i = 0; i < 20; ++i)
		data.push_back(std::rand());
	binaryheap<int> heap(data, false);
	std::sort(data.begin(), data.end(), std::greater<>());
	EXPECT_EQ(data.front(), heap.front());
	EXPECT_EQ(20, heap.size());
	heap.pop_front();
	EXPECT_EQ(19, heap.size());
}
TEST(generic_heap_sort, minimum_as_priority) {
	std::vector<int> data;
	for (auto i = 0; i < 20; ++i)
		data.push_back(std::rand());
	auto temp = data;
	std::sort(temp.begin(), temp.end());
	heap_sort(data);
	EXPECT_EQ(data, temp);
}
TEST(generic_heap_sort, maximum_as_priority) {
	std::vector<int> data;
	for (auto i = 0; i < 20; ++i)
		data.push_back(std::rand());
	auto temp = data;
	std::sort(temp.begin(), temp.end(), std::greater<>());
	heap_sort(data, false);
	EXPECT_EQ(data, temp);
}
TEST(binary_search_tree_key_value, calling_empty) {
	binary_search_tree<int, int> data;
	EXPECT_TRUE(data.empty());
}
// binary search tree key value pair test cases
TEST(binary_search_tree_key_value, calling_size) {
	binary_search_tree<int, int> data;
	EXPECT_EQ(0, data.size());
	data.insert(89, 90);
	EXPECT_EQ(1, data.size());
}
TEST(binary_search_tree_key_value, calling_insert) {
	binary_search_tree<int, int> data;
	data.insert(89, 90);
	EXPECT_EQ(1, data.size());
}
TEST(binary_search_tree_key_value, calling_insert_multiple) {
	binary_search_tree<int, int> data;
	data.insert(89, 9440);
	data.insert(78, 940);
	data.insert(90, 9430);
	EXPECT_EQ(3, data.size());
}
TEST(binary_search_tree_key_value, calling_insert_duplicate) {
	binary_search_tree<int, int> data;
	data.insert(89, 90);
	EXPECT_EQ(1, data.size());
	data.insert(89, 90);
	EXPECT_EQ(1, data.size());
}
TEST(binary_search_tree_key_value, calling_find_min){
	binary_search_tree<int, int> data;
	data.insert(89, 90);
	data.insert(78, 90);
	data.insert(90, 90);
	EXPECT_EQ(78, data.find_min());
}
TEST(binary_search_tree_key_value, calling_find_max){
	binary_search_tree<int, int> data;
	data.insert(89, 690);
	data.insert(78, 790);
	data.insert(90, 990);
	EXPECT_EQ(90, data.find_max());
}
TEST(binary_search_tree_key_value, calling_remove){
	binary_search_tree<int, int> data;
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	EXPECT_EQ(3, data.size());
	data.remove(78);
	EXPECT_EQ(2, data.size());
	data.remove(90);
	EXPECT_EQ(1, data.size());
	data.remove(89);
	EXPECT_EQ(0, data.size());
}
TEST(binary_search_tree_key_value, calling_find_min_empty){
	binary_search_tree<int, int> data;
	EXPECT_ANY_THROW(data.find_min());
}
TEST(binary_search_tree_key_value, calling_find_max_empty){
	binary_search_tree<int, int> data;
	EXPECT_ANY_THROW(data.find_max());
}
TEST(binary_search_tree_key_value, calling_remove_contains){
	binary_search_tree<int, int> data;
	data.insert(89, 90);
	data.insert(78, 90);
	data.insert(90, 90);
	EXPECT_TRUE(data.contains(78));
	EXPECT_TRUE(data.contains(90));
	EXPECT_TRUE(data.contains(89));
	EXPECT_FALSE(data.contains(100));
}
TEST(binary_search_tree_key_value, calling_Clear){
	binary_search_tree<int, int> data;
	data.insert(89, 90);
	data.insert(78, 90);
	data.insert(90, 90);
	EXPECT_EQ(3, data.size());
	data.clear();
	EXPECT_EQ(0, data.size());
}
// clone test 
TEST(binary_search_tree_key_value, calling_clone){
	binary_search_tree<int, int> data;
	data.insert(89, 90);
	data.insert(78, 90);
	data.insert(90, 90);
	binary_search_tree<int, int> clone(data);
	EXPECT_EQ(3, clone.size());
	EXPECT_TRUE(clone.contains(78));
	EXPECT_TRUE(clone.contains(90));
	EXPECT_TRUE(clone.contains(89));
	clone.clear();
	EXPECT_EQ(0, clone.size());
	EXPECT_EQ(3, data.size());
	EXPECT_FALSE(clone.contains(78));
	EXPECT_FALSE(clone.contains(90));
	EXPECT_FALSE(clone.contains(89));
}
// test case calling items()
TEST(binary_search_tree_key_value, calling_items){
	binary_search_tree<int, int> data;
	data.insert(89, 901);
	data.insert(78, 902);
	data.insert(90, 903);
	std::vector<std::pair<int, int>> goal = { {78,902},{89,901},{90,903} };
	EXPECT_EQ(goal, data.items());
}
// test case calling items() random large sample
TEST(binary_search_tree_key_value, calling_items_random){
	binary_search_tree<int, int> data;
	std::vector<std::pair<int, int>> goal;
	for (size_t i = 0; i < 30; ++i) {
		auto key = std::rand();
		auto value = std::rand();
		data.insert(key, value);
		goal.push_back({ key,value });
	}
	std::sort(goal.begin(), goal.end());
	EXPECT_EQ(goal, data.items());
}
// test calling min for pair key value
TEST(binary_search_tree_key_value, calling_min){
	binary_search_tree<int, int> data;
	data.insert(89, 901);
	data.insert(78, 902);
	data.insert(90, 903);
	std::pair<int, int> goal = { 78,902 };
	EXPECT_EQ(goal, data.min());
}
// test calling max for pair key value
TEST(binary_search_tree_key_value, calling_max){
	binary_search_tree<int, int> data;
	data.insert(89, 901);
	data.insert(78, 902);
	data.insert(90, 903);
	std::pair<int, int> goal = { 90,903 };
	EXPECT_EQ(goal, data.max());
}
// test calling min for pair key value, throw exception
TEST(binary_search_tree_key_value, calling_min_empty){
	binary_search_tree<int, int> data;
	EXPECT_ANY_THROW(data.min());
}
// test calling max for pair key value, throw exception
TEST(binary_search_tree_key_value, calling_max_empty){
	binary_search_tree<int, int> data;
	EXPECT_ANY_THROW(data.max());
}
TEST(red_black_tree, calling_size) {
	red_black_tree<int, std::string> name;
	EXPECT_EQ(0, name.size());
}
TEST(red_black_tree, calling_front) {
	red_black_tree<int, std::string> name;
	name.insert(1, std::string("michael s"));
	std::pair<int, std::string> goal = make_pair( 1, "michael s" );
	EXPECT_EQ(goal, name.top());
}
TEST(red_black_tree, calling_insert_multiple) {
	red_black_tree<int, std::string> name;
	name.insert(1, std::string("michael s"));
	name.insert(2, std::string("dwi s"));
	name.insert(3, std::string("kuncjoro s"));
	std::pair<int, std::string> goal = make_pair(2, "dwi s");
	EXPECT_EQ(goal, name.top());
}
TEST(red_black_tree, calling_size_on_multiple_insert) {
	red_black_tree<int, std::string> name;
	name.insert(1, std::string("michael s"));
	name.insert(2, std::string("dwi s"));
	EXPECT_EQ(2, name.size());
}
TEST(red_black_tree, calling_empty) {
	red_black_tree<int, int> data;
	EXPECT_TRUE(data.empty());
}
TEST(red_black_tree, calling_min) {
	red_black_tree<int, int> data;
	data.insert(89, 901);
	data.insert(78, 902);
	data.insert(90, 903);
	std::pair<int, int> goal = { 78,902 };
	EXPECT_EQ(goal, data.min());
}
TEST(red_black_tree, calling_min_random) {
	red_black_tree<int, int> data;
	std::vector<std::pair<int, int>> goal;
	for (size_t i = 0; i < 30; ++i) {
		auto key = std::rand();
		auto value = std::rand();
		data.insert(key, value);
		goal.push_back({ key,value });
	}
	std::sort(goal.begin(), goal.end());
	EXPECT_EQ(goal.front(), data.min());
}
TEST(red_black_tree, calling_max) {
	red_black_tree<int, int> data;
	data.insert(89, 901);
	data.insert(78, 902);
	data.insert(90, 903);
	std::pair<int, int> goal = { 90,903 };
	EXPECT_EQ(goal, data.max());
}
TEST(red_black_tree, calling_max_random) {
	red_black_tree<int, int> data;
	std::vector<std::pair<int, int>> goal;
	for (size_t i = 0; i < 30; ++i) {
		auto key = std::rand();
		auto value = std::rand();
		data.insert(key, value);
		goal.push_back({ key,value });
	}
	std::sort(goal.begin(), goal.end());
	EXPECT_EQ(goal.back(), data.max());
}
TEST(red_black_tree, calling_items) {
	red_black_tree<int, int> data;
	data.insert(89, 901);
	data.insert(78, 902);
	data.insert(90, 903);
	std::vector<std::pair<int, int>> goal = { {78,902},{89,901},{90,903} };
	EXPECT_EQ(goal, data.items());
}
TEST(red_black_tree, calling_items_random) {
	red_black_tree<int, int> data;
	std::vector<std::pair<int, int>> goal;
	for (size_t i = 0; i < 30; ++i) {
		auto key = std::rand();
		auto value = std::rand();
		data.insert(key, value);
		goal.push_back({ key,value });
	}
	std::sort(goal.begin(), goal.end());
	EXPECT_EQ(goal, data.items());
}
TEST(red_black_tree, calling_contain) {
	red_black_tree<int, int> data;
	auto temp = 0;
	for (size_t i = 0; i < 30; ++i) {
		auto key = std::rand();
		if (i == 15)
			temp = key;
		auto value = std::rand();
		data.insert(key, value);
	}
	data.insert(99, 66);
	EXPECT_TRUE(data.contain(99));
	EXPECT_TRUE(data.contain(temp));
}
TEST(red_black_tree, calling_delete_max){
	red_black_tree<std::string, size_t> data;
	data.insert(std::string("michael"), 2);
	data.insert(std::string("simon"), 3);
	data.insert(std::string("yoel"), 4);
	std::pair<std::string, size_t> temp = {std::string("simon"), 3};
	data.delete_max();
	EXPECT_EQ(temp, data.max());
}
TEST(red_black_tree, calling_delete_min){
	red_black_tree<std::string, size_t> data;
	data.insert(std::string("michael"), 2);
	data.insert(std::string("simon"), 3);
	data.insert(std::string("yoel"), 4);
	std::pair<std::string, size_t> temp = {std::string("simon"), 3};
	data.delete_min();
	EXPECT_EQ(temp, data.min());
}
TEST(red_black_tree, DISABLED_random_delete_min){
	red_black_tree<int, double> data;
	std::set<int> key;
	for (size_t i = 0; i < 20; i++){
		key.insert(std::rand());
	}
	for(auto beg = key.begin(); beg!= key.end(); ++beg){
		data.insert(*beg, 90.2);
	}
	auto beg = key.begin();
	while(beg!= key.end()){
		auto temp_pair = std::make_pair(*beg, 90.2);
		EXPECT_EQ(temp_pair, data.min());
		data.delete_min();
		++beg;
	}
}
TEST(red_black_tree, DISABLED_random_delete_max){
	red_black_tree<int, double> data;
	std::vector<std::pair<int, double>> temp = {
		{13,90.2}, {136,90.2},{133,90.2},
		{113,90.2},{1389,90.2}
	};
	for (size_t i = 0; i < 5; i++)
		data.insert(temp[i].first, temp[i].second);

	std::sort(temp.begin(), temp.end(), std::greater<>());
	auto beg = temp.begin();
	while(beg!= temp.end()){
		EXPECT_EQ(*beg, data.max());
		data.delete_max();
		++beg;
	}
}
class non_recursive_binary_search_tree_test : public ::testing::Test {
protected:
	non_recursive_binary_search_tree<int, int> data;
	void SetUp()override {
	}
	void TearDown()override {
		data.clear();
	}
};

TEST_F(non_recursive_binary_search_tree_test, calling_empty) {
	EXPECT_TRUE(data.empty());
}
TEST_F(non_recursive_binary_search_tree_test, calling_size) {
	EXPECT_EQ(0, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_insert) {
	data.insert(100, 90);
	EXPECT_EQ(1, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_insert_multiple) {
	for (int i = 0; i < 10; i++)
		data.insert(i, 90);
	EXPECT_EQ(10, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_insert_duplicate) {
	data.insert(11,90);
	data.insert(11, 89);
	EXPECT_EQ(2, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_find_min) {
	data.insert(89, 90);
	data.insert(78, 90);
	data.insert(90, 90);
	auto pairmin = std::make_pair(78, 90);
	EXPECT_EQ(pairmin, data.minimum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_find_max) {
	data.insert(89, 690);
	data.insert(78, 790);
	data.insert(90, 990);
	auto pairmax = std::make_pair(90, 990);
	EXPECT_EQ(pairmax, data.maximum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_find_min_empty) {
	EXPECT_ANY_THROW(data.minimum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_find_max_empty) {
	EXPECT_ANY_THROW(data.maximum());
}
// random test case for non recursive binary tree, minimum
TEST_F(non_recursive_binary_search_tree_test, calling_find_min_random) {
	std::set<int> key;
	for (size_t i = 0; i < 20; i++)
		key.insert(std::rand());
	for (auto beg = key.begin(); beg != key.end(); ++beg)
		data.insert(*beg, 90);
	auto pairmin = std::make_pair(*key.begin(), 90);
	EXPECT_EQ(pairmin, data.minimum());
}
// random test case for non recursive binary tree, maximum
TEST_F(non_recursive_binary_search_tree_test, calling_find_max_random) {
	std::set<int> key;
	for (size_t i = 0; i < 20; i++)
		key.insert(std::rand());

	for (auto beg = key.begin(); beg != key.end(); ++beg)
		data.insert(*beg, 90);
	auto max = key.end();
	--max;
	auto pairmax = std::make_pair(*max, 90);
	EXPECT_EQ(pairmax, data.maximum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_remove) {
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	data.insert(100, 900);
	EXPECT_EQ(4, data.size());
	data.remove(78);
	EXPECT_EQ(3, data.size());
	data.remove(90);
	EXPECT_EQ(2, data.size());
	data.remove(89);
	EXPECT_EQ(1, data.size());
	data.remove(100);
	EXPECT_EQ(0, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_remove_random) {
	std::set<int> key;
	for (size_t i = 0; i < 20; i++)
		key.insert(std::rand());

	for (auto beg = key.begin(); beg != key.end(); ++beg)
		data.insert(*beg, 90);

	auto max = key.end();
	--max;
	auto pairmax = std::make_pair(*max, 90);
	EXPECT_EQ(pairmax, data.maximum());
	data.remove(*max);
	key.erase(max);
	max = key.end();
	--max;
	pairmax = std::make_pair(*max, 90);
	EXPECT_EQ(pairmax, data.maximum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_remove_multiple_times) {
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	data.insert(100, 900);
	EXPECT_EQ(4, data.size());
	data.remove(78);
	EXPECT_EQ(3, data.size());
	data.remove(90);
	EXPECT_EQ(2, data.size());
	data.remove(89);
	EXPECT_EQ(1, data.size());
	data.remove(100);
	EXPECT_EQ(0, data.size());
	EXPECT_ANY_THROW(data.minimum());
	EXPECT_ANY_THROW(data.maximum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_remove_for_non_exist) {
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	data.insert(100, 900);
	data.remove(101);
	EXPECT_EQ(4, data.size());
	data.remove(781);
	EXPECT_EQ(4, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_contain){
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	data.insert(100, 900);
	EXPECT_TRUE(data.contain(78));
	EXPECT_TRUE(data.contain(90));
	EXPECT_TRUE(data.contain(89));
	EXPECT_FALSE(data.contain(1000));
}
// calling contain after remove
TEST_F(non_recursive_binary_search_tree_test, calling_contain_after_remove){
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	data.insert(100, 900);
	data.remove(78);
	EXPECT_FALSE(data.contain(78));
	EXPECT_TRUE(data.contain(90));
	EXPECT_TRUE(data.contain(89));
	EXPECT_TRUE(data.contain(100));
	data.remove(100);
	EXPECT_FALSE(data.contain(100));
	data.remove(90);
	EXPECT_FALSE(data.contain(90));
	data.remove(89);
	EXPECT_FALSE(data.contain(89));
}
TEST_F(non_recursive_binary_search_tree_test, calling_clear) {
	data.insert(89, 990);
	data.insert(78, 980);
	data.insert(90, 790);
	data.insert(100, 900);
	EXPECT_EQ(4, data.size());
	data.clear();
	EXPECT_EQ(0, data.size());
	EXPECT_ANY_THROW(data.minimum());
	EXPECT_ANY_THROW(data.maximum());
}
TEST_F(non_recursive_binary_search_tree_test, calling_clear_on_empty) {
	data.clear();
	EXPECT_EQ(0, data.size());
}
TEST_F(non_recursive_binary_search_tree_test, calling_delete_on_root) {
	EXPECT_TRUE(data.empty());
	data.insert(111, 2332);
	// data.print();
	EXPECT_FALSE(data.empty());
	data.remove(111);
	// data.print();
	EXPECT_TRUE(data.empty());
	EXPECT_ANY_THROW(data.minimum());
	EXPECT_ANY_THROW(data.maximum());
}
#endif	