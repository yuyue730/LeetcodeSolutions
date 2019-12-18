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
        cout << "2 next large is [" << implObj->inorderSuccessor510(root)->val << "]\n\n";
    }

    // 513. Find Bottom Left Tree Value Test
    void findBottomLeftValue513Test() {
        cout << "513. Find Bottom Left Tree Value test starts.\n";
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);

        cout << "Left most node value in the last row = [" 
            << implObj->findBottomLeftValue513(root) << "]\n\n";
        return;
    }

    // 514. Freedom Trail Test
    void findRotateSteps514Test() {
        cout << "514. Freedom Trail test starts.\n";
        cout << "ring = godding, key = gd => steps = [" 
            << implObj->findRotateSteps514("godding", "gd") << "]\n\n";
        return;
    }

    // 515. Find Largest Value in Each Tree Row Test
    void largestValues515Test() {
        cout << "515. Find Largest Value in Each Tree Row test starts.\n";
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->right = new TreeNode(2);

        TreeNode* cur = root->left;
        cur->left = new TreeNode(5);
        cur->right = new TreeNode(3);

        cur = root->right;
        cur->right = new TreeNode(9);
        vector<int> result = implObj->largestValues515(root);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 516. Longest Palindromic Subsequence Test
    void longestPalindromeSubseq516Test() {
        cout << "516. Longest Palindromic Subsequence test starts.\n";
        cout << "Longest palindromic subsequence of bbbab = [" 
            << implObj->longestPalindromeSubseq516("bbbab") << "]\n\n";
        return;
    }

    // 517. Super Washing Machines Test
    void findMinMoves517Test() {
        cout << "517. Super Washing Machines test starts.\n";
        vector<int> machines = {0, 0, 11, 5};
        cout << "Minimum Number of moves = [" << implObj->findMinMoves517(machines) << "]\n\n";
        return;
    }

    // 518. Coin Change 2 Test
    void change518Test() {
        cout << "518. Coin Change 2 test starts.\n";
        vector<int> coins = {1, 2 ,5};
        cout << "# of ways to reach 5 = [" << implObj->change518(5, coins) << "]\n\n";
        return;
    }

    // 519. Random Flip Matrix Test
    void Solution519Test() {
        cout << "519. Random Flip Matrix test starts.\n";
        Session5Impl::Solution519 sol(2, 3);
        vector<int> flip1 = sol.flip();
        cout << "Flip 1 = [" << flip1[0] << ", " << flip1[1] << "]\n";
        vector<int> flip2 = sol.flip();
        cout << "Flip 1 = [" << flip2[0] << ", " << flip2[1] << "]\n";
        vector<int> flip3 = sol.flip();
        cout << "Flip 1 = [" << flip3[0] << ", " << flip3[1] << "]\n\n";
        sol.reset();
    }

    // 523. Continuous Subarray Sum Test
    void checkSubarraySum523Test() {
        cout << "523. Continuous Subarray Sum test starts.\n";
        vector<int> nums = {23, 2, 6, 4, 7};
        int k = 6;
        cout << "Can get subarray sum = [" << implObj->checkSubarraySum523(nums, k) << "]\n\n";
        return;
    }

    // 524. Longest Word in Dictionary through Deleting Test
    void findLongestWord524Test() {
        cout << "524. Longest Word in Dictionary through Deleting test starts.\n";
        string s = "abpcplea";
        vector<string> d = {"ale", "apple", "monkey", "plea"};
        cout << "Longest word = [" << implObj->findLongestWord524(s, d) << "]\n\n";
        return;
    }

    // 525. Contiguous Array Test
    void findMaxLength525Test() {
        cout << "525. Contiguous Array test starts.\n";
        vector<int> nums = {0, 1, 0};
        cout << "Max Length = [" << implObj->findMaxLength525(nums) << "]\n\n";
        return;
    }

    // 526. Beautiful Arrangement Test
    void countArrangement526Test() {
        cout << "526. Beautiful Arrangement test starts.\n";
        cout << "N = 2; countArrangement = [" << implObj->countArrangement526(2) << "]\n\n";
        return;
    }

private:
    Session5Impl * implObj;
};

#endif