#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool noswap(vector<int> nums, int i, int index)
{
    for (int j = index; j < i; j++){
        if (nums[j] == nums[i])
            return true;
    }
    return false;
}

void permUni(vector<vector<int>>& res,vector<int>& nums, int index)
{
    if (index == nums.size()){
        res.push_back(nums);
        return;
    }
    for (int j = index; j < nums.size(); j++){
        //if (j>index && nums[j] == nums[index])//并不能保证没有重复序列出现
        //    continue;
        //if (j>index && nums[j] == nums[j - 1])
        //    continue;
        //如果当前j指向的数字前面出现过，则不交换
        if (noswap(nums, j, index))
            continue;
        swap(nums[j], nums[index]);
        permUni(res, nums, index + 1);
        swap(nums[j], nums[index]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    permUni(res, nums, 0);
    return res;
}

//int main()
//{
//    vector<int> nums = { 1, 1, 2, 2 };
//    vector<vector<int>> res = permuteUnique(nums);
//    return 0;
//}