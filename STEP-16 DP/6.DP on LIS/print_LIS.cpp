#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to reconstruct and return the LIS
vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();

    // Stores indices of smallest tail of all increasing subsequences of length i+1
    vector<int> tempIndices;

    // Stores the index of the previous element in the LIS for each element
    vector<int> prevIndex(n, -1);

    // For tracking where each element is placed in LIS
    vector<int> lisIndex;

    for (int i = 0; i < n; ++i) {
        int num = nums[i];

        // Find the index where 'num' can be placed (first element >= num)
        auto it = lower_bound(tempIndices.begin(), tempIndices.end(), num,
            [&](int index, int val) {
                return nums[index] < val;
            });

        int pos = it - tempIndices.begin();

        // If num extends the LIS
        if (it == tempIndices.end()) {
            tempIndices.push_back(i);
        } else {
            tempIndices[pos] = i;
        }

        // Set the previous index for reconstruction
        if (pos != 0) {
            prevIndex[i] = tempIndices[pos - 1];
        }
    }

    // Reconstruct the LIS using prevIndex
    vector<int> lis;
    int lastIndex = tempIndices.back(); // Index of last element in LIS

    while (lastIndex != -1) {
        lis.push_back(nums[lastIndex]);
        lastIndex = prevIndex[lastIndex];
    }

    // Currently LIS is in reverse order, so reverse it
    reverse(lis.begin(), lis.end());

    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    vector<int> lis = getLIS(nums);

    cout << "Longest Increasing Subsequence: ";
    for (int x : lis) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Length of LIS: " << lis.size() << endl;

    return 0;
}
