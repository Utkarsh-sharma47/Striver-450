#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1);    // dp[i]: length of LIS ending at i
    vector<int> count(n, 1); // count[i]: number of LIS ending at i

    int maxLen = 1; // To keep track of max LIS length

    // Traverse all elements
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // If nums[i] can extend the LIS ending at nums[j]
            if (nums[i] > nums[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    // Found a longer sequence ending at i
                    dp[i] = dp[j] + 1;
                    count[i] = count[j]; // Start new count
                }
                else if (dp[j] + 1 == dp[i])
                {
                    // Found another way to make same length LIS
                    count[i] += count[j];
                }
            }
        }
        maxLen = max(maxLen, dp[i]); // Update maxLen if needed
    }

    // Count total number of subsequences with length == maxLen
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
        {
            result += count[i];
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << "Number of Longest Increasing Subsequences: "
         << findNumberOfLIS(nums) << endl;
    return 0;
}
