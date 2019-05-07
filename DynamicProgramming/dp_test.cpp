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
