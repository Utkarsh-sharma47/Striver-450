/*
You are given n items, each with a weight w[i] and a value v[i].
You have a knapsack with maximum weight capacity W.
You can either take or skip each item (you cannot take partial items).
Return the maximum total value you can carry in the knapsack.
*/

/*
WHY NOT GREEDY:
Because picking the item with the best value-to-weight 
ratio first doesn't always leave space for the best combination of items.
So, greedy makes short-sighted choices and misses the optimal solution.
*/

#include <bits/stdc++.h>
using namespace std;

class KnapsackSolver {
public:
//-------------------------------------------------------------------------

    // 1. Memoization (Top-down DP)
    // Recursive function with memoization (caching)
    int knapsackMemo(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
        // Base case: only one item (i=0)
        if (i == 0) {
            return (wt[0] <= W) ? val[0] : 0;
        }

        // Return cached result if already computed
        if (dp[i][W] != -1) return dp[i][W];

        // Option 1: do not take the current item
        int notTake = knapsackMemo(i - 1, W, wt, val, dp);

        // Option 2: take the current item (if weight allows)
        int take = INT_MIN;
        if (wt[i] <= W)
            take = val[i] + knapsackMemo(i - 1, W - wt[i], wt, val, dp);

        // Cache and return the best of the two options
        return dp[i][W] = max(take, notTake);
    }

//-------------------------------------------------------------------------

    // 2. Tabulation (Bottom-up DP)
    int knapsackTab(int n, int W, vector<int> &wt, vector<int> &val) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case: fill first row (only considering item 0)
        for (int w = wt[0]; w <= W; w++) {
            dp[0][w] = val[0];
        }

        // Fill the table row by row
        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= W; w++) {
                int notTake = dp[i - 1][w]; // skip current item
                int take = INT_MIN;

                // take current item if it fits
                if (wt[i] <= w)
                    take = val[i] + dp[i - 1][w - wt[i]];

                dp[i][w] = max(take, notTake); // best of both
            }
        }

        return dp[n - 1][W]; // final answer
    }

//-------------------------------------------------------------------------

    // 3. Space Optimized (using 2 rows instead of full 2D table)
    int knapsackSpaceOpt(int n, int W, vector<int> &wt, vector<int> &val) {
        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        // Initialize base case
        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }

        // Only keep previous and current row to save space
        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= W; w++) {
                int notTake = prev[w];
                int take = INT_MIN;
                if (wt[i] <= w)
                    take = val[i] + prev[w - wt[i]];
                curr[w] = max(take, notTake);
            }
            prev = curr; // update for next iteration
        }

        return prev[W];
    }

//----------------------------------------------------------------------------

    // 4. 1D Space Optimization (Best Space)
    int knapsack1D(int n, int W, vector<int> &wt, vector<int> &val) {
        vector<int> dp(W + 1, 0);

        // Initialize base case for item 0
        for (int w = wt[0]; w <= W; w++) {
            dp[w] = val[0];
        }

        // Traverse from item 1 to n-1
        for (int i = 1; i < n; i++) {
            // Traverse weights from right to left (important!)
            for (int w = W; w >= 0; w--) {
                if (wt[i] <= w) {
                    // Update dp[w] using previous values (not overwritten yet)
                    dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
                }
            }
        }

        return dp[W];
    }
};

//----------------------------------------------------------------------------

int main() {
    int n = 4;                      // Number of items
    int W = 7;                      // Maximum capacity of the knapsack
    vector<int> wt = {1, 3, 4, 5};  // Weights of items
    vector<int> val = {1, 4, 5, 7}; // Values of items

    KnapsackSolver solver;

    // Memoization
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << "Memoization: " << solver.knapsackMemo(n - 1, W, wt, val, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << solver.knapsackTab(n, W, wt, val) << endl;

    // Space Optimization (2 arrays)
    cout << "Space Optimized: " << solver.knapsackSpaceOpt(n, W, wt, val) << endl;

    // 1D Space Optimization (best space usage)
    cout << "1D Space Optimized: " << solver.knapsack1D(n, W, wt, val) << endl;

    return 0;
}
/*
Method	        Time Complexity	    Space Complexity
Memoization	    O(N × W)	        O(N × W) (due to recursion stack and DP table)
Tabulation	    O(N × W)	        O(N × W)
Space Opti  	O(N × W)	        O(2 × W) ≈ O(W)
1D Space Opti	O(N × W)	        O(W) (best)
*/