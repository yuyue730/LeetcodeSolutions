#ifndef _BINARYTREE_IMPL_H
#define _BINARYTREE_IMPL_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class BinaryTreeImpl {
public:
    BinaryTreeImpl() {
        cout << "Impl object for Leetcode Binary Tree problems constructed.\n";
    }

    // 94. Binary Tree Inorder Traversal
    vector<int> inorderTraversal94(TreeNode* root) {
        vector<int> results;
        if (root == NULL) {
            return results;
        }
        inorderTraversal94DFS(root, results);
        return results;
    }

    void inorderTraversal94DFS(
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
    vector<TreeNode *> generateTrees95(int n) {
        vector<TreeNode *> result;
        if (n == 0) {
            return result;
        }
        return generateTrees95Rec(1, n);
    }

    vector<TreeNode *> generateTrees95Rec(int start, int end) {
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
    bool isValidBST98(TreeNode* root)
    {
        if (root == NULL) {
            return true;
        }

        return isValidBST98PreOrder(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST98PreOrder(
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
    void recoverTree99(TreeNode* root)
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

    void recoverTree99InOrder(
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
    bool isSymmetric101(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetric101DFS(root->left, root->right);
    }

    bool isSymmetric101DFS(
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
    vector<vector<int>> levelOrder102(TreeNode* root) {
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
    vector<vector<int>> zigzagLevelOrder103(TreeNode* root)
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
    int maxDepth104(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(maxDepth104(root->left), maxDepth104(root->right));
    }

    // 105. Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode* buildTree105(
        vector<int>& preorder, vector<int>& inorder
    ) {
        int preLeft = 0, preRight = preorder.size() - 1;
        int inLeft = 0, inRight = inorder.size() - 1;
        return buildTree105helper(
            preorder, 0, preorder.size() - 1,
            inorder, 0, inorder.size() - 1
        );
    }

    TreeNode * buildTree105helper(
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

    // 106. Construct Binary Tree from Inorder and Postorder Traversal
    TreeNode * buildTree106(
        vector<int>& inorder, vector<int>& postorder
    ) {
        int inLeft = 0, inRight = inorder.size() - 1;
        int postLeft = 0, postRight = postorder.size() - 1;
        return buildTree106helper(
            inorder, 0, inorder.size() - 1,
            postorder, 0, postorder.size() - 1
        );
    }

    TreeNode * buildTree106helper(
        const vector<int>& in, int inLeft, int inRight, 
        const vector<int>& post, int postLeft, int postRight
    ) {
        if (inLeft > inRight || postLeft > postRight) {
            return NULL;
        }

        TreeNode * cur = new TreeNode(post[postRight]);
        int i = inLeft;
        for (; i <= inRight; ++i) {
            if (in[i] == cur->val) {
                break;
            }
        }

        cur->left = buildTree106helper(
            in, inLeft, i - 1, post, postLeft, postLeft + i - inLeft - 1
        );
        cur->right = buildTree106helper(
            in, i + 1, inRight, post, postLeft + i - inLeft, postRight - 1
        );

        return cur;
    }

    // 108. Convert Sorted Array to Binary Search Tree
    TreeNode * sortedArrayToBST108(vector<int>& nums) {
        return sortedArrayToBST108helper(nums, 0, nums.size() - 1);
    }

    TreeNode * sortedArrayToBST108helper(
        const vector<int>& arr, int left, int right
    ) {
        if (left > right) {
            return NULL;
        }

        int mid = (left + right) / 2;
        TreeNode * cur = new TreeNode(arr[mid]);

        cur->left = sortedArrayToBST108helper(arr, left, mid - 1);
        cur->right = sortedArrayToBST108helper(arr, mid + 1, right);
        return cur;
    }

    // 109. Convert Sorted List to Binary Search Tree
    TreeNode * sortedListToBST109(ListNode* head) {
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

    // 110. Balanced Binary Tree
    bool isBalanced110(TreeNode* root)
    {
        return (checkDepth110(root) != -1);
    }

    int checkDepth110(TreeNode * cur)
    {
        if (cur == NULL) {
            return 0;
        }

        int leftDepth = checkDepth110(cur->left);
        if (leftDepth == -1) {
            return -1;
        }
        int rightDepth = checkDepth110(cur->right);
        if (rightDepth == -1) {
            return -1;
        }

        if (abs(leftDepth - rightDepth) > 1) 
            return -1;
        else return max(leftDepth, rightDepth) + 1;
    }

    // 112. Path Sum
    bool hasPathSum112(TreeNode* root, int sum)
    {
        if (root == NULL || sum < 0) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {
            return true;
        }

        return hasPathSum112(root->left, sum - root->val)
            || hasPathSum112(root->right, sum - root->val);
    }

    // 113. Path Sum II
    vector<vector<int>> pathSum113(TreeNode* root, int sum) {
        vector<vector<int>> allResults;
        if (root == NULL) {
            return allResults;
        }
        vector<int> curResult;
        pathSum113helper(curResult, allResults, sum, root);
        return allResults;
    }

    void pathSum113helper(
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
    void flatten114(TreeNode* root) {
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

    // 116. Populating Next Right Pointers in Each Node
    // 117. Populating Next Right Pointers in Each Node II
    Node* connect116(Node* root) {
        if (!root) {
            return NULL;
        }

        vector<Node *> * curLevel = new vector<Node *>();
        curLevel->push_back(root);
        while (!curLevel->empty()) {
            vector<Node *> * nextLevel = new vector<Node *>();

            for (int i = 0; i < curLevel->size(); ++i) {
                if (i < curLevel->size() - 1) {
                    curLevel->at(i)->next = curLevel->at(i + 1);
                }

                if ((*curLevel)[i]->left) {
                    nextLevel->push_back((*curLevel)[i]->left);
                }
                if ((*curLevel)[i]->right) {
                    nextLevel->push_back((*curLevel)[i]->right);
                }
            }

            curLevel = nextLevel;
        }

        return root;
    }

    // 124. Binary Tree Maximum Path Sum
    int maxPathSum124(TreeNode* root)
    {
        if (root == NULL) {
            return 0;
        }

        int result = INT_MIN;
        maxPathSum124helper(root, result);
        return result;
    }

    int maxPathSum124helper(TreeNode * cur, int & result)
    {
        if (cur == NULL) {
            return 0;
        }

        int left = max(maxPathSum124helper(cur->left, result), 0);
        int right = max(maxPathSum124helper(cur->right, result), 0);
        result = max(result, left + right + cur->val);
        return max(left, right) + cur->val;
    }

    // 144. Binary Tree Preorder Traversal
    vector<int> preorderTraversal144(TreeNode* root)
    {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        stack<TreeNode *> preStk({root});
        while (!preStk.empty()) {
            TreeNode *cur = preStk.top();
            preStk.pop();
            result.push_back(cur->val);
            if (cur->right) {
                preStk.push(cur->right);
            }
            if (cur->left) {
                preStk.push(cur->left);
            }
        }

        return result;
    }

    // 199. Binary Tree Right Side View
    vector<int> rightSideView199(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode *> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            result.push_back(node_queue.back()->val);
            int q_size = node_queue.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode * cur = node_queue.front();
                node_queue.pop();
                if (cur->left) {
                    node_queue.push(cur->left);
                }
                if (cur->right) {
                    node_queue.push(cur->right);
                }
            }
        }

        return result;
    }

    // 222. Count Complete Tree Nodes
    int countNodes222(TreeNode* root) {
        if (!root) {
            return 0;
        }

        TreeNode *p_left = root->left;
        int h_left = 1;
        while (p_left) {
            h_left++;
            p_left = p_left->left;
        }

        TreeNode *p_right = root->right;
        int h_right = 1;
        while (p_right) {
            h_right++;
            p_right = p_right->right;
        }

        if (h_left == h_right) {
            return pow(2, h_left) - 1;
        } else {
            return countNodes222(root->left) + countNodes222(root->right) + 1;
        }
    }

    // 226. Invert Binary Tree
    TreeNode* invertTree226(TreeNode* root) {
        if (!root) {
            return NULL;
        }

        TreeNode * tmp = invertTree226(root->left);
        root->left = invertTree226(root->right);
        root->right = tmp;
        return root;
    }

    // 230. Kth Smallest Element in a BST
    int kthSmallest230(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }
        stack<TreeNode*> node_stk;
        TreeNode * cur = root;
        int ct = 0;

        while (cur || !node_stk.empty()) {
            while (cur) {
                node_stk.push(cur);
                cur = cur->left;
            }

            cur = node_stk.top();
            node_stk.pop();
            ++ct;
            if (ct == k) {
                return cur->val;
            }
            cur = cur->right;
        }

        return 0;
    }

    // 235. Lowest Common Ancestor of a Binary Search Tree
    TreeNode* lowestCommonAncestor235(
        TreeNode* root, TreeNode* p, TreeNode* q
    ) {
        if (!root) {
            return NULL;
        }

        if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor235(root->right, p, q);
        }

        if (root->val > max(p->val, q->val)) {
            return lowestCommonAncestor235(root->left, p, q);
        }

        return root;
    }

    // 236. Lowest Common Ancestor of a Binary Tree
    TreeNode* lowestCommonAncestor236(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }

        TreeNode * left = lowestCommonAncestor236(root->left, p, q);
        TreeNode * right = lowestCommonAncestor236(root->right, p, q);

        if (left && right) {
            return root;
        } else {
            return left ? left : right;
        }
    }

    // 250. Count Univalue Subtrees
    int countUnivalSubtrees250(TreeNode* root) {
        int result = 0;
        is_unival(root, -1, result);
        return result;
    }

    bool is_unival(TreeNode * cur, int val, int &result) {
        if (!cur) {
            return true;
        }

        bool is_left_univ = is_unival(cur->left, cur->val, result);
        bool is_right_univ = is_unival(cur->right, cur->val, result);
        if (!is_left_univ || !is_right_univ) {
            return false;
        }

        ++result;
        return cur->val == val;
    }
};

#endif