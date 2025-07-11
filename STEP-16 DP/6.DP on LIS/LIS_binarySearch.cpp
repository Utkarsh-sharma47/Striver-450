#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

// Function to compute length of Longest Increasing Subsequence using binary search with lower_bound
int lengthOfLIS(vector<int>& nums) {
    vector<int> temp; // This will store the current smallest last elements of increasing subsequences

    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i]; // current element in the array

        // Use lower_bound to find the index of the smallest element >= num
        // This helps maintain sorted order of temp
        auto it = lower_bound(temp.begin(), temp.end(), num);

        if (it == temp.end()) {
            // If num is greater than all elements in temp, add it to the end
            temp.push_back(num);
        } else {
            // Otherwise, replace the first element >= num to maintain the smallest possible tail value
            *it = num;
        }

        // Debug: Print temp after every iteration (optional)
        // for (int x : temp) cout << x << " ";
        // cout << endl;
    }

    // The size of temp is the length of the longest increasing subsequence
    return temp.size();
}

// Main function to test the LIS code
int main() {
    // Example input
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Get the length of LIS
    int result = lengthOfLIS(nums);

    // Print the result
    cout << "Length of Longest Increasing Subsequence is: " << result << endl;

    return 0;
}
