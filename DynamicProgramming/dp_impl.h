#ifndef _DP_IMPL_H
#define _DP_IMPL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DpImpl {
public:
    DpImpl();

    // 44. Wildcard Matching
    bool isMatch44(string s, string p);

    // 62. Unique Paths
    int uniquePaths62(int m, int n);

    // 63. Unique Paths II
    int uniquePathsWithObstacles63(vector<vector<int>>& obstacleGrid);

    // 64. Minimum Path Sum
    int minPathSum64(vector<vector<int>>& grid);

    // 70. Climbing Stairs
    int climbStairs70(int n);

    // 72. Edit Distance
    int minDistance72(string word1, string word2);

    // 91. Decode Ways
    int numDecodings91(string s);

    // 96. Unique Binary Search Trees
    int numTrees96(int n);

    // 97. Interleaving String
    bool isInterleave97(string s1, string s2, string s3);

    // 120. Triangle
    int minimumTotal120(vector<vector<int>>& triangle);

    // 123. Best Time to Buy and Sell Stock III
    int maxProfit123(vector<int>& prices);
    
    // 132. Palindrome Partitioning II
    int minCut132(string s);
};

#endif