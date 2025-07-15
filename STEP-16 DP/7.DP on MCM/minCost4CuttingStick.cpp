/*
Given an integer array cuts where cuts[i] denotes a position you 
should perform a cut at.

You should perform the cuts in order, you can change the order of the 
cuts as you wish.

The cost of one cut is the length of the stick to be cut, 
the total cost is the sum of costs of all cuts. When you cut a stick, 
it will be split into two smaller sticks (i.e. the sum of their lengths 
is the length of the stick before the cut). 

Return the minimum total cost of the cuts.
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// <------------------MEMOIZATION------------------>
int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if (i > j) return 0; // No cuts to make between cuts[i] and cuts[j]

    if (dp[i][j] != -1) return dp[i][j];

    int mini = INF;
    for (int k = i; k <= j; k++) {
        int cost = cuts[j+1] - cuts[i-1]; // Length of stick after adding 0 and n
        int left = f(i, k-1, cuts, dp);   // Cost of left part
        int right = f(k+1, j, cuts, dp);  // Cost of right part
        mini = min(mini, cost + left + right); // Take min over all cuts
    }
    return dp[i][j] = mini;
}

// <------------------MAIN FUNCTION------------------>
int main() {
    int n = 9; // Length of the stick
    vector<int> cuts = {5, 6, 1, 4}; // Positions where you want to cut

    // Sort and prepare for memoization
    vector<int> sortedCuts = cuts;
    sortedCuts.push_back(0); sortedCuts.push_back(n);
    sort(sortedCuts.begin(), sortedCuts.end());

    int c = cuts.size();
    vector<vector<int>> dp(c+2, vector<int>(c+2, -1));

    // Memoization call
    int minCostMemo = f(1, c, sortedCuts, dp);

    cout << "Minimum Cost (Memoization): " << minCostMemo << endl;

    return 0;
}
