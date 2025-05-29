#include <iostream>               // For input and output
#include <vector>                 // For using vectors
#include <string>                 // For using strings

using namespace std;

class Solution {
public:
    // Function to check if it's safe to place a queen at board[row][col]
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check all rows above in the same column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        // All checks passed, position is safe
        return true;
    }

    // Backtracking function to solve the N-Queens problem
    void solve(int row, vector<string>& board, vector<vector<string>>& result, int n) {
        // If all rows are filled, add the current board to result
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            // Check if placing a queen at (row, col) is safe
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';        // Place the queen
                solve(row + 1, board, result, n); // Recurse for the next row
                board[row][col] = '.';        // Backtrack: remove the queen
            }
        }
    }

    // Main function to be called to solve N-Queens
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;        // To store all valid board configurations
        vector<string> board(n, string(n, '.')); // Initialize empty board with '.'
        solve(0, board, result, n);           // Start solving from the first row
        return result;                        // Return all the valid solutions
    }
};

// Main function to test the solution
int main() {
    int n;
    cout << "Enter number of queens (n): ";
    cin >> n;                                 // Take user input for board size

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n); // Solve the problem

    cout << "\nTotal solutions: " << solutions.size() << "\n\n";

    // Print each solution
    for (auto& solution : solutions) {
        for (string& row : solution)
            cout << row << "\n";              // Print each row of the solution
        cout << "\n";                         // Separate each solution
    }

    return 0;
}
