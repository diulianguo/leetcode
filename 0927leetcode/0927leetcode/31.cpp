#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();
    int pos = -1;
    for (int i = n - 1; i > 0; i--){
        if (nums[i] > nums[i - 1]){
            pos = i - 1;
            break;
        }
    }
    if (pos == -1){
        sort(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > 0; i--){
        if (nums[i] > nums[pos]){
            swap(nums[i], nums[pos]);
            break;
        }
    }
    auto it = nums.begin();
    it += pos + 1;
    sort(it, nums.end());
}

//int main()
//{
//    vector<int> nums = { 1, 1 };
//    nextPermutation(nums);
//    return 0;
//}

