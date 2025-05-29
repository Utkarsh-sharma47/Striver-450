#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse the array twice (simulate circular array)
        for (int i = 2 * n - 1; i >= 0; --i) {
            int idx = i % n;

            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[idx] = st.top();
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};

// Test the function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> res = sol.nextGreaterElements(nums);

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
