/*
A ninja can train in 3 activities (0, 1, 2) each day.
He can't do the same activity on two consecutive days.
Each activity on each day has a certain number of points.
Maximize the total points over n days.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute maximum training points using tabulation
int ninjaTraining(int n, vector<vector<int>> &points) {
    // Create a 2D dp array of size n x 4
    // dp[day][last] = max points from day 0 to day with last activity being 'last'
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case: Fill day 0 values for each possible 'last' activity
    for (int last = 0; last < 4; ++last) {
        int maxPoint = 0;

        // Try all 3 activities
        for (int task = 0; task < 3; ++task) {
            if (task != last) { // Can't do the same task as 'last'
                maxPoint = max(maxPoint, points[0][task]);
            }
        }

        // Store max possible for day 0 with 'last' activity restriction
        dp[0][last] = maxPoint;
    }

    // Fill the dp table from day 1 to day n-1
    for (int day = 1; day < n; ++day) {
        for (int last = 0; last < 4; ++last) {
            int maxPoint = 0;

            // Try all 3 possible tasks for today
            for (int task = 0; task < 3; ++task) {
                if (task != last) { // Can't repeat the task done yesterday
                    // points today + best score till yesterday doing this task
                    int point = points[day][task] + dp[day - 1][task];

                    // Store the maximum
                    maxPoint = max(maxPoint, point);
                }
            }

            // Save the best score for current day and last activity
            dp[day][last] = maxPoint;
        }
    }

    // Final answer is the max points on last day when we don’t care what was done last
    return dp[n - 1][3];
}

int main() {
    int n;
    cin >> n; // Input number of days

    // Declare points matrix: n rows, 3 activities per day
    vector<vector<int>> points(n, vector<int>(3));

    // Input training points for each activity per day
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    // Call the function and print the result
    cout << ninjaTraining(n, points) << endl;

    return 0;
}
