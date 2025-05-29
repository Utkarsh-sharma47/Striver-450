#include <bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int>& arr,
                     vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++) {
        // Skip duplicates
        if (i > ind && arr[i] == arr[i - 1]) continue;

        if (arr[i] > target) break;

        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds); // move to next index
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // sort for skipping duplicates
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main() {
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans = combinationSum2(v, 8);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
