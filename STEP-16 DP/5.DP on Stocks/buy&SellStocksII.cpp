#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
// <------------------MEMOIZATION------------------>

int f(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
    // Base case: all days are processed
    if (i == prices.size()) return 0;

    if (dp[i][canBuy] != -1) return dp[i][canBuy];

    int profit = 0;
    if (canBuy) {
        int buy = -prices[i] + f(i + 1, 0, prices, dp);  // Buy and switch to sell mode
        int skip = f(i + 1, 1, prices, dp);              // Skip buying
        profit = max(buy, skip);
    } else {
        int sell = prices[i] + f(i + 1, 1, prices, dp);  // Sell and switch to buy mode
        int skip = f(i + 1, 0, prices, dp);              // Skip selling
        profit = max(sell, skip);
    }

    return dp[i][canBuy] = profit;
}

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1)); // dp[day][canBuy]
    return f(0, 1, prices, dp); // Start at day 0 with permission to buy
}

//////////////////////////////////////////////////////////////////////////
// <------------------TABULATION------------------>

int maxProfitTab(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[day][canBuy]

    for (int i = n - 1; i >= 0; --i) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            if (canBuy) {
                int buy = -prices[i] + dp[i + 1][0];  // Buy today
                int skip = dp[i + 1][1];              // Skip today
                dp[i][canBuy] = max(buy, skip);
            } else {
                int sell = prices[i] + dp[i + 1][1];  // Sell today
                int skip = dp[i + 1][0];              // Skip today
                dp[i][canBuy] = max(sell, skip);
            }
        }
    }

    return dp[0][1]; // Start at day 0 with permission to buy
}

//////////////////////////////////////////////////////////////////////////
// <------------------SPACE OPTIMIZATION------------------>

int maxProfitSpaceOptimized(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0); // ahead = dp[i+1], curr = dp[i]

    for (int i = n - 1; i >= 0; --i) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            if (canBuy) {
                int buy = -prices[i] + ahead[0];
                int skip = ahead[1];
                curr[canBuy] = max(buy, skip);
            } else {
                int sell = prices[i] + ahead[1];
                int skip = ahead[0];
                curr[canBuy] = max(sell, skip);
            }
        }
        ahead = curr; // Move to next day
    }

    return ahead[1]; // Start at day 0 with permission to buy
}

//////////////////////////////////////////////////////////////////////////
// <------------------MAIN FUNCTION------------------>

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit using Memoization: " << maxProfitMemo(prices) << endl;
    cout << "Maximum Profit using Tabulation: " << maxProfitTab(prices) << endl;
    cout << "Maximum Profit using Space Optimization: " << maxProfitSpaceOptimized(prices) << endl;

    return 0;
}
