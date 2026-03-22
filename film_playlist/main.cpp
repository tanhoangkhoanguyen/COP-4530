#include <iostream>
#include <string>
#include "FilmPlaylist.h"
using namespace std;

/*
Template represent the frontend of the film playlist
*/
class FilmPlaylistManager {
private:
    int user_choice;
    FilmPlaylist<FilmMetadata> Agent;

public:
    FilmPlaylistManager() {
        cout << "[INFO] Initialized Film_Playlist_Manager object\n\n";
    }

    void display_options() {
        cout << "\n===== Film Playlist Manager =====\n";
        cout << "Option 1. Add a Film\n";
        cout << "Option 2. Remove a Film\n";
        cout << "Option 3. Display Playlist Forward\n";
        cout << "Option 4. Display Playlist Backward\n";
        cout << "Option 5. Exit\n";
        cout << "Please enter your choice.. ";
    }

	FilmMetadata get_film_metadata() {
	    string name, producer;
	    int duration;
	    
        cin.ignore();
	
	    cout << "Enter film title: ";
	    getline(cin, name);
	
	    cout << "Enter producer name: ";
	    getline(cin, producer);
	
	    cout << "Enter duration (seconds): ";
	    cin >> duration;
	
	    return FilmMetadata(name, producer, duration);
	}

	// Routing user_choice to the correct operations
    void routing_options() {
    	// Add a film
    	if (user_choice == 1) {
			FilmMetadata film = get_film_metadata();
			Agent.add(film);
        }
    	// Remove a film
        if (user_choice == 2) {
			FilmMetadata film = get_film_metadata();
            Agent.remove(film);
        }
        // Display playlist forward
        if (user_choice == 3)
            Agent.displayForward();
        // Display playlist backward
        if (user_choice == 4)
            Agent.displayBackward();
	}

    void run() {
    	// An infinite loop to prompt for user options
        do {
            display_options();
            cin >> user_choice;

            // Check if input failed
            if (cin.fail()) {
		        cin.clear(); // clear error flag
		        cin.ignore();
		        cout << "Invalid input. Please enter a number in range [1, 5].\n";
		        continue;    // restart loop
		    }

            // Exit condition
            if (user_choice == 5) break;
            
            // Route to selected operation
			routing_options();

			cout << '\n';
        } while (true);

	    cout << "Exiting Music Playlist Manager feature...\n";
    }
};

int main() {
    FilmPlaylistManager admin;
    admin.run();
    return 0;
}