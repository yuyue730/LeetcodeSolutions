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
// (Unique Binary Search Trees is a Dynamic Programming problem)
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

// 98. Validate Binary Search Tree
bool BinaryTreeImpl::isValidBST98(TreeNode* root)
{
    if (root == NULL) {
        return true;
    }

    return isValidBST98PreOrder(root, LONG_MIN, LONG_MAX);
}

bool BinaryTreeImpl::isValidBST98PreOrder(
    TreeNode *cur, long minVal, long maxVal
) {
    if (cur == NULL) {
        return true;
    }

    if (cur->val < minVal || cur->val > maxVal) {
        return false;
    }

    return isValidBST98PreOrder(cur->left, minVal, cur->val)
        && isValidBST98PreOrder(cur->right, cur->val, maxVal);
}

// 99. Validate Binary Search Tree
void BinaryTreeImpl::recoverTree99(TreeNode* root)
{
    if (root == NULL) {
        return;
    }

    vector<TreeNode *> allNodes;
    vector<int> allValues;
    recoverTree99InOrder(root, allNodes, allValues);

    sort(allValues.begin(), allValues.end());
    for (int i = 0; i < allValues.size(); ++i) {
        allNodes[i]->val = allValues[i];
    }
    return;
}

void BinaryTreeImpl::recoverTree99InOrder(
    TreeNode * cur, 
    vector<TreeNode *> & allNodes, 
    vector<int> & allValues
) {
    if (cur == NULL) {
        return;
    }

    if (cur->left) {
        recoverTree99InOrder(cur->left, allNodes, allValues);
    }

    allNodes.push_back(cur);
    allValues.push_back(cur->val);

    if (cur->right) {
        recoverTree99InOrder(cur->right, allNodes, allValues);
    } 
}