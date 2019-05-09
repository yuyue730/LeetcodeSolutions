#ifndef _DP_TEST_H
#define _DP_TEST_H

#include <iostream>
#include "dp_impl.h"
using namespace std;

class DpTest {
public:
    DpTest();

    // 44. Wildcard Matching Test
    void isMatch44Test();

    // 62. Unique Paths Test
    void uniquePaths62Test();

    // 63. Unique Paths II Test
    void uniquePathsWithObstacles63Test();

    // 64. Minimum Path Sum Test
    void minPathSum64Test();

    // 70. Climbing Stairs Test
    void climbStairs70Test();

    // 72. Edit Distance Test
    void minDistance72Test();

private:
    DpImpl * implObj;
};

#endif