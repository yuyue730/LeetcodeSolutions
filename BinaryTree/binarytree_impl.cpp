#include "binarytree_impl.h"

#include <iostream>
#include <queue>
#include <stack>
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

// 101. Symmetric Tree
bool BinaryTreeImpl::isSymmetric101(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isSymmetric101DFS(root->left, root->right);
}

bool BinaryTreeImpl::isSymmetric101DFS(
    TreeNode *left, TreeNode *right
) {
    if (left == NULL && right == NULL) {
        return true;
    }

    if (left == NULL || right == NULL) {
        return false;
    }

    if (left->val != right->val) {
        return false;
    }

    return isSymmetric101DFS(left->left, right->right)
        && isSymmetric101DFS(left->right, right->left);
}

// 102. Binary Tree Level Order Traversal
vector<vector<int>> BinaryTreeImpl::levelOrder102(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    queue<TreeNode *> curQ;
    curQ.push(root);

    while (!curQ.empty()) {
        vector<int> curLevelVec;
        for (int i = curQ.size(); i > 0; --i) {
            TreeNode *cur = curQ.front();
            curQ.pop();
            curLevelVec.push_back(cur->val);
            if (cur->left) {
                curQ.push(cur->left);
            }
            if (cur->right) {
                curQ.push(cur->right);
            }
        }

        result.push_back(curLevelVec);
    }

    return result;
}

// 103. Binary Tree Zigzag Level Order Traversal
vector<vector<int>> BinaryTreeImpl::zigzagLevelOrder103(TreeNode* root)
{
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    stack<TreeNode *> * curLevel = new stack<TreeNode *>();
    bool isLeft = false;
    curLevel->push(root);

    while (!curLevel->empty()) {
        vector<int> curResult;
        stack<TreeNode *> * nextLevel = new stack<TreeNode *>();

        while (!curLevel->empty()) {
            TreeNode * cur = curLevel->top();
            curLevel->pop();
            curResult.push_back(cur->val);
            if (isLeft) {
                if (cur->left)
                    nextLevel->push(cur->left);
                if (cur->right)
                    nextLevel->push(cur->right);
            } else {
                if (cur->right)
                    nextLevel->push(cur->right);
                if (cur->left)
                    nextLevel->push(cur->left);
            }
        }

        result.push_back(curResult);
        curLevel = nextLevel;
        isLeft = !isLeft;
    }

    return result;
}

// 104. Maximum Depth of Binary Tree (DFS)
int BinaryTreeImpl::maxDepth104(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(maxDepth104(root->left), maxDepth104(root->right));
}

// 105. Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* BinaryTreeImpl::buildTree105(
    vector<int>& preorder, vector<int>& inorder
) {
    int preLeft = 0, preRight = preorder.size() - 1;
    int inLeft = 0, inRight = inorder.size() - 1;
    return buildTree105helper(
        preorder, 0, preorder.size() - 1,
        inorder, 0, inorder.size() - 1
    );
}

TreeNode * BinaryTreeImpl::buildTree105helper(
    const vector<int>& pre, int preLeft, int preRight,
    const vector<int>& in, int inLeft, int inRight
) {
    if (preLeft > preRight || inLeft > inRight) {
        return NULL;
    }

    int i = inLeft;
    for (; i <= inRight; ++i) {
        if (in[i] == pre[preLeft]) {
            break;
        }
    }

    TreeNode * root = new TreeNode(pre[preLeft]);
    root->left = buildTree105helper(
        pre, preLeft + 1, preLeft + i - inLeft,
        in, inLeft, i - 1
    );
    root->right = buildTree105helper(
        pre, preLeft + i - inLeft + 1, preRight,
        in, i + 1, inRight
    );
    return root;
}

// 109. Convert Sorted List to Binary Search Tree
TreeNode * BinaryTreeImpl::sortedListToBST109(ListNode* head) {
    if (head == NULL) {
        return NULL;
    } 
    if (head->next == NULL) {
        return new TreeNode(head->val);
    }

    ListNode * slow = head;
    ListNode * fast = head;
    ListNode * last = slow;
    while (fast->next && fast->next->next) {
        last = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    last->next = NULL;

    TreeNode * root = new TreeNode(slow->val);
    if (slow != head) {
        root->left = sortedListToBST109(head);
    }
    root->right = sortedListToBST109(fast);
    return root;
}

// 113. Path Sum II
vector<vector<int>> BinaryTreeImpl::pathSum113(TreeNode* root, int sum) {
    vector<vector<int>> allResults;
    if (root == NULL) {
        return allResults;
    }
    vector<int> curResult;
    pathSum113helper(curResult, allResults, sum, root);
    return allResults;
}

void BinaryTreeImpl::pathSum113helper(
    vector<int> & curResult,
    vector<vector<int>> & allResults,
    int remain,
    TreeNode * cur
) {
    if (cur == NULL) {
        return;
    }

    curResult.push_back(cur->val);

    if (remain == cur->val && cur->left == NULL && cur->right == NULL) {
        allResults.push_back(curResult);
        curResult.pop_back();
        return;
    }

    pathSum113helper(curResult, allResults, remain - cur->val, cur->left);
    pathSum113helper(curResult, allResults, remain - cur->val, cur->right);
    curResult.pop_back();
}

// 114. Flatten Binary Tree to Linked List
void BinaryTreeImpl::flatten114(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    if (root->left) {
        flatten114(root->left);
    }
    if (root->right) {
        flatten114(root->right);
    }

    TreeNode * tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    while (root->right) {
        root = root->right;
    }
    root->right = tmp;
}