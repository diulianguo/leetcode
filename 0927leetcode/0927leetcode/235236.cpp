#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//第一次自己写对的回溯，纪念一下
//vector<TreeNode*> FatherNode(TreeNode *root, TreeNode *p, vector<TreeNode*>& pfather)
//{
//    TreeNode *tmp = root;
//    vector<TreeNode*> pfather1, pfather2;
//    if (tmp){
//        if (tmp == p)//如果按值来查找，出现值相同的节点就完蛋了
//            pfather.push_back(tmp);
//        else{
//            pfather.push_back(tmp);
//            pfather1 = pfather;//如果沿左路下降
//            FatherNode(tmp->left, p, pfather);
//
//            if (pfather[pfather.size() - 1] != p){
//                pfather = pfather1;
//                FatherNode(tmp->right, p, pfather);//如果沿右路下降
//            }
//        }
//    }
//    return pfather;
//}
//
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//    TreeNode *tmp = root;
//    vector<TreeNode*> pfather, qfather;
//    pfather = FatherNode(root, p, pfather);
//    qfather = FatherNode(root, q, qfather);
//    for (int i = pfather.size() - 1; i >= 0; i--){
//        for (int j = qfather.size() - 1; j >= 0; j--){
//            if (pfather[i] == qfather[j])
//                return pfather[i];
//        }
//    }
//}

//二叉树
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//    if (root == NULL || root == p || root == q)
//        return root;
//    //查看左子树中是否有p,q的公共祖先
//    TreeNode* left = lowestCommonAncestor(root->left, p, q);
//    //查看右子树中是否有p,q的公共祖先
//    TreeNode* right = lowestCommonAncestor(root->right, p, q);
//    if (left&&right)
//        return root;
//    return left == NULL ? right : left;
//}

//二叉搜索树
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (root->val > max(p->val, q->val))
        return lowestCommonAncestor(root->left, p, q);
    if (root->val > min(p->val, q->val) && root->val < max(p->val, q->val))
        return root;
    if (root->val < min(p->val, q->val))
        return lowestCommonAncestor(root->right, p, q);
}

//int main()
//{
//    TreeNode root(3), p1(5), p2(1), p3(6), p4(2), p5(2), p6(8), p7(7), p8(4);
//    root.left = &p1;
//    root.right = &p2;
//    p1.left = &p3;
//    p1.right = &p4;
//    p2.left = &p5;
//    p2.right = &p6;
//    p4.left = &p7;
//    p4.right = &p8;
//    TreeNode* tmp = lowestCommonAncestor(&root, &p5, &p6);
//    cout << tmp->val;
//    system("pause");
//    return 0;
//}