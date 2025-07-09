/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ----------------------------------
    // MEMOIZATION APPROACH (Top-Down)
    // ----------------------------------

    bool memoHelper(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // Base Cases:
        if(i < 0 && j < 0) return true;  // Both strings are empty
        if(j < 0) return false;          // Pattern exhausted, string not
        if(i < 0) {
            // If string is empty, pattern must be all '*'
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == s[i] || p[j] == '?') {
            return dp[i][j] = memoHelper(i-1, j-1, s, p, dp);
        }
        else if(p[j] == '*') {
            // '*' matches:
            // 1. Zero chars → move pattern pointer only
            // 2. One or more chars → move string pointer only
            return dp[i][j] = memoHelper(i-1, j, s, p, dp) || memoHelper(i, j-1, s, p, dp);
        }
        else {
            return dp[i][j] = false;
        }
    }

    bool isMatchMemo(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoHelper(n-1, m-1, s, p, dp);
    }

    // ----------------------------------
    // TABULATION APPROACH (Bottom-Up)
    // ----------------------------------

    bool isMatchTab(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // Empty pattern and empty string match
        dp[0][0] = true;

        // If s is empty, p must be all '*'
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*') {
                    // '*' → 0 or more characters
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    Solution sol;

    string s = "adceb";
    string p = "*a*b";

    cout << "Using Memoization: " << (sol.isMatchMemo(s, p) ? "true" : "false") << endl;
    cout << "Using Tabulation : " << (sol.isMatchTab(s, p) ? "true" : "false") << endl;

    return 0;
}
