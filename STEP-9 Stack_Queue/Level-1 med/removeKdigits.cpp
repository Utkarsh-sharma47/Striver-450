#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            // Remove larger digits from the stack if possible
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If there are still digits to remove, pop from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Construct the number from the stack
        std::string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') {
            idx++;
        }
        ans = ans.substr(idx);

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution sol;
    std::string num;
    int k;
    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << "Enter k: ";
    std::cin >> k;

    std::string result = sol.removeKdigits(num, k);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
