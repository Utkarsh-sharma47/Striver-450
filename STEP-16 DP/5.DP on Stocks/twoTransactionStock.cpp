#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
// <------------------MEMOIZATION------------------>

int f(int i, int canBuy, int transactionsLeft, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (i == prices.size() || transactionsLeft == 0)
        return 0;

    if (dp[i][canBuy][transactionsLeft] != -1)
        return dp[i][canBuy][transactionsLeft];

    int profit = 0;
    if (canBuy)
    {
        int buy = -prices[i] + f(i + 1, 0, transactionsLeft, prices, dp); // Buy
        int skip = f(i + 1, 1, transactionsLeft, prices, dp);             // Skip
        profit = max(buy, skip);
    }
    else
    {
        int sell = prices[i] + f(i + 1, 1, transactionsLeft - 1, prices, dp); // Sell and reduce transaction count
        int skip = f(i + 1, 0, transactionsLeft, prices, dp);                 // Skip
        profit = max(sell, skip);
    }

    return dp[i][canBuy][transactionsLeft] = profit;
}

int maxProfitMemo(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, dp); // Start from day 0, canBuy = 1, 2 transactions allowed
}

//////////////////////////////////////////////////////////////////////////
// <------------------TABULATION------------------>

int maxProfitTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int canBuy = 0; canBuy <= 1; ++canBuy)
        {
            for (int transactionsLeft = 1; transactionsLeft <= 2; ++transactionsLeft)
            {
                if (canBuy)
                {
                    int buy = -prices[i] + dp[i + 1][0][transactionsLeft];
                    int skip = dp[i + 1][1][transactionsLeft];
                    dp[i][canBuy][transactionsLeft] = max(buy, skip);
                }
                else
                {
                    int sell = prices[i] + dp[i + 1][1][transactionsLeft - 1];
                    int skip = dp[i + 1][0][transactionsLeft];
                    dp[i][canBuy][transactionsLeft] = max(sell, skip);
                }
            }
        }
    }

    return dp[0][1][2]; // Start from day 0, canBuy = 1, 2 transactions allowed
}

//////////////////////////////////////////////////////////////////////////
// <------------------SPACE OPTIMIZATION------------------>

int maxProfitSpaceOptimized(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)); // dp[i+1]
    vector<vector<int>> curr(2, vector<int>(3, 0));  // dp[i]

    for (int i = n - 1; i >= 0; --i)
    {
        for (int canBuy = 0; canBuy <= 1; ++canBuy)
        {
            for (int transactionsLeft = 1; transactionsLeft <= 2; ++transactionsLeft)
            {
                if (canBuy)
                {
                    int buy = -prices[i] + ahead[0][transactionsLeft];
                    int skip = ahead[1][transactionsLeft];
                    curr[canBuy][transactionsLeft] = max(buy, skip);
                }
                else
                {
                    int sell = prices[i] + ahead[1][transactionsLeft - 1];
                    int skip = ahead[0][transactionsLeft];
                    curr[canBuy][transactionsLeft] = max(sell, skip);
                }
            }
        }
        ahead = curr; // move current to ahead
    }

    return ahead[1][2]; // Start at day 0, canBuy = 1, 2 transactions allowed
}

//////////////////////////////////////////////////////////////////////////
// <------------------MAIN FUNCTION------------------>

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << "Maximum Profit with 2 Transactions (Memoization): " << maxProfitMemo(prices) << endl;
    cout << "Maximum Profit with 2 Transactions (Tabulation): " << maxProfitTab(prices) << endl;
    cout << "Maximum Profit with 2 Transactions (Space Optimized): " << maxProfitSpaceOptimized(prices) << endl;

    return 0;
}
