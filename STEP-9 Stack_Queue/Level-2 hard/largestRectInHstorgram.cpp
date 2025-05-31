#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();            // size of the histogram
        stack<int> st;                 // stack to store indices
        int maxarea = 0;               // variable to keep track of maximum area
        int i;

        for (i = 0; i < n; i++) {
            // pse code
            // while current bar is less than the bar at stack top,
            // keep popping from the stack
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int element = st.top();      // now lets talk abou this
                st.pop();                    // remove the taller bar index

                int nse = i;                 // current element which made this element pop out (acts as Next Smaller Element index)
                int pse = st.empty() ? -1 : st.top();  // Previous Smaller Element index

                // calculate area with arr[element] as height and width between pse and nse
                maxarea = max(maxarea, arr[element] * (nse - pse - 1));
            }
            st.push(i); // push current index to stack
        }

        // Process remaining elements in the stack (right boundary is n)
        while (!st.empty()) {
            int element = st.top();    // now lets talk abou this
            st.pop();

            int nse = n;                          // no smaller to the right, so take n as NSE index
            int pse = st.empty() ? -1 : st.top(); // previous smaller index

            // calculate area using arr[element] as height and full span
            maxarea = max(maxarea, arr[element] * (nse - pse - 1));
        }

        return maxarea; // return the largest area found
    }
};

int main() {
    Solution sol;
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(histogram) << endl;
    return 0;
}
