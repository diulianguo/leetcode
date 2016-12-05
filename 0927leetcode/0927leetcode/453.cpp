#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minMoves(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 1; i < nums.size(); i++){
        res += nums[i] - nums[0];
    }
    return res;
}

int minMoves2(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), res = 0;
    int mid = n / 2;
    for (int i = 0; i < mid; i++){
        res += nums[mid] - nums[i];
    }
    for (int i = mid + 1; i < n; i++){
        res += nums[i] - nums[mid];
    }
    return res;
}