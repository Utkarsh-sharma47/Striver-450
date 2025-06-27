/*
You are given an m x n matrix board containing letters 'X' and 'O', 
capture regions that are surrounded:

-Connect:  A cell is connected to adjacent cells horizontally or vertically.
-Region:   To form a region connect every 'O' cell.
-Surround: The region is surrounded with 'X' cells if you can connect the region 
           with 'X' cells and none of the region cells are on the edge of board.

-To capture a surrounded region, replace all 'O's with 'X's in-place 
within the original board. You do not need to return anything.

 
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Depth-First Search function to mark safe 'O's connected to the boundary
    void DFS(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis) {
        int R = board.size();        // Total rows
        int C = board[0].size();     // Total columns
        vis[r][c] = 1;               // Mark current cell as visited

        // Directions: up, down, left, right
        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, -1, 1};

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dirX[i];  // new row
            int nc = c + dirY[i];  // new col

            // Check if the new cell is within bounds and is unvisited 'O'
            if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                board[nr][nc] == 'O' && !vis[nr][nc]) {
                DFS(nr, nc, board, vis);  // Continue DFS
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int R = board.size();         // Get number of rows
        if (R == 0) return;           // Empty board check
        int C = board[0].size();      // Get number of columns

        // Create visited matrix initialized to 0 (unvisited)
        vector<vector<int>> vis(R, vector<int>(C, 0));

        // Traverse the first row and last row
        for (int i = 0; i < C; i++) {
            if (board[0][i] == 'O') {
                DFS(0, i, board, vis);       // First row
            }
            if (board[R - 1][i] == 'O') {
                DFS(R - 1, i, board, vis);   // Last row
            }
        }

        // Traverse the first column and last column
        for (int i = 0; i < R; i++) {
            if (board[i][0] == 'O') {
                DFS(i, 0, board, vis);       // First column
            }
            if (board[i][C - 1] == 'O') {
                DFS(i, C - 1, board, vis);   // Last column
            }
        }

        // Now convert all unvisited 'O's to 'X' (they are surrounded)
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';  // Convert to 'X'
                }
            }
        }

        // No need to return anything since board is modified in place
    }
};

// Optional: Function to print the board
void printBoard(vector<vector<char>>& board) {
    for (auto row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
}

// Example usage
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Before solve:\n";
    printBoard(board);

    sol.solve(board);

    cout << "\nAfter solve:\n";
    printBoard(board);

    return 0;
}
