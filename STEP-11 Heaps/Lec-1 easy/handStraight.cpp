/*
Alice has some number of cards and she wants to rearrange
 the cards into groups so that each group is of size groupSize, 
 and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value 
written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.
*/
#include <iostream>
#include <vector>
#include <map> // for ordered map
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // If total cards can't be evenly divided into groups, return false
        if (n % groupSize != 0) return false;

        // Use map to store frequency of each card (automatically sorted)
        map<int, int> mp;
        for (int card : hand) {
            mp[card]++; // Count how many times each card appears
        }

        // Continue until all cards are grouped
        while (!mp.empty()) {
            int curr = mp.begin()->first; // Get the smallest card to start the group

            // Try to form a group of size 'groupSize' starting from 'curr'
            for (int j = 0; j < groupSize; j++) {
                int neededCard = curr + j; // Next consecutive card needed

                // If the needed card is not available, we can't form a valid group
                if (mp[neededCard] == 0) return false;

                // Use one instance of this card
                mp[neededCard]--;

                // If this card is used up completely, remove it from the map
                if (mp[neededCard] == 0) {
                    mp.erase(neededCard);
                }
            }
        }

        // All cards were successfully grouped
        return true;
    }
};

// Function to test the above solution
int main() {
    Solution sol;

    // Sample input
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;

    // Function call
    bool result = sol.isNStraightHand(hand, groupSize);

    // Print result
    if (result)
        cout << "True: Cards can be grouped into consecutive groups of size " << groupSize << endl;
    else
        cout << "False: Cannot group cards into consecutive groups of size " << groupSize << endl;

    return 0;
}
