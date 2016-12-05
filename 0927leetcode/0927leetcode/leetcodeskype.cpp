#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<int>> twoSum(vector<int> nums, int target)
{
    vector<vector<int>> res;
    unordered_map<int, int> dic;
    for (int i = 0; i < nums.size(); i++){
        vector<int> tmp;
        if (dic.find(nums[i]) == dic.end())
            dic[nums[i]] = i;
        if (dic.find(target - nums[i]) != dic.end()){
            int last = dic[target - nums[i]];
            int cur = i;
            if (cur != last){
                tmp.push_back(last);
                tmp.push_back(cur);
                res.push_back(tmp);
            }
        }
    }
    return res;
}

//int main()
//{
//    vector<int> nums = { 1, 2, 3, 3, 4, 5 };
//    vector<vector<int>> res = twoSum(nums, 6);
//    return 0;
//}