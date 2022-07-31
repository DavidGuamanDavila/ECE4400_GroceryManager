//
//  main.cpp
//
//  Created by Michael McCarthy and Anton David Guaman Davila
//

#include <iostream>
#include <string>
#include "Item.h"
#include "DLL.h"
#include "Queue.h"
#include "BST.h"
#include "GroceryController.h"


int main() {

    GroceryController G;
    G.addItem("orange", "fruits", 20231023, 5.00);
    G.addItem("orange", "fruits", 20231023, 5.00);
    G.addItem("orange", "fruits", 20231023, 5.00);
    G.addItem("Waygu Beef", "Meat", 20241023, 100.00);
    G.addItem("pineapple", "fruits", 20231024, 2.56);
    G.addItem("apple", "fruits", 20231025, 10.12);
    G.addCustomer("Mike");
    G.addCustomer("Dave");

    G.displayByPrice();
    //G.displayByExpiry();
    //G.displayList();

    //G.removeItem("pineapple");
    G.removeItem("orange");
    G.removeItem("orange");
    G.displayByPrice();
    

    G.displayByCategory("fruits");

    G.displayCustomerHistory();

    return 0;

  }