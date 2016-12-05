#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int h = obstacleGrid.size();
    int w = obstacleGrid[0].size();
    vector<vector<int>> steps(h + 1, vector<int>(w + 1, 0));
    //steps[x][y]表示到达坐标为(x+1,y+1)的方案数
    steps[0][1] = 1;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if (!obstacleGrid[i-1][j-1])
                steps[i][j] = steps[i - 1][j] + steps[i][j - 1];
        }
    }
    return steps[h][w];
}

//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    vector<vector<int>> obstacleGrid(m, vector<int>(n));
//    for (int i = 0; i < m; i++){
//        for (int j = 0; j < n; j++){
//            cin >> obstacleGrid[i][j];
//        }
//    }
//    cout << uniquePathsWithObstacles(obstacleGrid);
//    system("pause");
//    return 0;
//}