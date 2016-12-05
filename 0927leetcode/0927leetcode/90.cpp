#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> sets;
    vector<int> temp;
    sets.push_back(temp);
    if (n == 0)
        return sets;

    sort(nums.begin(), nums.end());
    int cur, pre;
    int index = 0;//上次加进来子集的起始index
    for (int i = 0; i < n; i++){
        cur = nums[i];
        vector<int> add;
        int m = sets.size();
        int start = 0;
        if (i>0 && nums[i] == nums[i - 1])
            start = index;
        for (int j = start; j < m; j++){
            add = sets[j];
            add.push_back(cur);
            sets.push_back(add);
        }
        index = m;

        pre = cur;
    }
    return sets;
}

//int main()
//{
//    vector<int> nums = { 4, 4, 4, 1, 4 };
//    subsetsWithDup(nums);
//}