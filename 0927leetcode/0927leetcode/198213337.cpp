#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

//dp[i]表示到第i个房子的最大收益，第i个房子可能抢也可能不抢
///198
//int rob(vector<int>& nums)
//{
//    if (nums.size() == 0)
//        return 0;
//    if (nums.size() == 1)
//        return nums[0];
//    if (nums.size() == 2)
//        return max(nums[0], nums[1]);
//    vector<int> dp(nums.size(), 0);
//    dp[0] = nums[0];
//    dp[1] = max(nums[0],nums[1]);
//    for (int i = 2; i < nums.size(); i++){
//        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//    }
//    int maxMoney = 0;
//    for (int i = 0; i < dp.size(); i++){
//        if (dp[i]>maxMoney)
//            maxMoney = dp[i];
//    }
//    return maxMoney;
//}

//213
//int rob(vector<int>& nums)
//{
//    if (nums.size() == 0)
//        return 0;
//    if (nums.size() == 1)
//        return nums[0];
//    if (nums.size() == 2)
//        return max(nums[0], nums[1]);
//    vector<int> dp(nums.size(), 0);
//    dp[0] = nums[0];
//    for (int i = 1; i < nums.size(); i++){
//        dp[i] = max(dp[i - 1], (i == 1 ? 0 : dp[i - 2]) + nums[i]);
//    }
//    int res1 = dp[nums.size() - 2];
//    for (int i = 0; i < dp.size(); i++){
//        dp[i] = 0;
//    }
//    dp[1] = nums[1];
//    for (int i = 2; i < nums.size(); i++){
//        dp[i] = max(dp[i - 1], (i == 2 ? 0 : dp[i - 2]) + nums[i]);
//    }
//    int res2 = dp[nums.size() - 1];
//    return max(res1, res2);
//}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<TreeNode*, int> dp1;//偷该节点
map<TreeNode*, int> dp2;//不偷该节点

void dfs(TreeNode* node)
{
    if (node == NULL)
        return;

    dfs(node->left);
    dfs(node->right);  

    dp1[node] = dp2[node->left] + dp2[node->right] + node->val;
    dp2[node] = max(max(dp1[node->left] + dp1[node->right], dp2[node->left] + dp2[node->right]), max(dp1[node->left] + dp2[node->right], dp1[node->right] + dp2[node->left]));
}

int rob(TreeNode* root)
{
    dfs(root);
    return max(dp1[root], dp2[root]);
}


//int main()
//{
//    //vector<int> nums = { 1, 2, 1, 1 };
//    /*TreeNode root(2), p1(3), p2(1);
//    root.left = NULL;
//    root.right = &p1;
//    p1.left = NULL;
//    p1.right = &p2;
//    cout << rob(&root) << endl;*/
//    unsigned int x = 50;
//    unsigned int y = 2;
//    cout << x*y << endl;
//    system("pause");
//    return 0;
//}
//int rightn = 6;
//int guess(int num)
//{
//    if (num > rightn)
//        return 1;
//    else if (num < rightn)
//        return -1;
//    else
//        return 0;
//}

//int guessNumber(int n)
//{
//    int i = 1, j = n, mid;
//    while (i<j){
//        mid = i + (j - i) / 2;
//        if (guess(mid) == -1)
//            i = mid + 1;
//        else if (guess(mid) == 1)
//            j = mid - 1;
//        else
//            return mid;
//    }
//    return i;
//}

//int main()
//{
//    int n;
//    cin >> n;
//    cout << guessNumber(n) << endl;
//    system("pause");
//    return 0;
//}