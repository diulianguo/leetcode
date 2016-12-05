#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int treeHeight(TreeNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL){
        return 1;
    } 
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
    if (root == NULL)
        return true;
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    if (abs(rh - lh) > 1){
        return false;
    } else{
        return isBalanced(root->left) && isBalanced(root->right);
    }
}