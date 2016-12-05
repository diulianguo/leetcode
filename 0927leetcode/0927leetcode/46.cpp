#include<iostream>
#include<vector>
using namespace std;

void swapArray(vector<int>& temp, int i, int j)
{
    //交换i和j两个位置的字符
    int cur = temp[i];
    temp[i] = temp[j];
    temp[j] = cur;
}

void perm(vector<vector<int>>& res, vector<int>& temp, int index)
{
    //将temp中从index位置开始，与其他元素（包括自己）分别交换,这样所有的叶节点就是全部的解
    if (index == temp.size()){
        res.push_back(temp);
        return;
    }
    for (int i = index; i < temp.size(); i++){
        swapArray(temp, index, i);//index和i位置的元素交换，换完以后继续深度向下交换
        perm(res, temp, index + 1);
        swapArray(temp, index, i);//恢复原状不交换
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> temp = nums;
    vector<vector<int>> res;
    perm(res, temp, 0);
    return res;
}

//int main()
//{
//    vector<int> nums = { 1, 2, 3 };
//    vector<vector<int>> res = permute(nums);
//}