#include <bits/stdc++.h>
using namespace std;

/*
    Function to search for a target in a rotated sorted array.
    Time Complexity: O(log n)
    Space Complexity: O(1)
*/
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) // ✅ Use <= to include right edge
    {
        int mid = left + (right - left) / 2;

        // If mid element is the target
        if (nums[mid] == target)
            return mid;

        // Check if the left half is sorted
        if (nums[left] <= nums[mid])
        {
            // Check if target lies in the left half
            if (target >= nums[left] && target < nums[mid])
            {
                right = mid - 1;
            }
            else // Search in right half
            {
                left = mid + 1;
            }
        }
        else // Right half is sorted
        {
            // Check if target lies in the right half
            if (target > nums[mid] && target <= nums[right])
            {
                left = mid + 1;
            }
            else // Search in left half
            {
                right = mid - 1;
            }
        }
    }

    // If target is not found
    return -1;
}

int main()
{
    vector<int> v = {3, 4, 0, 1, 2};
    cout << search(v, 0); // Output: 2
    return 0;
}
