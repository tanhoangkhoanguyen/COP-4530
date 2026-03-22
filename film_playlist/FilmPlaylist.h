#ifndef FILM_PLAYLIST_H
#define FILM_PLAYLIST_H

#include <iostream>
#include <set>
#include <string>
#include "FilmMetadata.h"
using namespace std;

const int hash_base = 257;
const int mod = 1e9 + 7;

/*
Template Doubly Linked List class representing the backend of the film playlist
The template has four main operations and an automatic memory cleanup feature
*/
template <typename T>
class FilmPlaylist {
private:
    Node<T>* head; // The head of Linked List
    Node<T>* tail; // The taif of Linked List
    /*
		The set is used to control the uniqueness of films in the playlist, avoid duplicating films.
		- set.count() operates in O(log n) time complexity.
		- set.erase() operates in O(log n) time complexity.
	*/
    set<int> film_list;

	string trim(string s) {
	    size_t start = s.find_first_not_of(" \t\n\r");
	    size_t end = s.find_last_not_of(" \t\n\r");
	
	    if (start == string::npos) // string is all whitespace
	        return "";
	
	    return s.substr(start, end - start + 1);
	}

	// String Hasing algorithm to control the uniqueness
    int hash_str(string s) {
    	int result = 0;
    	for (auto i : s)
    		(result = result * hash_base + i) %= mod;
    	return result;
	}
	
	bool check_film(T value, bool save_id) {
		// Create an unique id
	    string id = trim(value.name) + '|' 
	              + trim(value.producer) + '|' 
	              + to_string(value.duration);
	
	    int hashed_id = hash_str(id);
	    if (film_list.count(hashed_id))
	        return true;  // already exists
	
	    if (save_id) film_list.insert(hashed_id);
	    else         film_list.erase(hashed_id);
	    return false;  // new film
	}

public:
    FilmPlaylist() {
        head = nullptr;
        tail = nullptr;
    }

    // Add a new film to the playlist
    void add(T value) {        
		if (check_film(value, true)) {
			cout << "This film was already added.\n";
			return;
		}
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Film added successfully.\n";
    }

    // Remove a film from the playlist
    void remove(T value) {
		if (!check_film(value, false)) {
			cout << "This film does not exist.\n";
			return;
		}
		
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {

                if (current == head)
                    head = current->next;                

                if (current == tail)
                    tail = current->prev;

                if (current->prev != nullptr)
                    current->prev->next = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev;

                delete current;
                cout << "Film removed successfully.\n";
                return;
            }
            current = current->next;
        }

        cout << "Film not found.\n";
    }

    // Display the film playlist forward
    void displayForward() const {
        Node<T>* current = head;

        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\nPlaylist (Forward):\n";
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
    }

    // Display the film playlist backward
    void displayBackward() const {
        Node<T>* current = tail;

        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "\nPlaylist (Backward):\n";
        while (current != nullptr) {
            current->data.display();
            current = current->prev;
        }
    }

    // Destructor. Activate when exiting the program
    ~FilmPlaylist() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

#endif