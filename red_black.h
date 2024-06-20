#pragma once
#include <iostream>
namespace red_black {
	enum color { RED, BLACK }; // red = 0, black = 1
	template <class Key, class Value>
	class node {
	public:
		Key key;
		Value value;
		node *parent;
		node* left;
		node* right;
		bool color;
		node(const Key &key, const Value &value, const bool &color) {
			this->key = key;
			this->value = value;
			this->color = color;
			left = right = parent = nullptr;
		}
	};
	template <class Key, class Value>
	class red_black_tree {
	public:
		// ctor: create a red black tree
		red_black_tree() {
			nil = new node<Key, Value>(Key(), Value(), BLACK);
			root = nil;
			sz = 0;
		}
		// dtor: destroy the red black tree
		// empty: check if the tree is empty
		bool empty()const {
			return sz==0;
		}
		size_t size()const {
			return sz;
		}
		// insert: insert a new node into the tree, 
		// key is the key of the node, value is the value of the node
		void insert(const Key &key, const Value &value);
		// minimum: find the minimum node in the tree, return a pair of key and value
		std::pair<Key, Value> minimum(){
			if(empty())
				throw std::out_of_range("calling minimum() on empty tree");
			auto min = minimum(root);
			return std::make_pair(min->key, min->value);
		}
		// maximum: find the maximum node in the tree, return a pair of key and value
		const std::pair<Key, Value> maximum(){
			if(empty())
				throw std::out_of_range("calling maximum() on empty tree");
			auto max = maximum(root);
			return std::make_pair(max->key, max->value);
		
		}
	private:
		node<Key, Value>* root;
		node<Key, Value>* nil;
		size_t sz;
		void left_rotate(node<Key, Value>* x);
		void right_rotate(node<Key, Value>* x);
		void insert_fixup(node<Key, Value>* z);
		void delete_fixup(node<Key, Value>* x);
		node<Key, Value>* minimum(node<Key, Value>* x);
		node<Key, Value>* maximum(node<Key, Value>* x);
		void inorder(node<Key, Value>* x);
		void preorder(node<Key, Value>* x);
		void postorder(node<Key, Value>* x);
	};

	// left_rotate: rotate the tree to the left
	template<class Key, class Value>
	inline void red_black_tree<Key, Value>::left_rotate(node<Key, Value>* x)
	{
		auto y = x->right; // set y
		x->right = y->left; // turn y's left subtree into x's right subtree
		if(y->left != nil)
			y->left->parent = x;
		y->parent = x->parent; // link x's parent to y
		if (x->parent == nil)
			root = y;
		else if(x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x; // put x on y's left
		x->parent = y;
	}

	// right_rotate: rotate the tree to the right
	template<class Key, class Value>
	inline void red_black_tree<Key, Value>::right_rotate(node<Key, Value>* x)
	{
		auto y = x->left; // set y
		x->left = y->right; // turn y's right subtree into x's left subtree
		if(y->right != nil)
			y->right->parent = x;
		y->parent = x->parent; // link x's parent to y
		if (x->parent == nil)
			root = y;
		else if(x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x; // put x on y's right
		x->parent = y;
	}

	// insert_fixup: fix the tree after insertion
	template<class Key, class Value>
	inline void red_black_tree<Key, Value>::insert_fixup(node<Key, Value>* z)
	{
		while (z->parent->color == RED) {
			if (z->parent == z->parent->parent->left) {
				auto y = z->parent->parent->right;
				if (y->color == RED) { // case 1
					z->parent->color = BLACK; 
					y->color = BLACK; 
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else if (z == z->parent->right) { // case 2
					z = z->parent;
					left_rotate(z);
				}
				else { // case 3
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					right_rotate(z->parent->parent);
				}
			}
			else {
				auto y = z->parent->parent->left;
				if (y->color == RED) { // case 1
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color = RED;
					z = z->parent->parent;
				}
				else if (z == z->parent->left) { // case 2
					z = z->parent;
					right_rotate(z);
				}
				else { // case 3
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					left_rotate(z->parent->parent);
				}
			}
		}
	}

	//minimum: find the minimum node in the tree
	template<class Key, class Value>
	inline node<Key, Value>* red_black_tree<Key, Value>::minimum(node<Key, Value>* x)
	{
		while (x->left != nil)
			x = x->left;
		return x;
	}
	template<class Key, class Value>
	inline node<Key, Value>* red_black_tree<Key, Value>::maximum(node<Key, Value>* x)
	{
		while (x->right!=nil)
			x = x->right;
		return x;
	}
	template<class Key, class Value>
	void red_black_tree<Key, Value>::insert(const Key& key, const Value& value) {
		auto y = nil;
		auto x = root;
		auto z = new node<Key, Value>(key, value, RED);
		++sz;
		while (x != nil) {
			y = x;
			if (z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		z->parent = y;
		if(y==nil)
			root = z; // tree was empty
		else if(z->key < y->key)
			y->left = z;
		else
			y->right = z;
		z->left = z->right = nil;
		z->color = RED;
		insert_fixup(z);
	}
}