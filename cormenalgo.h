#ifndef CORMEN_ALGORITHM
#define CORMEN_ALGORITHM
#include <iostream>
#include <vector>
using std::vector;
namespace cormen {
	template <typename T, typename Compareble>
	void insertion_sort(vector<T>& data, Compareble comp) {
		auto len = data.size();
		auto j = 0;
		auto key = T();
		for (auto i = 1; i < len; ++i) {
			j = i - 1;
			key = data[i];
			while (j >= 0 && comp(data[j], key)) {
				data[j + 1] = data[j];
				--j;
			}
			data[j + 1] = key;
		}
	}
	template <typename T>
	void insertion_sort(vector<T>& data) {
		auto len = data.size();
		auto j = 0;
		auto key = T();
		for (auto i = 1; i < len; ++i) {
			j = i - 1;
			key = data[i];
			while (j >= 0 && data[j] > key) {
				data[j + 1] = data[j];
				--j;
			}
			data[j + 1] = key;
		}
	}
	template<typename T> class LinkedList;
	template<typename T>class Node {
	private:
		T item;
		Node<T>* next;
		friend class LinkedList<T>;
	};
	template<typename T> class LinkedList {
	public:
		LinkedList();
		~LinkedList();
		constexpr bool empty()const;
		constexpr T& front()const;
		const T& back()const;
		void push_back(const T& item);
		void push_front(const T& item);
		void pop_front();
		void clear();
		size_t size()const;
	private:
		Node<T>* head;
	};
	template<typename T>
	LinkedList<T>::LinkedList() : head(nullptr) {
	}
	template<typename T>
	LinkedList<T>::~LinkedList() {
		while (!empty())
			pop_front();
	}
	template<typename T>
	constexpr bool LinkedList<T>::empty() const {
		return head == nullptr;
	}
	template<typename T>
	constexpr T& LinkedList<T>::front() const {
		return head->item;
	}
	template<typename T>
	const T& LinkedList<T>::back() const
	{
		auto temp = head;
		while (temp->next)
			temp = temp->next;
		return temp->item;
	}
	template<typename T>
	void LinkedList<T>::push_back(const T& item)
	{
	}
	template<typename T>
	void LinkedList<T>::push_front(const T& item)
	{
		auto temp = new Node<T>;
		temp->item = item;
		temp->next = head;
		head = temp;
	}
	template<typename T>
	void LinkedList<T>::pop_front()
	{
		if(!head){
			throw std::out_of_range("LinkedList is empty before pop_front");
		}
		auto old = head;
		head = old->next;
		delete old;
	}
	template<typename T>
	void LinkedList<T>::clear()
	{
		while (!empty()) {
			pop_front();
		}
	}
	template<typename T>
	size_t LinkedList<T>::size()const
	{
		auto temp = head;
		size_t i= 0;
		if (empty())
			return 0;
		while (temp){
			++i;
			temp = temp->next;
		}
		delete temp;
		return i;
	}
};
#endif // !CORMEN_ALGORITHM
