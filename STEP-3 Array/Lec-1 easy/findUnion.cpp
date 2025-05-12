#include <bits/stdc++.h>
using namespace std;
/*
using TWO POINTER approach
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m)
    {
        // Skip duplicates in result
        //since only repeated elements can be inserted multiple times
        if (!result.empty() && result.back() == nums1[i]) {
            i++;
            continue;
        }
        if (!result.empty() && result.back() == nums2[j]) {
            j++;
            continue;
        }

        if (nums1[i] < nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            result.push_back(nums2[j]);
            j++;
        }
        else // nums1[i] == nums2[j]
        {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
    }

    // Process remaining elements in nums1
    while (i < n)
    {
        if (result.empty() || result.back() != nums1[i])
            result.push_back(nums1[i]);
        i++;
    }

    // Process remaining elements in nums2
    while (j < m)
    {
        if (result.empty() || result.back() != nums2[j])
            result.push_back(nums2[j]);
        j++;
    }

    // Print union
    for (int val : result)
        cout << val << "  ";
    cout << endl;

    return result;
}


vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i != nums1.size() && j != nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            v.push_back(nums1[i]);
            i++;
            j++;
        }

        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    // print union
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    return v;
}

int main()
{
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(5);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(8);

    // intersectoinArray(v1,v2);
    unionArray(v1, v2);

    return 0;
}