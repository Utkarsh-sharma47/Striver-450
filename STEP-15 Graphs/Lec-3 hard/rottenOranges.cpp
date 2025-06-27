/*
You are given an m x n grid where each cell can have one of three no.
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent 
to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell
 has a fresh orange.
If this is impossible, return -1.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();             // rows
        int m = grid[0].size();          // columns

        vector<vector<int>> vis(n, vector<int>(m, 0));  // visited matrix
        queue<pair<pair<int, int>, int>> q;             // ((row,col), time)
        int freshcnt = 0;              // count of fresh oranges
        int maxtime = 0;               // to track max time taken

        // Step 1: Initialize queue with all rotten oranges and count fresh ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 2;             // mark rotten
                    q.push({{i, j}, 0});       // add to queue with time 0
                } else if (grid[i][j] == 1) {
                    freshcnt++;                // count fresh oranges
                }
            }
        }

        // Direction arrays: up, down, left, right
        int dirX[4] = {-1, 1, 0, 0};
        int dirY[4] = {0, 0, -1, 1};

        // Step 2: BFS traversal
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            maxtime = max(maxtime, time);  // track max time

            for (int k = 0; k < 4; k++) {
                int nextrow = row + dirX[k];
                int nextcol = col + dirY[k];

                // Validity checks
                if (nextrow >= 0 && nextrow < n && nextcol >= 0 && nextcol < m) {
                    // If it's a fresh orange and unvisited
                    if (grid[nextrow][nextcol] == 1 && vis[nextrow][nextcol] == 0) {
                        vis[nextrow][nextcol] = 2;  // mark it rotten
                        q.push({{nextrow, nextcol}, time + 1});
                        freshcnt--;                // decrease fresh count
                    }
                }
            }
        }

        // Step 3: If some fresh oranges are left
        if (freshcnt != 0) return -1;

        return maxtime;
    }
};

// Test in main()
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution s;
    int result = s.orangesRotting(grid);

    if (result == -1)
        cout << "Not all oranges can rot." << endl;
    else
        cout << "Minimum time to rot all oranges: " << result << " minute(s)" << endl;

    return 0;
}
