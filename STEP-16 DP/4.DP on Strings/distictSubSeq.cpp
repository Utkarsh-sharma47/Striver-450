#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -----------------------------
    // MEMOIZATION APPROACH (Top-Down)
    // -----------------------------

    int memoHelper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // Base case: if t is empty, we found one valid subsequence
        if(j < 0) return 1;
        // If s is empty but t is not, no match possible
        if(i < 0) return 0;

        // If already computed, return the stored result
        if(dp[i][j] != -1) return dp[i][j];

        // Characters match
        if(s[i] == t[j]) {
            // Option 1: take both characters → move both pointers
            // Option 2: skip s[i] → move i only
            dp[i][j] = memoHelper(i-1, j-1, s, t, dp) + memoHelper(i-1, j, s, t, dp);
        } else {
            // Characters don’t match → only option is to skip s[i]
            dp[i][j] = memoHelper(i-1, j, s, t, dp);
        }

        return dp[i][j];
    }

    int numDistinctMemo(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // dp[i][j] = ways to form t[0..j] from s[0..i]
        return memoHelper(n-1, m-1, s, t, dp);
    }

    // -----------------------------
    // TABULATION APPROACH (Bottom-Up)
    // -----------------------------

    int numDistinctTab(string s, string t) {
        int n = s.size();
        int m = t.size();

        // dp[i][j] = number of ways to form t[0..j-1] from s[0..i-1]
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        // Empty t is a subsequence of any s prefix
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // Fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    // Option 1: take both characters
                    // Option 2: skip s[i-1]
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    // Only option: skip s[i-1]
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};

int main() {
    Solution sol;

    string s = "babgbag";
    string t = "bag";

    cout << "Using Memoization: " << sol.numDistinctMemo(s, t) << endl;
    cout << "Using Tabulation : " << sol.numDistinctTab(s, t) << endl;

    return 0;
}
