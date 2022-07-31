#pragma once

#include <iostream>
#include "DLL.h"
//dt is used to determine if the key value in the TData is int or float
//this accounts for sorting by price and expiry date
template<typename dt>
class Node {
public:
	dt key;
	NodeDLL<Item>* ptr = NULL;
	Node<dt>* left = NULL;
	Node<dt>* right = NULL;
	Node(dt k, NodeDLL<Item>* p) {
		key = k;
		ptr = p;
	}
};

template<typename dt>
class BST {
	Node<dt>* root = NULL;

public:
	//key is either price or EXP date
	void insert(dt k, NodeDLL<Item>* p) {
		root = insertRec(root, k, p);
	}
	Node<dt>* insertRec(Node<dt>* root, dt k, NodeDLL<Item>* p) {
		//insert if there are no items
		if (root == NULL) {
			root = new Node<dt>(k, p);
			return root;
		}
		if (k < root->key)
			root->left = insertRec(root->left, k, p);
		else if (k > root->key)
			root->right = insertRec(root->right, k, p);
		// NOTE: handle quantity case here
		return root;
	}

	void search(dt k) {
		searchRec(root, k);
	}
	Node<dt>* searchRec(Node<dt>* n, dt k) {
		if (n == NULL) {
			return n;
		}
		else {
			if (k < n->key)
				n->left = searchRec(n->left, k);
			else if (k > n->key)
				n->right = searchRec(n->right, k);
			else {
				Item* item = n->ptr->data;
				cout << item->getName() << endl;
				return n;
			}
		}
	}
};