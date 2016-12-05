#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> res;
    int x = matrix.size();
    if (x == 0)
        return res;
    int y = matrix[0].size();
    if (y == 0)
        return res;
    vector<vector<bool>> vis(x, vector<bool>(y));

    int i = 0, j = -1, count = 0;
    while (count < x*y){
        while (j < y - 1 && !vis[i][j + 1]){
            res.push_back(matrix[i][++j]);
            vis[i][j] = true;
            ++count;
        }
        while (i < x - 1 && !vis[i + 1][j]){
            res.push_back(matrix[++i][j]);
            vis[i][j] = true;
            ++count;
        }
        while (j>0 && !vis[i][j - 1]){
            res.push_back(matrix[i][--j]);
            vis[i][j] = true;
            ++count;
        }
        while (i > 0 && !vis[i - 1][j]){
            res.push_back(matrix[--i][j]);
            vis[i][j] = true;
            ++count;
        }
    }
    return res;
}

//int main()
//{
//    vector<vector<int>> matrix =
//    {};
//    vector<int> res = spiralOrder(matrix);
//    return 0;
//}