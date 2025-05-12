#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int> &nums)
{
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); i++)
  {
    m[nums[i]]++;
  }
 
  int zero = m[0];
  int one = m[1];
  int two = m[2];


  int i=0;
  for(int x; i<(zero); i++)
  {
    nums[i]=0;
  }
  for(int x; i<(zero + one); i++)
  {
    nums[i]=1;
  }
  for(int x; i<(zero + one + two); i++)
  {
    nums[i]=2;
  }

  return ;
}

int main()
{
  vector<int> v = {0, 0, 1, 1, 0};
  sortZeroOneTwo(v);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }

  return 0;
}