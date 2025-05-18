#include <bits/stdc++.h>
using namespace std;

/*
Given an array nums of size n, which denotes the positions of stalls,
and an integer k, which denotes the number of aggressive cows, assign
stalls to k cows such that the minimum distance between any two cows is
the maximum possible. Find the maximum possible minimum distance.
*/

// Function to check if k cows can be placed with at least 'dist' minimum separation
bool possibleCows(const vector<int> &v, int dist, int k)
{
    int count = 1;   // Start with the first cow placed
    int last = v[0]; // Position of the last placed cow

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - last >= dist)
        {                // Check if the current stall can accommodate a cow
            last = v[i]; // Update the last placed cow's position
            count++;     // Increment the count of cows placed
            if (count >= k)
                return true; // If we have placed all cows, return true
        }
    }
    return false; // Not possible to place all cows with the given distance
}

// Function to find the largest minimum distance
int aggressiveCows(vector<int> &v, int k)
{
    sort(v.begin(), v.end()); // Sort the stall positions

    int left = 1;                // Minimum possible distance
    int right = v.back() - v[0]; // Maximum possible distance
    int result = 0;              // To store the result

    while (left <= right)
    {
        int mid = left + ((right - left) / 2); // Calculate mid distance

        if (possibleCows(v, mid, k))
        {                   // Check if it's possible to place cows with 'mid' distance
            result = mid;   // Update result
            left = mid + 1; // Try for a bigger minimum distance
        }
        else
        {
            right = mid - 1; // Try for a smaller one
        }
    }

    return result; // Return the largest minimum distance found
}

int main()
{
    vector<int> v = {0, 3, 4, 7, 9, 10};          // Stall positions
    int cows = 4;                                 // Number of cows
    int maxMinDistance = aggressiveCows(v, cows); // Calculate maximum minimum distance
    cout << maxMinDistance << endl;               // Output the result
    return 0;
}