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
};

#endif