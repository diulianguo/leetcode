#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& temp, int min,int max, int num)
{
    if (num == 0){
        res.push_back(temp);
        return;
    } else{
        int cur = min;
        while (cur <= max){
            temp.push_back(cur);//假设加上这个数
            dfs(res, temp, cur + 1, max, num - 1);
            temp.pop_back();//不加这个数，返回之前的状态
            cur++;
        }
    }
}

vector<vector<int>> combine(int n,int k)
{
    vector<vector<int>> res;
    vector<int> temp;
    if (n == 0)
        return res;
    dfs(res, temp, 1, n, k);
    return res;
}

//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<vector<int>> res = combine(n, k);
//    return 0;
//}