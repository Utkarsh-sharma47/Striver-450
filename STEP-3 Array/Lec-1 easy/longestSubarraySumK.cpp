#include <bits/stdc++.h>
using namespace std;
/*
TWO POINTERS is all elements are positive

PREFIX SUM + HASHING - when +ve/-ve elements are there

*/

int main()
{
    int k = 4; // sum=4
    vector<int> v;
    v.push_back(2);
    v.push_back(-1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(5);
    v.push_back(-2);

    int maxlen = 0;
    int sum = 0;
    //MAP - sum(key) , index(value)
    unordered_map<int, int> m;
    int i = 0;
    while (i != v.size())
    {
        sum = sum + v[i];
       
        // sum is equal then consider that length
        if(sum == k)
        {
            maxlen = i+1;
        }

        // if one part of subarray have sum X-k and other part has sum k, where: subarray sum = x
        if(m.find(sum-k) != m.end())
        {
            maxlen = max(maxlen, i-m[sum-k]);
        }

    // store in map only when that value (sum-k) is not present in map
        if(m.find(sum) == m.end()){
            m[sum]=i;//map ki "sum" wali 'key' mai "i" 'value' store kardo
        }
        i++;
    }

    cout<<"max len = "<<maxlen;

    return 0;
}