#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the nth Fibonacci number using memoization
int fibonacci(int n, vector<int>& dp) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // If the value is already computed, return it
    if (dp[n] != -1) return dp[n];

    // Otherwise, compute and store it in dp array
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Initialize a dp array with -1 indicating uncomputed values
    vector<int> dp(n + 1, -1);

    int result = fibonacci(n, dp);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}
