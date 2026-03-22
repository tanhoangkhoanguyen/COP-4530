#include <iostream>
#include <limits>
#include <string>
#include "inventory_system.h"
using namespace std;

/*
Template represent the frontend of the game armory system
*/
class InventoryManager {
private:
    int user_choice;
    InventorySystem<Item> Agent;

public:
    InventoryManager() {
        cout << "[INFO] Inventory System initialized\n\n";
    }

    void display_options() {
        cout << "\n===== Game Inventory System =====\n";
        cout << "Option 1. Pick Item\n";
        cout << "Option 2. Use Item\n";
        cout << "Option 3. Show Inventory\n";
        cout << "Option 4. Exit\n";
        cout << "Please enter your choice.. ";
    }

    Item add_item_metadata() {
        string name;
        int power;

        cin.ignore();

        cout << "Enter item name: ";
        getline(cin, name);

		// Prompt user to enter valid power number
		while (true) {
		    cout << "Enter item power: ";
		    if (cin >> power) {
	            cin.ignore(numeric_limits<streamsize>::max(), '\n');		    
				break;                                            // success
			}
		    cout << "Invalid input. Please enter an integer number.\n";
		    cin.clear();                                          // clear error flag
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard invalid input
		}

        return Item(name, power);
    }

	// Routing user_choice to the correct operations
    void routing_options() {
    	// Add an item
        if (user_choice == 1) {
            Item item = add_item_metadata();
            Agent.pickItem(item);
        }
    	// Use an item
        if (user_choice == 2)
            Agent.useItem();
        // Show the remaining items in the inventory
        if (user_choice == 3)
            Agent.showInventory();
    }

    void run() {
    	// An infinite loop to prompt for user options
        do {
            display_options();
            cin >> user_choice;

            // Check if input failed
            if (cin.fail()) {
                cin.clear(); // clear error flag
//                cin.ignore();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an item name.\n";
                continue;    // restart loop
            }

            // Exit condition
            if (user_choice == 4) break;

            // Route to selected operation
            routing_options();

			cout << '\n';
        } while (true);

        cout << "[INFO] Exiting Inventory System...\n";
    }
};

int main() {
    InventoryManager admin;
    admin.run();
    return 0;
}