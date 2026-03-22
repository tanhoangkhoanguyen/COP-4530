#ifndef INVENTORY_SYSTEM_H
#define INVENTORY_SYSTEM_H

#include <iostream>
#include "Item.h"
using namespace std;

/*
Template Stack class representing the backend of the armory system
The template has three main operations
*/
template <typename T>
class InventorySystem {
private:
    Node<T>* top; // The head of Linked List

    // Return true if the inventory is empty (top is pointing to a null pointer)
    bool isEmpty() { return top == nullptr; }

public:
    InventorySystem() {
        top = nullptr;
    }

    // Push item into stack (pick item)
    void pickItem(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;

        cout << "Item added to inventory.\n";
    }

    // Pop item from stack (use item)
    void useItem() {
        if (isEmpty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        Node<T>* temp = top;
        top = top->next;

        cout << "You used:\n";
        temp->data.display();

        delete temp;
    }

    // Display inventory
    void showInventory() {
        if (isEmpty()) {
            cout << "Inventory is empty.\n";
            return;
        }

        Node<T>* current = top;
        cout << "\nRemaining items (Top to Bottom):\n";

        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }

    // Destructor to free memory. Activate when exiting the program
    ~InventorySystem() {
        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

#endif