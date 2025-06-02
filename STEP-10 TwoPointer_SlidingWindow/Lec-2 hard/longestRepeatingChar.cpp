/*
You are given a string s and an integer k.
You can choose any character of the string and
change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing
the same letter you can get after performing the above operations.
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, maxlen = 0, maxFreq = 0;
        unordered_map<char, int> m;

        for (int r = 0; r < s.size(); r++)
        {
            m[s[r]]++;
            maxFreq = max(maxFreq, m[s[r]]);

            // If we need to change more than k characters, shrink the window
            if ((r - l + 1) - maxFreq > k)
            {
                m[s[l]]--;
                l++;
            }

            // Always try to update maxlen (whether we shrank or not)
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

// Example usage
int main()
{
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << "Longest substring length: " << sol.characterReplacement(s, k) << endl;
    return 0;
}
