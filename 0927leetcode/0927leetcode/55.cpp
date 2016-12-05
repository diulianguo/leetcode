#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums)
{
    int farest = 0;
    for (int i = 0; i <= farest&& farest<nums.size() - 1; i++){
        if (nums[i] + i>farest)
            farest = nums[i] + i;
    }
    if (farest >= nums.size() - 1)
        return true;
    else
        return false;
}