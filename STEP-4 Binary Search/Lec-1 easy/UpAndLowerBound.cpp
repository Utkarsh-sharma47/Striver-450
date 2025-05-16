#include <bits/stdc++.h>
using namespace std;
//LOWER_BOUND:: smallest element greater or equal to x in sorted array
int lowerBound(vector<int> &nums, int x){
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // index of the first element >= x
}

// Returns the index of the first element > x
int upperBound(vector<int> &nums, int x){
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left; // index of the first element > x
}

int main()
{
  //vector<int> v={1,2,2,3};
  vector<int> v={3,5,8,15,19};
  cout<<v[lowerBound(v, 9)];
  


  return 0;
}