#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFallingPathSum_TAB(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Square matrix size

        // Step 1: Create a DP table same size as matrix
        vector<vector<int>> dp = matrix; // First row is same as input

        // Step 2: Start filling from second row to last row
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Initialize possible path values to INT_MIN (for max comparison)
                int up = dp[i - 1][j]; // directly above
                int leftDiag = (j > 0) ? dp[i - 1][j - 1] : INT_MIN; // top-left
                int rightDiag = (j < n - 1) ? dp[i - 1][j + 1] : INT_MIN; // top-right

                // Step 3: Current cell = value + max of 3 possible paths above
                dp[i][j] = matrix[i][j] + max({up, leftDiag, rightDiag});
            }
        }

        // Step 4: Final answer is max in the last row
        int maxSum = INT_MIN;
        for (int j = 0; j < n; ++j) {
            maxSum = max(maxSum, dp[n - 1][j]);
        }

        return maxSum;
    }
    //MEORIZATION
//-------------------------------------------------------------------------------------
    int maxFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // Start with first row same as matrix

        // Fill the DP table from second row onwards
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = dp[i - 1][j]; // directly above
                int leftDiag = (j > 0) ? dp[i - 1][j - 1] : INT_MIN;
                int rightDiag = (j < n - 1) ? dp[i - 1][j + 1] : INT_MIN;

                dp[i][j] = matrix[i][j] + max({up, leftDiag, rightDiag});
            }
        }

        // Find max in last row
        int maxSum = INT_MIN;
        for (int j = 0; j < n; ++j) {
            maxSum = max(maxSum, dp[n - 1][j]);
        }

        return maxSum;
    }
};

// Example usage
int main() {
    Solution sol;

    // Test input
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    // Output the result
    cout << "Maximum Falling Path Sum TAB: " << sol.maxFallingPathSum_TAB(matrix) << endl;
    cout << "Maximum Falling Path Sum MEMO: " << sol.maxFallingPathSum(matrix) << endl;
    return 0;
}
