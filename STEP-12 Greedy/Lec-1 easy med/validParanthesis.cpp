#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum number of open brackets '(' possible
        int high = 0; // Maximum number of open brackets '(' possible

        // Traverse each character in the string
        for (char c : s) {
            if (c == '(') {
                // An open bracket definitely increases both low and high
                low++;
                high++;
            } else if (c == ')') {
                // A closing bracket tries to close a previous '('
                if (low > 0) low--; // If we assume some '(' was open, close it
                high--;             // It definitely reduces the open count

            } else if (c == '*') {
                // Star can be '(', ')' or empty
                if (low > 0) low--; // If '*' is ')', try to close an open bracket
                high++;             // If '*' is '(', increase max possible opens
            }

            // If at any point, the maximum open brackets becomes negative,
            // it means too many ')' have been used → invalid
            if (high < 0) return false;
        }

        // At the end, if minimum open brackets can be balanced (i.e., zero), it's valid
        return low == 0;
    }
};

// Test the function with some example cases
int main() {
    Solution solution;

    string test1 = "(*))";
    cout << "Input: " << test1 << "\nOutput: " << (solution.checkValidString(test1) ? "Valid" : "Invalid") << endl;

    string test2 = "(*()";
    cout << "Input: " << test2 << "\nOutput: " << (solution.checkValidString(test2) ? "Valid" : "Invalid") << endl;

    string test3 = "(*)))";
    cout << "Input: " << test3 << "\nOutput: " << (solution.checkValidString(test3) ? "Valid" : "Invalid") << endl;

    string test4 = "((*)";
    cout << "Input: " << test4 << "\nOutput: " << (solution.checkValidString(test4) ? "Valid" : "Invalid") << endl;

    return 0;
}
