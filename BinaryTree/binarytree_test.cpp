#include "binarytree_test.h"

BinaryTreeTest::BinaryTreeTest() {
    cout << "Test object for Leetcode Binary Tree problems constructed.\n";
    implObj = new BinaryTreeImpl();
}

// 94. Binary Tree Inorder Traversal Test
void BinaryTreeTest::inorderTraversal94Test() {
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
void BinaryTreeTest::generateTrees95Test() {
    cout << "95. Unique Binary Search Trees II test.\n";
    vector<TreeNode *> result = implObj->generateTrees95(3);
    cout << "Can generate " << result.size() << " trees.\n";
    for (int i = 0; i < result.size(); ++i) {
        TreeNode * cur = result[i];
        cout << "i = " << i << "; Root value " << cur->val << "\n";
    }
    return;
}