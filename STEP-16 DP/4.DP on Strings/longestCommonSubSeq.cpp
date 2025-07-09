#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    // ------------------ MEMOIZATION (TOP-DOWN) ------------------

    // Recursive function to compute LCS using memoization
    int lcsMemo(int i, int j, const string &text1, const string &text2, vector<vector<int>> &dp) {
        // Base case: if any index is out of bounds, return 0
        if (i < 0 || j < 0) return 0;

        // If already computed, return cached result
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, add 1 and move diagonally
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + lcsMemo(i - 1, j - 1, text1, text2, dp);
        }
        // Else, take the max by excluding one character from either string
        return dp[i][j] = max(
            lcsMemo(i - 1, j, text1, text2, dp),
            lcsMemo(i, j - 1, text1, text2, dp)
        );
    }

    // ------------------ TABULATION (BOTTOM-UP) ------------------

    int lcsTab(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        // Create DP table of size (n1+1) x (n2+1) initialized with 0
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If characters match, take diagonal + 1
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    s=s+(text1[i-1]);
                } else {
                    // Else take max from left or top
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // LCS length is in the bottom-right cell
        return dp[n1][n2];
    }

    // ------------------ MAIN FUNCTION ------------------

    int longestCommonSubsequence(string text1, string text2) {
        // ------------------- MEMOIZATION CALL -------------------
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));  // Memoization table
        int lcs_len_memo = lcsMemo(n1 - 1, n2 - 1, text1, text2, dp);

        // ------------------- TABULATION CALL -------------------
        int lcs_len_tab = lcsTab(text1, text2);

        // You can return either of them; they will be same
        // return lcs_len_memo;
        return lcs_len_tab;
    }
};

// ------------------ DRIVER CODE ------------------

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "aze";

    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of LCS: " << result << endl;
    cout<<sol.s;
    return 0;
}
