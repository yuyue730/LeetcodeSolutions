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

    // 527. Word Abbreviation Test
    void wordsAbbreviation527Test() {
        cout << "527. Word Abbreviation test starts.\n";
        vector<string> dict = {
            "like", "god", "internal", "me", "internet", 
            "interval", "intension", "face", "intrusion"
        };
        vector<string> result = implObj->wordsAbbreviation527(dict);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 528. Random Pick with Weight Test
    void Solution528Test() {
        cout << "528. Random Pick with Weight test starts.\n";
        vector<int> w = {1, 3};
        Session5Impl::Solution528 obj(w);
        cout << "Result = [";
        for (int i = 0; i < 10; ++i) {
            cout << obj.pickIndex() << ((i == 9) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 529. Minesweeper Test
    void updateBoard529Test() {
        cout << "529. Minesweeper test starts.\n";
        vector<vector<char>> board = {
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'M', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'}
        };

        vector<int> click = {3, 0};
        vector<vector<char>> result = implObj->updateBoard529(board, click);

        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[0].size(); ++j) {
                cout << result[i][j] << ((j == result[0].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 530. Minimum Absolute Difference in BST Test
    void getMinimumDifference530Test() {
        cout << "530. Minimum Absolute Difference in BST test starts.\n";
        TreeNode* root = new TreeNode(1);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(2);

        cout << "Min Abs Diff = [" << implObj->getMinimumDifference530(root) << "]\n\n";
        return;
    }

    // 531. Lonely Pixel I Test
    void findLonelyPixel531Test() {
        cout << "531. Lonely Pixel I test starts.\n";
        vector<vector<char>> picture = {
            {'W', 'W', 'B'},
            {'W', 'B', 'W'},
            {'B', 'W', 'W'}
        };

        cout << "Number of lonely pixel = [" << implObj->findLonelyPixel531(picture) << "]\n\n";
        return;
    }

    // 536. Construct Binary Tree from String Test
    void str2tree536Test() {
        cout << "536. Construct Binary Tree from String test starts.\n";
        TreeNode* result = implObj->str2tree536("4(2(3)(1))(6(5))");
        cout << "4(2(3)(1))(6(5)) will generate root = [" << result->val << "]\n\n";
        return;
    }

    // 538. Convert BST to Greater Tree Test
    void convertBST538Test() {
        cout << "538. Convert BST to Greater Tree test starts.\n";
        TreeNode * root = new TreeNode(5);
        root->left = new TreeNode(2);
        root->right = new TreeNode(13);
        TreeNode * result = implObj->convertBST538(root);
        cout << "BST Greater root = [" << result->val << "]\n\n";
        return;
    }

    // 539. Minimum Time Difference Test
    void findMinDifference539Test() {
        cout << "539. Minimum Time Difference test starts.\n";
        vector<string> timeSpots = {"23:59", "00:00"};
        cout << "Min Diff = [" << implObj->findMinDifference539(timeSpots) << "]\n\n";
        return;
    }
    
    // 540. Single Element in a Sorted Array Test
    void singleNonDuplicate540Test() {
        cout << "540. Single Element in a Sorted Array test starts.\n";
        vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
        cout << "Non dup element = [" << implObj->singleNonDuplicate540(nums) << "]\n\n";
        return;
    }

    // 542. 01 Matrix Test
    void updateMatrix542Test() {
        cout << "542. 01 Matrix test starts.\n";
        vector<vector<int>> matrix = {
            {0, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
        };
        vector<vector<int>> result = implObj->updateMatrix542(matrix);
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
        return;
    }

private:
    Session5Impl * implObj;
};

#endif