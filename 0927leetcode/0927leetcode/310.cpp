#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int novis(vector<bool> vis)
{
    int num = 0;
    for (int i = 0; i < vis.size(); i++){
        if (vis[i] == 0)
            num++;
    }
    return num;
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
    vector<int> degree(n);
    vector<int> res;
    vector<bool> vis(n);
    queue<int> q;
    for (auto it = edges.begin(); it != edges.end();it++){
        degree[it->first]++;
        degree[it->second]++;
    }
    for (int i = 0; i < n; i++){
        if (degree[i] == 1)
            q.push(i);
    }
    if (q.size() == n){
        for (int i = 0; i < n; i++)
            res.push_back(i);
        return res;
    }
    while (!q.empty() && novis(vis)>2){
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        for (auto it = edges.begin(); it != edges.end(); it++){
            if (it->first == cur){
                degree[it->second]--;
                if (degree[it->second] == 1)
                    q.push(it->second);
            }
            if (it->second == cur){
                degree[it->first]--;
                if (degree[it->first] == 1)
                    q.push(it->first);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (!vis[i])
            res.push_back(i);
    }
    return res;
}

//int main()
//{
//    int n = 6;
//    vector < pair < int, int >> prerequisites = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 3, 4 }, { 4, 5 } };
//    vector<int> res = findMinHeightTrees(n, prerequisites);
//    system("pause");
//    return 0;
//}