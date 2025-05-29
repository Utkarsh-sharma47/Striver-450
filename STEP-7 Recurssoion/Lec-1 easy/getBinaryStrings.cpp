#include <bits/stdc++.h>
using namespace std;

void BS(int n, vector<string> &ans, string s)
{
    if(s.size()==n)
    {
        ans.push_back(s);
        return;
    }
    //include one
    BS(n, ans, s+'1');
    //include zero
    BS(n, ans, s+'0');
}

vector<string> genBinaryString(int n)
{
    vector<string> ans;
    BS(n, ans, "");
    return ans;
}


int main()
{
    vector<string> ans;
    ans=genBinaryString(3);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    
    return 0;
}
