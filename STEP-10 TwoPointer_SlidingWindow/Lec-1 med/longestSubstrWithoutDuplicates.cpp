#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;

        map<char, int> m;  // Stores the last index of each character
        int maxlen = 0;    // Length of longest substring
        int l = 0;         // Left pointer of window

        for (int r = 0; r < s.size(); r++) {
            if (m.find(s[r]) != m.end()) {
                // Move left pointer only forward, never backward
                l = max(l, m[s[r]] + 1);
            }
            m[s[r]] = r;  // Update the character's latest index
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
