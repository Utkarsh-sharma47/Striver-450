/*
Given a binary array nums and an integer k,
return the maximum number of consecutive 1's in the array
if you can flip at most k 0's.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
we need largest string with k zeroes at max

if(zerocount>k)
we will increase the "l" and dont let the length exceed maxlen
if arr[l] is zero so dec the zero count
and inc l
*/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxlen = 0, l = 0, z = 0;

        for (int r = 0; r < nums.size(); r++)
        {
            if (nums[r] == 0)
                z++;

            // while (z > k) {
            //     if (nums[l] == 0) z--;
            //     l++;
            // }
            // loop can be replaced
            if (z > k)
            {
                if (nums[r] == 0)
                    z--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int k, n, val;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements (0 or 1): ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        nums.push_back(val);
    }

    cout << "Enter the maximum number of 0s that can be flipped: ";
    cin >> k;

    int result = sol.longestOnes(nums, k);
    cout << "Maximum length of consecutive 1s after flipping at most " << k << " zeros: " << result << endl;

    return 0;
}
