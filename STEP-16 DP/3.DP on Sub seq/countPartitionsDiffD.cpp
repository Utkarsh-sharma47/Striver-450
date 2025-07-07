#include<bits/stdc++.h>
using namespace std;
/*
Q.Given an array arr of n integers and an integer diff, 
count the number of ways to partition the array into two subsets 
such that the absolute difference between their sums is equal to diff. 
Return the result modulo 109+7.
*/
#define MOD 1000000007

//MEMO
//ind=n-1, tar=(Tsum+Diff)/2
int f(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp) {
    // Base Case Simplified
    if (ind == 0) {
        if (tar == 0) return (arr[0] == 0 ? 2 : 1);
        return (arr[0] == tar ? 1 : 0);
    }

    if (dp[ind][tar] != -1) return dp[ind][tar];

    int notTake = f(ind - 1, tar, arr, dp) % MOD;
    int take = 0;
    if (arr[ind] <= tar)
        take = f(ind - 1, tar - arr[ind], arr, dp) % MOD;

    return dp[ind][tar] = (take + notTake) % MOD;
}
//----------------------------------------------------------------------
//TABULATION:-

int countPartitionsWithDiffD(vector<int> &arr, int D)
{
    int n=arr.size();
    int Tsum=0;
    for(int i=0; i<n; i++) Tsum+=arr[i];

    int tar=(Tsum+D)/2;
    if((Tsum+D)%2!=0) return 0;//for valid integer
    //dp init
    vector<vector<int>> dp(n,vector<int>(tar+1, -1));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=tar; j++)
        {
            //base cases
            if(i==0)
            {
                if(j==0 || arr[0]==j) {dp[i][j]=1; continue;}
                if(j==0 && arr[0]==0) {dp[i][j]=2; continue;}
                dp[i][j]=0;
                continue;
            }
            //otherwise traverse
            int notTake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j)
            {
                take=dp[i-1][j-arr[i]];
            }

            dp[i][j]=(take+notTake)%MOD;
        }
    }
    return dp[n-1][tar];
    
}

int main()
{
    vector<int> v={1,2,3,4};
    int diff=2;
    cout<<countPartitionsWithDiffD(v,diff);
    return 0;
}