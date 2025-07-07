// Partition a set into two subsets such that the absolute difference of their sums is minimized.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubsetSumDifference(vector<int>& nums) {
        int n = nums.size();
        int Tsum = 0;

        // Step 1: Compute total sum
        for (int i = 0; i < n; i++) Tsum += nums[i];

        int k = Tsum; // we want to check all subset sums up to Tsum

        // Step 2: Create DP table
        // dp[i][j] = true if we can form sum 'j' using first 'i+1' elements
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Step 3: Initialize base cases
        for (int i = 0; i < n; i++) dp[i][0] = true; // sum 0 is always possible

        if (nums[0] <= k) dp[0][nums[0]] = true; // only nums[0] can make that sum

        // Step 4: Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                bool notTake = dp[i - 1][j]; // exclude nums[i]
                bool take = false;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]]; // include nums[i]
                }
                dp[i][j] = take || notTake;
            }
        }

        // Step 5: Find minimum absolute difference between two subsets
        int minDiff = INT_MAX;

        // Only check sums from 0 to Tsum/2 to avoid duplicate checking
        for (int s1 = 0; s1 <= Tsum / 2; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = Tsum - s1;
                minDiff = min(minDiff, abs(s2 - s1));
            }
        }

        return minDiff;
    }
};

//  Test Driver
int main() {
    Solution obj;
    vector<int> nums = {1, 6, 11, 5}; // Expected output: 1
    cout << "Minimum Subset Sum Difference: " << obj.minSubsetSumDifference(nums) << endl;
    return 0;
}
