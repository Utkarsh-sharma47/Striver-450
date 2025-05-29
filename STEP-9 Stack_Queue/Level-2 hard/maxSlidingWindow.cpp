#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Stores indices

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements smaller than current from back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Add current element's index
            dq.push_back(i);

            // Remove front element if it's outside the window
            if (dq.front() <= i - k)
                dq.pop_front();

            // Record the max value for this window
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

// Main function to test
int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Max of each sliding window: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
