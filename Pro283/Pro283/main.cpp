#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int len = nums.size();
    int n = len;
    int i = 0;
    while(i<n){
        if (nums[i] == 0){
            for (int j = i + 1; j < len; j++)
                nums[j - 1] = nums[j];
            nums[len - 1] = 0;
            n--;
        } else
            i++;
    }
}

//出现超过n/3次的元素
//vector<int> majorityElement(vector<int>& nums)
//{
//    int s = nums.size();
//    if (!s)
//        return{};
//    vector<int> res;
//    int count = 0, candidate1 = 0, candidate2 = 0;
//
//    nth_element(nums.begin(), nums.begin() + s / 3, nums.end());
//
//    candidate1 = nums[s / 3];
//    for (int i = 0; i<s; i++)
//        nums[i] == candidate1 ? count++ : count;
//    if (count>s / 3)
//        res.push_back(candidate1);
//
//    nth_element(nums.begin(), nums.begin() + 2 * s / 3, nums.end());
//
//    count = 0, candidate2 = nums[2 * s / 3];
//    for (int i = 0; i<s; i++)
//        nums[i] == candidate2 ? count++ : count;
//    if (count>s / 3 && candidate1 != candidate2)
//        res.push_back(candidate2);
//
//    return res;
//}

//出现超过n/2次的元素
int majorityElement(vector<int>& nums)
{
    int len = nums.size();
    if (!len)
        return 0;
    vector<int> res;
    int candidate = 0, count = 0;

    nth_element(nums.begin(), nums.begin() + len / 2, nums.end());

    candidate = nums[len / 2];
    for (int i = 0; i < len; i++){
        nums[i] == candidate ? count++ : count;
    }
    if (count>len / 2)
        return candidate;
    return 0;
}

bool containsDuplicate(vector<int>& nums)
{
    int len = nums.size();
    if (len < 2){
        return false;
    }
    sort(nums.begin(), nums.end());
    int i = 0;
    while(i < len){
        int j = 1;
        while (nums[i + j] == nums[i]){
            j++;
        }
        i += j;
        if (j >1)
            return true;
    }
    return false;
}

void rotate(vector<int>& nums, int k)
{
    int temp;
    int numsSize = nums.size();
    k = k%numsSize;
    for (int i = 0, j = numsSize - k - 1; i < j; i++, j--)
    {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    for (int i = numsSize - k, j = numsSize - 1; i < j; i++, j--)
    {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    for (int i = 0, j = numsSize - 1; i < j; i++, j--)
    {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
}

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    if (nums.size() == 0)
        return false;
    int temp[200000] = { 0 };
    vector<int> diff;
    for (int i = 0; i < nums.size(); i++)
    {
        if (temp[100000 + nums[i]] > 0)
        {
            diff.push_back(i + 1 - temp[100000 + nums[i]]);
            temp[100000 + nums[i]] = i + 1;
        } else
            temp[100000 + nums[i]] = i + 1;
    }
    for (int i = 0; i < diff.size(); i++)
    {
        if (diff[i] <= k)
            return true;
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    if (nums.size() == 0)
        return false;
    int temp[200000] = { 0 };
    vector<int> diffindex;
    vector<int> diff;
    for (int i = 0; i < nums.size(); i++)
    {
        if (temp[100000 + nums[i]] > 0)
        {
            diffindex.push_back(i + 1 - temp[100000 + nums[i]]);
            temp[100000 + nums[i]] = i + 1;
        } else
            temp[100000 + nums[i]] = i + 1;
    }
    for (int i = 0; i < diff.size(); i++)
    {
        if (diff[i] <= k)
            return true;
    }
    return false;
}

//可以有多笔交易
//int maxProfit(vector<int>& prices)
//{
//    int len = prices.size();
//    int maxprofit = 0;
//    for (int i = 1; i < len; i++){
//        maxprofit += max(prices[i] - prices[i - 1], 0);
//    }
//    return maxprofit;
//}

//只能一笔交易
int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    int maxprofit = 0;
    //暴力算法超时了
    /*for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (prices[j] - prices[i]>maxprofit)
                maxprofit = prices[j] - prices[i];
        }
    }*/
    int minprice = INT_MAX;
    for (int i = 0; i < len; i++){
        if (prices[i] < minprice)
            minprice = prices[i];
        maxprofit = max(maxprofit, prices[i] - minprice);
    }
    return maxprofit;
}

int minimumTotal(vector<vector<int>>& triangle)
{
    /*int n = triangle.size();
    int minSum = triangle[0][0];
    int minPoint;
    for (int i = 1; i < n; i++){
        int len = triangle[i].size();
        minPoint = INT_MAX;
        for (int j = 0; j < len; j++){
            minPoint = min(minPoint, triangle[i][j]);
        }
        minSum += minPoint;
    }
    return minSum;*/
    if (triangle.empty() || triangle[0].empty()) return 0;
    vector<int> dp = triangle.back();
    for (int i = triangle.size() - 2; i >= 0; i--){
        for (int j = 0; j < triangle[i].size(); j++)
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
    }
    return dp[0];
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> triangle;
    for (int i = 0; i < numRows; i++){
        triangle.push_back(vector<int>(i + 1,1));
        for (int j = 1; j < i; j++)
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
    return triangle;
}

vector<int> getRow(int rowIndex)
{
    vector<int> curRow(rowIndex + 1, 1);
    for (int i = 2; i < rowIndex+1; i++){
        for (int j = i - 1; j>0; j--)
            curRow[j] = curRow[j - 1] + curRow[j];
    }
    return curRow;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = 0, j = 0;
    int len1 = m, len2 = n;
    while (i < len1 && j < len2){
        if (nums1[i] < nums2[j]){
            i++;
        } else{
            for (int k = len1-1; k >= i; k--){
                nums1[k + 1] = nums1[k];
            }
            nums1[i] = nums2[j];
            len1++;
            j++;
        }
    }
    while (j < n){
        nums1[len1++] = nums2[j++];
    }
}

vector<int> plusOne(vector<int>& digits)
{
    int len = digits.size();
    for (int i = len - 1; i >= 0; i--){
        if (digits[i] != 9){
            digits[i]++;
            return digits;
        } else
            digits[i] = 0;
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
}

int removeDuplicates(vector<int>& nums)
{
    int len = nums.size();
    int rlen = len;
    int j = 0;
    for (int i = 0; i <len; i++){
        while (i!=len-1 && nums[i] == nums[i + 1]){
            rlen--;
            i++;
        }
        nums[j++] = nums[i];
    }
    return rlen;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

//根据中序和后序确定二叉树
//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
//{
//    TreeNode* root = nullptr;
//    int m = inorder.size();
//    int n = postorder.size();
//    if (m == 0 || n == 0)
//        return root;
//    root = new TreeNode(postorder[n - 1]);
//    stack<TreeNode*> s;
//    s.push(root);
//    int post_ptr = n - 2;
//    int in_ptr = m - 1;
//    int flag = 0;//构造右子树，一般后序中根节点前面的节点是右子树的根节点
//    TreeNode* cur = s.top();//当前根节点
//    while (post_ptr >= 0){
//        if (!s.empty() && s.top()->val == inorder[in_ptr]){
//            //没有右子树
//            cur = s.top();//新的当前节点
//            s.pop();
//            in_ptr--;
//            flag = 1;//构造左子树
//        } else{
//            if (flag){
//                cur->left = new TreeNode(postorder[post_ptr]);
//                cur = cur->left;
//                s.push(cur);
//                post_ptr--;
//                flag = 0;
//            } else{
//                cur->right = new TreeNode(postorder[post_ptr]);
//                cur = cur->right;
//                s.push(cur);
//                post_ptr--;
//            }
//        }
//    }
//    return root;
//}

//根据前序和中序确定二叉树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    TreeNode* root = nullptr;
    int m = inorder.size();
    int n = preorder.size();
    if (m == 0 || n == 0)
        return root;
    root = new TreeNode(preorder[0]);
    stack<TreeNode*> s;
    s.push(root);
    int pre_ptr = 1;
    int in_ptr = 0;
    int flag = 0;//构造左子树，一般前序中根节点后面的节点是左子树的根节点
    TreeNode* cur = s.top();//当前根节点
    while (pre_ptr < n){
        if (!s.empty() && s.top()->val == inorder[in_ptr]){
            cur = s.top();
            s.pop();
            in_ptr++;
            flag = 1;//相等没有左子树，不等有左子树
        } else{
            if (flag==0){
                cur->left = new TreeNode(preorder[pre_ptr]);
                cur = cur->left;
                s.push(cur);
                pre_ptr++;
            } else{
                cur->right = new TreeNode(preorder[pre_ptr]);
                cur = cur->right;
                s.push(cur);
                flag = 0;
                pre_ptr++;
            }
        }
    }
    return root;
}

int main()
{
    /*vector<int> nums(6); 
    for (int i = 0; i < 6; i++){
        cin >> nums[i];
    }*/
    /*vector<int> res = majorityElement(nums);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }*/
    /*rotate(nums,3);
    for (int i = 0; i < 7; i++){
        cout<< nums[i]<<" ";
    }*/
    //cout << majorityElement(nums);
    //cout << maxProfit(nums);
    /*vector<vector<int>> triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
    cout << minimumTotal(triangle);*/
    /*int n;
    cin >> n;
    vector<vector<int>> triangle = generate(n);
    for (int i = 0; i < n; i++){
        cout << "[";
        for (int j = 0; j < triangle[i].size()-1; j++)
            cout << triangle[i][j] << " ";
        cout << triangle[i][triangle[i].size() - 1] << "]" << endl;
    }*/
    /*vector<int> nums1 = { 1, 2, 4, 5 };
    nums1.resize(10);
    vector<int> nums2 = { 3, 7 };
    merge(nums1, 4, nums2, 2);*/
    /*vector<int> nums1 = { 1, 1, 2 };
    cout << removeDuplicates(nums1);*/
    //vector<int> nums2 = plusOne(nums1);
    vector<int> inorder = { 2,1,3 };
    vector<int> preorder = { 1,2,3};
    TreeNode* tree = buildTree(preorder,inorder);
    system("pause");
    return 0;
}