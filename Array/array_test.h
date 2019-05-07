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

    // 35. Search Insert Position Test
    void searchInsert35Test();

    // 41. First Missing Positive Test
    void firstMissingPositive41Test();

    // 45. Jump Game II Test
    void jump45Test();

    // 48. Rotate Image Test
    void rotate48Test();

    // 53. Maximum Subarray Test
    void maxSubArray53Test();

    // 54. Spiral Matrix Test
    void spiralOrder54Test();

    // 55. Jump Game Test
    void canJump55Test();

    // 56. Merge Intervals Test
    void merge56Test();

    // 57. Insert Interval Test
    void insert57Test();

    // 59. Spiral Matrix II Test
    void generateMatrix59Test();

    // 66. Plus One Test
    void plusOne66Test();

private:
    ArrayImpl * implObj;
};

#endif