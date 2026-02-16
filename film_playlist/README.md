# Film Playlist Manager

## Overview

This project is a **console-based Film Playlist Manager** written in C++. It allows users to manage a playlist of films. Each film has metadata including its **name**, **producer**, and **duration** (in seconds).

The backend uses a **doubly linked list** to store the playlist, and a **hash set** to ensure that no duplicate films are added. The program also trims whitespace and handles invalid inputs gracefully.

### Features

* Add a new film to the playlist
* Remove an existing film from the playlist
* Display the playlist forward (from first to last)
* Display the playlist backward (from last to first)
* Prevents duplicate films using a hash-based unique ID

### Files

| File Name        | Description                                                                                     |
| ---------------- | ----------------------------------------------------------------------------------------------- |
| `FilmMetadata.h` | Contains the `FilmMetadata` class and `Node` template for the doubly linked list.               |
| `FilmPlaylist.h` | Contains the `FilmPlaylist` template class which manages the backend playlist operations.       |
| `main.cpp`       | Contains the `FilmPlaylistManager` frontend class and the `main()` function to run the program. |

## How to Run

### Prerequisites

* A C++ compiler
* Command line / terminal access

### Compilation

Compile all files together using your compiler. For example, using `g++`:

```bash
g++ main.cpp -o FilmPlaylistManager
```

### Run

After compiling, run the executable:

```bash
./FilmPlaylistManager
```

You will see a menu with options:

```
===== Film Playlist Manager =====
Option 1. Add a Film
Option 2. Remove a Film
Option 3. Display Playlist Forward
Option 4. Display Playlist Backward
Option 5. Exit
Please enter choice..
```

Follow the prompts to add or remove films, or display the playlist in either direction. Enter `5` to exit the program.