#ifndef _DP_TEST_H
#define _DP_TEST_H

#include <iostream>
#include "dp_impl.h"
using namespace std;

class DpTest {
public:
    DpTest() {
        cout << "Test object for Leetcode Dynamic Programming problems constructed.\n";
        implObj = new DpImpl();
    }

    // 44. Wildcard Matching Test
    void isMatch44Test() {
        cout << "44. Wildcard Matching test starts.\n";
        cout << "*a*b and adceb isMatch = [" << implObj->isMatch44("adceb", "*a*b") << "].\n\n";
        return;
    }

    // 62. Unique Paths Test
    void uniquePaths62Test() {
        cout << "62. Unique Paths test starts.\n";
        cout << "3 * 2 grid will have " << implObj->uniquePaths62(3, 2) << " methods.\n\n";
        return;
    }

    // 63. Unique Paths II Test
    void uniquePathsWithObstacles63Test() {
        cout << "63. Unique Paths II test starts.\n";
        vector<vector<int>> obstacles = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };
        cout << "Number of unique paths = " << implObj->uniquePathsWithObstacles63(obstacles) << "\n\n";
        return;
    }

    // 64. Minimum Path Sum Test
    void minPathSum64Test() {
        cout << "64. Minimum Path Sum test starts.\n";
        vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
        };
        cout << "Grid will have min path = " << implObj->minPathSum64(grid) << ".\n\n";
        return;
    }

    // 70. Climbing Stairs Test
    void climbStairs70Test() {
        cout << "70. Climbing Stairs test starts.\n";
        cout << "3 starts will have " << implObj->climbStairs70(3) << " ways.\n\n";
        return;
    }

    // 72. Edit Distance Test
    void minDistance72Test() {
        cout << "72. Edit Distance test starts.\n";
        cout << "'horse' and 'ros' will have " << implObj->minDistance72("horse", "ros") << " steps.\n\n";
        return;
    }

    // 91. Decode Ways Test
    void numDecodings91Test() {
        cout << "91. Decode Ways test starts.\n";
        cout << "226 will be decoded into [" << implObj->numDecodings91("12") << "].\n\n";
        return;
    }

    // 96. Unique Binary Search Trees Test
    void numTrees96Test() {
        cout << "96. Unique Binary Search Trees test starts.\n";
        cout << "4 will generate [" << implObj->numTrees96(4) << "]\n";
        cout << "5 will generate [" << implObj->numTrees96(5) << "]\n\n";
        return;
    }

    // 97. Interleaving String Test
    void isInterleave97Test() {
        cout << "97. Interleaving String test.\n";
        string s1 = "a", s2 = "", s3 = "a";//s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
        cout << "s1 and s2 can generage 3 [" << (implObj->isInterleave97(s1, s2, s3) ? "True" : "False")
            << "].\n\n";
        return; 
    }

    // 120. Triangle Test
    void minimumTotal120Test() {
        cout << "120. Triangle test starts.\n";
        vector<vector<int>> triangle = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
        };

        cout << "Min total = [" << implObj->minimumTotal120(triangle) << "]\n\n";
        return;
    }

    // 123. Best Time to Buy and Sell Stock III Test
    void maxProfit123Test() {
        cout << "123. Best Time to Buy and Sell Stock III test starts.\n";
        vector<int> prices = {3,3,5,0,0,3,1,4};
        cout << "Max Profit = [" << implObj->maxProfit123(prices) << "]\n\n";
        return;
    }

    // 132. Palindrome Partitioning II Test
    void minCut132Test() {
        cout << "132. Palindrome Partitioning II test starts.\n";
        cout << "Min Cut = " << implObj->minCut132("efe") << "\n\n";
        return;
    }

    // 139. Word Break Test
    void wordBreak139Test() {
        cout << "139. Word Break test starts.\n";
        string s = "leetcode";
        vector<string> strVec = {"leet", "code"};
        cout << "Word can break = [" << (implObj->wordBreak139(s, strVec) ? "True" : "False")
            << "].\n\n";
        return;
    }

    // 152. Maximum Product Subarray Test
    void maxProduct152Test() {
        cout << "152. Maximum Product Subarray test starts.\n";
        vector<int> nums = {2,3,-2,4};
        cout << "Max Product = [" << implObj->maxProduct152(nums) << "]\n\n";
        return;
    }

    // 198. House Robber Test
    void rob198Test() {
        cout << "198. House Robber test starts.\n";
        vector<int> nums = {1,2,3,1};
        cout << "Max money = [" << implObj->rob198(nums) << "]\n\n";
        return;
    }

    // 221. Maximal Square Test
    void maximalSquare221Test() {
        cout << "198. House Robber test starts.\n";
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };
        cout << "Max square size = [" << implObj->maximalSquare221(matrix) << "]\n\n";
        return;
    }

    // 256. Paint House Test
    void minCost256Test() {
        cout << "256. Paint House test starts.\n";
        vector<vector<int>> costs = {{17,2,17},{16,16,5},{14,3,19}};
        cout << "Min cost = [" << implObj->minCost256(costs) << "]\n\n";
        return;
    }

private:
    DpImpl * implObj;
};

#endif