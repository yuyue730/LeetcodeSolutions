#ifndef _BINARYTREE_IMPL_H
#define _BINARYTREE_IMPL_H

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTreeImpl {
public:
    BinaryTreeImpl();

    // 94. Binary Tree Inorder Traversal
    vector<int> inorderTraversal94(TreeNode* root);

    // 95. Unique Binary Search Trees II
    vector<TreeNode*> generateTrees95(int n);

    // 98. Validate Binary Search Tree
    bool isValidBST98(TreeNode* root);

    // 99. Recover Binary Search Tree
    void recoverTree99(TreeNode* root);

private:
    // 94. Binary Tree Inorder Traversal helper
    void inorderTraversal94DFS(TreeNode *curNode, vector<int> & result);

    // 95. Unique Binary Search Trees II helper
    vector<TreeNode*> generateTrees95Rec(int start, int end);

    // 98. Validate Binary Search Tree helper
    bool isValidBST98PreOrder(TreeNode *cur, long minVal, long maxVal);

    // 99. Recover Binary Search Tree helper
    void recoverTree99InOrder(
        TreeNode * cur, 
        vector<TreeNode *> & allNodes, 
        vector<int> & allValues
    );
};

#endif