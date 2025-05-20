#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++; // Skip leading spaces

    if (i == n) return 0;

    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') sign = -1;
        i++;
    }

    if (i == n || !isdigit(s[i])) return 0; // Check if next char is digit

    long long Ans = 0;
    while (i < n && isdigit(s[i])) {
        Ans = Ans * 10 + (s[i] - '0');
        if (sign == 1 && Ans >= INT_MAX) return INT_MAX;
        if (sign == -1 && -Ans <= INT_MIN) return INT_MIN;
        i++;
    }

    return static_cast<int>(Ans * sign);
}

int main() {
    string s = " 0-1";
    cout << myAtoi(s) << endl;
    return 0;
}
