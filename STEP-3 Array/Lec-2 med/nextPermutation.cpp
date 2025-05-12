#include <bits/stdc++.h>
using namespace std;

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int bp = -1;

        // Step 1: Find the first index from the right where nums[i] < nums[i+1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                bp = i;
                break;
            }
        }

        /* If no such breakpoint is found, reverse the entire array, means already last 
            permuatation diya tha , ab first pr aa jao by reversing it
        */
        if (bp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the next greater element to the right of bp
        for (int i = n - 1; i > bp; i--) {
            if (nums[i] > nums[bp]) {
                swap(nums[i], nums[bp]);
                break;
            }
        }

        // Step 3: sort the part after "bp"
        sort(nums.begin() + bp + 1, nums.end());
    }

int main()
{
  vector<int> v = {1, 2, -3, -1, -2,3};
  nextPermutation(v);
  for(int i=0; i<v.size(); i++)
  {
    cout<<v[i]<<" ";
  }

  return 0;
}