#pragma once

#include <iostream>
#include <string>

#include "BST.h"
#include "CQ.h"
#include "DLL.h"
#include "Item.h"
#include "Queue.h"

using namespace std;

class GroceryController {

private:
	DLL<Item, string>* GroceryList;
	BST<double, Item>* GL_Price;
	BST<double, Item>* GL_Exp;
	CQ<string>* Customer_History;

	Item* createItem(string name, string cat, double exp, double price) {
		Item* newItem = new Item;
		newItem->setName(name);
		newItem->setCategory(cat);
		newItem->setExpiryDate(exp);
		newItem->setPrice(price);
		return newItem;
	}

	void PrintItem(Queue<Item>* q) {
		while (!q->isEmpty()) {
			Item* n = q->deQueue();
			cout << n->getName() << ", ";
			cout << n->getCategory() << ", ";
			cout << n->getPrice() << ", ";
			cout << n->getExpiryDate() << ", ";
			cout << n->getStock();
			cout << endl;
		}
	}

public:
	GroceryController() {
		GroceryList = new DLL<Item, string>;
		GL_Price = new BST<double, Item>;
		GL_Exp = new BST<double, Item>;
		Customer_History = new CQ<string>(3);
	}
	void addItem(string name, string cat, double exp, double price) {

		Item* item = createItem(name, cat, exp, price);

		Item* dup = GroceryList->searchDuplicate(name);

		if (dup != NULL) {
			dup->incStock();
			return;
		}

		NodeDLL<Item>* ptr = GroceryList->pushDLL(item);

		GL_Price->insert(item->getPrice(), ptr);

		GL_Exp->insert(item->getExpiryDate(), ptr);
	}
	void removeItem(string name) {

		Item* dup = GroceryList->searchDuplicate(name);

		if (dup != NULL && dup->getStock() > 1) {
			dup->decStock();
			return;
		}
		// index 0 = price
		// index 1 = expiry
		double* priceAndExpiry = GroceryList->deletevalueDLL(name);

		GL_Price->deleteNode(priceAndExpiry[0]);
		GL_Exp->deleteNode(priceAndExpiry[1]);
	}
	void addCustomer(string customer) {
		Customer_History->enQueue(customer);
	}

	void displayList() {
		cout << "List:" << endl;
		GroceryList->printDLL();
	}
	void displayByPrice() {
		cout << "PRICE:" << endl;
		PrintItem(GL_Price->display());
	}
	void displayByExpiry() {
		cout << "Expiry:" << endl;
		PrintItem(GL_Exp->display());
	}
	void displayByCategory(string cat) {
		cout << "Category: " << endl;
		PrintItem(GroceryList->displayCat(cat));
	}

	void displayCustomerHistory() {
		cout << "Customer History:" << endl;
		Customer_History->displayQueue();
	}

};
