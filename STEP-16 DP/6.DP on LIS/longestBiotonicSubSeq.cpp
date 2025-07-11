/*
Given an array arr[] of n elements, find the length of the longest subsequence
which is first strictly increasing, then strictly decreasing.
*/
#include <bits/stdc++.h>
using namespace std;

int LongestBitonicSubsequence(vector<int> &arr)
{
    int n = arr.size();
    vector<int> inc(n, 1); // LIS from left
    vector<int> dec(n, 1); // LDS from right

    // Compute LIS for each index
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && inc[i] < inc[j] + 1)
            {
                inc[i] = inc[j] + 1;
            }
        }
    }

    // Compute LDS for each index (from right)
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && dec[i] < dec[j] + 1)
            {
                dec[i] = dec[j] + 1;
            }
        }
    }

    // Find the max of (LIS[i] + LDS[i] - 1)
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, inc[i] + dec[i] - 1);
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << "Length of Longest Bitonic Subsequence = "
         << LongestBitonicSubsequence(arr) << endl;
    return 0;
}
