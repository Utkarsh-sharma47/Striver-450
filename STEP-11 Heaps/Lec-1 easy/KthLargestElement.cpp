#include <iostream>
#include <vector>
#include <queue> // For priority_queue
using namespace std;

// Function to find Kth largest element
int findKthLargest(vector<int> &nums, int k)
{
    // Min-heap to store k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Traverse all elements
    for (int i = 0; i < nums.size(); i++)
    {
        if (minHeap.size() < k)
            minHeap.push(nums[i]);

        else if (minHeap.top() < nums[i])
        {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    // The top of the heap is the Kth largest element
    return minHeap.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4}; // Input array
    int k = 2;

    int result = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
