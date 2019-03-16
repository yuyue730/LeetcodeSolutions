#ifndef _ARRAY_TEST_H
#define _ARRAY_TEST_H

#include "array_impl.h"

class ArrayTest {
public:
    ArrayTest();

    // 4. Median of Two Sorted Arrays Test
    void findMedianSortedArrays4Test();

    // 11. Container With Most Water Test
    void maxArea11Test();

    // 15. 3Sum Test
    void threeSum15Test();

    // 53. Maximum Subarray Test
    void maxSubArray53Test();

    // 66. Plus One Test
    void plusOne66Test();

private:
    ArrayImpl * implObj;
};

#endif