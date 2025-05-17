#include <bits/stdc++.h>
using namespace std;

int NthRoot(int N, int M)
{
    int left = 1, right = M;
       while(left<=right)
       {
        int mid = left+(right-left)/2;
        if(pow(mid,N)==M) return mid;
        else if(pow(mid,N)>M) right = mid-1;
        else left = mid+1;
       }
       return -1;
}

int main()
{
    int M = 69, N = 4; // 4th root of 16 is = 2
    cout<<NthRoot(N,M);

    return 0;
}