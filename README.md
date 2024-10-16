Race UP interview assignment - Driverless - Stefano Garbari
# Maze Solver (BFS)

This program solves a maze using a Breadth-First Search (BFS) algorithm. It finds the shortest path (or one of the shortest) from the exit to the start, rather than from the start to the exit, which is explained below.

## Overview

- The maze is represented as a 2D character matrix (`vector<vector<char>>`) called `maze`.
- A corresponding boolean matrix, `explored`, tracks which cells of the maze have already been visited during the search.
- The elements of the BFS queue are of type `cell`, which stores:
  - The position `x`, `y` of the cell.
  - The index `prev`, which points to the previous cell in the path.
  - The string `dir`, which indicates the direction needed to move toward the exit from the current cell.

## Algorithm

1. **Input Processing:**
   - The maze is read into the `maze` matrix.
   - During this process, the exit point is identified, and the corresponding cell is added to a list (`queue`) for exploration.

2. **BFS Execution:**
   - The algorithm iterates over the list in a typical BFS manner:
     1. Take the next cell from the list.
     2. If the cell is the start, the search terminates (solution found).
     3. Otherwise, add all neighboring cells to the list, but only if:
        - They are not walls.
        - They haven’t been explored yet.
   - If the entire list is processed without finding the start, the loop exits (no solution exists).

3. **Path Reconstruction:**
   - If the start is found, the path is traced back from the start to the exit, using `prev`, and printing on screen the direction of each step along the way, using the `dir` value stored in each cell.

## How to Run the Code

1. **Compile the Code**
The code is written in C++ and needs to be compiled using a C++ compiler before running it.

2. **Execute the Program**
After compiling, run the program and input the maze via standard input (stdin). Enter the maze row by row, with each row separated by newlines and/or spaces. After the last row is inserted, input the EOF character in order for the program to start. The input format must be correct, as there is **no input validation**. If the rows have different lengths, the program may crash or behave unexpectedly.
