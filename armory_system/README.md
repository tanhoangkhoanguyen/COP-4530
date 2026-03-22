# Game Armory System

## Overview

This project is a **console-based Game Armory System** written in C++. It stimulates a in game character's inventory. Each item has metadata including its **name** and **power**.

The backend uses a **single linked list** to build a **Stack class**. The program also trims whitespace and handles invalid inputs gracefully.

### Features

* Pick an item (add a new item to the inventory)
* Use an item (remove the top item from the inventory)
* Show inventory (display items in the inventory from top to bottom)

### Files

| File Name        | Description                                                                                     |
| ---------------- | ----------------------------------------------------------------------------------------------- |
| `item.h` | Contains the `Item` class and `Node` template for the single linked list.               |
| `inventory_system.h` | Contains the `InventorySystem` template class which manages the backend inventory operations.       |
| `main.cpp`       | Contains the `InventoryManager` frontend class and the `main()` function to run the program. |

## How to Run

### Prerequisites

* A C++ compiler
* Command line / terminal access

### Compilation

Compile all files together using your compiler. For example, using `g++`:

```bash
g++ main.cpp -o InventoryManager
```

### Run

After compiling, run the executable:

```bash
InventoryManager.exe
```

You will see a menu with options:

```
===== item inventory Manager =====
Option 1. Pick Item
Option 1. Pick Item
Option 3. Show Inventory
Option 4. Exit
Please enter your choice..
```

Follow the prompts to add or remove items, or display the inventory in either direction. Enter `4` to exit the program.