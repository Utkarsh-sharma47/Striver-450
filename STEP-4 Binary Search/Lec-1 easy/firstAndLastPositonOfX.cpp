/*

Q. Get first and last positoon of element "x" in sorted array

*/
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int x)
{
    int first = -1;
    int left = 0, right = nums.size() - 1;
    // find first
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == x)
        {
            first = mid;
            right = mid-1;
        }
        else if(nums[mid]>x)
        {
            left = mid+1;
        }
        else{
            right=mid-1;
        }
    }

    //find last
    int last=-1;
    left =0; right=nums.size()-1;
     while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == x)
        {
            last = mid;
            left = mid+1;
        }
        else if(nums[mid]>x)
        {
            left = mid+1;
        }
        else{
            right=mid-1;
        }
    }

    return{first , last};
}

int main()
{
    vector<int> v = {3, 4, 4, 4, 8, 10};
    vector<int> ans = searchRange(v, 4);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}