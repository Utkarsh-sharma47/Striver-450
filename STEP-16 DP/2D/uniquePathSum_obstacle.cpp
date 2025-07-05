#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        // Check boundaries and obstacles
        if (i < 0 || j < 0)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0; // Blocked cell
        if (i == 0 && j == 0)
            return 1; // Reached the starting point

        // If already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursively count paths from top and left
        int up = helper(i - 1, j, obstacleGrid, dp);
        int left = helper(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1)); // dp[i][j] = number of paths to reach (i,j)
        return helper(m - 1, n - 1, obstacleGrid, dp);
    }
    // TABLUATION
    //-----------------------------------------------------------------------------------------------
    int uniquePathsWithObstacles_TAB(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp[i][j] = number of paths to reach (i,j)

        // Base case: if starting cell is not blocked
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;

        // Fill the DP table
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // Skip the starting cell or obstacle
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0; // Blocked cell
                }
                else
                {
                    int up = (i > 0) ? dp[i - 1][j] : 0;   // From top
                    int left = (j > 0) ? dp[i][j - 1] : 0; // From left
                    dp[i][j] = up + left;                  // Total paths
                }
            }
        }

        return dp[m - 1][n - 1]; // Destination
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    cout << "Unique Paths (with obstacles) Memorization: " << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << "Unique Paths (with obstacles) Tabulation: " << sol.uniquePathsWithObstacles_TAB(obstacleGrid) << endl;
    return 0;
}
