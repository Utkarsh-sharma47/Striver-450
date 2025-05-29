#include <bits/stdc++.h>
using namespace std;

void para(int n, int open, int close, vector<string> &ans, string s) {
    if(open + close == 2 * n) {
        ans.push_back(s);
        return;
    }
    if(open < n) {
        para(n, open + 1, close, ans, s + '(');
    }
    if(open > close) {
        para(n, open, close + 1, ans, s + ')');
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    para(n, 0, 0, ans, "");
    return ans;
}

int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    vector<string> v = generateParenthesis(n);

    for(auto it : v) {
        cout << it << " ";
    }

    return 0;
}
