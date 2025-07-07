#include <bits/stdc++.h>
using namespace std;

    bool canPartition(vector<int>& nums) {
        int n = nums.size(); // size of the input array
        int Tsum = 0;

        // Step 1: Calculate the total sum of the array
        for (int i = 0; i < n; i++) Tsum += nums[i];

        // Step 2: If total sum is odd, we cannot split into two equal parts
        if (Tsum % 2 != 0) return false;

        int k = Tsum / 2; // required target sum for one subset

        // Step 3: Create DP table
        // dp[i][j] = true if we can form sum j using elements from 0 to i
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Step 4: Fill the DP table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {

                // Base Case 1: sum = 0 is always possible (by taking nothing)
                if (j == 0) {
                    dp[i][j] = true;
                    continue;
                }

                // Base Case 2: First element, only one way to make sum
                if (i == 0) {
                    dp[i][j] = (nums[0] == j);
                    continue;
                }

                // Recursive Case:
                // Not Take current element: check if sum j can be formed without nums[i]
                bool notTake = dp[i - 1][j];

                // Take current element: only if nums[i] <= j
                bool take = false;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }

                // Result is true if either take or notTake is true
                dp[i][j] = take || notTake;
            }
        }

        // Final answer: can we form sum = k using all n elements
        return dp[n - 1][k];
    }


int main()
{
    vector<int> v={1,2,3,4};
    if(canPartition(v))cout<<"YES";
    else cout<<"NO";

    return 0;
}
