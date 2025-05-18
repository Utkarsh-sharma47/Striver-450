#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int missing = arr[mid] - (mid + 1); // How many numbers are missing up to this index

        if (missing < k)
        {
            left = mid + 1; // Move right to find more missing numbers
        }
        else
        {
            right = mid - 1; // We have enough missing numbers before mid
        }
    }

    return left + k;
}

int main()
{
    vector<int> v = {2, 3, 4, 7, 11};
    cout << findKthPositive(v, 5) << endl; // Output: 9
    return 0;
}
