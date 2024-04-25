#ifndef LINKED_LIST_PROBLEM
#define LINKED_LIST_PROBLEM
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
		if (!this->head) 
			this->head = node;
		else 
			this->tail->next = node;
		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
	while (node) {
		fout << node->data;
		node = node->next;
		if (node) 
			fout << sep;
	}
}
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
	vector<int> temp;
	SinglyLinkedList* ls = new SinglyLinkedList();
	while (llist) {
		temp.push_back(llist->data);
		llist = llist->next;
	}
	auto rbegin = temp.rbegin();
	auto rend = temp.rend();
	while (rbegin != rend) {
		ls->insert_node(*rbegin);
		++rbegin;
	}
}
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, 
	SinglyLinkedListNode* head2) {
	vector<int> temp;
	while (head1) {
		temp.push_back(head1->data);
		head1 = head1->next;
	}
	while (head2) {
		temp.push_back(head2->data);
		head2 = head2->next;
	}
	std::sort(temp.begin(), temp.end());
	SinglyLinkedList* it = new SinglyLinkedList();
	auto begin = temp.begin();
	auto end = temp.end();
	while (begin != end) {
		it->insert_node(*begin);
		++begin;
	}
	return it->head;
}
#endif // !LINKED_LIST_PROBLEM
