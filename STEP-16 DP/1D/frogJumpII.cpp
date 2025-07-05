/*
A frog is at the 0th stair and wants to reach the nth stair. 
The frog can jump at most k steps at a time. The cost to reach 
each stair is given in the heights[] array. The cost of a jump 
from stair i to j is abs(heights[i] - heights[j]).

Find the minimum total cost to reach the n-1th stair from 0.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Function to compute minimum energy to reach last step
int frogJumpK(int n, int k, vector<int>& heights) {
    // dp[i] will store the minimum energy to reach stair i
    vector<int> dp(n, 0);

    dp[0] = 0; // Base case: starting point

    // Compute dp[i] for all i from 1 to n-1
    for (int i = 1; i < n; i++) {
        int minSteps = INT_MAX;

        // Try all jumps from 1 to k
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jump);
            }
        }

        dp[i] = minSteps; // Store the minimum energy to reach step i
    }

    return dp[n - 1]; // Minimum energy to reach last step
}

int main() {
    int n, k;
    cout << "Enter number of stairs (n): ";
    cin >> n;
    cout << "Enter max jump size (k): ";
    cin >> k;

    vector<int> heights(n);
    cout << "Enter heights of stairs:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int result = frogJumpK(n, k, heights);
    cout << "Minimum energy required: " << result << endl;

    return 0;
}
