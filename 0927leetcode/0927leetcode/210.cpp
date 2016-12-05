#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<int> order;
    vector<int> res;
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
        order.push_back(cur);
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
            return res;
        }
    }
    return order;
}

//int main()
//{
//    int n = 4;
//    vector < pair < int, int >> prerequisites = { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } };
//    vector<int> res = findOrder(n, prerequisites);
//    system("pause");
//    return 0;
//}