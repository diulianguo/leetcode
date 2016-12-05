#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool vis[5][5];
struct node{
    int x;
    int y;
};
queue<node> s;

void bfs(vector<vector<int>> maze, int x, int y)
{
    int curx;
    int cury;
    node cur;
    if (!vis[x][y]){
        cur.x = x;
        cur.y = y;
        s.push(cur);
    }
    if (x == 4 && y == 4)
        return;

    node child;
    //先横着走，再竖着走
    if (y + 1 < maze.size() && maze[x][y + 1] == 0 && !vis[x][y + 1]){
        child.x = x;
        child.y = y + 1;
        bfs(maze, child.x, child.y);
    } else if (x + 1 < maze.size() && maze[x + 1][y] == 0 && !vis[x + 1][y]){
        child.x = x + 1;
        child.y = y;
        bfs(maze, child.x, child.y);
    } else{
        s.pop();
        cur = s.back();
        bfs(maze, cur.x, cur.y);
    }
}

//int main()
//{
//    memset(vis, 0, sizeof(vis));
//    vector<vector<int>> maze(5, vector<int>(5));
//    for (int i = 0; i < maze.size(); i++){
//        for (int j = 0; j < maze.size(); j++){
//            cin >> maze[i][j];
//        }
//    }
//
//    bfs(maze, 0, 0);
//    while (!s.empty()){
//        node cur = s.front();
//        s.pop();
//        cout << "(" << cur.x << ", " << cur.y << ")" << endl;
//    }
//
//    system("pause");
//    return 0;
//}
