#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

/*
Template Node for singly linked list
*/
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

#endif

/*
Item class represents an item in the game inventory. It includes:
- name       – Name of the item
- power      – The power scale of that item
*/
class Item {
private:
    // Trim whitespace at the beginning & end
	string trim(string s) {
	    size_t start = s.find_first_not_of(" \t\n\r");
	    size_t end = s.find_last_not_of(" \t\n\r");
	
	    if (start == string::npos) // string is all whitespace
	        return "invalid_item";
	
	    return s.substr(start, end - start + 1);
	}

public:
    string name;
    int power;

	// Instantiating a FilmMetadata object with no arguments
    Item() {}

	// Instantiating a FilmMetadata object with arguments
    Item(string name, int power) {
        this->name  = trim(name);
        this->power = power;
    }

	// Display the FilmMetadata object
    void display() const {
        cout << "Item: " << name
             << " | Power: " << power << endl;
    }
};