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

    // 53. Maximum Subarray
    int maxSubArray53(vector<int>& nums);

    // 66. Plus One
    vector<int> plusOne66(vector<int>& digits);

private:
    // 4. Median of Two Sorted Arrays helper
    double findKthInTwoArray(
            const vector<int>& nums1, int i, 
            const vector<int>& nums2, int j, int k);

    // 53. Maximum Subarray helper
    int maxSubArrayRec(const vector<int>& nums, int left, int right);
};

#endif