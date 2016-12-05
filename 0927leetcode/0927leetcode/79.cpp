#include<iostream>
#include<vector>
#include<string>
using namespace std;

//bool vis[100][100];
////从(i,j)位置开始走，手否能找到字符串s
//bool Search(vector<vector<char>> board, int i,int j,string s)
//{
//    if (s.length() == 0)
//        return true;
//    vector<vector<int>> neigh = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//    for (int k = 0; k < neigh.size(); k++){
//        int x = i + neigh[k][0];
//        int y = j + neigh[k][1];
//        if (x>=0 && x < board.size() && y>=0 && y < board[0].size() && board[x][y]==s[0] && !vis[x][y]){
//            vis[x][y] = true;
//            if (s.length()==1 || Search(board, x, y, s.substr(1, s.size() - 1)))
//                return true;
//            vis[x][y] = false;
//        }
//    }
//    return false;
//}
//
//bool exist(vector<vector<char>>& board, string word)
//{
//    for (int i = 0; i < board.size(); i++){
//        for (int j = 0; j < board[i].size(); j++){
//            if (board[i][j] == word[0]){
//                vis[i][j] = true;
//                if (Search(board, i, j, word.substr(1, word.size() - 1)))
//                    return true;
//                vis[i][j] = false;
//            }
//        }
//    }
//    return false;
//}

//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    vector<vector<char>> board(m, vector<char>(n));
//    for (int i = 0; i < m; i++){
//        for (int j = 0; j < n; j++){
//            cin >> board[i][j];
//        }
//    }
//    memset(vis, 0, sizeof(vis));
//    string word;
//    cin >> word;
//    cout << exist(board, word);
//    return 0;
//}