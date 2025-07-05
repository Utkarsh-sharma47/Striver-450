#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); // Total number of houses

        // Base case: if there's only one house, rob it
        if (n == 1) return nums[0];

        // Create a dp array of size n to store max money at each house
        vector<int> dp(n, 0);

        dp[0] = nums[0]; // Only one choice: rob the first house
        dp[1] = max(nums[0], nums[1]); // Either rob the first or second, whichever has more money

        // Fill the dp array using bottom-up approach
        for (int i = 2; i < n; i++) {
            // Option 1: Rob current house and add money from i-2 (non-adjacent)
            int pick = nums[i] + dp[i - 2];

            // Option 2: Don't rob current house, take max till previous house
            int notPick = dp[i - 1];

            // Store the maximum of both choices
            dp[i] = max(pick, notPick);
        }

        // The last element holds the max amount of money that can be robbed
        return dp[n - 1];
    }
};

// Main function to test the solution
int main() {
    Solution sol;
    vector<int> houses = {2, 7, 9, 3, 1};

    int maxMoney = sol.rob(houses);
    cout << "Maximum money that can be robbed: " << maxMoney << endl;

    return 0;
}
