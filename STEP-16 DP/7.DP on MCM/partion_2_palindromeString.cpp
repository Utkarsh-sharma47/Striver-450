#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// Helper to check if s[i..j] is a palindrome
    bool isPali(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
// <---------------------------------MEMORIZATION------------------------------->
// DP function to find min cuts from index i to end
    int f(int i, int n, string &s, vector<int> &dp) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int mincut = INT_MAX;

        for (int k = i; k < n; k++) {
            if (isPali(i, k, s)) {
                // If s[i..k] is palindrome, make a cut after k
                int cut = 1 + f(k + 1, n, s, dp);
                mincut = min(mincut, cut);
            }
        }

        return dp[i] = mincut;
    }

    int minCutMEMO(string s) {
        int n = s.size();
        if (n <= 1) return 0;

        vector<int> dp(n, -1);

        // Subtract 1 because no cut is needed for a single partition
        return f(0, n, s, dp) - 1;
    }

// <---------------------------------TABULATION------------------------------->

    int minCut(string s) {
        int n = s.size();

        // dp[i] will store the minimum number of cuts needed for s[i..n-1]
        vector<int> dp(n + 1, 0); // dp[n] = 0 as base case

        // Fill from back to front
        for (int i = n - 1; i >= 0; i--) {
            int mincut = INT_MAX;

            for (int k = i; k < n; k++) {
                if (isPali(i, k, s)) {
                    int cut = 1 + dp[k + 1];
                    mincut = min(mincut, cut);
                }
            }

            dp[i] = mincut;
        }

        // Subtract 1 because we make cuts between palindromic parts
        return dp[0] - 1;
    }
};
int main() {
    Solution sol;
    string s = "aab";
    cout << sol.minCut(s)<<endl; // Output: 1 → ["aa", "b"]
    cout << sol.minCutMEMO(s); // Output: 1 → ["aa", "b"]
    return 0;
}
