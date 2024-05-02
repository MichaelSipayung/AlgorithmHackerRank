#ifndef CORMEN_ALGORITHM
#define CORMEN_ALGORITHM
#include <iostream>
#include <ostream>
#include <vector>
using std::vector;
namespace cormen {
	template <typename T, typename Comparable>
	void insertion_sort(vector<T>& data, Comparable comp) {
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
	template<typename T> class linked_list;
	template<typename T>class node {
	public:
		node() = default;
		explicit node(T it) : item(std::move(it)), next(nullptr){}
	private:
		T item;
		node<T>* next;
		friend class linked_list<T>;
	};
	template<typename T> class linked_list {
		//friend std::ostream& operator<<(std::ostream&, const linked_list<T>&);
	public:
		linked_list();
		~linked_list();
		[[nodiscard]] constexpr bool empty()const;
		[[nodiscard]] constexpr T& front()const;
		[[nodiscard]] const T& back()const;
		void push_back(const T& item);
		void push_front(const T& item);
		void pop_front();
		void clear();
		void print();
		[[nodiscard]] size_t size()const;
	private:
		node<T>* head;
		size_t sz = 0;
	};

	template<typename T>
	linked_list<T>::linked_list() : head(nullptr) {
	}
	template<typename T>
	linked_list<T>::~linked_list() {
		while (!empty())
			pop_front();
	}
	template<typename T>
	constexpr bool linked_list<T>::empty() const {
		return head == nullptr;
	}
	template<typename T>
	constexpr T& linked_list<T>::front() const {
		return head->item;
	}
	template<typename T>
	const T& linked_list<T>::back() const
	{
		auto temp = head;
		while (temp->next)
			temp = temp->next;
		return temp->item;
	}
	template<typename T>
	void linked_list<T>::push_back(const T& item)
	{
		auto new_item = new node<T>(item);
		auto temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = new_item;
		++sz;
	}
	template<typename T>
	void linked_list<T>::push_front(const T& item)
	{
		auto temp = new node<T>;
		temp->item = item;
		temp->next = head;
		head = temp;
		++sz;
	}
	template<typename T>
	void linked_list<T>::pop_front()
	{
		if(!head)
			throw std::out_of_range("linked_list is empty before pop_front");
		auto old = head;
		head = old->next;
		--sz;
		delete old;
	}
	template<typename T>
	void linked_list<T>::clear()
	{
		while (!empty()) 
			pop_front();
		sz = 0;
	}
	template<typename T>
	void linked_list<T>::print()
	{
		auto temp = head;
		while(temp)
		{
			cout << temp->item << " ";
			temp = temp->next;
		}
		delete temp;
	}
	template<typename T>
	size_t linked_list<T>::size()const{
		return sz;
	}
};
#endif // !CORMEN_ALGORITHM
