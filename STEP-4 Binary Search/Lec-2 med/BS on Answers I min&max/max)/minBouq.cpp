#include <bits/stdc++.h>
using namespace std;

int bouqMade(vector<int> v, int mid, int k)
{
    int count = 0, b = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= mid)
        {
            count++;
            if (count == k)
            {
                b++;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    return b;
}
int minDays(vector<int> &v, int m, int k)
{
    int left = *min_element(v.begin(), v.end());
    int right = *max_element(v.begin(), v.end());
    int minD = INT_MAX;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int fb = bouqMade(v, mid, k);

        if (fb < m) // need more days
        {
            left = mid + 1;
        }
        else
        { // lets dec the days
            minD = min(minD, mid);
            right = mid - 1;
        }
    }
    if (minD != INT_MAX)
        return minD;
    else
        return -1;
}

int main()
{
    vector<int> v = {7,7,7,7,13,11,12,7};
    cout<<minDays(v,2,3);

    

    return 0;
}