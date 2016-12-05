#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> sets;
    int n = nums.size();
    vector<int> temp;
    sets.push_back(temp);
    if (n == 0)
        return sets;
    for (int i = 0; i < n; i++){
        int cur = nums[i];
        vector<int> add;
        int m = sets.size();
        for (int j = 0; j < m; j++){
            add = sets[j];
            add.push_back(cur);
            sets.push_back(add);
        }
    }
    return sets;
}

//int main()
//{
//    vector<int> nums = { 1, 2, 3 };
//    subsets(nums);
//}