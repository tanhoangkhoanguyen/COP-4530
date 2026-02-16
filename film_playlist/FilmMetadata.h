#ifndef FILM_METADATA_H
#define FILM_METADATA_H

#include <iostream>
#include <string>
using namespace std;

/*
The FilmMetadata class represents the metadata of a film in the playlist. It includes:
- name       – Name of the film
- producer   – The producer
- duration   – The length of the film in seconds
*/
class FilmMetadata {
public:
    string name;
    string producer;
    int duration;

	// Instantiating a Song object with no arguments
    FilmMetadata() {}

	// Instantiating a Song object with arguments
    FilmMetadata(string name, string producer, int duration) {
	    this->name     = name;
	    this->producer = producer;
	    this->duration = duration;
	}

	// Display the FilmMetadata object
    void display() const {
        cout << "Name: " << name
             << " | Producer: " << producer
             << " | Duration: " << duration << " sec" << endl;
    }

    // Compare films
    bool operator == (const FilmMetadata& other) const {
        return (name == other.name && producer == other.producer && duration == other.duration);
    }
};

/*
Template Node class for Doubly Linked List
*/
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T value) {
        data = value;   // film metadata
        next = nullptr; // next Node object in Linked List
        prev = nullptr; // previous Node object in Linked List
    }
};

#endif