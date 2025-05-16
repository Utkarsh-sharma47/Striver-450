#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}

int main() {
    vector<int> v = {5, 6, 7, 1, 2, 3, 4};
    cout << findMin(v) << endl; // Add endl to avoid terminal garbage
    return 0;
}

