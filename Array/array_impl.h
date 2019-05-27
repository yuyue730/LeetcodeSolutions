#ifndef _ARRAY_IMPL_H
#define _ARRAY_IMPL_H

#include <vector>
using namespace std;

class ArrayImpl {
public:
    ArrayImpl();

    // 4. Median of Two Sorted Arrays
    double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2);

    // 11. Container With Most Water
    int maxArea11(vector<int>& heights);

    // 15. 3Sum
    vector<vector<int>> threeSum15(vector<int>& nums);

    // 16. 3Sum Closest
    int threeSumClosest16(vector<int>& nums, int target);

    // 18. 4Sum
    vector<vector<int>> fourSum18(vector<int>& nums, int target);

    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates26(vector<int>& nums);

    // 31. Next Permutation
    void nextPermutation31(vector<int>& nums);

    // 33. Search in Rotated Sorted Array
    int search33(vector<int>& nums, int target);

    // 34. Find First and Last Position of Element in Sorted Array
    vector<int> searchRange34(vector<int>& nums, int target);

    // 35. Search Insert Position
    int searchInsert35(vector<int>& nums, int target);

    // 41. First Missing Positive
    int firstMissingPositive41(vector<int>& nums);

    // 45. Jump Game II
    int jump45(vector<int>& nums);

    // 48. Rotate Image
    void rotate48(vector<vector<int>>& matrix);

    // 53. Maximum Subarray
    int maxSubArray53(vector<int>& nums);

    // 54. Spiral Matrix
    vector<int> spiralOrder54(vector<vector<int>>& matrix);

    // 55. Jump Game
    bool canJump55(vector<int>& nums);

    // 56. Merge Intervals
    vector<vector<int>> merge56(vector<vector<int>>& intervals);

    // 57. Insert Interval
    vector<vector<int>> insert57(
        vector<vector<int>>& intervals, 
        vector<int>& newInterval
    );

    // 59. Spiral Matrix II
    vector<vector<int>> generateMatrix59(int n);

    // 66. Plus One
    vector<int> plusOne66(vector<int>& digits);

    // 74. Search a 2D Matrix
    bool searchMatrix74(vector<vector<int>>& matrix, int target);

    // 75. Sort Colors
    void sortColors75(vector<int>& nums);

    // 81. Search in Rotated Sorted Array II
    bool search81(vector<int>& nums, int target);

    // 88. Merge Sorted Array
    void merge88(vector<int>& nums1, int m, vector<int>& nums2, int n);

    // 118. Pascal's Triangle
    vector<vector<int>> generate118(int numRows);

private:
    // 4. Median of Two Sorted Arrays helper
    double findKthInTwoArray(
        const vector<int>& nums1, int i, 
        const vector<int>& nums2, int j, int k
    );

    // 53. Maximum Subarray helper
    int maxSubArrayRec(const vector<int>& nums, int left, int right);
};

#endif