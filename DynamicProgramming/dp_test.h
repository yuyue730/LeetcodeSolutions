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

    // 64. Minimum Path Sum Test
    void minPathSum64Test();

private:
    DpImpl * implObj;
};

#endif