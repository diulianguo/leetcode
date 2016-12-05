#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int NodeSum(TreeNode* p)
{
    int left = 0, right = 0;
    if (p->left == NULL && p->right == NULL)
        return 1;
    if (p->left)
        left = NodeSum(p->left);
    if (p->right)
        right = NodeSum(p->right);
    return 1 + left + right;
}

int kthSmallest(TreeNode* root, int k)
{
    if (root->left){
        if (NodeSum(root->left) >= k)
            return kthSmallest(root->left, k);
        if (NodeSum(root->left) < k - 1)
            return kthSmallest(root->right, k - NodeSum(root->left) - 1);
        return root->val;
    } else{
        if (k == 1)
            return root->val;
        else
            return kthSmallest(root->right, k - 1);
    }
    return root->val;
}

//int main()
//{
//    TreeNode root(1);
//    cout << kthSmallest(&root, 1);
//    system("pause");
//    return 0;
//}