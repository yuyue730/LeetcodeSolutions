// Leetcode Dynamic Programming main function
#include <iostream>
#include "dp_test.h"
using namespace std;

int main() {
    cout << "Leetcode Dynamic Programming Problem Solution Application starts.\n";
    DpTest * testObj = new DpTest();
    cout << "\nTest for problems starts.\n";

    testObj->isMatch44Test();
    testObj->uniquePaths62Test();
    testObj->uniquePathsWithObstacles63Test();
    testObj->minPathSum64Test();
    testObj->climbStairs70Test();
    testObj->minDistance72Test();
    testObj->numDecodings91Test();
    testObj->numTrees96Test();
    testObj->isInterleave97Test();

    return 0;
}