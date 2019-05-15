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

private:
    // 94. Binary Tree Inorder Traversal helper
    void inorderTraversal94DFS(TreeNode *curNode, vector<int> & result);

    // 95. Unique Binary Search Trees II helper
    vector<TreeNode*> generateTrees95Rec(int start, int end);
};

#endif