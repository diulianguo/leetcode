#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n)
{
    vector<int> dp(n + 1, 1);
    dp[2] = dp[0] + dp[1];
    for (int i = 3; i < n+1; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

