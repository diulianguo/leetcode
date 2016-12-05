#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n)
{
    //递归方法时间超限
    /*if (m == 1 || n == 1)
        return 1;
    else
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);*/
    vector<vector<int>> steps(m, vector<int>(n, 1));
    //steps[m-1][n-1]表示mxn的网格，从左上角到右下角(m-1,n-1)有多少种方案，
    //steps[x][y]到当前位置(x,y)的方案数即为到他左边和上边的位置的方案数总和
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            steps[i][j] = steps[i][j - 1] + steps[i - 1][j];
        }
    }
    return steps[m - 1][n - 1];
}

//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    cout << uniquePaths(m, n);
//    system("pause");
//    return 0;
//}