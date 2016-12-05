#include<iostream>
#include<vector>
using namespace std;

//dp[i]表示target为i时有多少种拆分方法
int combinationSum4(vector<int>& nums, int target)
{
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++){
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] <= i)
                dp[i] += dp[i - nums[j]];//target拆分为i+x，则dp[target]=dp[target-i];i从1到target-1循环
        }
    }
    return dp[target];
}

//int main()
//{
//    int target;
//    vector<int> nums = { 1, 2, 3 };
//    while (cin >> target){
//        cout << combinationSum4(nums, target);
//    }
//}