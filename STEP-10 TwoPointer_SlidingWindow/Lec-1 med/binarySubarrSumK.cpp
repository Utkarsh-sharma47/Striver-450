/*
Given a binary array nums and an integer goal, 
return the number of non-empty subarrays with a sum goal.

*/

/*
APPROACH:-
function(arr, goal) - function(arr, goal-1) = subarr with sum K
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Helper function: counts subarrays with sum <= goal
    int numSubarraysWithSumless(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // No subarray can have negative sum

        int cnt = 0, sum = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            // Shrink the window until sum <= goal
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            cnt += (r - l + 1); // Number of valid subarrays ending at r
        }

        return cnt;
    }

    // Main function: counts subarrays with sum == goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Count of subarrays with sum == goal
        return numSubarraysWithSumless(nums, goal) - numSubarraysWithSumless(nums, goal - 1);
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Number of subarrays with sum " << goal << " is: " 
         << sol.numSubarraysWithSum(nums, goal) << endl;

    return 0;
}
