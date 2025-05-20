/*
Given two strings s and goal, return true if and only 
if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character
 of s to the rightmost position.

*/
#include <bits/stdc++.h>
using namespace std;

bool check(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        string S=s+s;
        if(S.find(goal)<S.size()) return true;
        else return false;
    }

int main()
{
  string s="abcde", t="cdeab";
//   string s="abc", t="wc";
//   cout<<s.find(t);
    if(check(s,t)) cout<<"TRUE";
    else cout<<"FALSE";

  return 0;
}