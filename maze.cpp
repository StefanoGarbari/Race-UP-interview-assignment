//Race UP interview assignment - Driverless - Stefano Garbari

#include <vector>
#include <iostream>

using namespace std;

// Struct to represent each cell in the queue and track path information
struct cell {
    int x;      // x-coordinate of the cell
    int y;      // y-coordinate of the cell
    int prev;   // Index of the previous cell in the path
    string dir; // Direction to move towards the exit from this cell
};

int main() {
    vector<cell> queue;              // Queue for BFS
    vector<vector<char>> maze;       // Matrix representing the maze
    vector<vector<bool>> explored;   // Matrix to track explored cells

    cout << "Input the maze:" << endl;

    // Input maze and initialize exploration matrix
    while (!cin.eof()) {
        string row;
        cin >> row;

        // Add the current row to the maze
        maze.push_back(vector<char>(row.begin(), row.end()));
        // Initialize the corresponding explored row with 'false'
        explored.push_back(vector<bool>(row.size(), false));

        // Find the exit ('E') and add it to the queue
        int pos = row.find('E');
        if (pos != -1)
            queue.push_back(cell{ int(maze.size()-1), pos, -1, "END"});
    }

    // Remove any empty row added at the end of input
    if (maze[maze.size() - 1].empty())
        maze.pop_back();

    // BFS search to find the start ('S')
    int n = 0;
    while (n < queue.size()) {
        int x = queue[n].x;
        int y = queue[n].y;

        // If start ('S') is found, break the loop
        if (maze[x][y] == 'S')
            break;

        // Explore the neighboring cells (up, down, left, right) if valid and unexplored
        if (x != 0 && maze[x - 1][y] != '#' && !explored[x - 1][y]) {
            queue.push_back(cell{x - 1, y, n, "DOWN"});
            explored[x - 1][y] = true;
        }

        if (x != maze.size() - 1 && maze[x + 1][y] != '#' && !explored[x + 1][y]) {
            queue.push_back(cell{x + 1, y, n, "UP"});
            explored[x + 1][y] = true;
        }

        if (y != 0 && maze[x][y - 1] != '#' && !explored[x][y - 1]) {
            queue.push_back(cell{x, y - 1, n, "RIGHT"});
            explored[x][y - 1] = true;
        }

        if (y != maze[x].size() - 1 && maze[x][y + 1] != '#' && !explored[x][y + 1]) {
            queue.push_back(cell{x, y + 1, n, "LEFT"});
            explored[x][y + 1] = true;
        }

        n++;
    }

    // If no solution is found, print a message and exit
    if (n == queue.size()) {
        cout << "There is no solution!" << endl;
        return 0;
    }

    // Backtrack from the start ('S') and print the directions
    while (n) {
        cout << queue[n].dir << endl;
        n = queue[n].prev;
    }

    return 0;
}
