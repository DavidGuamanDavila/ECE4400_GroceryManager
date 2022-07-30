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

Item* createItem(string name, string cat, string exp, double price) {
    Item* newItem = new Item;
    newItem->setName(name);
    newItem->setCategory(cat);
    newItem->setExpiryDate(exp);
    newItem->setPrice(price);
    return newItem;
}

int main() {
    Item* x = createItem("orange", "fruits", "9 dec", 1.91);
    Item* z = createItem("pineapple", "fruits", "1 july", 2.56);
    Item* a = createItem("apple", "fruits", "8 feb", 10.12);
    DLL<Item, string> y;
    y.pushDLL(x);
    y.pushDLL(z);
    y.pushDLL(a);
    y.printDLL();
    y.deletevalueDLL("cucumber");
    float g = y.deletevalueDLL("pineapple");
    y.printDLL();
    float p = y.deletevalueDLL("orange");
    y.printDLL();
    float gp = y.deletevalueDLL("apple");
    y.deletevalueDLL("hey");
    y.printDLL();
    cout << g << endl;
    cout << p << endl;
    cout << gp << endl;
    return 0;

}