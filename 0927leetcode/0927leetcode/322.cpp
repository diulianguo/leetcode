#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

//典型的动态规划问题
int coinChange(vector<int>& coins, int amount)
{
    //凑出amount量的钱，最少多少个硬币
    //dp[n]=min(dp[n],dp[n-coin(m)]+1);
    int n = coins.size();
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    sort(coins.begin(), coins.end());
    for (int i = 0; i < n; i++){
        for (int j = coins[0]; j <= amount; j++){
            if (j >= coins[i])
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    return dp[amount]>amount ? amount : dp[amount];
}

//int main()
//{
//    vector<int> coins = { 1, 2, 5 };
//    cout << coinChange(coins, 11);
//    system("pause");
//    return 0;
//}