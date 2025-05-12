#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& nums, int k) {
        while(k--)
        {
            int temp = nums[0];
            for(int i=1; i<nums.size(); i++)
            {
                nums[i-1] = nums[i]; 
            }
            nums[nums.size()-1]=temp;
        }

    }

int main()
{
    vector<int> v ; 
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // cout<<v[v.size()-1]<<endl;
    rotateArray(v,2);

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<"  ";
    }

    return 0;
}