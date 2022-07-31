#pragma once
#include <string>
#include <iostream>
#include "Queue.h"
using namespace std;

// Node Class Begins
template <typename DT>
class NodeDLL {
public:
    // Creation of data 
    //data is a pointer to an item
    DT* data;
    // Creation of pointer to next node
    NodeDLL <DT>* next;
    // Creation of pointer to previous node
    NodeDLL <DT>* prev;
    //Constructor creation
    NodeDLL(DT* new_data) {
        this->data = new_data;
        next = NULL;
        prev = NULL;
    }
};
// Node Class Ends

// Double Linked List Class Begins
template <typename DT, typename DelT>
class DLL {
public:
    //Initialize head reference node
    NodeDLL <DT>* head_ref;

    // Constructor
    DLL() {
        head_ref = NULL;
    }
    //DLL(const DLL& p1) {
    //    
    //}
    // Function to print the DLL elements
    void printDLL() {
        //Create a temporary rote to traverse the DLL
        NodeDLL <DT>* temp = head_ref;
        if (head_ref == NULL) {
            cout << "List is empty!" << endl;
        }
        else {
            while (temp != NULL) {
                cout << temp->data->getPrice() << " ";
                temp = temp->next;
            }
        }
    }
    DT* searchDuplicate(DelT i) {
        if (head_ref == NULL) {
            return NULL;
        }
        else {
            NodeDLL < DT >* curr = head_ref;
            while (curr != NULL) {
                if (i == curr->data->getName()) {
                    return curr->data;
                }
                curr = curr->next;
            }
            return NULL;
        }
        
    }
    // Function that inserts data to the begining of the DLL and returns a node
    NodeDLL <DT>* pushDLL(DT* new_data) {
        NodeDLL <DT>* new_node = new NodeDLL<DT>(new_data);
        if (head_ref == NULL) {
            // Make the new node next equal to the head reference
            new_node->next = head_ref;
            // Make the head reference equal the new node
            head_ref = new_node;
            // Make the previous of the new node equal to NULL
            new_node->prev = NULL;
        }
        else {
            // Make the new node next equal to the head reference
            new_node->next = head_ref;
            // Make the previous of head reference to the new node
            head_ref->prev = new_node;
            // Make head reference point to the new node
            head_ref = new_node;
            // Make the previous node of the new_node point to NULL
            new_node->prev = NULL;
        }
        return new_node;
    }

    ////Function that Deletes an item using the name of the item and returns a float, the price of the item deleted
    double* deletevalueDLL(DelT key) {
        // Check if DLL or the name of the item is empty
        if (head_ref == NULL || key == "") {
            if (head_ref == NULL) {
                cout << "Nothing to be deleted. DLL is empty." << endl;
            }
            else {
                cout << "Nothing was deleted. Key parameter is empty" << endl;
            }
            return 0;
        }
        else {
            // Create two pointers to aid with the traversal
            NodeDLL < DT >* curr = head_ref;
            NodeDLL < DT >* prev = NULL;
            //Create variable that will have the current item name
            DelT CurrItemName = curr->data->getName();
            //Initialize array that will return the price or expiry date
            double information[2];
            // Traverse through the DLL
            while (CurrItemName != key) {
                //Address situation where the key is not within the SLL
                if (curr == NULL || curr->next == NULL) {
                    cout << "No record found with the name entered." << endl;
                    return 0;
                }
                //Update pointers by moving them to their next position
                prev = curr;
                curr = curr->next;
                //Update the current item name with respect to the current pointer
                CurrItemName = curr->data->getName();
            }
            information[0] = curr->data->getPrice();
            information[1] = curr->data->getExpiryDate();
            // ----------------------------------------------------
            // Now address different situations
            // Check if the node found is the only node in the list
            if (CurrItemName == key && curr->next == NULL && curr->prev == NULL && curr == head_ref) {
                // Update the head reference to NULL
                head_ref = NULL;
                free(curr);
                cout << "Head node was deleted. Head node was the only node in the DLL" << endl;
            }
            // Check if the node deleted is the first node and the DLL has more nodes
            else if (curr == head_ref) {
                head_ref = head_ref->next;
                // Make sure the previous of the head reference is pointing to NULL
                head_ref->prev = NULL;
                cout << "Head node was deleted. Head node was not the only node in the ""DLL" << endl;
                delete curr;
            }
            // Check if the node deleted is the last node
            else if (curr->next == NULL) {
                prev->next = NULL;
                cout << "Last node was deleted" << endl;
                free(curr);
            }
            // Address the last situation where the node is not in the front or end of the DLL
            else {
                prev->next = curr->next;
                (curr->next)->prev = curr->prev;
                cout << "Node deleted. Found within the DLL. Not head or last node." << endl;
                delete curr;
            }
            return information;
        }
    }
    //Function that displays by category and returns a queue
    Queue <DT>* displayCat(DelT category) {
        //Address scenario where the DLL is empty and there is no item
        //Create a temporary node to traverse the DLL
        NodeDLL <DT>* temp = head_ref;
        //Create a queue that will be returned
        Queue<DT>* queue = new Queue<DT>();
        if (head_ref == NULL) {
            cout << "List is empty!" << endl;
        }
        //Address scenario where the DLL is not empty
        else {
            //Traverse the DLL while the temp is not NULL
            while (temp != NULL) {
                //Compare if the current Node category is equal to the parameter passed into the function
                if (temp->data->getCategory() == category) {
                    //Enqueue
                    queue->enQueue(temp->data);
                    //Move to the next node
                    temp = temp->next;
                }
                //Address scenario where the Node category is not equal to the parameter passed into the function
                else {
                    //Move to the next node
                    temp = temp->next;
                }
            }
        }
        //Finally, return the queue
        return queue;
    }
    // Destructor 
    //~DLL() {
    //    NodeDLL < DT >* deln = head_ref;
    //    NodeDLL < DT >* nextdel = NULL;
    //    // Traverse through the DLL
    //    while (deln != NULL) {
    //        // Update pointers
    //        nextdel = deln->next;
    //        delete deln;
    //        deln = nextdel;
    //    }
    //    delete nextdel;
    //    delete head_ref;
    //}
};
// Double Linked List Class Ends