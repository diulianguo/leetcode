#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp,int target,int index)
{
    int n = candidates.size();
    if (target == 0){
        res.push_back(temp);
        return;
    } else{
        for (int i = index; i < n; i++){
            if (candidates[i]>target)
                continue;
            temp.push_back(candidates[i]);//假设加上这个数
            dfs(candidates, res, temp, target - candidates[i],i);
            temp.pop_back();//不加这个数，返回之前的状态
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    int n = candidates.size();
    vector<vector<int>> res;
    vector<int> temp;
    if (n == 0)
        return res;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, res, temp, target, 0);
    return res;
}

//int  main()
//{
//    int target = 7;
//    vector<int> candidates = { 2, 3, 6, 7 };
//    vector<vector<int>> ans = combinationSum(candidates, target);
//    return 0;
//}

