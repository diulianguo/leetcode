#include<iostream>
#include<vector>
using namespace std;

//dp[i]��ʾtargetΪiʱ�ж����ֲ�ַ���
int combinationSum4(vector<int>& nums, int target)
{
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++){
        for (int j = 0; j < nums.size(); j++){
            if (nums[j] <= i)
                dp[i] += dp[i - nums[j]];//target���Ϊi+x����dp[target]=dp[target-i];i��1��target-1ѭ��
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