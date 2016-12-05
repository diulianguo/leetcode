#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs2(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int target, int index)
{
    int n = candidates.size();
    if (target == 0){
        res.push_back(temp);
        return;
    } else{
        for (int i = index; i < n; i++){
            if (candidates[i]>target)
                continue;
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);//假设加上这个数
            dfs2(candidates, res, temp, target - candidates[i], i + 1);
            temp.pop_back();//不加这个数，返回之前的状态
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    int n = candidates.size();
    vector<vector<int>> res;
    vector<int> temp;
    if (n == 0)
        return res;
    sort(candidates.begin(), candidates.end());
    dfs2(candidates, res, temp, target, 0);
    return res;
}

//int  main()
//{
//    int target = 8;
//    vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
//    vector<vector<int>> ans = combinationSum2(candidates, target);
//    return 0;
//}

