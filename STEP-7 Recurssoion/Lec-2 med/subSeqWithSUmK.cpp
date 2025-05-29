#include <iostream>
#include <vector>
using namespace std;

void findSubsequences(int index, vector<int>& arr, vector<int>& current, int currentSum, int k) {
    if (index == arr.size()) {
        if (currentSum == k) {
            for (int num : current)
                cout << num << " ";
            cout << endl;
        }
        return;
    }

    // Include current element
    current.push_back(arr[index]);
    findSubsequences(index + 1, arr, current, currentSum + arr[index], k);

    // Exclude current element
    current.pop_back();
    findSubsequences(index + 1, arr, current, currentSum, k);
}

int main() {
    vector<int> arr = {1, 2, 1};
    int k = 2;
    vector<int> current;
    
    cout << "Subsequences with sum " << k << " are:\n";
    findSubsequences(0, arr, current, 0, k);

    return 0;
}
