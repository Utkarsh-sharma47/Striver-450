#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        // Step 1: XOR of all elements gives a ^ b (a and b are unique)
        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
        }

        // Step 2: Find rightmost set bit in x (where a and b differ)
        int setbit = x & (-x);

        // Step 3: Divide elements into two groups and XOR separately
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & setbit) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }

        return {a, b}; // two unique numbers
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 2, 1, 4}; // 3 and 4 appear once
    vector<int> result = sol.singleNumber(nums);

    cout << "The two unique numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
