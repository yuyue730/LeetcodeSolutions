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

private:
    DpImpl * implObj;
};

#endif