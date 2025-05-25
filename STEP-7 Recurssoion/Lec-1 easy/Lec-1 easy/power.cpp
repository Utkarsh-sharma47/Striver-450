#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n == 0)
        return 1.0;
    long N = n;
    if (N < 0)
    {
        N = -N;
        x = 1.0 / x;
    }
    if (N % 2 == 0)
        return myPow(x * x, N / 2);
    else
        return x * myPow(x, N - 1);
}

// Example: creating a linked list with values 1 -> 2 -> 3 -> 4 -> 5
int main()
{
    double x = 2.0;
    int n = 10;
    cout << myPow(x, n);
    return 0;
}
