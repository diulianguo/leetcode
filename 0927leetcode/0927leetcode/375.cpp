#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

//dp[i][j]表示猜从[i,j]的数字保证能赢的最少钱数
int getMoneyAmount(int n)
{
    if (n == 1)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 1; len < n; len++){
        for (int i = 1; i + len <= n; i++){
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++){
                dp[i][j] = min(dp[i][j], k + max(k - 1 >= i ? dp[i][k - 1] : 0, k + 1 <= j ? dp[k + 1][j] : 0));
            }
        }
    }
    return dp[1][n];
}

//int main()
//{
//    cout << getMoneyAmount(3) << endl;
//    system("pasuse");
//    return 0;
//}