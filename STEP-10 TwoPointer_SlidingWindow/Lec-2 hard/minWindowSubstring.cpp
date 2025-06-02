/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every 
character in t (including duplicates) is included in the window. 
  If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/      

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Map to store frequency of characters in t
        unordered_map<char, int> required;
        for (char c : t) {
            required[c]++;
        }

        // Two pointers for the sliding window
        int left = 0;
        int count = 0; // To count how many characters of t are matched
        int minLen = INT_MAX; // Minimum length of valid window
        int startIndex = -1; // Start index of the minimum window substring

        // Traverse the string s with a sliding window
        for (int right = 0; right < s.size(); right++) {
            // If character at right is needed, decrement count in map
            if (required[s[right]] > 0) {
                count++; // We matched one useful character
            }
            required[s[right]]--; // Always decrease frequency in map

            // When all characters of t are matched
            while (count == t.size()) {
                // Update the minimum window size and its starting index
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Before moving left pointer, increase the character count back
                required[s[left]]++;

                // If character at left was a useful match, reduce count
                if (required[s[left]] > 0) {
                    count--;
                }

                // Move left forward to shrink the window
                left++;
            }
        }

        // If no valid window found, return empty string
        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window substring: " << sol.minWindow(s, t) << endl;
    return 0;
}
