/*
You are given an integer array nums. You are initially positioned 
at the array's first index, and each element in the array represents 
your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise
*/

/*
APPROACH:-

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind = 0; // max index we can currently reach
        int i = 0;      // pointer to iterate through the array

        // Loop through the array until the end
        while (i < nums.size()) {
            if (i > maxind) {
                // If we ever reach an index we can't get to,
                // then we can't proceed further — return false
                return false;
            }

            // Update the maximum index we can reach from here
            // maxind is the farthest we can go from either:
            // - where we’ve already reached
            // - the current index + the jump we can make from here
            maxind = max(maxind, i + nums[i]);

            // Move to the next index
            i++;
        }

        // If we were able to process all elements, we can reach the end
        return true;
    }
};

// Test the function with some examples
int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Input: [2,3,1,1,4] → Output: " 
         << (solution.canJump(nums1) ? "true" : "false") << endl;
    // Explanation: Can jump 2 → then 3 → reach end

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Input: [3,2,1,0,4] → Output: " 
         << (solution.canJump(nums2) ? "true" : "false") << endl;
    // Explanation: Cannot pass the 0 at index 3

    vector<int> nums3 = {0};
    cout << "Input: [0] → Output: " 
         << (solution.canJump(nums3) ? "true" : "false") << endl;
    // Explanation: Already at the last index

    return 0;
}
