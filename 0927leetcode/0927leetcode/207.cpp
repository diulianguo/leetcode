#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<int> indegree(numCourses, 0);
    queue<int> q;
    vector<bool> vis(numCourses, 0);
    for (auto it = prerequisites.begin(); it != prerequisites.end(); it++){
        indegree[it->first]++;
    }
    for (int i = 0; i < indegree.size(); i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++){
            if (it->second == cur && !vis[it->first]){
                indegree[it->first]--;
                if (indegree[it->first] == 0)
                    q.push(it->first);
            }
        }
    }
    for (int i = 0; i < numCourses; i++){
        if (!vis[i]){
            return false;
        }
    }
    return true;
}

//int main()
//{
//    int n = 2;
//    vector < pair < int, int >> prerequisites = { { 1, 0 }};
//    cout << canFinish(n, prerequisites);
//    system("pause");
//    return 0;
//}