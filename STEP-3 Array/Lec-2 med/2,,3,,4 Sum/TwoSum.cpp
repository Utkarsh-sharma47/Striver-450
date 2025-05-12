#include <bits/stdc++.h>
using namespace std;

/*
using Hashing: we will use MAP - 'element' (key) and 'index' (value),
then we iterate through each element then search for "X-arr[i]"

*/

 vector<int> twoSumV(vector<int>& nums, int target) {
        vector <int> v;
        sort(nums.begin(), nums.end());
        int i=0, j=nums.size()-1;
        while(i<j)
        {
            int sum = nums[i]+nums[j];
            if(sum==target)
            {
                v.push_back(i);
                v.push_back(j);
                break;
            }
            else if(sum>target) j--;
            else i++;
        }

        return v;
        
    }


void twoSum(int arr[], int n, int x, unordered_map<int,int>m)
{
    bool b = false;
    for(int i=0; i<n; i++)
    {
        if(m.find(x-arr[i])!=m.end())
        {
            bool b = true;
            cout<<arr[i]<<" and "<<m[x-arr[i]];
            return;
        }
    }
    if(!b)
    {
        cout<<"NULL";
        return;
    }
}

int main()
{
    // int x = 6;
    // int n = 5;
    // int arr[5];
    // unordered_map <int, int> m;
    // for(int i=0; i<n; i++)
    // {
    //     cout<<"enter element "<<i+1<<" = ";
    //     cin>>arr[i];
    //     m[arr[i]] = i;
    // }
    // twoSum(arr, n, x, m);

    vector <int> v = {1,6,2,10,3};
    int t = 7;
    vector <int> ans = twoSumV(v,t);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i];
    }

    return 0;
}

// arrray : 2,3,1,3,6