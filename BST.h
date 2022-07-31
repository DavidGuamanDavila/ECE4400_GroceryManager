#pragma once

#include <iostream>
#include "DLL.h"
#include "Queue.h"
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
//dt is the data type used for the key value
//qt is the type of the elements stored in the queue
template<typename dt, typename qt>
class BST {

private:

	Node<dt>* root = NULL;
	Queue<qt>* queue = NULL;

	//METHODS USED FOR RECURSION
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
				return n;
			}
		}
	}

	Node<dt>* deleteNodeRec(Node<dt>* n, dt k) {
		if (n == NULL) {
			return NULL;
		}

		//Recursion
		if (k < n->key) {
			n->left = deleteNodeRec(n->left, k);
		}
		else if (k > n->key) {
			n->right = deleteNodeRec(n->right, k);
		}
		//Node to be deleted
		else {
			//node with one or no children
			if (n->left == NULL && n->right == NULL)
				return NULL;
			else if (n->left == NULL) {
				Node<dt>* temp = n->right;
				free(n);
				return temp;
			}
			else if (n->left == NULL) {
				Node<dt>* temp = n->right;
				free(n);
				return temp;
			}
			//Node has two children
			else {
				Node<dt>* temp = minNode(n->right);

				//copy data
				n->key = temp->key;
				n->ptr = temp->ptr;

				//delete the copied node
				n->right = deleteNodeRec(n->right, temp->key);
			}
		}
		return n;
	}

	//Find node with smallest value
	Node<dt>* minNode(Node<dt>* n) {
		Node<dt>* curr = n;
		while (curr && curr->left != NULL)
			curr = curr->left;

		return curr;
	}

	void displayRec(Node<dt>* root, Queue<qt>* q) {
		if (root != NULL) {
			displayRec(root->right, q);
			q->enQueue(root->ptr->data);
			displayRec(root->left, q);
		}
	}

public:

	BST() {
		root = NULL;
		queue = new Queue<qt>();
	}
	//key is either price or EXP date from Item Class
	void insert(dt k, NodeDLL<Item>* p) {
		root = insertRec(root, k, p);
	}

	void search(dt k) {
		searchRec(root, k);
	}


	void deleteNode(dt k) {
		root = deleteNodeRec(root, k);
	}

	//used to load a queue to be returned for printing data. 
	//The Queue will be DeQueued By GroceryControl class
	Queue<qt>* display() {
		displayRec(root,queue);
		return queue;
	}

};