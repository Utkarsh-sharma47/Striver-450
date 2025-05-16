/*
Q. Given a sorted array nums and an integer x.
 Find the floor and ceil of x in nums.
 -The floor of x is the largest element in the array which is
 smaller than or equal to x.
 -The ceiling of x is the smallest element in the array
 greater than or equal to x.
 If no floor or ceil exists, output -1.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x)
{
    sort(nums.begin(), nums.end()); // Make sure the array is sorted
    int left = 0, right = nums.size() - 1;
    int floor = -1, ceil = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == x)
        {
            floor = nums[mid];
            ceil = nums[mid];
            break;
        }
        else if (nums[mid] < x)
        {
            floor = nums[mid];
            left = mid + 1;
        }
        else
        {
            ceil = nums[mid];
            right = mid - 1;
        }
    }

    return {floor, ceil};
}


int main()
{
    vector<int> v = {3, 4, 4, 7, 8, 10};
    vector<int> ans = getFloorAndCeil(v, 5);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}