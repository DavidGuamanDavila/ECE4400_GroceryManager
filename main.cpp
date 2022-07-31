//
//  main.cpp
//
//  Created by Michael McCarthy and Anton David Guaman Davila
//

#include <iostream>
#include <string>
#include "Item.h"
#include "DLL.h"
#include "CQ.h"
#include "Queue.h"
#include "BST.h"


Item* createItem(string name, string cat, double exp, double price) {
	Item* newItem = new Item;
	newItem->setName(name);
	newItem->setCategory(cat);
	newItem->setExpiryDate(exp);
	newItem->setPrice(price);
	return newItem;
}

int main() {
	//Test DLL
	//Item* x = createItem("orange", "fruits", 20028912, 1.91);
	//Item* z = createItem("pineapple", "fruits", 20019345, 2.56);
	//Item* a = createItem("apple", "fruits", 12138913, 10.12);
	//DLL<Item, string> y;
	//y.pushDLL(x);
	//y.pushDLL(z);
	//y.pushDLL(a);
	//y.printDLL();
	//double iggy = y.deletevalueDLL("cucumber",true);
	//double g = y.deletevalueDLL("pineapple", false);
	//y.printDLL();
	//double p = y.deletevalueDLL("orange", false);
	//y.printDLL();
	//double gp = y.deletevalueDLL("apple",true);
	//y.deletevalueDLL("hey", false);
	//y.printDLL();
	//cout << iggy << endl;
	//cout << g << endl;
	//cout << p << endl;
	//cout << gp << endl;


	//Circular Queue Testing
	//CQ<string> x(3);
	//x.deQueue();
	//x.enQueue("Bob Dylan");
	//x.enQueue("Michael McCarthy");
	//x.enQueue("John Cena");
	//x.displayQueue();
	//x.enQueue("Kanye West");
	//x.displayQueue();
	//x.enQueue("John Jones");
	//x.displayQueue();
	//x.enQueue("Jhay Cortez");
	//x.displayQueue();
	//x.deQueue();
	//x.displayQueue();
	//x.deQueue();
	//x.displayQueue();
	//x.deQueue();
	//x.displayQueue();
	return 0;
};