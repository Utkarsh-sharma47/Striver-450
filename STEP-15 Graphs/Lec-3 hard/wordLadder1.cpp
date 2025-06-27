/*
A transformation sequence from word beginWord to word endWord using a
dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk
such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList,
return the number of words in the shortest transformation sequence
from beginWord to endWord, or 0 if no such sequence exists.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // Queue for BFS, storing word and the number of steps to reach it
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start from the beginWord with 1 step

        // Store words in a set for fast lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not in wordList, no transformation is possible
        if (st.find(endWord) == st.end())
            return 0;

        // Remove beginWord from set if it exists
        st.erase(beginWord);

        // Start BFS
        while (!q.empty())
        {
            string word = q.front().first; // Current word
            int step = q.front().second;   // Steps taken so far
            q.pop();

            // Try changing every character of the word
            for (int i = 0; i < word.size(); i++)
            {
                char originalLetter = word[i]; // Save original character

                // Try replacing with 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    // If this new word is the endWord, return steps + 1
                    if (word == endWord)
                        return step + 1;

                    // If this new word exists in the set (valid transformation)
                    if (st.find(word) != st.end())
                    {
                        q.push({word, step + 1}); // Add to queue for further processing
                        st.erase(word);           // Remove from set to avoid revisiting
                    }
                }

                word[i] = originalLetter; // Restore original character
            }
        }

        // If we reach here, no transformation sequence exists
        return 0;
    }
};

int main()
{
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
