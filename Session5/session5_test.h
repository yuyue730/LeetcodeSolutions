#ifndef _SESSION_5_TEST_H
#define _SESSION_5_TEST_H

#include "session5_impl.h"

class Session5Test {
public:
    Session5Test() {
        cout << "Test object for Leetcode Session 5 problems constructed.\n";
        implObj = new Session5Impl();
    }

    // 503. Next Greater Element II Test
    void nextGreaterElements503Test() {
        cout << "503. Next Greater Element II test starts.\n";
        vector<int> nums = {1, 2, 1};
        vector<int> result = implObj->nextGreaterElements503(nums);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 505. The Maze II Test
    void shortestDistance505Test() {
        cout << "505. The Maze II test starts.\n";
        vector<vector<int>> maze = {
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0}
        };
        vector<int> start = {0, 4};
        vector<int> end = {4, 4};

        cout << "Shortest distance = [" << implObj->shortestDistance505(maze, start, end)
            << "]\n\n";
    }

    // 508. Most Frequent Subtree Sum Test
    void findFrequentTreeSum508Test() {
        cout << "508. Most Frequent Subtree Sum test starts.\n";
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(2);
        root->right = new TreeNode(-3);
        vector<int> result = implObj->findFrequentTreeSum508(root);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 509. Fibonacci Number Test
    void fib509Test() {
        cout << "509. Fibonacci Number test starts.\n";
        cout << "N = 10 => Sum = [" << implObj->fib509(10) << "]\n\n";
        return;
    }

    // 510. Inorder Successor in BST II Test
    void inorderSuccessor510Test() {
        cout << "510. Inorder Successor in BST II test starts.\n";
        Node510 * root;
        root->val = 2;
        root->left = new Node510();
        root->left->val = 1;
        root->left->parent = root;
        root->right = new Node510();
        root->right->val = 3;
        root->right->parent = root;

        cout << "1 next large is [" << implObj->inorderSuccessor510(root->left)->val << "]\n";
        cout << "2 next large is [" << implObj->inorderSuccessor510(root)->val << "]\n";
    }

private:
    Session5Impl * implObj;
};

#endif