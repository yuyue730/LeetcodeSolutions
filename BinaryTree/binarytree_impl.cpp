#include "binarytree_impl.h"

#include <iostream>
using namespace std;

BinaryTreeImpl::BinaryTreeImpl() {
    cout << "Impl object for Leetcode Binary Tree problems constructed.\n";
}

// 94. Binary Tree Inorder Traversal
vector<int> BinaryTreeImpl::inorderTraversal94(TreeNode* root) {
    vector<int> results;
    if (root == NULL) {
        return results;
    }
    inorderTraversal94DFS(root, results);
    return results;
}

void BinaryTreeImpl::inorderTraversal94DFS(
    TreeNode *curNode, vector<int> & result
) {
    if (curNode->left) {
        inorderTraversal94DFS(curNode->left, result);
    }
    result.push_back(curNode->val);
    if (curNode->right) {
        inorderTraversal94DFS(curNode->right, result);
    }
}