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

// 95. Unique Binary Search Trees II
vector<TreeNode *> BinaryTreeImpl::generateTrees95(int n) {
    vector<TreeNode *> result;
    if (n == 0) {
        return result;
    }
    return generateTrees95Rec(1, n);
}

vector<TreeNode *> BinaryTreeImpl::generateTrees95Rec(int start, int end) {
    vector<TreeNode *> result;
    if (start > end) {
        result.push_back(NULL);
        return result;
    }

    for (int i = start; i <= end; ++i) {
        vector<TreeNode *> left = generateTrees95Rec(start, i - 1);
        vector<TreeNode *> right = generateTrees95Rec(i + 1, end);

        for (int m = 0; m < left.size(); ++m) {
            for (int n = 0; n < right.size(); ++n) {
                TreeNode * cur = new TreeNode(i);
                cur->left = left[m];
                cur->right = right[n];
                result.push_back(cur);
            }
        }
    }
    
    return result;
}