/*
Given a string s, partition s such that every substring of 
the partition is a palindrome.
 Return all possible palindrome partitioning of s.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Check if a substring s[left..right] is a palindrome
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    // Backtracking function
    void backtrack(int start, const string& s, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path); // Found a valid partition
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1)); // Choose
                backtrack(end + 1, s, path, result);              // Explore
                path.pop_back();                                  // Un-choose
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution sol;
    vector<vector<string>> partitions = sol.partition(input);

    cout << "Palindrome partitions:\n";
    for (const auto& part : partitions) {
        cout << "[ ";
        for (const string& word : part)
            cout << "\"" << word << "\" ";
        cout << "]\n";
    }

    return 0;
}
