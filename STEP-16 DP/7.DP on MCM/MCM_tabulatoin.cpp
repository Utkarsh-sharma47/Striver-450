/*TAB
Given array of size 'N' which represent dimensoins of 'N-1' matrices.
find minimum cost to multiply all matrices
(cost = number of operations)
*/

#include <bits/stdc++.h>
using namespace std;

// Tabulation method to calculate MCM
int MCM_Tab(vector<int> &arr)
{
    int n = arr.size();

    // dp[i][j] will store the min cost of multiplying matrices i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill dp table using bottom-up approach
    // Length of matrix chain (l)
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try all positions to place parenthesis
            for (int k = i; k < j; k++)
            {
                // cost = left + right + cost of multiplying result matrices
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1]; // Final answer
}

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30}; // Matrix dimensions: 40x20, 20x30, 30x10, 10x30

    cout << "Minimum cost (Tabulation): " << MCM_Tab(arr) << endl;

    return 0;
}
