#ifndef _BINARYTREE_TEST_H
#define _BINARYTREE_TEST_H

#include "binarytree_impl.h"

#include <iostream>
using namespace std;

class BinaryTreeTest {
public:
    BinaryTreeTest() {
        cout << "Test object for Leetcode Binary Tree problems constructed.\n";
        implObj = new BinaryTreeImpl();
    }

    // 94. Binary Tree Inorder Traversal Test
    void inorderTraversal94Test() {
        cout << "94. Binary Tree Inorder Traversal test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur = cur->left;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(4);
        root->right = new TreeNode(5);

        vector<int> result = implObj->inorderTraversal94(root);
        cout << "Inorder traversal result [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 95. Unique Binary Search Trees II Test
    void generateTrees95Test() {
        cout << "95. Unique Binary Search Trees II test starts.\n";
        vector<TreeNode *> result = implObj->generateTrees95(3);
        cout << "Can generate " << result.size() << " trees.\n";
        for (int i = 0; i < result.size(); ++i) {
            TreeNode * cur = result[i];
            cout << "i = " << i << "; Root value " << cur->val << "\n";
        }
        return;
    }

    // 98. Validate Binary Search Tree Test
    void isValidBST98Test() {
        cout << "98. Validate Binary Search Tree test starts.\n";

        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        root->left = new TreeNode(3);
        cur = root->left;
        cur->left = new TreeNode(2); cur->right = new TreeNode(4);

        cur = root;
        cur->right = new TreeNode(6);
        cur = cur->right; cur->right = new TreeNode(8);

        cout << "Is Valid BST = [" << (implObj->isValidBST98(root) ? "True" : "False")
            << "]\n\n";
        return;
    }

    // 99. Recover Binary Search Tree Test
    void recoverTree99Test() {
        cout << "99. Recover Binary Search Tree test starts.\n";

        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        root->left = new TreeNode(6);
        cur = root->left;
        cur->left = new TreeNode(2); cur->right = new TreeNode(3);

        cur = root;
        cur->right = new TreeNode(4);
        cur = cur->right; cur->right = new TreeNode(8);

        implObj->recoverTree99(root);
        cout << "Please exam the root [" << root->val << "]\n";
        return;
    }

    // 101. Symmetric Tree Test
    void isSymmetric101Test() {
        cout << "101. Symmetric Tree test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur = cur->left;
        cur->left = new TreeNode(3); cur->right = new TreeNode(4);
        cur = cur->right; cur->left = new TreeNode(5);

        cur = root;
        cur->right = new TreeNode(2);
        cur = cur->right;
        cur->left = new TreeNode(4); cur->right = new TreeNode(3);
        cur = cur->left; cur->right = new TreeNode(5);

        cout << "Is tree symmetirc = [" 
            << (implObj->isSymmetric101(root) ? "True" : "False") << "]\n\n";
        return;
    }

    // 102. Binary Tree Level Order Traversal Test
    void levelOrder102Test() {
        cout << "102. Binary Tree Level Order Traversal test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);  cur->right = new TreeNode(3);
        cur = cur->right;
        cur->left = new TreeNode(4);  cur->right = new TreeNode(5);

        vector<vector<int>> result = implObj->levelOrder102(root);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
    }

    // 103. Binary Tree Zigzag Level Order Traversal Test
    void zigzagLevelOrder103Test() {
        cout << "103. Binary Tree Zigzag Level Order Traversal test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);  cur->right = new TreeNode(3);
        cur = cur->right;
        cur->left = new TreeNode(4);  cur->right = new TreeNode(5);

        vector<vector<int>> result = implObj->zigzagLevelOrder103(root);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
    }

    // 104. Maximum Depth of Binary Tree (DFS) Test
    void maxDepth104Test() {
        cout << "104. Maximum Depth of Binary Tree (DFS) test starts.\n";

        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);  cur->right = new TreeNode(3);
        cur = cur->right;
        cur->left = new TreeNode(4);  cur->right = new TreeNode(5);

        cout << "Max depth = [" << implObj->maxDepth104(root) << "]\n\n";
        return;
    }

    // 105. Construct Binary Tree from Preorder and Inorder Traversal Test
    void buildTree105Test() {
        cout << "105. Construct Binary Tree from Preorder and Inorder Traversal " 
            << "test starts.\n";
        
        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        TreeNode * result = implObj->buildTree105(preorder, inorder);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 106. Construct Binary Tree from Inorder and Postorder Traversal Test
    void buildTree106Test() {
        cout << "106. Construct Binary Tree from Inorder and Postorder Traversal "
            << "test starts.\n";

        vector<int> inorder = {9,3,15,20,7};
        vector<int> postorder = {9,15,7,20,3};
        TreeNode * result = implObj->buildTree106(inorder, postorder);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 108. Convert Sorted Array to Binary Search Tree Test
    void sortedArrayToBST108Test() {
        cout << "108. Convert Sorted Array to Binary Search Tree test starts.\n";
        vector<int> nums = {-10, -3, 0, 5, 9};
        TreeNode * root = implObj->sortedArrayToBST108(nums);
        cout << "Please exam result via debugger. root = [" << root->val << "].\n\n";
        return;
    }

    // 109. Convert Sorted List to Binary Search Tree Test
    void sortedListToBST109Test() {
        cout << "109. Convert Sorted List to Binary Search Tree test starts.\n";
        ListNode * head = new ListNode(-10);
        ListNode * cur = head;
        cur->next = new ListNode(-3); cur = cur->next;
        cur->next = new ListNode(0); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(9);

        TreeNode * result = implObj->sortedListToBST109(head);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 110. Balanced Binary Tree Test
    void isBalanced110Test() {
        cout << "110. Balanced Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(11);
        cur = cur->left;
        cur->left = new TreeNode(7); cur->right = new TreeNode(2);

        cur = root;
        cur->right = new TreeNode(8); cur = cur->right;
        cur->left = new TreeNode(13); cur->right = new TreeNode(4);
        cur = cur->right;
        cur->left = new TreeNode(5); cur->right = new TreeNode(1);

        cout << "isBalanced = [" << (implObj->isBalanced110(root) ? "True" : "False") 
            << "].\n\n";
        return;
    }

    // 112. Path Sum Test
    void hasPathSum112Test() {
        cout << "112. Path Sum test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(11);
        cur = cur->left;
        cur->left = new TreeNode(7); cur->right = new TreeNode(2);

        cur = root;
        cur->right = new TreeNode(8); cur = cur->right;
        cur->left = new TreeNode(13); cur->right = new TreeNode(4);
        cur = cur->right;
        cur->left = new TreeNode(5); cur->right = new TreeNode(1);

        cout << "hasPathSum = [" << (implObj->hasPathSum112(root, 22) ? "True" : "False")
            << "].\n\n";
        return;
    }

    // 113. Path Sum II Test
    void pathSum113Test() {
        cout << "113. Path Sum II test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(4);
        cur = cur->left; cur->left = new TreeNode(11);
        cur = cur->left;
        cur->left = new TreeNode(7); cur->right = new TreeNode(2);

        cur = root;
        cur->right = new TreeNode(8); cur = cur->right;
        cur->left = new TreeNode(13); cur->right = new TreeNode(4);
        cur = cur->right;
        cur->left = new TreeNode(5); cur->right = new TreeNode(1);

        vector<vector<int>> result = implObj->pathSum113(root, 22);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
        return;
    }

    // 114. Flatten Binary Tree to Linked List Test
    void flatten114Test() {
        cout << "114. Flatten Binary Tree to Linked List test starts.\n";
        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2); cur = cur->left;
        cur->left = new TreeNode(3); cur->right = new TreeNode(4);

        cur = root;
        cur->right = new TreeNode(5); cur = cur->right;
        cur->right = new TreeNode(6);

        implObj->flatten114(root);
        cout << "Please exam result via debugger. root = [" << root->val << "].\n\n";
        return;
    }

    // 116. Populating Next Right Pointers in Each Node Test
    void connect116Test() {
        cout << "116. Populating Next Right Pointers in Each Node test starts.\n";
        Node * root = new Node(
            3, 
            new Node(9, NULL, NULL, NULL), 
            new Node(
                20, 
                new Node(15, NULL, NULL, NULL), 
                new Node(7, NULL, NULL, NULL), 
                NULL
            ),
            NULL
        );

        Node * result = implObj->connect116(root);
        cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
        return;
    }

    // 124. Binary Tree Maximum Path Sum Test
    void maxPathSum124Test()
    {
        cout << "124. Binary Tree Maximum Path Sum test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        cout << "BT Max Path Sum = [" << implObj->maxPathSum124(root) << "]\n\n";
        return;
    }

    // 144. Binary Tree Preorder Traversal Test
    void preorderTraversal144Test() {
        cout << "144. Binary Tree Preorder Traversal test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        vector<int> result = implObj->preorderTraversal144(root);
        cout << "Pre order output = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "].\n\n";
        return;
    }

    // 199. Binary Tree Right Side View
    void rightSideView199Test() {
        cout << "199. Binary Tree Right Side View test starts.\n";
        TreeNode * root = new TreeNode(-10);
        TreeNode * cur = root;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);
        cur = cur->right;
        cur->left = new TreeNode(15); cur->right = new TreeNode(7);

        vector<int> result = implObj->rightSideView199(root);
        cout << "Right side view vector [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "].\n\n";
        return;
    }

    // 222. Count Complete Tree Nodes Test
    void countNodes222Test() {
        cout << "222. Count Complete Tree Nodes test starts.\n";
        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(3);
        cur = root->left;
        cur->left = new TreeNode(4);
        cur->right = new TreeNode(5);
        cur = root->right;
        cur->left = new TreeNode(6);

        cout << "# of nodes = [" << implObj->countNodes222(root) << "]\n\n";
        return;
    }

    // 226. Invert Binary Tree Test
    void invertTree226Test() {
        cout << "226. Invert Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(4);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(7);
        cur = root->left;
        cur->left = new TreeNode(1);
        cur->right = new TreeNode(3);
        cur = root->right;
        cur->left = new TreeNode(6);
        cur->right = new TreeNode(9);

        TreeNode * result = implObj->invertTree226(root);
        cout << "Please exam result " << result->val << "\n\n";
        return;
    }

    // 230. Kth Smallest Element in a BST Test
    void kthSmallest230Test() {
        cout << "230. Kth Smallest Element in a BST test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(6);
        cur = root->left;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(4);

        cout << "Kth smallest elem = [" << implObj->kthSmallest230(root, 2) << "]\n\n";
        return;
    }

    // 235. Lowest Common Ancestor of a Binary Search Tree Test
    void lowestCommonAncestor235Test() {
        cout << "235. Lowest Common Ancestor of a Binary Search Tree test starts.\n";
        TreeNode * root = new TreeNode(6);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(8);

        cur = root->left;
        cur->left = new TreeNode(0);
        cur->right = new TreeNode(4);
        
        cur = cur->right;
        cur->left = new TreeNode(3);
        TreeNode * p = cur->left;
        cur->right = new TreeNode(5);
        TreeNode * q = cur->right;

        cur = root->right;
        cur->left = new TreeNode(7);
        cur->right = new TreeNode(9);

        cout << "Common ancester of <3, 5> is [" 
            << implObj->lowestCommonAncestor235(root, p, q)->val << "]\n\n";
        return;
    }

    // 236. Lowest Common Ancestor of a Binary Tree Test
    void lowestCommonAncestor236Test() {
        cout << "236. Lowest Common Ancestor of a Binary Tree test starts.\n";
        TreeNode * root = new TreeNode(3);
        TreeNode * cur = root;
        cur->left = new TreeNode(5);
        TreeNode * p = cur->left;
        cur->right = new TreeNode(1);

        cur = root->left;
        cur->left = new TreeNode(6);
        cur->right = new TreeNode(2);

        cur = cur->right;
        cur->left = new TreeNode(7);
        cur->right = new TreeNode(4);
        TreeNode * q = cur->right;

        cur = root->right;
        cur->left = new TreeNode(0);
        cur->right = new TreeNode(8);

        cout << "Common ancester of <5, 4> is [" 
            << implObj->lowestCommonAncestor236(root, p, q)->val << "]\n\n";
        return;
    }

    // 250. Count Univalue Subtrees Test
    void countUnivalSubtrees250Test() {
        cout << "250. Count Univalue Subtrees test starts.\n";
        TreeNode * root = new TreeNode(5);
        TreeNode * cur = root;
        cur->left = new TreeNode(1);
        cur->right = new TreeNode(5);

        cur = root->left;
        cur->left = new TreeNode(5);
        cur->right = new TreeNode(5);

        cur = root->right;
        cur->right = new TreeNode(5);
        cout << "# of unival substrees = [" << implObj->countUnivalSubtrees250(root) 
            << "]\n\n";
        return;
    }

private:
    BinaryTreeImpl * implObj;
};

#endif