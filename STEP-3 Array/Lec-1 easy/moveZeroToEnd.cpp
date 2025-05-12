#include <bits/stdc++.h>
using namespace std;
/*
using TWO POINTER approach
*/

    void moveZeroes(vector<int>& nums)
{
    int pos = 0; // position to place next non-zero

    // First pass: move all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[pos++] = nums[i];
        }
    }

    // Second pass: fill remaining elements with 0
    for (int i = pos; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(3);
    v.push_back(0);
    v.push_back(4);

    moveZeroes(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }

    return 0;
}