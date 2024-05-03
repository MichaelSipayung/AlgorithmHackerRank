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
		explicit node(T it) : item(std::move(it)), next(nullptr) {}
	private:
		T item;
		node<T>* next;
		friend class linked_list<T>;
	};
	template<typename T> class linked_list {
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
		node<T>* get_tail();
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
		auto tail = get_tail();
		if (!tail)
			push_front(item);
		else {
			tail->next = new_item;
			++sz;
		}
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
		if (!head)
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
		while (temp){
			cout << temp->item << " ";
			temp = temp->next;
		}
	}
	template<typename T>
	size_t linked_list<T>::size()const {
		return sz;
	}
	template<typename T>
	node<T>* linked_list<T>::get_tail()
	{
		if (!head)
			return nullptr;
		auto temp = head;
		while (temp->next)
			temp = temp->next;
		return temp;
	}
	template<typename T> class d_linked_list;
	template<typename T> class d_node
	{
	public:
		explicit d_node(const T& d = T{}, d_node<T>* p = nullptr,
			d_node<T>* n = nullptr) : item(d), prev(p), next(n) {}
		// for debugging purposes
		const T& get_item()const { return item; }
		const d_node<T>* get_prev()const { return prev; }
		const d_node<T>* get_next()const { return next; }
	private:
		T item;
		d_node<T>* prev;
		d_node<T>* next;
		friend class d_linked_list<T>;
	};
	template<typename T> class d_linked_list
	{
	public:
		d_linked_list();
		~d_linked_list();
		[[nodiscard]] bool empty()const;
		[[nodiscard]] const T& front()const;
		[[nodiscard]] const T& back()const;
		void push_front(const T&)noexcept;
		void push_back(const T&)noexcept;
		void pop_back();
		void pop_front();
		[[nodiscard]] size_t size() const;
		const d_node<T>* get_head() const { return head; }
		const d_node<T>* get_tail() const { return tail; }
	private:
		d_node<T>* head;
		d_node<T>* tail;
		size_t sz = 0;
	protected:
		void add(d_node<T>* pos, const T& val);
		void remove(d_node<T>* pos);
	};
	// ctor for doubly linked list, head and tail is sentinel node for quick access
	template<typename T>
	d_linked_list<T>::d_linked_list()
	{
		head = new d_node<T>(); // create a sentinel, this is must be non null
		tail = new d_node<T>(); // but it's only dummy node
		head->next = tail;
		tail->prev = head;
	}
	// dtor of the doubly linked list, destroy all only if the list is not empty
	template<typename T>
	d_linked_list<T>::~d_linked_list()
	{
		while (!empty())
			pop_front(); // clear all node
		delete head; // clear the sentinel node
		delete tail;
	}
	// empty: checking the current list if contain any element except on head and tail
	template<typename T>
	bool d_linked_list<T>::empty() const {
		return (head->next == tail);
	}
	// front: get the first element from doubly linked list
	template<typename T>
	const T& d_linked_list<T>::front() const {
		if (empty())
			throw std::out_of_range("call front on empty list");
		return head->next->item;
	}
	// back: get the last element from doubly linked list
	template<typename T>
	const T& d_linked_list<T>::back() const
	{
		if (empty())
			throw std::out_of_range("call back on empty list");
		return tail->prev->item;
	}
	// push_front: adding new element on the front of the list
	template<typename T>
	void d_linked_list<T>::push_front(const T& val)noexcept {
		add(head->next, val);
		++sz;
	}
	// push_back: adding new element on the back of the list
	template<typename T>
	void d_linked_list<T>::push_back(const T& val)noexcept {
		add(tail, val);
		++sz;
	}
	// pop_back: removing the element from the bottom of the list
	template<typename T>
	void d_linked_list<T>::pop_back() {
		if (empty())
			throw std::out_of_range("call pop_back on empty list");
		remove(tail->prev);
		--sz;
	}
	// pop_front: removing the element from the top of the list
	template<typename T>
	void d_linked_list<T>::pop_front() {
		if (empty())
			throw std::out_of_range("call pop_front on empty list");
		remove(head->next);
		--sz;
	}
	// size: total element on doubly linked list, except head and tail element
	template<typename T>
	size_t d_linked_list<T>::size() const {
		return sz;
	}
	// add: protected member of the doubly linked list class, adding item before pos
	template<typename T>
	void d_linked_list<T>::add(d_node<T>* pos, const T& val)
	{
		auto new_item = new d_node<T>(val);
		new_item->next = pos; // link new_item in between pos
		new_item->prev = pos->prev; // and pos->prev
		pos->prev->next = new_item;
		pos->prev = new_item;
	}
	// remove: removing node pos from list, u: predecessor, w: successor
	template<typename T>
	void d_linked_list<T>::remove(d_node<T>* pos)
	{
		auto u = pos->prev; // remove pos from list
		auto w = pos->next; // [u -> pos ->w]
		u->next = w;
		w->prev = u;
		delete pos;
	}
};
#endif // !CORMEN_ALGORITHM
