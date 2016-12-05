#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//用广度优先搜索的算法
int minPathSum(vector<vector<int>>& grid)
{
    int h = grid.size();
    int w = grid[0].size();
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i <= h; i++)
        dp[i][0] = INT_MAX;
    for (int j = 0; j <= w; j++)
        dp[0][j] = INT_MAX;
    dp[0][1] = 0;
    //dp[x+1][y+1]表示到点(x,y)的权重
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[h][w];
}

//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    vector<vector<int>> grid(m, vector<int>(n));
//    for (int i = 0; i < m; i++){
//        for (int j = 0; j < n; j++){
//            cin >> grid[i][j];
//        }
//    }
//    cout << minPathSum(grid);
//    system("pause");
//    return 0;
//}