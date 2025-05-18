#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;
    }   

int main()
{
  vector<int> v = {0};

  // for (int i = 0; i < v.size(); i++)
  // {
  //   cout << v[i] << " ";
  // }

  return 0;
}