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

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    bool left = false;
    queue<TreeNode*> t;
    vector<vector<int>> res;
    if (root == NULL)
        return res;
    t.push(root);
    while (!t.empty()){
        vector<int> temp;
        int cursize = t.size();
        for (int i = 0; i < cursize; i++)
        {
            TreeNode* cur = t.front();
            t.pop();
            temp.push_back(cur->val);
            if (cur->left)
                t.push(cur->left);
            if (cur->right)
                t.push(cur->right);
        }
        if (left){
            vector<int> tmp(temp.rbegin(), temp.rend());
            temp = tmp;
        }
        left = !left;
        res.push_back(temp);
    }
    return res;
}

//int main()
//{
//    TreeNode p1(1),p2(2),p3(3), p4(4), p5(5);
//    p1.left = &p2;
//    p1.right = &p3;
//    p2.left = &p4;
//    p3.right = &p5;
//    vector<vector<int>> res = zigzagLevelOrder(&p1);
//    return 0;
//}