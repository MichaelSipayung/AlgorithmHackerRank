#ifndef CORMEN_ALGORITHM
#define CORMEN_ALGORITHM
#include <iostream>
#include <ostream>
#include <vector>

using std::vector;
namespace cormen {
    template<typename T, typename Comparable>
    void insertion_sort(vector<T> &data, Comparable comp) {
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

    template<typename T>
    void insertion_sort(vector<T> &data) {
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

    template<typename T>
    class linked_list;

    template<typename T>
    class node {
    public:
        node() = default;

        explicit node(T it) : item(std::move(it)), next(nullptr) {}

    private:
        T item;
        node<T> *next;

        friend class linked_list<T>;
    };

    template<typename T>
    class linked_list {
    public:
        linked_list();

        ~linked_list();

        [[nodiscard]] constexpr bool empty() const;

        [[nodiscard]] constexpr T &front() const;

        [[nodiscard]] const T &back() const;

        void push_back(const T &item);

        void push_front(const T &item);

        void pop_front();

        void clear();

        void print();

        [[nodiscard]] size_t size() const;

    private:
        node<T> *head;
        size_t sz = 0;

        node<T> *get_tail();
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
    constexpr T &linked_list<T>::front() const {
        return head->item;
    }

    template<typename T>
    const T &linked_list<T>::back() const {
        auto temp = head;
        while (temp->next)
            temp = temp->next;
        return temp->item;
    }

    template<typename T>
    void linked_list<T>::push_back(const T &item) {
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
    void linked_list<T>::push_front(const T &item) {
        auto temp = new node<T>;
        temp->item = item;
        temp->next = head;
        head = temp;
        ++sz;
    }

    template<typename T>
    void linked_list<T>::pop_front() {
        if (!head)
            throw std::out_of_range("linked_list is empty before pop_front");
        auto old = head;
        head = old->next;
        --sz;
        delete old;
    }

    template<typename T>
    void linked_list<T>::clear() {
        while (!empty())
            pop_front();
        sz = 0;
    }

    template<typename T>
    void linked_list<T>::print() {
        auto temp = head;
        while (temp) {
            cout << temp->item << " ";
            temp = temp->next;
        }
    }

    template<typename T>
    size_t linked_list<T>::size() const {
        return sz;
    }

    template<typename T>
    node<T> *linked_list<T>::get_tail() {
        if (!head)
            return nullptr;
        auto temp = head;
        while (temp->next)
            temp = temp->next;
        return temp;
    }

    template<typename T>
    class d_linked_list;

    template<typename T>
    class d_node {
    public:
        explicit d_node(const T &d = T{}, d_node<T> *p = nullptr,
                        d_node<T> *n = nullptr) : item(d), prev(p), next(n) {}

        // for debugging purposes
        const T &get_item() const { return item; }

        const d_node<T> *get_prev() const { return prev; }

        const d_node<T> *get_next() const { return next; }

    private:
        T item;
        d_node<T> *prev;
        d_node<T> *next;

        friend class d_linked_list<T>;
    };

    template<typename T>
    class d_linked_list {
    public:
        d_linked_list();

        ~d_linked_list();

        bool empty() const;

        const T &front() const;

        const T &back() const;

        void push_front(const T &) noexcept;

        void push_back(const T &) noexcept;

        void pop_back();

        void pop_front();

        size_t size() const;

        const d_node<T> *get_head() const { return head; }

        const d_node<T> *get_tail() const { return tail; }

    private:
        d_node<T> *head;
        d_node<T> *tail;
        size_t sz = 0;
    protected:
        void add(d_node<T> *pos, const T &val);

        void remove(d_node<T> *pos);
    };

    // ctor for doubly linked list, head and tail is sentinel node for quick access
    template<typename T>
    d_linked_list<T>::d_linked_list() {
        head = new d_node<T>(); // create a sentinel, this is must be not null
        tail = new d_node<T>(); // but it's only dummy node
        head->next = tail;
        tail->prev = head;
    }

    // dtor of the doubly linked list, destroy all only if the list is not empty
    template<typename T>
    d_linked_list<T>::~d_linked_list() {
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
    const T &d_linked_list<T>::front() const {
        if (empty())
            throw std::out_of_range("call front on empty list");
        return head->next->item;
    }

    // back: get the last element from doubly linked list
    template<typename T>
    const T &d_linked_list<T>::back() const {
        if (empty())
            throw std::out_of_range("call back on empty list");
        return tail->prev->item;
    }

    // push_front: adding new element on the front of the list
    template<typename T>
    void d_linked_list<T>::push_front(const T &val) noexcept {
        add(head->next, val);
        ++sz;
    }

    // push_back: adding new element on the back of the list
    template<typename T>
    void d_linked_list<T>::push_back(const T &val) noexcept {
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
    void d_linked_list<T>::add(d_node<T> *pos, const T &val) {
        auto new_item = new d_node<T>(val);
        new_item->next = pos; // link new_item in between pos
        new_item->prev = pos->prev; // and pos->prev
        pos->prev->next = new_item;    // update the next pointer of the node at the
        // position where new_item is inserted
        pos->prev = new_item;    // update the prev pointer of the node at the
        // position where new_item is inserted
    }

    // remove: removing node pos from list, u: predecessor, w: successor
    template<typename T>
    void d_linked_list<T>::remove(d_node<T> *pos) {
        auto u = pos->prev; // remove pos from list
        auto w = pos->next; // [u -> pos ->w]
        u->next = w;
        w->prev = u;
        delete pos;
    }

    template<typename T>
    void merge(std::vector<T> &ls, const int &beg, const int &mid, const int &end) {
        vector<T> temp;
        for(auto k =beg; k<=end;++k) // copy ls[low...hi] to temp
            temp.push_back(ls[k]);
        // merge the element in sorted order
        auto i=beg;
        auto j = mid+1;
        for(auto k=beg; k<=end; ++k){
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

    template<typename T>
    void merge_sort(vector<T> &ls, const int &beg, const int &end) {
        if(end<=beg)
            return;
        int mid = beg + (end-beg)/2;
        merge_sort(ls, beg, mid);
        merge_sort(ls, mid+1, end);
        merge(ls,beg,mid,end);
    }

    // merge sort with lambada params, custom comparable, default is less than
    template<typename T, typename Comparable>
    void merge(std::vector<T> &ls, const int &beg, const int &mid, const int &end,
        Comparable comp){
        std::vector<T> temp;
        for(auto k=beg; k<=end;++k)
            temp.push_back(ls[k]);
        auto i=beg;
        auto j= mid+1;
        for(auto k = beg; k<=end; ++k){
            if(i>mid) //control the half left
                ls[k] = temp[j++ - beg];
            else if(j>end) //control the left right
                ls[k] = temp[i++ - beg];
            else if(comp(temp[j - beg], temp[i - beg])) //compare half right with half left
                ls[k] = temp[j++ - beg];
            else
                ls[k] = temp[i++ - beg];
        }
    }

    template<typename T, typename Comparable>
    void merge_sort(vector<T> &ls, const int &beg, const int &end,
        Comparable comp){
        if(end<=beg)
            return;
        int mid = beg + (end-beg)/2;
        merge_sort(ls, beg,mid,comp);
        merge_sort(ls,mid+1,end,comp);
        merge(ls,beg,mid,end,comp);
    }

    template<typename T>
    class circle_list;

    template<typename T>
    class node_circle{
    public:
        node_circle(const T& value) : item{value}, next{nullptr}{}
        ~node_circle(){next = nullptr;}
        const T& get_item()const{return item;}
    private:
        T item;
        node_circle *next;
        friend class circle_list<T>;
    };

    template<typename T>
    class circle_list
    {
    public:
        circle_list(): cursor{nullptr}{}
        ~circle_list(){
            while(!empty())
                remove();
        }
        bool empty() const;
        const T &front() const; // element following cursor, if not advance,
        // the front is the last inserted element
        const T &back() const; // element at the cursor, conversly to front behavior
        void advance(); // advance cursor
        void add(const T&); // add item after cursor, if current [a,b], add 'c'
        // will make the list [c,a,b], this maintain the circular behavior
        void remove(); // remove node after cursor
    private:
        node_circle<T> *cursor;    
    };

    template<typename T>
    void circle_list<T>::remove(){
        if(empty())
            throw std::out_of_range("calling remove() on empty circle_list");
        auto old = cursor->next;
        if(old == cursor)
            cursor = nullptr;
        else
            cursor->next = old->next;
        delete old;
    }
    template<typename T>
    bool circle_list<T>::empty()const{
        return cursor == nullptr;
    }

    template<typename T>
    const T &circle_list<T>::back()const{
        if(empty())
            throw std::out_of_range("calling back() on empty circle_list");
        return cursor->item;
    }

    template<typename T>
    const T & circle_list<T>::front()const{
        if(empty())
            throw std::out_of_range("calling front() on empty circle_list");
        return cursor->next->item;
    }

    template<typename T>
    void circle_list<T>::advance(){
        cursor = cursor->next;
    }

    template<typename T>
    void circle_list<T>::add(const T& item){
        auto new_node = new node_circle<T>(item);
        if(empty()){
            new_node->next = new_node; //since we deal with circular list
            cursor = new_node; //cursor point to new_node
        }else{
            new_node->next = cursor->next; //link in v after cursor
            cursor->next= new_node; //cursor next point to newly added node
        }
    }

    template<typename T>
    void rdoubly_linked_list(d_linked_list<T> &ls){
        d_linked_list<T> temp;
        while(!ls.empty()){ // copying the original ls to temp
            const auto item = ls.front();
            ls.pop_front();
            temp.push_front(item);
        }
        while(!temp.empty()){
            const auto item = temp.front();
            temp.pop_front();
            ls.push_back(item);
        }
    }
};
#endif // !CORMEN_ALGORITHM
