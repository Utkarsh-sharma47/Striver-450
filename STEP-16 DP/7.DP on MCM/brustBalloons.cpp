#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // -------------------- Memoization --------------------
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;
        for (int k = i; k <= j; k++)
        {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + f(i, k - 1, nums, dp) + f(k + 1, j, nums, dp);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }

    int maxCoinsMemo(vector<int> nums)
    {
        int n = nums.size();

        // Padding 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j] stores max coins for subarray [i..j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return f(1, n, nums, dp);
    }

    // -------------------- Tabulation --------------------
    int maxCoinsTab(vector<int> nums)
    {
        int n = nums.size();

        // Padding 1 at both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[i][j] stores max coins for subarray [i..j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Build bottom-up from length 1 to n
        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                int maxi = 0;

                for (int k = i; k <= j; k++)
                {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];

                    maxi = max(maxi, coins);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};

int main()
{
    Solution s;

    vector<int> nums = {3, 1, 5};

    // Using Memoization
    int memoResult = s.maxCoinsMemo(nums);
    cout << "Max Coins (Memoization): " << memoResult << endl;

    // Using Tabulation
    int tabResult = s.maxCoinsTab(nums);
    cout << "Max Coins (Tabulation): " << tabResult << endl;

    return 0;
}
