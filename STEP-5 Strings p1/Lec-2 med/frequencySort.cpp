#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>


/*
sine we used a vector
for tree
2 = e
1 = t,r
*/


using namespace std;


    string frequencySort(string s)
    {
        unordered_map<char, int> um;
        for (char c : s)
        {
            um[c]++;
        }

        // Map frequency to vector of characters with that frequency, sorted descending frequency order
        map<int, vector<char>, greater<>> m;
        for (auto it : um)
        {
            m[it.second].push_back(it.first);
        }

        string ans;
        for (auto itr : m)
        {
            for (char c : itr.second)
            {
                ans.append(itr.first, c);  // append char c itr.first times
            }
        }
        return ans;
    }

int main()
{
    string s=frequencySort("tree");
    cout<<s;

    return 0;
}
