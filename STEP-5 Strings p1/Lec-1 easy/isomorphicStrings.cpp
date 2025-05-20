/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can
be replaced to get t.

All occurrences of a character must be replaced with another
character while preserving the order of characters.
No two characters may map to the same character,
but a character may map to itself.
*/
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, char> sToT;
    unordered_map<char, char> tToS;

    for (int i = 0; i < s.length(); ++i)
    {
        char sc = s[i], tc = t[i];

        // Check if mapping exists and is consistent
        if ((sToT.count(sc) && sToT[sc] != tc) ||
            (tToS.count(tc) && tToS[tc] != sc))
        {
            return false;
        }

        sToT[sc] = tc;
        tToS[tc] = sc;
    }

    return true;
}

int main()
{
    string s = "egg";
    string t = "add";

    if (isIsomorphic(s, t))
    {
        cout << "TRUE";
    }
    else
        cout << "FALSE";

    return 0;
}