#include "dp_test.h"

DpTest::DpTest() {
    cout << "Test object for Leetcode Dynamic Programming problems constructed.\n";
    implObj = new DpImpl();
}

// 44. Wildcard Matching Test
void DpTest::isMatch44Test() {
    cout << "44. Wildcard Matching test starts.\n";
    cout << "*a*b and adceb isMatch = [" << implObj->isMatch44("adceb", "*a*b") << "].\n\n";
    return;
}

// 62. Unique Paths Test
void DpTest::uniquePaths62Test() {
    cout << "62. Unique Paths test starts.\n";
    cout << "3 * 2 grid will have " << implObj->uniquePaths62(3, 2) << " methods.\n\n";
    return;
}

// 63. Unique Paths II Test
void DpTest::uniquePathsWithObstacles63Test() {
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
void DpTest::minPathSum64Test() {
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
void DpTest::climbStairs70Test() {
    cout << "70. Climbing Stairs test starts.\n";
    cout << "3 starts will have " << implObj->climbStairs70(3) << " ways.\n\n";
    return;
}

// 72. Edit Distance Test
void DpTest::minDistance72Test() {
    cout << "72. Edit Distance test starts.\n";
    cout << "'horse' and 'ros' will have " << implObj->minDistance72("horse", "ros") << " steps.\n\n";
    return;
}

// 91. Decode Ways Test
void DpTest::numDecodings91Test() {
    cout << "91. Decode Ways test starts.\n";
    cout << "226 will be decoded into [" << implObj->numDecodings91("12") << "].\n\n";
    return;
}

// 96. Unique Binary Search Trees Test
void DpTest::numTrees96Test() {
    cout << "96. Unique Binary Search Trees test starts.\n";
    cout << "4 will generate [" << implObj->numTrees96(4) << "]\n";
    cout << "5 will generate [" << implObj->numTrees96(5) << "]\n\n";
    return;
}

// 97. Interleaving String Test
void DpTest::isInterleave97Test() {
    cout << "97. Interleaving String test.\n";
    string s1 = "a", s2 = "", s3 = "a";//s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << "s1 and s2 can generage 3 [" << (implObj->isInterleave97(s1, s2, s3) ? "True" : "False")
        << "].\n\n";
    return; 
}