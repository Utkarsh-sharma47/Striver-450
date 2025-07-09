/*
Given a string s, find the longest palindromic 
subsequence's length in s.

A subsequence is a sequence that can be derived from 
another sequence by deleting some or no elements without 
changing the order of the remaining elements.
*/

/*
APP:-
S1=given sting,, S2=reverse of given string
find LCS(subseq) in S1,S2 to get longest palindrom in given stirng
*/
#include <bits/stdc++.h>
using namespace std;

// Class containing the LPS logic
class Solution {
public:
    int longestPalindromeSubseq(string s2) {
        int n = s2.size(); // Length of the input string

        // Create a 2D DP table to store subproblem results
        // dp[i][j] = length of longest palindromic subsequence
        // in s1[0..i] and s2[0..j] where s2 is reversed s1
        vector<vector<int>> dp(n, vector<int>(n, 0));

        string s1 = s2;               // Store the original string
        reverse(s2.begin(), s2.end()); // Reverse it to compare with original

        // Tabulation: Fill the dp table row-wise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    // If characters match, extend previous LPS
                    if (i > 0 && j > 0)
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1; // First row/column base case
                } else {
                    // Characters do not match: take max of excluding i or j
                    int op1 = (i > 0) ? dp[i - 1][j] : 0;
                    int op2 = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = max(op1, op2);
                }
            }
        }

        // The bottom-right cell contains the final answer
        return dp[n - 1][n - 1];
    }
};

// Driver function
int main() {
    Solution sol;

    // Example input
    string input = "bbbab";

    // Call the function
    int result = sol.longestPalindromeSubseq(input);

    // Print the result
    cout << "Length of Longest Palindromic Subsequence: " << result << endl;

    return 0;
}
