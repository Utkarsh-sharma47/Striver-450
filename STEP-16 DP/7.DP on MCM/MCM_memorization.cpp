/*MEMO
Given array of size 'N' which represent dimensoins of 'N-1' matrices.
find minimum cost to multiply all matrices
(cost = number of operations)
*/

#include <bits/stdc++.h>
using namespace std;

// Function to recursively find the minimum cost to multiply matrices from i to j
int MCM_Memo(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    // Base case: single matrix, no cost
    if (i == j)
        return 0;

    // If already calculated, return stored value
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // Try all possible positions to split the product
    for (int k = i; k < j; k++)
    {
        // Cost = cost of multiplying left part + right part + cost of multiplying resulting two matrices
        int cost = MCM_Memo(i, k, arr, dp) +
                   MCM_Memo(k + 1, j, arr, dp) +
                   arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, cost); // Take the minimum
    }

    // Store and return
    return dp[i][j] = mini;
}

int main()
{
    vector<int> arr = {40, 20, 30, 10, 30}; // Matrix dimensions: 40x20, 20x30, 30x10, 10x30
    int n = arr.size();

    // Initialize dp table with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // Call memoization function from 1 to n-1 (matrix positions)
    cout << "Minimum cost (Memoization): " << MCM_Memo(1, n - 1, arr, dp) << endl;

    return 0;
}
