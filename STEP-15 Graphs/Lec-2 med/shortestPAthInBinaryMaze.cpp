/*
Given a 2D binary grid (0 = wall, 1 = path), and a source and destination cell, 
find the minimum number of steps to reach the destination from the source by 
only moving up/down/left/right through cells with value 1.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest path in a binary maze
int shortestPathBinaryMaze(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    int srcX = source.first;
    int srcY = source.second;
    int destX = destination.first;
    int destY = destination.second;

    // If source or destination is blocked (0), return -1
    if (grid[srcX][srcY] == 0 || grid[destX][destY] == 0)
        return -1;

    // Distance matrix initialized with -1
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[srcX][srcY] = 0;

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // BFS queue: {row, col}
    queue<pair<int, int>> q;
    q.push({srcX, srcY});

    while (!q.empty()) {
        auto it = q.front();
        int r= it.first;
        int c= it.second;
        q.pop();

        // Traverse 4 directions
        for (int i = 0; i < 4; i++) {
            int newr = r + dx[i];
            int newc = c + dy[i];

            // Check bounds and if cell is open and unvisited
            if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                grid[newr][newc] == 1 && dist[newr][newc] == -1) {
                
                dist[newr][newc] = dist[r][c] + 1;
                q.push({newr, newc});
            }
        }
    }

    return dist[destX][destY]; // -1 if not reachable
}

int main() {
    // Example binary maze
    vector<vector<int>> grid = {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 1, 1}
    };

    pair<int, int> source = {0, 0};      // Starting cell
    pair<int, int> destination = {3, 3}; // Target cell

    int result = shortestPathBinaryMaze(grid, source, destination);
    if (result != -1)
        cout << "Shortest path length is: " << result << endl;
    else
        cout << "Destination not reachable from source." << endl;

    return 0;
}
