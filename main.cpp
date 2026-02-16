// Brief description: Film Playlist Manager - A doubly linked list-based playlist system for managing film metadata

#include <iostream>
#include <string>
#include <set>
using namespace std;

/*
The FilmMetadata struct represents the metadata of a film in the playlist. It includes:
- name       – Name of the film (default: empty string)
- producer   – The producer (default: empty string)
- duration   – The length of the film in minutes (default: 0)
*/
struct FilmMetadata {
    string name, producer;
    int duration;

    FilmMetadata(string n = string(), string p = string(), int d = 0) 
        : name(n), producer(p), duration(d) {}

    /*
    Displays the film metadata in a formatted manner
    Outputs: Name, Producer, and Duration to console
    */
    void display() const {
        cout << "Name: " << name << " | Producer: " << producer 
             << " | Duration: " << duration << " min\n";
    }

    /*
    Compares two FilmMetadata objects for equality
    Return true if all fields (name, producer, duration) match, false otherwise
    */
    bool operator==(const FilmMetadata& o) const {
        return name == o.name && producer == o.producer && duration == o.duration;
    }
};

// Node template
template <typename T>
struct Node {
    T data;
    Node *next, *prev;
    Node(T v) : data(v), next(nullptr), prev(nullptr) {}
};

/*
Template Doubly Linked List class representing the backend of the film playlist
The template has four main operations and an automatic memory cleanup feature
*/
template <typename T>
class FilmPlaylist {
    Node<T> *head, *tail;
    set<int> film_set;

    string trim(string s) {
        size_t start = s.find_first_not_of(" \t\n\r");
        size_t end = s.find_last_not_of(" \t\n\r");
        return (start == string::npos) ? "" : s.substr(start, end - start + 1);
    }
    // String Hasing algorithm to control the uniqueness
    int hash_str(string s) {
        const int base = 257, mod = 1e9 + 7;
        int res = 0;
        for (char c : s) (res = res * base + c) %= mod;
        return res;
    }

    int get_id(const T& v) {
        return hash_str(trim(v.name) + '|' + trim(v.producer) + '|' + to_string(v.duration));
    }

public:
    FilmPlaylist() : head(nullptr), tail(nullptr) {}

    // Add a new film to the playlist
    void add(T value) {
        int id = get_id(value);
        if (film_set.count(id)) {
            cout << "This film was already added.\n";
            return;
        }
        
        film_set.insert(id);
        Node<T>* node = new Node<T>(value);
        
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        cout << "Film added successfully.\n";
    }

    // Remove a film from the playlist
    void remove(T value) {
        int id = get_id(value);
        if (!film_set.count(id)) {
            cout << "This film does not exist.\n";
            return;
        }

        film_set.erase(id);
        for (Node<T>* cur = head; cur; cur = cur->next) {
            if (cur->data == value) {
                if (cur == head) head = cur->next;
                if (cur == tail) tail = cur->prev;
                if (cur->prev) cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
                cout << "Film removed successfully.\n";
                return;
            }
        }
    }

    // Display the film playlist forward
    void displayForward() const {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "\nPlaylist (Forward):\n";
        for (Node<T>* cur = head; cur; cur = cur->next)
            cur->data.display();
    }

    // Display the film playlist backward
    void displayBackward() const {
        if (!tail) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "\nPlaylist (Backward):\n";
        for (Node<T>* cur = tail; cur; cur = cur->prev)
            cur->data.display();
    }

    // Destructor. Activate when exiting the program
    ~FilmPlaylist() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

/*
FilmPlaylistManager: Template represent the frontend of the film playlist
*/
class FilmPlaylistManager {
    FilmPlaylist<FilmMetadata> playlist;

    void show_menu() {
        cout << "\n===== Film Playlist Manager =====\n"
             << "1. Add a Film\n2. Remove a Film\n"
             << "3. Display Playlist Forward\n4. Display Playlist Backward\n"
             << "5. Exit\nChoice: ";
    }

    FilmMetadata get_film() {
        string name, producer;
        int duration;
        cin.ignore();
        cout << "Enter film title: "; getline(cin, name);
        cout << "Enter producer name: "; getline(cin, producer);
        cout << "Enter duration (minutes): "; cin >> duration;
        return FilmMetadata(name, producer, duration);
    }

public:
    void run() {
        cout << "[INFO] Initialized Film Playlist Manager\n";
        int choice;
        
        while (true) {
            show_menu();
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Enter a number [1-5].\n";
                continue;
            }

            if (choice == 5) break;
            
            if (choice == 1 || choice == 2) {
                FilmMetadata film = get_film();
                choice == 1 ? playlist.add(film) : playlist.remove(film);
            } else if (choice == 3) {
                playlist.displayForward();
            } else if (choice == 4) {
                playlist.displayBackward();
            } else {
                cout << "Invalid choice.\n";
            }
            cout << '\n';
        }
        cout << "Exiting Film Playlist Manager...\n";
    }
};

int main() {
    FilmPlaylistManager().run();
    return 0;
}