/*
Given the arrival and departure times of all trains reaching 
a particular railway station, determine the minimum number of
platforms required so that no train is kept waiting. 
Consider all trains arrive and depart on the same day.



In any particular instance, the same platform cannot be used 
for both the departure of one train and the arrival of another train, 
necessitating the use of different platforms in such cases.
*/

/*
APPROACH:-
1. Sort the arrival and departure times separately.

2. Use two pointers:
One for arrival events
One for departure events

3. Traverse the sorted arrays:
If a train arrives before the earliest departure → need a new platform
If a train departs before or at the time of next arrival → free up a platform
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinimumPlatforms(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();

    // Sort both arrival and departure times
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0, j = 0;       // Pointers for arrival and departure
    int platforms = 0;      // Platforms needed currently
    int maxPlatforms = 0;   // Store the result (max platforms needed at any time)

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            // A train is arriving before the current one departs
            platforms++;
            i++;
        } else {
            // A train is departing, so one platform gets free
            platforms--;
            j++;
        }

        // Update max platforms needed
        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}

int main() {
    // Sample test case
    vector<int> arrival  = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    int result = findMinimumPlatforms(arrival, departure);
    cout << "Minimum number of platforms required = " << result << endl;

    return 0;
}
