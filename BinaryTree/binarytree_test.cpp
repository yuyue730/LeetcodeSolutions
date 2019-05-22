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
void BinaryTreeTest::isValidBST98Test() {
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
void BinaryTreeTest::recoverTree99Test() {
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
void BinaryTreeTest::isSymmetric101Test() {
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

// 102. Binary Tree Level Order Traversal
void BinaryTreeTest::levelOrder102Test() {
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