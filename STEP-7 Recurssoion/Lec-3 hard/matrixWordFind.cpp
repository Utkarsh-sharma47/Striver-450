/*
Given an m x n grid of characters board and a string word, 
return true if word exists in the grid.

The word can be constructed from letters of sequentially 
adjacent cells, where adjacent cells are horizontally or vertically
 neighboring. The same letter cell may not be used more than once.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        if (idx == word.size()) return true; // Word matched
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited

        bool found = dfs(board, i + 1, j, word, idx + 1) ||
                     dfs(board, i - 1, j, word, idx + 1) ||
                     dfs(board, i, j + 1, word, idx + 1) ||
                     dfs(board, i, j - 1, word, idx + 1);

        board[i][j] = temp; // Backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word, 0))
                    return true;
        return false;
    }
};

/*
STEPS:
1. for every char in matrix call a function
2. FUNCTION:-
- check if any index is out of vound or char is not matching = return false
- mark that particular char of matrix as "#"
-- traverse in all four direction and 
    if: any direction gives full word=true
    else: make that word back to its orginal form '#' then return false 
*/

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word;
    cout << "Enter the word to search: ";
    cin >> word;

    Solution sol;
    bool result = sol.exist(board, word);

    if (result)
        cout << "The word \"" << word << "\" exists in the board." << endl;
    else
        cout << "The word \"" << word << "\" does NOT exist in the board." << endl;

    return 0;
}
