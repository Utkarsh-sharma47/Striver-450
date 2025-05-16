#include <bits/stdc++.h>
using namespace std;

/*
    There is an integer array nums sorted in non-decreasing order
     (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown
 pivot index k (0 <= k < nums.length) such that the resulting array is
  [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
  (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at
  pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target,
return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

*/

bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Found the target
            if (nums[mid] == target) return true;

            // Duplicate check: skip if left, mid, and right are equal (for duplicates case)
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }

int main()
{
    vector<int> v = {2,5,6,0,0,1,2};
    bool b= search(v, 0); // Output: true
    if(b) cout<<"TRUE";
    else cout<<"false";
    return 0;
}
