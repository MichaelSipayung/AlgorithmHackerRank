#ifndef CORMEN_ALGORITHM
#define CORMEN_ALGORITHM
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
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

	template <typename T> void insertion_sort(vector<T>& data) {
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

	template <typename T> class linked_list;

	template <typename T> class node {
	public:
		node() = default;

		explicit node(T it) : item(std::move(it)), next(nullptr) {}

	private:
		T item;
		node<T>* next;

		friend class linked_list<T>;
	};

	template <typename T> class linked_list {
	public:
		linked_list();

		~linked_list();

		[[nodiscard]] constexpr bool empty() const;

		[[nodiscard]] constexpr T& front() const;

		[[nodiscard]] const T& back() const;

		void push_back(const T& item);

		void push_front(const T& item);

		void pop_front();

		void clear();

		void print();

		[[nodiscard]] size_t size() const;

	private:
		node<T>* head;
		size_t sz = 0;

		node<T>* get_tail();
	};

	template <typename T> linked_list<T>::linked_list() : head(nullptr) {}

	template <typename T> linked_list<T>::~linked_list() {
		while (!empty())
			pop_front();
	}

	template <typename T> constexpr bool linked_list<T>::empty() const {
		return head == nullptr;
	}

	template <typename T> constexpr T& linked_list<T>::front() const {
		return head->item;
	}

	template <typename T> const T& linked_list<T>::back() const {
		auto temp = head;
		while (temp->next)
			temp = temp->next;
		return temp->item;
	}

	template <typename T> void linked_list<T>::push_back(const T& item) {
		auto new_item = new node<T>(item);
		auto tail = get_tail();
		if (!tail)
			push_front(item);
		else {
			tail->next = new_item;
			++sz;
		}
	}

	template <typename T> void linked_list<T>::push_front(const T& item) {
		auto temp = new node<T>;
		temp->item = item;
		temp->next = head;
		head = temp;
		++sz;
	}

	template <typename T> void linked_list<T>::pop_front() {
		if (!head)
			throw std::out_of_range("linked_list is empty before pop_front");
		auto old = head;
		head = old->next;
		--sz;
		delete old;
	}

	template <typename T> void linked_list<T>::clear() {
		while (!empty())
			pop_front();
		sz = 0;
	}

	template <typename T> void linked_list<T>::print() {
		auto temp = head;
		while (temp) {
			cout << temp->item << " ";
			temp = temp->next;
		}
	}

	template <typename T> size_t linked_list<T>::size() const { return sz; }

	template <typename T> node<T>* linked_list<T>::get_tail() {
		if (!head)
			return nullptr;
		auto temp = head;
		while (temp->next)
			temp = temp->next;
		return temp;
	}

	template <typename T> class d_linked_list;

	template <typename T> class d_node {
	public:
		explicit d_node(const T& d = T{}, d_node<T>* p = nullptr,
			d_node<T>* n = nullptr)
			: item(d), prev(p), next(n) {}

		// for debugging purposes
		const T& get_item() const { return item; }

		const d_node<T>* get_prev() const { return prev; }

		const d_node<T>* get_next() const { return next; }

	private:
		T item;
		d_node<T>* prev;
		d_node<T>* next;

		friend class d_linked_list<T>;
	};

	template <typename T> class d_linked_list {
	public:
		d_linked_list();

		~d_linked_list();

		bool empty() const;

		const T& front() const;

		const T& back() const;

		void push_front(const T&) noexcept;

		void push_back(const T&) noexcept;

		void pop_back();

		void pop_front();

		size_t size() const;

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
	template <typename T> d_linked_list<T>::d_linked_list() {
		head = new d_node<T>(); // create a sentinel, this is must be not null
		tail = new d_node<T>(); // but it's only dummy node
		head->next = tail;
		tail->prev = head;
	}

	// dtor of the doubly linked list, destroy all only if the list is not empty
	template <typename T> d_linked_list<T>::~d_linked_list() {
		while (!empty())
			pop_front(); // clear all node
		delete head;   // clear the sentinel node
		delete tail;
	}

	// empty: checking the current list if contain any element except on head and
	// tail
	template <typename T> bool d_linked_list<T>::empty() const {
		return (head->next == tail);
	}

	// front: get the first element from doubly linked list
	template <typename T> const T& d_linked_list<T>::front() const {
		if (empty())
			throw std::out_of_range("call front on empty list");
		return head->next->item;
	}

	// back: get the last element from doubly linked list
	template <typename T> const T& d_linked_list<T>::back() const {
		if (empty())
			throw std::out_of_range("call back on empty list");
		return tail->prev->item;
	}

	// push_front: adding new element on the front of the list
	template <typename T> void d_linked_list<T>::push_front(const T& val) noexcept {
		add(head->next, val);
		++sz;
	}

	// push_back: adding new element on the back of the list
	template <typename T> void d_linked_list<T>::push_back(const T& val) noexcept {
		add(tail, val);
		++sz;
	}

	// pop_back: removing the element from the bottom of the list
	template <typename T> void d_linked_list<T>::pop_back() {
		if (empty())
			throw std::out_of_range("call pop_back on empty list");
		remove(tail->prev);
		--sz;
	}

	// pop_front: removing the element from the top of the list
	template <typename T> void d_linked_list<T>::pop_front() {
		if (empty())
			throw std::out_of_range("call pop_front on empty list");
		remove(head->next);
		--sz;
	}

	// size: total element on doubly linked list, except head and tail element
	template <typename T> size_t d_linked_list<T>::size() const { return sz; }

	// add: protected member of the doubly linked list class, adding item before pos
	template <typename T> void d_linked_list<T>::add(d_node<T>* pos, const T& val) {
		auto new_item = new d_node<T>(val);
		new_item->next = pos;       // link new_item in between pos
		new_item->prev = pos->prev; // and pos->prev
		pos->prev->next = new_item; // update the next pointer of the node at the
		// position where new_item is inserted
		pos->prev = new_item; // update the prev pointer of the node at the
		// position where new_item is inserted
	}

	// remove: removing node pos from list, u: predecessor, w: successor
	template <typename T> void d_linked_list<T>::remove(d_node<T>* pos) {
		auto u = pos->prev; // remove pos from list
		auto w = pos->next; // [u -> pos ->w]
		u->next = w;
		w->prev = u;
		delete pos;
	}

	template <typename T>
	void merge(std::vector<T>& ls, const int& beg, const int& mid, const int& end) {
		vector<T> temp;
		for (auto k = beg; k <= end; ++k) // copy ls[low...hi] to temp
			temp.push_back(ls[k]);
		// merge the element in sorted order
		auto i = beg;
		auto j = mid + 1;
		for (auto k = beg; k <= end; ++k) {
			if (i > mid)
				ls[k] = temp[j++ - beg];
			else if (j > end)
				ls[k] = temp[i++ - beg];
			else if (temp[j - beg] < temp[i - beg])
				ls[k] = temp[j++ - beg];
			else
				ls[k] = temp[i++ - beg];
		}
	}

	template <typename T>
	void merge_sort(vector<T>& ls, const int& beg, const int& end) {
		if (end <= beg)
			return;
		int mid = beg + (end - beg) / 2;
		merge_sort(ls, beg, mid);
		merge_sort(ls, mid + 1, end);
		merge(ls, beg, mid, end);
	}

	// merge sort with lambada params, custom comparable, default is less than
	template <typename T, typename Comparable>
	void merge(std::vector<T>& ls, const int& beg, const int& mid, const int& end,
		Comparable comp) {
		std::vector<T> temp;
		for (auto k = beg; k <= end; ++k)
			temp.push_back(ls[k]);
		auto i = beg;
		auto j = mid + 1;
		for (auto k = beg; k <= end; ++k) {
			if (i > mid) // control the half left
				ls[k] = temp[j++ - beg];
			else if (j > end) // control the left right
				ls[k] = temp[i++ - beg];
			else if (comp(temp[j - beg],
				temp[i - beg])) // compare half right with half left
				ls[k] = temp[j++ - beg];
			else
				ls[k] = temp[i++ - beg];
		}
	}

	template <typename T, typename Comparable>
	void merge_sort(vector<T>& ls, const int& beg, const int& end,
		Comparable comp) {
		if (end <= beg)
			return;
		int mid = beg + (end - beg) / 2;
		merge_sort(ls, beg, mid, comp);
		merge_sort(ls, mid + 1, end, comp);
		merge(ls, beg, mid, end, comp);
	}

	template <typename T> class circle_list;

	template <typename T> class node_circle {
	public:
		node_circle(const T& value) : item{ value }, next{ nullptr } {}
		~node_circle() { next = nullptr; }
		const T& get_item() const { return item; }

	private:
		T item;
		node_circle* next;
		friend class circle_list<T>;
	};

	template <typename T> class circle_list {
	public:
		circle_list() : cursor{ nullptr } {}
		~circle_list() {
			while (!empty())
				remove();
		}
		bool empty() const;
		const T& front() const; // element following cursor, if not advance,
		// the front is the last inserted element
		const T& back() const; // element at the cursor, conversly to front behavior
		void advance();        // advance cursor
		void add(const T&);   // add item after cursor, if current [a,b], add 'c'
		// will make the list [c,a,b], this maintain the circular behavior
		void remove(); // remove node after cursor
	private:
		node_circle<T>* cursor;
	};

	template <typename T> void circle_list<T>::remove() {
		if (empty())
			throw std::out_of_range("calling remove() on empty circle_list");
		auto old = cursor->next;
		if (old == cursor)
			cursor = nullptr;
		else
			cursor->next = old->next;
		delete old;
	}
	template <typename T> bool circle_list<T>::empty() const {
		return cursor == nullptr;
	}

	template <typename T> const T& circle_list<T>::back() const {
		if (empty())
			throw std::out_of_range("calling back() on empty circle_list");
		return cursor->item;
	}

	template <typename T> const T& circle_list<T>::front() const {
		if (empty())
			throw std::out_of_range("calling front() on empty circle_list");
		return cursor->next->item;
	}

	template <typename T> void circle_list<T>::advance() { cursor = cursor->next; }

	template <typename T> void circle_list<T>::add(const T& item) {
		auto new_node = new node_circle<T>(item);
		if (empty()) {
			new_node->next = new_node; // since we deal with circular list
			cursor = new_node;         // cursor point to new_node
		}
		else {
			new_node->next = cursor->next; // link in v after cursor
			cursor->next = new_node;       // cursor next point to newly added node
		}
	}

	template <typename T> void rdoubly_linked_list(d_linked_list<T>& ls) {
		d_linked_list<T> temp;
		while (!ls.empty()) { // copying the original ls to temp
			const auto item = ls.front();
			ls.pop_front();
			temp.push_front(item);
		}
		while (!temp.empty()) {
			const auto item = temp.front();
			temp.pop_front();
			ls.push_back(item);
		}
	}

	// recursive example by drawing a ruler
	void draw_one_tick(const size_t& tick_len, const int& tick_lbl = -1) {
		for (auto i = 0; i < tick_len; ++i)
			std::cout << "-";
		if (tick_lbl >= 0)
			std::cout << " " << tick_lbl;
		std::cout << std::endl;
	}

	void draw_ticks(const size_t& tick_len) { // draw tick of given length
		if (tick_len > 0) {                     // stop when length drop to 0
			draw_ticks(tick_len - 1);             // recursively draw left ticks
			draw_one_tick(tick_len);              // draw center tick
			draw_ticks(tick_len - 1);             // recursively draw right ticks
		}
	}

	void draw_ruler(const size_t& ninches, const size_t& major_len) {
		draw_one_tick(major_len, 0); // draw tick 0 and it's label
		for (auto i = 1; i <= ninches; ++i) {
			draw_ticks(major_len - 1);   // draw ticks for this inch
			draw_one_tick(major_len, i); // draw tick i and its label
		}
	}

	// recusively sum of all element on a vector, with linear running time
	template <typename Number>
	Number recursive_sum(const vector<Number>& ls, const size_t& ls_len) {
		if (ls.empty())
			throw std::out_of_range("calling recursive_sum() on empty container");
		if (ls_len == 1) // base case
			return ls[0];
		return recursive_sum(ls, ls_len - 1) + ls[ls_len - 1]; // recursive case
	}

	// reversing element on array by linear recursion
	template <typename T>
	void reverse_array(vector<T>& ls, const size_t& beg = 0,
		const size_t& end = 0) {
		if (ls.empty())
			throw std::out_of_range("calling reverse_array() on empty container");
		if (beg < end) {
			std::swap(ls[beg], ls[end]);
			reverse_array(ls, beg + 1, end - 1);
		}
		return; // dealing with size of ls is odd, beg==end
	}
	// binary_sum: performing binary recursion by summing all element on container
	template <typename Number>
	Number binary_sum(const vector<Number>& ls, const size_t& beg = 0,
		const size_t& last = 0) {
		if (last == 1)
			return ls[beg];
		return binary_sum(ls, beg, floor(last / 2.0)) +
			binary_sum(ls, beg + floor(last / 2.0), ceil(last / 2.0));
	}

	// binary_fib: performing binary recursion by calculate fibonacci number
	size_t binary_fib(const size_t& n) {
		if (n <= 1)
			return n;                                   // base case
		return binary_fib(n - 1) + binary_fib(n - 2); // since F_i = f_i-1+ f_i-2
	}

	// linear_fib: performing linear recursion by calculate fibonacci number
	// return a pair of fibonacci number of n, and n-1
	std::pair<size_t, size_t> linear_fib(const size_t& n) {
		std::pair<size_t, size_t> result = { 0, 0 };
		if (n <= 1)
			return std::make_pair(n, 0);
		else {
			result = linear_fib(n - 1);
			return { result.first + result.second, result.first };
		}
	}

	// prefix_averages(): demonstrate the running time O(n^2) by computing prefix
	// avg
	template <typename Number>
	std::vector<double> prefix_averages(const std::vector<Number>& ls) {
		std::vector<double> result;
		for (auto i = 0; i <= ls.size() - 1; ++i) {
			auto temp = 0.0;
			for (auto j = 0; j <= i; ++j) // 1 + 2 + 3 + .... + n = (n(n+1))/2
				temp += ls[j];
			result.push_back(temp / (i + 1));
		}
		return result;
	}

	// prefix_averages_lin(): demonstrate the running time O(n) by computing prefix
	// avg
	template <typename Number>
	std::vector<double> prefix_averages_lin(const vector<Number>& ls) {
		auto temp = 0.0;
		vector<double> result;
		for (auto i = 0; i < ls.size(); ++i) {
			temp += ls[i]; // remember the last sum, this and the next line O(n)
			result.push_back(temp / (i + 1));
		}
		return result;
	}

	// power_linear(): demonstrate the running time O(n) by computing power of x by
	// n
	template <typename Number>
	Number power_linear(const Number& x, const size_t& n) {
		if (n == 0)
			return 1;
		return x * power_linear(x, n - 1);
	}
	// power_logarithm(): demonstrate the running time O(log n) by computing power
	// of x by n
	template <typename Number>
	Number power_logarithm(const Number& x, const size_t& n) {
		if (n == 0)
			return 1;
		if (n % 2 != 0) {
			auto y = power_logarithm(x, (n - 1) / 2);
			return x * y * y;
		}
		else {
			auto y = power_logarithm(x, n / 2);
			return y * y;
		}
	}
	template <typename T> class stack_array {
		enum { INITIAL_CAPACITY = 100 };

	public:
		stack_array(const size_t& cap = INITIAL_CAPACITY);
		size_t size() const;
		bool empty() const;
		const T& top() const;
		void push(const T&);
		void pop();

	private:
		T* s;
		size_t capacity;
		int pos;
	};

	template <typename T>
	stack_array<T>::stack_array(const size_t& cap)
		: s(new T[cap]), capacity{ cap }, pos{ -1 } {}

	template <typename T> size_t stack_array<T>::size() const { return pos + 1; }

	template <typename T> bool stack_array<T>::empty() const { return pos < 0; }

	template <typename T> const T& stack_array<T>::top() const {
		if (empty())
			throw std::out_of_range("calling top() on empty stack array based");
		return s[pos];
	}

	template <typename T> void stack_array<T>::push(const T& item) {
		if (size() == capacity)
			throw std::out_of_range("calling push() on full stack array based");
		s[++pos] = item;
	}

	template <typename T> void stack_array<T>::pop() {
		if (empty())
			throw std::out_of_range("calling pop() on empty stack array based");
		--pos;
	}
	// stack based on singly linked list
	template <typename T> class stack_linked {
	public:
		stack_linked() : s(), n{ 0 } {}
		size_t size() const;
		bool empty() const;
		const T& top() const;
		void pop();
		void push(const T&);

	private:
		linked_list<T> s;
		size_t n;
	};
	template <typename T> inline size_t stack_linked<T>::size() const { return n; }
	template <typename T> inline bool stack_linked<T>::empty() const {
		return size() == 0;
	}
	template <typename T> inline const T& stack_linked<T>::top() const {
		if (empty())
			throw std::out_of_range("calling top() on empty stack based linked list");
		return s.front();
	}
	template <typename T> inline void stack_linked<T>::pop() {
		if (empty())
			throw std::out_of_range("calling po() on empty stack based linked list");
		s.pop_front();
		--n;
	}
	template <typename T> inline void stack_linked<T>::push(const T& item) {
		s.push_front(item);
		++n;
	}

	// parent_pair(): matching parentheses problem, applications of stack, O(n)
	bool parent_pair(const std::string& ls) {
		char opening[] = { '{', '[', '(' };
		char closing[] = { '}', ']', ')' };
		stack_linked<char> temp;
		for (const auto& i : ls) {
			if (i == opening[0] || i == opening[1] || i == opening[2])
				temp.push(i);
			else {
				if (temp.empty())
					return false; // no matching pair
				else {          // not match as a pair
					if (temp.top() == opening[0]) {
						if (i != closing[0])
							return false;
					}
					else if (temp.top() == opening[1]) {
						if (i != closing[1])
							return false;
					}
					else if (temp.top() == opening[2]) {
						if (i != closing[2])
							return false;
					}
				}
				temp.pop(); // match, pop it
			}
		}
		return temp.size() == 0;
	}

	// queue interface, data structure that maintain the FIFO behavior, using
	// circular
	template <typename T> class queue_array {
		enum { INITIAL_CAPACITY = 100 };

	public:
		queue_array(const size_t& cap = INITIAL_CAPACITY)
			: pointer{ 0 }, first{ 0 }, curr{ 0 }, capacity{ cap }, s(new T[cap]) {}
		size_t size() const;
		bool empty() const;
		const T& front() const;
		void enqueue(const T&);
		void dequeue();

	private:
		int pointer;
		int first;
		int curr;
		size_t capacity;
		T* s;
	};

	template <typename T> size_t queue_array<T>::size() const { return curr; }

	template <typename T> bool queue_array<T>::empty() const { return size() == 0; }

	template <typename T> const T& queue_array<T>::front() const {
		if (empty())
			throw std::out_of_range("calling front() on empty queue");
		return s[first]; // first, current postion after or before dequeue
	}

	template <typename T> void queue_array<T>::enqueue(const T& item) {
		if (size() == capacity)
			throw std::out_of_range("calling enqueue() on full queue");
		s[pointer] = item;                  // position to insert the element
		pointer = (pointer + 1) % capacity; // if r+1 >= n, go back, set r = remainder
		++curr;                             // increase the size()
	}

	template <typename T> void queue_array<T>::dequeue() {
		if (empty())
			throw std::out_of_range("calling dequeue() on empty queue");
		first = (first + 1) % capacity; // move forward without copy entire remainder
		--curr;                         // reduce the size
	}

	// queue_linked: queue data structure based on doubly linked list
	template <typename T> class queue_linked {
	public:
		queue_linked() : sz{ 0 }, ls() {}
		int size() const { return sz; }
		bool empty() const { return sz == 0; }
		const T& front() const;
		void enqueue(const T&);
		void dequeue();

	private:
		size_t sz;
		circle_list<T> ls;
	};

	template <typename T> const T& queue_linked<T>::front() const {
		if (empty())
			throw std::out_of_range(
				"calling front() on empty queue based on circular ls");
		return ls.front();
	}

	template <typename T> void queue_linked<T>::enqueue(const T& item) {
		ls.add(item);
		ls.advance();
		++sz;
	}

	template <typename T> void queue_linked<T>::dequeue() {
		if (empty())
			throw std::out_of_range(
				"calling dequeue() on empty queue based on circular ls");
		ls.remove();
		--sz;
	}

	template <typename T> class queue_doubly_linked {
	public:
		queue_doubly_linked() : sz{ 0 }, ls() {}
		bool empty() const { return sz == 0; }
		size_t size() const { return sz; }
		const T& front() const;
		const T& back() const;
		void push_front(const T&) noexcept;
		void push_back(const T&) noexcept;
		void pop_back();
		void pop_front();

	private:
		size_t sz;
		d_linked_list<T> ls;
	};
	template <typename T> inline const T& queue_doubly_linked<T>::front() const {
		if (empty())
			throw std::out_of_range("calling front() on empty deque");
		return ls.front();
	}
	template <typename T> inline const T& queue_doubly_linked<T>::back() const {
		if (empty())
			throw std::out_of_range("calling back() on empty deque");
		return ls.back();
	}
	template <typename T>
	inline void queue_doubly_linked<T>::push_front(const T& item) noexcept {
		ls.push_front(item);
		++sz;
	}
	template <typename T>
	inline void queue_doubly_linked<T>::push_back(const T& item) noexcept {
		ls.push_back(item);
		++sz;
	}
	template <typename T> inline void queue_doubly_linked<T>::pop_back() {
		if (empty())
			throw std::out_of_range("calling pop_back() on empty deque");
		ls.pop_back();
		--sz;
	}
	template <typename T> inline void queue_doubly_linked<T>::pop_front() {
		if (empty())
			throw std::out_of_range("calling pop_front() on empty deque");
		ls.pop_front();
		--sz;
	}
	// vector_arr: vector class based on array behavior, if size()==n, increase it
	template<typename T>
	class vector_arr {
	public:
		explicit vector_arr(const size_t init_sz = 0) : sz{ init_sz },
			capacity{ init_sz + SPARSE_CAPACITY } {
			arr = new T[capacity];
		}
		vector_arr(const vector_arr& rhs);
		vector_arr& operator=(const vector_arr& rhs);
		~vector_arr() { delete[]arr; }
		void reserve(const size_t&);
		void resize(const size_t&);
		T& operator[](const size_t&);
		const T& operator[](const size_t&)const;
		bool empty()const { return sz == 0; }
		size_t size()const { return sz; }
		//size_t capacity_v()const { return capacity; }
		void push_back(const T&);
		void pop_back();
		const T& back()const;
		const T& front()const;
	protected:
		static const size_t SPARSE_CAPACITY = 16;
	private:
		size_t sz;
		size_t capacity;
		T* arr;
	};
	template<typename T>
	inline vector_arr<T>::vector_arr(const vector_arr& rhs) :
		sz{ rhs.size }, capacity{ rhs.capacity }, arr{ nullptr }
	{
		arr = new T[capacity];
		for (size_t i = 0; i < sz; ++i)
			arr[i] = rhs.arr[i];
	}
	template<typename T>
	inline vector_arr<T>& vector_arr<T>::operator=(const vector_arr& rhs)
	{
		vector_arr<T> cp = rhs;
		std::swap(*this, cp);
		return *this;
	}
	template<typename T>
	inline void vector_arr<T>::reserve(const size_t& n_cap)
	{
		if (n_cap < sz)
			return;
		auto temp = new T[n_cap]; //request new capacity
		for (size_t i = 0; i < sz; ++i)
			temp[i] = std::move(arr[i]);
		capacity = n_cap;
		std::swap(arr, temp);
		delete[]temp;
	}
	template<typename T>
	inline void vector_arr<T>::resize(const size_t& n_cap)
	{
		if (n_cap > capacity)
			reserve(n_cap * 2);
		sz = n_cap;
	}
	template<typename T>
	inline T& vector_arr<T>::operator[](const size_t& pos)
	{
		if (empty())
			throw std::out_of_range("vector: index out of range()");
		else if (pos >= sz && pos != 0)
			throw std::out_of_range("vector: index out range");
		return arr[pos];
	}
	template<typename T>
	inline const T& vector_arr<T>::operator[](const size_t& pos) const
	{
		if (empty())
			throw std::out_of_range("vector: index out of range");
		else if (pos >= sz && pos != 0)
			throw std::out_of_range("vector: index out range");
		return arr[pos];
	}
	template<typename T>
	inline void vector_arr<T>::push_back(const T& item)
	{
		if (sz == capacity)
			reserve(2 * capacity + 1);
		arr[sz++] = item;
	}
	template<typename T>
	inline void vector_arr<T>::pop_back()
	{
		if (empty())
			throw std::out_of_range("calling pop_back() on empty vector");
		--sz;
	}
	template<typename T>
	inline const T& vector_arr<T>::back() const
	{
		if (empty())
			throw std::out_of_range("calling back() on empty vector");
		return arr[sz - 1];
	}
	template<typename T>
	inline const T& vector_arr<T>::front() const
	{
		if (empty())
			throw std::out_of_range("calling front() on empty vector");
		return arr[0];
	}
	template<typename T>
	class list_adt {
	private:
		struct node {
		public:
			node(const T& d = T{}, node* p = nullptr, node* n = nullptr) :
				item{ d }, prev{ p }, next{ n } {}
			T item;
			node* prev;
			node* next;
		};
	public:
		class iterator_adt {
		public:
			// prefer inline
			T& operator*() {
				return itr_node->item;
			}
			bool operator==(const iterator_adt& rhs)const {
				return itr_node == rhs.itr_node;
			}
			bool operator!=(const iterator_adt& rhs)const {
				return itr_node != rhs.itr_node;
			}
			iterator_adt& operator++() {
				itr_node = itr_node->next;
				return *this;
			}
			iterator_adt& operator--() {
				itr_node = itr_node->prev;
				return *this;
			}
			friend class list_adt;
		private:
			node* itr_node; // pointer to the node
			iterator_adt(node* node_u) { itr_node = node_u; } //create from node
		};
	public:
		list_adt();
		~list_adt();
		size_t size()const {
			return sz;
		}
		bool empty()const {
			return sz == 0;
		}
		iterator_adt begin()const { return iterator_adt(head->next); } //begin of container

		iterator_adt end()const { return iterator_adt(tail); } //last+1 container

		void push_back(const T& item) { insert(end(), item); }

		void push_front(const T& item) { insert(begin(), item); }

		void pop_back() { erase(--end()); }

		void pop_front() { erase(begin()); }

		void erase(const iterator_adt& pos);

		void insert(const iterator_adt& pos, const T& item);

		const T& back()const {
			if (empty())
				throw std::out_of_range("calling back() on empty list");
			return *--end();
		}
		const T& front()const {
			if (empty())
				throw std::out_of_range("calling front() on empty list");
			return *begin();
		}
	private:
		size_t sz;
		node* head;
		node* tail;
	};
	// ctor for list, first time head and tail point to each other
	template<typename T>
	inline list_adt<T>::list_adt()
	{
		sz = 0;
		head = new node;
		tail = new node;
		head->next = tail; // point to each other for empty list
		tail->prev = head;
	}
	//dtor for list, freed the resource used by node
	template<typename T>
	inline list_adt<T>::~list_adt()
	{
		while (!empty())
			pop_front();
		delete head;
		delete tail;
	}
	// erase node 'pos' from a list
	template<typename T>
	inline void list_adt<T>::erase(const iterator_adt& pos)
	{
		if (empty() || pos == nullptr)
			throw std::out_of_range("calling erase() for empty list");
		auto v = pos.itr_node; //node to remove
		auto w = v->next; //successor
		auto u = v->prev; //predecessor
		u->next = w; // unlink pos
		w->prev = u;
		delete v; //delete v
		--sz;
	}
	// insert 'item' before node 'pos'
	template<typename T>
	inline void list_adt<T>::insert(const iterator_adt& pos, const T& item)
	{
		auto w = pos.itr_node;
		auto u = w->prev; // predecessor
		auto v = new node;
		v->item = item;
		v->next = w; w->prev = v; // link in v before w
		v->prev = u; u->next = v; // link in v after u
		++sz;
	}
	template<class Container>
	inline void buble_sort(Container& ls) {
		size_t len = ls.size();
		while (len > 1) {
			size_t track = 0;
			for (size_t i = 1; i < len; ++i)
				if (ls[i - 1] > ls[i]) {
					std::swap(ls[i - 1], ls[i]);
					track = i;
				}
			len = track; // dont traver to back if it already in sorted
		}
	}
	// binary_tree: binary tree class, implementation
	template<typename T>
	class binary_tree {
	protected:
		class node_tr {
		public:
			T item;
			node_tr* parent;
			node_tr* left;
			node_tr* right;
			node_tr(const T& _it) : item{ _it }, parent{ nullptr },
				left{ nullptr }, right{ nullptr } {}
		};
	public:
		class position_tr {
		public:
			position_tr(node_tr* tr = nullptr) : _tr{ tr } {}
			T& operator*() {
				if (!_tr)
					throw std::out_of_range("calling dereference for invalid node");
				return _tr->item;
			}
			const T& value()const {
				if ((!_tr))
					throw std::out_of_range("calling value() on invalid node");
				return _tr->item;
			}
			position_tr left()const { return position_tr(_tr->left); }
			position_tr right()const { return position_tr(_tr->right); }
			position_tr parent()const { return position_tr(_tr->parent); }
			bool is_root()const { return _tr->parent == nullptr; }
			bool is_external()const {
				return !_tr->left && !_tr->right;
			}
			friend class binary_tree;
		private:
			node_tr* _tr;
		};
		typedef std::list<position_tr> position_list;
	public:
		binary_tree();
		// return total node on binary tree
		size_t size()const { return sz; }
		// return true for empty binary tree otherwise false
		bool empty()const { return size() == 0; }
		// return root position
		position_tr root()const { return position_tr(_root); }
		// list of all nodes
		position_list positions()const {
			position_list pl;
			if (empty())
				return position_list(pl);
			preorder(_root, pl); // preorder traversal
			return position_list(pl); // return resulting list
		}
		// position at the left most
		position_tr left_most()const {
			auto pos = root();
			if (pos._tr)
				while (pos.left()._tr)
					pos = pos.left();
			return pos;
		}
		// position at the right most
		position_tr right_most()const {
			auto pos = root();
			if (pos._tr)
				while (pos.right()._tr)
					pos = pos.right();
			return pos;
		}
		// erase all node or clear binary tree
		void erase() {
			if (empty())
				return;
			_erase();
		}
		// adding root to empty tree
		void add_root(const T& item = T{}) {
			if (!empty())
				throw std::out_of_range("calling add_root() for non empty tree");
			_root = new node_tr(item);
			sz = 1;
		}
		// expand external node
		void expand_external(const position_tr&, const T& left_item,
			const T& right_item);
		// removing the node at pos p and its parent (above external)
		position_tr remove_above_external(const position_tr& p) {
			if (empty())
				throw std::out_of_range("calling remove_above_external() on empty tree");
			if (p.is_root())
				throw std::out_of_range("calling remove_above_external() on root");
			if (!p.is_external())
				throw std::out_of_range("calling remove_above_external() for non external");
			auto w = p._tr; // get p node and parent
			auto v = w->parent;
			auto sibling = w; // temporary assigment, assignment is at the next line
			if (w == v->left) // if parent of w->parent->left = w sibl is right 
				sibling = v->right;
			else
				sibling = v->left;
			if (v == _root) {
				_root = sibling; // child of root
				sibling->parent = nullptr; // make sibling root
			}
			else {
				auto grand_parent = v->parent; // w is grandparent
				if (v == grand_parent->left) //replace parent by sibling
					grand_parent->left = sibling;
				else
					grand_parent->right = sibling;
				sibling->parent = grand_parent;
			}
			delete w; //delete removed nodes
			delete v;
			sz -= 2;
			return position_tr(sibling);
		}
	protected:
		// preorder traversal
		void preorder(node_tr* v, std::list<position_tr>& pl)const {
			pl.push_back(position_tr(v)); // add this node
			if (v->left)
				preorder(v->left, pl); // traverse left subtree
			if (v->right)
				preorder(v->right, pl); // traverse right subtree
		}
	private:
		node_tr* _root; // pointer to the root
		size_t sz; // number of nodes
		void _erase();
	};

	template<typename T>
	inline binary_tree<T>::binary_tree() : _root{ nullptr }, sz{ 0 }
	{
	}
	// transform p from external node into an internal node by creating 2 external nd
	template<typename T>
	inline void binary_tree<T>::expand_external(const binary_tree<T>::position_tr& p,
		const T& left_item, const T& right_item)
	{
		if (!p.is_external())
			throw std::out_of_range("calling expand_external() for non external node");
		auto v = p._tr;
		v->left = new node_tr(left_item);
		v->left->parent = v;
		v->right = new node_tr(right_item);
		v->right->parent = v;
		sz += 2;
	}
	template<typename T>
	inline void binary_tree<T>::_erase()
	{
		while (size() > 1) {
			auto left = left_most();
			auto right = right_most();
			if (!left.is_root())
				remove_above_external(left);
			if (!right.is_root())
				remove_above_external(right);
		}
		if (root()._tr != nullptr) {
			delete root()._tr;
			sz -= 1;
		}
		if (_root->left)
			_root->left = nullptr;
		if (_root->right)
			_root->right = nullptr;
		if (_root->parent)
			_root->parent = nullptr;
		if (_root)
			_root = nullptr;
	}
	template<typename Comparable>
	class binary_heap_max {
	public:
		explicit binary_heap_max(const size_t capacity = 100) :
			_heap(std::vector<Comparable>(capacity)), _sz{ 0 } {}
		explicit binary_heap_max(const std::vector<Comparable>& _ls) :
			_heap(_ls.size() + 10), _sz{ _ls.size() } {
			for (size_t i = 0; i < _ls.size(); ++i)
				_heap[i + 1] = _ls[i];
			build_heap();
		}
		const Comparable& max()const {
			if (empty())
				throw std::out_of_range("calling max() on empty heap");
			return _heap[1];
		}
		void clear() {
			_heap.clear();
			_sz = 0;
			_heap.resize(100);
		}
		void pop_max() {
			if (empty())
				throw std::out_of_range("calling pop_max() on empty");
			_heap[1] = std::move(_heap[_sz]); //move hole
			--_sz;
			precolate_down(1);
		}
		void insert(const Comparable& item) {
			precolate_up(item);
		}
		bool empty()const { return _sz == 0; }
		size_t size()const { return _sz; }
	private:
		std::vector<Comparable> _heap;
		size_t _sz;
		void precolate_up(const Comparable&);
		void precolate_down(size_t);
		void build_heap();
		void check_size();
	};
	// priority_queue_list: interface of priority queue based on list and sorted order
	template<typename T, class Comparable>
	class priority_queue_list {
	public:
		size_t size()const { return _data.size(); }
		bool empty()const { return _data.empty(); }
		void insert(const T&);
		const T& min_element()const;
		void remove_min();
	private:
		std::list<T> _data;
		Comparable compare;
	};
	// insert: insert an element to priority queue
	template<typename T, class Comparable>
	inline void priority_queue_list<T, Comparable>::insert(const T& _val)
	{
		auto begin = _data.begin();
		while ((begin != _data.end()) && !compare(_val, *begin))
			++begin;
		_data.insert(begin, _val);
	}
	// need constant reference, the value can't be write, since the priority integrity
	template<typename T, class Comparable>
	inline const T& priority_queue_list<T, Comparable>::min_element() const
	{
		if (empty())
			throw std::out_of_range("calling min_element() on empty priority_queue");
		return _data.front();
	}
	template<typename T, class Comparable>
	inline void priority_queue_list<T, Comparable>::remove_min()
	{
		if (empty())
			throw std::out_of_range("calling remove_min() on empty priority_queue");
		_data.pop_front();
	}
	// selection_sort: sorting algorithm based on priority queue, complexity O(n^2)
	template<typename T>
	void selection_sort(std::list<T>& _ls) {
		priority_queue_list<T, std::less<>> temp;
		auto len_ls = _ls.size();
		for (size_t i = 0; i < len_ls; ++i) // copy to priority queue
		{
			temp.insert(_ls.front());
			_ls.pop_front();
		}
		auto len = temp.size();
		for (size_t i = 0; i != len; ++i) {
			_ls.push_back(temp.min_element()); // copy back to container
			temp.remove_min(); // remove minimum element
		}
	}

	// binary_heap: class interface for priority queue, default priority is max
	template<typename Comparable>
	class binary_heap {
	public:
		// ctor for heap, default capacity is 100
		explicit binary_heap(const size_t& capacity = 100) :
			_heap{ std::vector<Comparable>(capacity) }, _sz{ 0 } {}
		// construct binary heap from initial collections item
		explicit binary_heap(const std::vector<Comparable>&);
		bool empty()const { return _sz == 0; }
		// return maximum or minimum of element, default is max
		const Comparable& front()const;
		// insert an element to heap, default insertion priority is max
		void insert(const Comparable& item);
		// remove maximum or minimum element from heap, default is max
		void pop_front();
		// clear all element from heap
		void clear();
	private:
		std::vector<Comparable> _heap;
		size_t _sz;
		// precolate down or sink to the hole
		void percolate_down(size_t hole);
		// percolate up or swim the to the hole
		void percolate_up(const Comparable& item);
		// check current heap size, if exceed the capacity, request or resize
		void check_size();
		// extablish heap order property from arbitary arrangments of items, runs on linear time
		void build_heap();
	};
	template<typename Comparable>
	inline binary_heap<Comparable>::binary_heap(const std::vector<Comparable>&
		collection) : _heap(collection.size() + 10), _sz{ collection.size() }
	{
		for (size_t i = 0; i < collection.size(); ++i)
			_heap[i + 1] = collection[i];
		build_heap(); // build heap based on given collection
	}
	template<typename Comparable>
	inline const Comparable& binary_heap<Comparable>::front() const
	{
		if (empty())
			throw std::out_of_range("calling front() on empty heap");
		return _heap[1];
	}
	template<typename Comparable>
	inline void binary_heap<Comparable>::insert(const Comparable& item) {
		percolate_up(item);
	}
	template<typename Comparable>
	inline void binary_heap<Comparable>::pop_front()
	{
		if (empty())
			throw std::out_of_range("calling pop_front() on empty heap");
		_heap[1] = std::move(_heap[_sz]);
		--_sz;
		percolate_down(1);
	}
	template<typename Comparable>
	inline void binary_heap<Comparable>::clear() {
		_heap.clear();
		_heap = std::vector<Comparable>(1);
		_sz = 0;
	}
	// percolate_down: percolate_down in the heap, 
	// hole is the index at which percolate begin
	template<typename Comparable>
	inline void binary_heap<Comparable>::percolate_down(size_t hole)
	{
		size_t child = 0;
		while ((2 * hole) <= _sz) {
			child = 2 * hole;
			if ((child != _sz) && (_heap[child] > _heap[child + 1]))
				++child; // who will the next candidate at the top (parent)
			if (_heap[child] > _heap[hole])
				break; // already not violate the order, stop!
			std::swap(_heap[hole], _heap[child]); // sink down or precolate_down
			hole = child; //remember the exchange position
		}
	}
	template<typename Comparable>
	inline void binary_heap<Comparable>::percolate_up(const Comparable& item)
	{
		check_size();
		size_t hole = ++_sz; // create hole at the end
		const Comparable temp = std::move(item);
		_heap[0] = std::move(temp);
		// move the key to the right (no violate the heap) position
		for (; item < _heap[hole / 2]; hole /= 2)
			_heap[hole] = std::move(_heap[hole / 2]);
		_heap[hole] = std::move(item);
	}
	template<typename Comparable>
	inline void binary_heap<Comparable>::check_size()
	{
		if (_sz == _heap.size() - 1)
			_heap.resize(2 * _heap.size());
	}
	template<typename Comparable>
	inline void binary_heap<Comparable>::build_heap()
	{
		for (int i = _sz / 2; i > 0; --i)
			percolate_down(i);
	}
	// heap_sort: sorting algorithm based on binary heap, complexity O(n log n)
	template<typename Comparable>
	inline void heap_sort_max(std::vector<Comparable>& _ls)
	{
		binary_heap_max<Comparable> temp(_ls);
		for (size_t i = 0; i < _ls.size(); ++i) {
			_ls[i] = temp.max();
			temp.pop_max();
		}
	}
	template<typename Comparable>
	inline void heap_sort_min(std::vector<Comparable>& _ls)
	{
		binary_heap<Comparable> temp(_ls);
		for (size_t i = 0; i < _ls.size(); ++i) {
			_ls[i] = temp.front();
			temp.pop_front();
		}
	}

	template<typename Comparable>
	inline void binary_heap_max<Comparable>::precolate_up(const Comparable& item)
	{
		check_size();
		auto hole = ++_sz;
		for (; item < _heap[hole / 2]; hole /= 2)
			_heap[hole] = std::move(_heap[hole / 2]);
		_heap[hole] = std::move(item);
	}
	template<typename Comparable>
	inline void binary_heap_max<Comparable>::precolate_down(size_t hole)
	{
		size_t child = 0;
		while (2 * hole <= size())
		{
			child = 2 * hole;
			if ((child != size()) && (_heap[child] < _heap[child + 1]))
				++child;
			if (_heap[child] < _heap[hole])
				break;
			std::swap(_heap[child], _heap[hole]);
			hole = child;
		}
	}
	template<typename Comparable>
	inline void binary_heap_max<Comparable>::build_heap()
	{
		for (int i = _sz / 2; i > 0; --i)
			precolate_down(i);
	}
	template<typename Comparable>
	inline void binary_heap_max<Comparable>::check_size()
	{
		if (size() == _heap.size() - 1)
			_heap.resize(_heap.size() * 2);
	}
	template<typename Comparable>
	class binaryheap {
	public:
		binaryheap(const size_t& capacity = 100, const bool& min_priority = true) :
			_heap(std::vector<Comparable>(capacity)), _sz{ 0 }, _minpriority{ min_priority } {}

		binaryheap(const std::vector<Comparable>& collections, const bool& min_priority = true)
			: _heap(collections.size() + 10), _minpriority{ min_priority },
			_sz{ collections.size() } {
			for (size_t i = 0; i < collections.size(); ++i)
				_heap[i + 1] = collections[i];
			build_heap();
		}

		const Comparable& front()const;

		void pop_front();

		void insert(const Comparable&);

		size_t size()const { return _sz; }

		bool empty()const { return _sz == 0; }

		void clear();
	private:
		size_t _sz;
		bool _minpriority;
		std::vector<Comparable> _heap;
		void build_heap();
		void check_size();
		void percolate_down(size_t);
		void percolate_up(const Comparable&);
	};
	template<typename Comparable>
	inline const Comparable& binaryheap<Comparable>::front() const
	{
		if (empty())
			throw std::out_of_range("calling front() on empty heap");
		return _heap[1];
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::pop_front()
	{
		if (empty())
			throw std::out_of_range("calling pop_front() on empty");
		_heap[1] = std::move(_heap[size()]);
		--_sz;
		percolate_down(1);
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::insert(const Comparable& item)
	{
		check_size();
		percolate_up(item);
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::clear()
	{
		_heap.clear();
		_heap.reserve(1);
		_sz = 0;
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::build_heap()
	{
		for (int i = size() / 2; i > 0; --i)
			percolate_down(i);
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::check_size()
	{
		if (_sz == _heap.size() - 1)
			_heap.reserve(2 * _heap.size());
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::percolate_down(size_t hole)
	{
		size_t child = 0;
		if (_minpriority) { // minimum for as a priority
			while (2 * hole <= size())
			{
				child = 2 * hole;
				if ((size() != child) && (_heap[child] > _heap[child + 1]))
					++child;
				if (_heap[child] > _heap[hole])
					break;
				std::swap(_heap[child], _heap[hole]);
				hole = child;
			}
		}
		else { // otherwise make maximum as priority
			while (2 * hole <= size())
			{
				child = 2 * hole;
				if ((size() != child) && (_heap[child] < _heap[child + 1]))
					++child;
				if (_heap[child] < _heap[hole])
					break;
				std::swap(_heap[child], _heap[hole]);
				hole = child;
			}
		}
	}
	template<typename Comparable>
	inline void binaryheap<Comparable>::percolate_up(const Comparable& item)
	{
		size_t hole = ++_sz;
		const Comparable temp = std::move(item);
		_heap[0] = std::move(temp);
		if (_minpriority) {
			for (; item < _heap[hole / 2]; hole /= 2)
				_heap[hole] = std::move(_heap[hole / 2]);
			_heap[hole] = std::move(item);
		}
		else {
			for (; item > _heap[hole / 2]; hole /= 2)
				_heap[hole] = std::move(_heap[hole / 2]);
			_heap[hole] = std::move(item);
		}
	}
	template<typename Comparable>
	void heap_sort(std::vector<Comparable>& _ls, const bool& min_priority = true) {
		binaryheap<Comparable> temp(_ls, min_priority);
		for (size_t i = 0; i < _ls.size(); ++i) {
			_ls[i] = temp.front();
			temp.pop_front();
		}
	}
	// binary search tree interface with key and value pair
	template<typename Comparable_Key, typename Comparable_Value>
	class binary_search_tree {
	public:
		binary_search_tree();
		// dtor for binary search tree
		~binary_search_tree() { clear(); }
		// copy ctor for binary search tree
		binary_search_tree(const binary_search_tree& rhs) :
			_root{ nullptr } {
			_root = clone(rhs._root);
		};
		// min: return minimum key and its value
		const std::pair<Comparable_Key, Comparable_Value> min()const {
			if (empty())
				throw std::out_of_range("calling min() on empty tree");
			return std::make_pair(find_min(_root)->_key, find_min(_root)->_value);
		}
		// max: return maximum key and its value
		const std::pair<Comparable_Key, Comparable_Value> max()const {
			if (empty())
				throw std::out_of_range("calling max() on empty tree");
			return std::make_pair(find_max(_root)->_key, find_max(_root)->_value);
		}
		// find_min: return minimum key
		const Comparable_Key& find_min()const {
			if (empty())
				throw std::out_of_range("calling find_min() on empty tree");
			return find_min(_root)->_key;
		}
		// find_max: return maximum key
		const Comparable_Key& find_max()const {
			if (empty())
				throw std::out_of_range("calling find_max() on empty tree");
			return find_max(_root)->_key;
		}
		// empty: return true if tree is empty otherwise false
		bool empty()const { return _root == nullptr; }
		// insert: insert key and value pair to tree
		void insert(const Comparable_Key& key, const Comparable_Value& value) {
			insert(key, value, _root);
		}
		// contains: return true if key is found otherwise false
		bool contains(const Comparable_Key& key)const {
			return contains(key, _root);
		}
		// remove: remove key from tree
		void remove(const Comparable_Key& key) {
			remove(key, _root);
		}
		// clear: remove all node from tree
		void clear() {
			clear(_root);
		}
		// size: return total number of node in tree
		size_t size()const {
			return size(_root);
		}
		// items: return all key and value pair in tree
		const std::vector<std::pair<Comparable_Key, Comparable_Value>> items()const {
			std::vector<std::pair<Comparable_Key, Comparable_Value>> vec;
			std::stack<binary_node*> st;
			auto current = _root;
			while (current || !st.empty()) {
				if (current) {
					st.push(current);
					current = current->_left;
				}
				else {
					current = st.top();
					st.pop();
					vec.push_back(std::make_pair(current->_key, current->_value));
					current = current->_right;
				}
			}
			return vec;
		}
		void insert(const Comparable_Key&& key, const Comparable_Value&& value) {
			insert(std::move(key), std::move(value), _root);
		}
	private:
		struct binary_node {
			Comparable_Key _key; // key
			Comparable_Value _value; // value
			binary_node* _left; // left child
			binary_node* _right; // right child
			// ctor for binary node with key and value pair
			binary_node(const Comparable_Key& key, const Comparable_Value& value,
				binary_node* lt, binary_node* rt) : _key{ key },
				_value{ value }, _left{ lt }, _right{ rt } {}
			// ctor for binary node with key and value pair
			binary_node(Comparable_Key&& key, Comparable_Value&& value, binary_node* lt,
				binary_node* rt) : _key{ std::move(key) }, _value{ std::move(value) },
				_left{ std::move(lt) }, _right{ std::move(rt) } {}
		};
		binary_node* _root;
		void insert(const Comparable_Key& key, const Comparable_Value& value,
			binary_node*& t)
		{
			if (t == nullptr)
				t = new binary_node(key, value, nullptr, nullptr);
			else if (key < t->_key)
				insert(key, value, t->_left);
			else if (t->_key < key)
				insert(key, value, t->_right);
			else
				; // duplicate
		}
		binary_node* find_min(binary_node* t)const {
			if (t == nullptr)
				return nullptr;
			else if (t->_left == nullptr)
				return t;
			return find_min(t->_left);
		}
		binary_node* find_max(binary_node* t)const {
			if (t == nullptr)
				return nullptr;
			else if (t->_right == nullptr)
				return t;
			return find_max(t->_right);
		}
		bool contains(const Comparable_Key& key, binary_node* t)const {
			if (t == nullptr)
				return false;
			else if (key < t->_key)
				return contains(key, t->_left);
			else if (t->_key < key)
				return contains(key, t->_right);
			return true; // match with given key
		}
		void remove(const Comparable_Key& key, binary_node*& t) {
			if (t == nullptr)
				return; // item not found
			if (key < t->_key)
				remove(key, t->_left);
			else if (t->_key < key)
				remove(key, t->_right);
			else if (t->_left != nullptr && t->_right != nullptr)
			{
				// in case deletion contains two child
				t->_key = find_min(t->_right)->_key;
				remove(t->_key, t->_right);
			}
			else {
				binary_node* old_node = t;
				t = (t->_left != nullptr) ? t->_left : t->_right;
				delete old_node;
			}
		}
		void clear(binary_node*& t) {
			if (t) {
				clear(t->_left); // delete all node from left-right
				clear(t->_right);
				delete t;
			}
			t = nullptr;
		}
		binary_node* clone(binary_node* t) {
			if (t == nullptr)
				return nullptr;
			return new binary_node(t->_key, t->_value,
				clone(t->_left), clone(t->_right));
		}
		size_t size(binary_node* t)const {
			if (t == nullptr)
				return 0;
			return 1 + size(t->_left) + size(t->_right);
		}
		void insert(Comparable_Key&& key, Comparable_Value&& value, binary_node*& t)
		{
			if (t == nullptr)
				t = new binary_node(std::move(key), std::move(value), nullptr, nullptr);
			else if (key < t->_key)
				insert(std::move(key), std::move(value), t->_left);
			else if (t->_key < key)
				insert(std::move(key), std::move(value), t->_right);
			else
				; // duplicate
		}
	};

	template<typename Comparable_Key, typename Comparable_Value>
	inline binary_search_tree<Comparable_Key, Comparable_Value>::binary_search_tree()
	{
		_root = nullptr;
	}
	template<typename key, typename value>
	class red_black_tree {
	public:
		red_black_tree() {
			_root = nullptr;
			_total_node	= 0;
		}
		// empty: return true if tree is empty otherwise false
		bool empty()const {
			return _total_node == 0;
		}
		// size: return total number of node in tree
		size_t size()const { 
			// return size(_root); 
			return _total_node;
		}
		bool contain(const key &k)const {
			return contain(_root, k);
		}
		// front: return the root key and value pair
		std::pair<key, value> top()const {
			if (empty())
				throw std::out_of_range("call top() on empty tree");
			return std::make_pair(_root->_key, _root->_value);
		}

		// insert: insert key and value pair to tree
		void insert(const key& k, const value& val) {
			_root = insert(_root, k, val);
			_root->_color = BLACK;
			_total_node++;
		}
		// items: return all key and value pair in tree using vector
		std::vector<std::pair<key, value>> items()const {
			std::vector<std::pair<key, value>> vec;
			std::stack<red_black_node*> st;
			auto current = _root;
			while (current || !st.empty()) {
				if (current) {
					st.push(current);
					current = current->_left;
				}
				else {
					current = st.top();
					st.pop();
					vec.push_back(std::make_pair(current->_key, current->_value));
					current = current->_right;
				}
			}
			return vec;
		}
		// min: return minimum key and its value
		std::pair<key, value> min(){
			if (empty())
				throw std::out_of_range("calling min() on empty tree");
			return std::make_pair(find_min(_root)->_key, find_min(_root)->_value);
		}
		// max: return maximum key and its value
		std::pair<key, value> max(){
			if (empty())
				throw std::out_of_range("calling max() on empty tree");
			return std::make_pair(find_max(_root)->_key, find_max(_root)->_value);
		}
		
		// delete_min: delete the smallest key at the tree
		void delete_min(){
			if(!red(_root->_left) && !red(_root->_right))
				_root->_color = RED;
			_root = delete_min(_root); // make the 3-node, and delete it
			// after performing delete, change the head color back
			if(_root)
				_root->_color = BLACK;
			if(_root)
				--_total_node;
		}

		// delete_max: delete the greatest key at the tree
		void delete_max(){
			if(!red(_root->_left) && !red(_root->_right)) // look at the parent
				_root->_color = RED;
			_root = delete_max(_root);
			if(_root)
				_root->_color = BLACK;
			if(_root)
				--_total_node;
		}
	private:
		enum {
			RED, BLACK
		};
		size_t _total_node;
		struct red_black_node
		{
			key _key;
			value _value;
			int _color;
			size_t _sz;
			red_black_node* _left;
			red_black_node* _right;
			red_black_node(const key& k = key{}, const value& v = value{},
				const int color = RED, const size_t sz = 1, red_black_node* lhs = nullptr,
				red_black_node* rhs = nullptr) : _key{ k }, _value{ v }, _color{ color },
				_left{ lhs }, _right{ rhs } {}
		};
		red_black_node* _root;
		red_black_node* rotate_left(red_black_node*& head) {
			red_black_node *x = head->_right;
			head->_right = x->_left;
			x->_left = head;
			x->_color = head->_color;
			head->_color = RED;
			x->_sz = head->_sz;
			head->_sz = 1 + size(head->_left) + size(head->_right);
			return x;
		}
		red_black_node* rotate_right(red_black_node*& head) {
			red_black_node *x = head->_left;
			head->_left = x->_right;
			x->_right = head;
			head->_color = RED;
			x->_sz = head->_sz;
			head->_sz = 1 + size(head->_left) + size(head->_right);
			return x;
		}
		bool red(const red_black_node* nd)const {
			if (!nd) return false;
			return nd->_color == RED;
		}
		void flip_color(red_black_node *& head) {
			if(head){
				head->_color =RED;
				if(head->_left)
					head->_left->_color = BLACK;
				if(head->_right)
					head->_right->_color = BLACK;
			}
		}
		red_black_node* insert(red_black_node* &head, const key& k, const value& val) {
			if (!head)
				return new red_black_node(k, val, RED, 1);
			if (k < head->_key) {
				head->_left = insert(head->_left, k, val);
				head->_sz++;
			}
			else if (head->_key < k) {
				head->_right = insert(head->_right, k, val);
				head->_sz++;
			}
			else
				head->_value = val;
			if (red(head->_right) && !red(head->_left))
				head = rotate_left(head);
			if (red(head->_left) && red(head->_left->_left))
				head = rotate_right(head);
			if (red(head->_left) && red(head->_right))
				flip_color(head);
			return head;
		}
		size_t size(red_black_node *head)const {
			if (!head) return 0;
			return head->_sz;
		}
		red_black_node* find_min(red_black_node* head) {
			if(!head) return nullptr;
			if(!head->_left) return head;
			return find_min(head->_left);
		}
		red_black_node* find_max(red_black_node* head) {
			if(!head) return nullptr;
			if(!head->_right) return head;
			return find_max(head->_right);
		}
		bool contain(const red_black_node* head, const key &k)const {
			if (!head)
				return false;
			if (k < head->_key)
				return contain(head->_left, k);
			else if (head->_key < k)
				return contain(head->_right, k);
			return true;
		}
		red_black_node *balance(red_black_node *&head){
			if(head)
				if(red(head->_right))
					head = rotate_left(head);
			return head;
		}
		red_black_node *move_red_right(red_black_node *&head){
			if(head){
				flip_color(head);
				if(head->_left && !red(head->_left->_left))
					head = rotate_right(head);
			}
			return head;
		}
		red_black_node *move_red_left(red_black_node *&head){
			if(head){
				flip_color(head);
				if(head->_right && red(head->_right->_left)){
					head->_right = rotate_right(head->_right);
					head = rotate_left(head);
				}
			}
			return head;
		}
		red_black_node *delete_max(red_black_node *&head){
			if(head){
				if(red(head->_left))
					head = rotate_right(head);
				if(!head->_right)
					return nullptr;
				if(!red(head->_right) && !red(head->_right->_left))
					head= move_red_right(head);
				head->_right = delete_max(head->_right);
			}
			return head ? balance(head) : nullptr;
		}

		red_black_node *delete_min(red_black_node *&head){
			if(head){
				if(!head->_left && !head->_right){
					--_total_node;
					return nullptr;
				}
				if(!red(head->_left) && !red(head->_left->_left))
					head = move_red_left(head);
				head->_left = delete_min(head->_left);
			}
			return head ? balance(head) : nullptr;
		}
		
	};
	template<typename key, typename value>
	class non_recursive_binary_search_tree {
	private:
		struct non_recursive_node {
			non_recursive_node(const key& k = key{}, const value& v = value{},
				non_recursive_node* lt = nullptr, non_recursive_node* rt = nullptr,
				non_recursive_node* pt = nullptr) : _key{ k }, _value{ v },
				left{ lt }, right{ rt }, parent{ pt } {}
			key _key;
			value _value;
			non_recursive_node* left;
			non_recursive_node* right;
			non_recursive_node* parent;
		};
	public:
		non_recursive_binary_search_tree() {
			_root = nullptr;
			_total_node = 0;
		}
		// empty: return true if tree is empty otherwise false
		bool empty()const {
			return _total_node == 0;
		}
		// size: return total number of node in tree
		size_t size()const {
			return _total_node;
		}
		// minimum: return minimum key and its value
		const std::pair<key, value> minimum()const {
			if (empty())
				throw std::out_of_range("calling minimum() on empty tree");
			auto min = minimum(_root);
			return std::make_pair(min->_key, min->_value);
		}
		// maximum: return maximum key and its value
		const std::pair<key, value> maximum()const {
			if (empty())
				throw std::out_of_range("calling maximum() on empty tree");
			auto max = maximum(_root);
			return std::make_pair(max->_key, max->_value);

			//return std::make_pair(maximum(_root)->_key, maximum(_root)->_value);
		}
		// successor: return the successor key and its value
		non_recursive_node* successor(const  key& k) {
			return find(_root, k);
		}
		// insert: insert key and value pair to tree
		void insert(const key& k, const value& v)noexcept {
			insert(_root, k, v);
		}
		// print: print all key and value pair in tree
		void print()const {
			print(_root);
		}
	private:
		non_recursive_node* _root;
		size_t _total_node;
		non_recursive_node* minimum(non_recursive_node* nd)const{
			auto current = nd;
			while (current->left)
				current = current->left;
			return current;
		}
		non_recursive_node* maximum(non_recursive_node* nd)const {
			auto current = nd;
			while (current->right)
				current = current->right;
			return current;
		}
		non_recursive_node* successor(non_recursive_node* x) {
			if (x->right) // if right subtree is not empty
				return minimum(x->right);
			non_recursive_node* y = x->parent; // goes up to the parent
			while (y && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}
		non_recursive_node* find(const non_recursive_node& nd, const
			key& k) {
			auto current = nd;
			while (current && current->_key != k) {
				if (k < current->_key)
					current = current->left;
				else
					current = current->right;
			}
			return current;
		}
		void insert(non_recursive_node *x, const key& k, const value& v) {
			non_recursive_node *y = nullptr;
			auto temp = x;
			while (temp) {
				y = temp;
				if (k < temp->_key)
					temp = temp->left;
				else
					temp = temp->right;
			}
			non_recursive_node *z = new non_recursive_node(k, v, nullptr, nullptr, y);
			if(!y)
				x = z;
			else if(k < y->_key)
				y->left = z;
			else
				y->right = z;
			_total_node++;
		}
		void print(const non_recursive_node* nd)const {
			if (nd) {
				print(nd->left);
				std::cout << nd->_key << " ";
				print(nd->right);
			}
		}
	};
};     // namespace cormen
#endif // !CORMEN_ALGORITHM