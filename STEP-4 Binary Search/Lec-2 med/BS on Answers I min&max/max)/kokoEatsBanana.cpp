#include <bits/stdc++.h>
using namespace std;

int time(vector<int>& v, int mid) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += (v[i] + mid - 1) / mid;  // same as ceil(v[i]/mid)
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int k = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int t = time(piles, mid);
            if (t <= h) {
                k = mid;              // valid speed, try to find smaller
                right = mid - 1;
            } else {
                left = mid + 1;       // too slow, increase speed
            }
        }

        return k;
    }

int main()
{
  vector<int> v = {3,6,7,11};
  cout<<minEatingSpeed(v,8);

  return 0;
}