#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// <----------------------------MEMOIZATION---------------------------->
// Helper function for memoization approach
int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
    // Base case: If we reached end of array, return 0
    if (ind == nums.size()) return 0;

    // If already computed, return the stored value
    if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

    // Not take the current element
    int len = f(ind + 1, prev, nums, dp);

    // Take the current element if it’s strictly increasing
    if (prev == -1 || nums[ind] > nums[prev]) {
        len = max(len, 1 + f(ind + 1, ind, nums, dp));
    }

    return dp[ind][prev + 1] = len;
}

// Main function for memoization
int memoizationLIS(vector<int>& nums) {
    int n = nums.size();

    // dp[ind][prev+1] where prev = -1 to n-1, so size is (n x n+1)
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return f(0, -1, nums, dp);
}

// <----------------------------TABULATION---------------------------->
int tabulationLIS(vector<int>& nums) {
    int n = nums.size();

    // dp[i] will store the LIS ending at index i
    vector<int> dp(n, 1);  // Every element is at least a subsequence of length 1

    // Build the dp array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If nums[j] < nums[i], then we can extend the subsequence ending at j
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // The maximum value in dp array is the answer
    return *max_element(dp.begin(), dp.end());
}

// <------------------MAIN FUNCTION------------------>
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Call memoization version
    cout << "Length of LIS using Memoization: " << memoizationLIS(nums) << endl;

    // Call tabulation version
    cout << "Length of LIS using Tabulation: " << tabulationLIS(nums) << endl;

    return 0;
}
