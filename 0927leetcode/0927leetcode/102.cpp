#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<vector<int>> levelOrder(TreeNode* root)
{
    TreeNode* tmp = root;
    vector<vector<int>> res;
    if (!root)
        return res;
    vector<int> curlevel;
    queue<TreeNode*> q1;
    q1.push(tmp);
    do{
        queue<TreeNode*> q2;
        while (!q1.empty()){
            tmp = q1.front();
            curlevel.push_back(tmp->val);
            q1.pop();
            if (tmp->left)
                q2.push(tmp->left);
            if (tmp->right)
                q2.push(tmp->right);
        }
        q1 = q2;
        res.push_back(curlevel);
        curlevel.clear();
    } while (!q1.empty());
    return res;
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    TreeNode* tmp = root;
    vector<vector<int>> res;
    if (!root)
        return res;
    vector<int> curlevel;
    queue<TreeNode*> q1;
    q1.push(tmp);
    do{
        queue<TreeNode*> q2;
        while (!q1.empty()){
            tmp = q1.front();
            curlevel.push_back(tmp->val);
            q1.pop();
            if (tmp->left)
                q2.push(tmp->left);
            if (tmp->right)
                q2.push(tmp->right);
        }
        q1 = q2;
        res.push_back(curlevel);
        curlevel.clear();
    } while (!q1.empty());
    return vector<vector<int>>(res.rbegin(),res.rend());
}

//int main()
//{
//    TreeNode root(3), p9(9), p20(20), p15(15), p7(7);
//    root.left = &p9;
//    root.right = &p20;
//    p20.left = &p15;
//    p20.right = &p7;
//    vector<vector<int>> res = levelOrderBottom(&root);
//    return 0;
//}