#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int x, int y)
{
    if (grid[x][y] == '0')
        return;
    grid[x][y] = '0';
    if (x - 1 >= 0)
        dfs(grid, x - 1, y);
    if (x + 1 < grid.size())
        dfs(grid, x + 1, y);
    if (y - 1 >= 0)
        dfs(grid, x, y - 1);
    if (y + 1 < grid[x].size())
        dfs(grid, x, y + 1);
}

int numIslands(vector<vector<char>>& grid)
{
    int height = grid.size();
    int width = grid[0].size();
    int num = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (grid[i][j]=='1'){
                num++;
                dfs(grid, i, j);
            }
        }
    }
    return num;
}

//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> grid(n, vector<char>(m));
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            cin >> grid[i][j];
//        }
//    }
//    cout << numIslands(grid);
//    system("pause");
//    return 0;
//}