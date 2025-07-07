#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the nth Fibonacci number using Dynamic Programming
int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Create a DP array to store Fibonacci numbers
    vector<int> dp(n + 1);

    // Initialize the first two Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp array from 2 to n
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // dp[i] = F(i-1) + F(i-2)
    }

    // Return the nth Fibonacci number
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}
