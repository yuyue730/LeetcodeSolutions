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

    // 16. 3Sum Closest Test
    void threeSumClosest16Test();

    // 18. 4Sum Test
    void fourSum18Test();

    // 26. Remove Duplicates from Sorted Array Test
    void removeDuplicates26Test();

    // 31. Next Permutation Test
    void nextPermutation31Test();

    // 33. Search in Rotated Sorted Array Test
    void search33Test();

    // 34. Find First and Last Position of Element in Sorted Array Test
    void searchRange34Test();

    // 53. Maximum Subarray Test
    void maxSubArray53Test();

    // 66. Plus One Test
    void plusOne66Test();

private:
    ArrayImpl * implObj;
};

#endif