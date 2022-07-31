#pragma once

#include<iostream>


template<typename dt>
class QNode {
public:
	dt* data = NULL;
	QNode<dt>* next ;
	//Initialize Constructor
	QNode(dt* data) {
		this->data = data;
		next = NULL;
	}
	//~QNode() {
	//	data = NULL;
	//	next = NULL;
	//	delete QNode;
	//}
};


template<typename dt>
class Queue {
private:
	QNode<dt>* head = NULL;
	QNode<dt>* tail = NULL;
public:

	//enqueue
	void enQueue(dt* data) {
		QNode<dt>* n = new QNode<dt>(data);
		//empty
		if (isEmpty()) {
			head = n;
			tail = n;
		}
		//not empty
		//Add to the back
		else {
			tail->next = n;
			tail = n;
		}
	}

	//dequeue
	dt* deQueue() {
		dt* d = NULL;
		if (isEmpty()) {
			return NULL;
		}
		else{
			QNode<dt>* temp = head;
			head = head->next;
			d = temp->data;
			delete temp;
		}
		if (isEmpty()) {
			head = NULL;
			tail = NULL;
		}
		return d;
	}

	bool isEmpty() {
		if (!head)
			return true;
		else
			return false;
	}

	~Queue<dt>() {
		while (!isEmpty()) {
			deQueue();
		}
	}

};