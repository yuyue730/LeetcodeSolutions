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

// 102. Binary Tree Level Order Traversal Test
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

// 103. Binary Tree Zigzag Level Order Traversal Test
void BinaryTreeTest::zigzagLevelOrder103Test() {
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
void BinaryTreeTest::maxDepth104Test() {
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
void BinaryTreeTest::buildTree105Test() {
    cout << "105. Construct Binary Tree from Preorder and Inorder Traversal " 
        << "test starts.\n";
    
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode * result = implObj->buildTree105(preorder, inorder);
    cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
    return;
}

// 106. Construct Binary Tree from Inorder and Postorder Traversal Test
void BinaryTreeTest::buildTree106Test() {
    cout << "106. Construct Binary Tree from Inorder and Postorder Traversal "
        << "test starts.\n";

    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode * result = implObj->buildTree106(inorder, postorder);
    cout << "Please exam result via debugger. root = [" << result->val << "].\n\n";
    return;
}

// 109. Convert Sorted List to Binary Search Tree Test
void BinaryTreeTest::sortedListToBST109Test() {
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

// 113. Path Sum II Test
void BinaryTreeTest::pathSum113Test() {
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
void BinaryTreeTest::flatten114Test() {
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
void BinaryTreeTest::connect116Test() {
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