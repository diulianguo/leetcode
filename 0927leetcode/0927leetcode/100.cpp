#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == NULL && q == NULL){
        return true;
    }
    if (p && q && p->val == q->val){
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}

//int main()
//{
//    TreeNode root1(1), root2(1), p1(2), t1(2), p2(3), t2(3);
//    root1.left = &p1;
//    root1.right = &p2;
//    root2.left = &t1;
//    root2.right = &t2;
//    cout << isSameTree(&root1, &root2);
//    system("pause");
//    return 0;
//}