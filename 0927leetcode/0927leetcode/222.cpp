#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root)
{
    if (root == NULL)
        return 0;
    TreeNode *ln = root;
    TreeNode *rn = root;
    int lh = 0, rh = 0;
    while (ln){
        ln = ln->left;
        lh++;
    }
    while (rn){
        rn = rn->right;
        rh++;
    }
    if (lh == rh)
        return pow(2, lh) - 1;
    else
        return countNodes(root->left) + countNodes(root->right) + 1;
}