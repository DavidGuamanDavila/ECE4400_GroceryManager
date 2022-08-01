#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
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
			cout << setprecision(9);
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

		if (priceAndExpiry != NULL) {
			GL_Price->deleteNode(priceAndExpiry[0]);
			GL_Exp->deleteNode(priceAndExpiry[1]);
		}

	}
	void addCustomer(string customer) {
		Customer_History->enQueue(customer);
	}

	void displayList() {
		cout << "List:" << endl;
		GroceryList->printDLL();
	}
	Queue<Item>* getList() {
		return GroceryList->printDLL();
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
	void writeFile() {
		ofstream out_file("../output.json");
		if (!out_file) {
			cerr << "Error with file" << endl;
			return;
		}
		Queue<Item>* q = getList();
		while (!q->isEmpty()) {
			Item* i = q->deQueue();
			out_file << "{" << endl;
			out_file << "   \"name\""<<":"<< "\""<< i->getName() << "\"," << endl;
			out_file << "   \"cat\"" << ":" << "\"" << i->getCategory() << "\"," << endl;
			out_file<< setprecision(9);
			out_file << "   \"exp\"" << ":" << i->getExpiryDate()<<"," << endl;
			out_file << "   \"price\"" << ":"<< i->getPrice() << "," << endl;
			out_file << "   \"stock\"" << ":"<< i->getStock() << endl;
			out_file << "}" << endl;
		}
		out_file.close();
	}
};
