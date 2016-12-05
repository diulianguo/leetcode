#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

//dp[x][y]表示以(x,y)为右下角的正方形的边长

int maximalSquare(vector<vector<char>>& matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int height = matrix.size();
    int width = matrix[0].size();
    vector<vector<int>> dp(height, vector<int>(width));
    int max = 0;
    for (int i = 0; i < width; i++){
        if (matrix[0][i] == '1'){
            dp[0][i] = 1;
            max = 1;
        }else
            dp[0][i] = 0;
    }
    for (int i = 0; i < height; i++){
        if (matrix[i][0] == '1'){
            dp[i][0] = 1;
            max = 1;
        }else
            dp[i][0] = 0;
    }
    for (int i = 1; i < height; i++){
        for (int j = 1; j < width; j++){
            if (matrix[i][j] == '1'){
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                if (dp[i][j]>max)
                    max = dp[i][j];
            }
        }
    }
    return max*max;
}


//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> matrix(n, vector<char>(m));
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            cin >> matrix[i][j];
//        }
//    }
//    cout << maximalSquare(matrix);
//    system("pause");
//    return 0;
//}