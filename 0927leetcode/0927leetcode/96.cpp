#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int numTrees(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++){
        for (int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

void GenerateTree(vector<TreeNode*>& res, int start, int end)
{
    if (start > end){
        res.push_back(NULL);
        return;
    }

    for (int i = start; i <= end; i++){
        vector<TreeNode*> left, right;
        GenerateTree(left, start, i - 1);
        GenerateTree(right, i + 1, end);
        for (int j = 0; j < left.size(); j++){
            for (int k = 0; k < right.size(); k++){
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                res.push_back(root);
            }
        }
    }
}

vector<TreeNode*> generateTrees(int n)
{
    vector<TreeNode*> res;
    if (n == 0)
        return res;
    GenerateTree(res, 1, n);
    return res;
}

//int main()
//{
//    int n;
//    cin >> n;
//    //cout << numTrees(n) << endl;
//    vector<TreeNode*> res = generateTrees(n);
//    return 0;
//}