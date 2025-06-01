#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Try programiz.pro\n";

    vector<int> v = {1, 2, 3, 4};

    // Fix 1: reverse is a standalone function in <algorithm>, not a member of vector
    reverse(v.begin(), v.begin() + 3);

    // Fix 2: you should print the value of `i`, not the entire vector
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}
