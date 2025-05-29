#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &arr)
    {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            // +ve element
            if (arr[i] > 0)
                st.push(arr[i]);
            // -ve element
            else
            {
                // only pop +ve when negative wla is bigger
                while (!st.empty() && st.top() > 0 && st.top() < abs(arr[i]))
                {
                    st.pop();
                }
                // also pop if same size
                if (!st.empty() && st.top() == abs(arr[i]))
                {
                    st.pop();
                }
                // only add -ve in stack when 1. stack is empty 2. top is negative
                else if (st.empty() || st.top() < 0)
                {
                    st.push(arr[i]);
                }
            }
        }

        while (!st.empty())
        {
            int x = st.top();
            ans.insert(ans.begin() + 0, x);
            st.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 10, -5}; // Sample input
    vector<int> result = sol.asteroidCollision(arr);

    cout << "Result: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
