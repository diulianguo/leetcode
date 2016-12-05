#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs3(vector<vector<int>>& res, vector<int>& temp, int target, int num,int min)
{
    if (target == 0 && num == 0){
        res.push_back(temp);
        return;
    } else{
        int cur = min;
        while (cur <= target && cur < 10){
            temp.push_back(cur);//������������
            dfs3(res, temp, target - cur, num - 1, cur + 1);//��num���������ڻ��м�����
            temp.pop_back();//���������������֮ǰ��״̬
            cur++;
        }
    }
}

vector<vector<int>> combinationSum3(int num, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    if (target == 0)
        return res;
    dfs3(res, temp, target, num, 1);
    return res;
}

//int  main()
//{
//    int k, n;
//    cin >> k >> n;
//    vector<vector<int>> ans = combinationSum3(k, n);
//    return 0;
//}