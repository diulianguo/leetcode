#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++){
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }
    int maxSum = INT_MIN;
    for (int i = 0; i < dp.size(); i++){
        if (dp[i]>maxSum)
            maxSum = dp[i];
    }
    return maxSum;
}

//int main()
//{
//    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
//    cout << maxSubArray(nums) << endl;
//    system("pause");
//    return 0;
//}