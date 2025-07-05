#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function with memoization
    int minSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // If out of bounds
        if (i < 0 || j < 0)
            return INT_MAX;
        // Base case: start cell
        if (i == 0 && j == 0)
            return grid[0][0];

        // If already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Move from top and left
        int fromTop = minSum(i - 1, j, grid, dp);
        int fromLeft = minSum(i, j - 1, grid, dp);

        // Add current cell value and take minimum
        return dp[i][j] = grid[i][j] + min(fromTop, fromLeft);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minSum(m - 1, n - 1, grid, dp);
    }

    // TABULATION
    //--------------------------------------------------------------------------------------------
    int minPathSum_TAB(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j] = min path sum to reach (i,j)

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j]; // start cell
                }
                else
                {
                    int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1]; // destination
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    cout << "Minimum Path Sum Memorizatoin: " << sol.minPathSum(grid) << endl;
    cout << "Minimum Path Sum Tabulation: " << sol.minPathSum_TAB(grid) << endl;
    return 0;
}
