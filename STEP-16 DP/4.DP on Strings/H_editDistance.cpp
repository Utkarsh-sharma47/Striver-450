/*
Given two strings word1 and word2, return the minimum number of operations
required to convert word1 to word2.

You have the following three operations permitted on a word:
-Insert a character
-Delete a character
-Replace a character
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // -----------------------------
    // MEMOIZATION APPROACH (Top-Down)
    // -----------------------------

    int memoHelper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // Base cases:
        if (i < 0)
            return j + 1; // Insert all remaining chars of s2
        if (j < 0)
            return i + 1; // Delete all remaining chars of s1

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
        {
            // Characters match → no operation needed
            return dp[i][j] = memoHelper(i - 1, j - 1, s1, s2, dp);
        }
        else
        {
            // Characters don't match → consider 3 operations:
            int insertOp = 1 + memoHelper(i, j - 1, s1, s2, dp);
            int deleteOp = 1 + memoHelper(i - 1, j, s1, s2, dp);
            int replaceOp = 1 + memoHelper(i - 1, j - 1, s1, s2, dp);

            // Take the minimum
            return dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }
    }

    int editDistanceMemo(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // dp[i][j] = min edits for s1[0..i], s2[0..j]
        return memoHelper(n - 1, m - 1, s1, s2, dp);
    }

    // -----------------------------
    // TABULATION APPROACH (Bottom-Up)
    // -----------------------------

    int editDistanceTab(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = min operations to convert s1[0..i-1] to s2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases:
        for (int i = 0; i <= n; i++)
            dp[i][0] = i; // Delete all characters
        for (int j = 0; j <= m; j++)
            dp[0][j] = j; // Insert all characters

        // Fill the dp table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    // Characters match → no extra cost
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // Choose minimum among insert, delete, and replace
                    int insertOp = 1 + dp[i][j - 1];
                    int deleteOp = 1 + dp[i - 1][j];
                    int replaceOp = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[n][m]; // Final result
    }
};

int main()
{
    Solution sol;

    string word1 = "horse";
    string word2 = "ros";

    cout << "Using Memoization: " << sol.editDistanceMemo(word1, word2) << endl;
    cout << "Using Tabulation : " << sol.editDistanceTab(word1, word2) << endl;

    return 0;
}
