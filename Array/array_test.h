#ifndef _ARRAY_TEST_H
#define _ARRAY_TEST_H

#include "array_impl.h"

class ArrayTest {
public:
    ArrayTest();

    // 11. Container With Most Water Test
    void maxArea11Test();

    // 53. Maximum Subarray
    void maxSubArray53Test();

    // 66. Plus One
    void plusOne66Test();

private:
    ArrayImpl * implObj;
};

#endif