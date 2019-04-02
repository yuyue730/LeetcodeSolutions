#include <iostream>
#include "array_test.h"
using namespace std;

ArrayTest::ArrayTest() {
    cout << "Test object for Leetcode Array problems constructed.\n";
    implObj = new ArrayImpl();
}

// 4. Median of Two Sorted Arrays Test
void ArrayTest::findMedianSortedArrays4Test() {
    cout << "4. Median of Two Sorted Arrays starts\n";

    vector<int> num1 = {1, 3, 5, 7, 9};
    vector<int> num2 = {2, 4, 6, 8, 10};

    cout << "Median of two array is " << implObj->findMedianSortedArrays4(num1, num2) << "\n\n";

    return;
}

// 11. Container With Most Water Test
void ArrayTest::maxArea11Test() {
    cout << "11. Container With Most Water test starts\n";

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = implObj->maxArea11(heights);
    cout << "Current max Area = " << result << "\n\n";

    return;
}

// 15. 3Sum Test
void ArrayTest::threeSum15Test() {
    cout << "15. 3Sum test starts\n";
    vector<int> nums = {-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0};
    vector<vector<int>> result = implObj->threeSum15(nums);

    cout << "Each sub arrays are\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Subarray " << i << ": [";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ";";
        }
        cout << "]\n";
    }
    cout << "\n";
    return;
}

// 16. 3Sum Closest Test
void ArrayTest::threeSumClosest16Test() {
    cout << "16. 3Sum Closest test starts\n";
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << "The closest difference is " << implObj->threeSumClosest16(nums, target) << ".\n\n";

    return;
}

// 18. 4Sum Test
void ArrayTest::fourSum18Test() {
    cout << "18. 4Sum test starts.";
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = implObj->fourSum18(nums, target);
    cout << "Result array of array is \n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "subarray " << i << " [";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << "; ";
        }
        cout << "]\n";
    }
    cout << "\n";
    return;
}

// 26. Remove Duplicates from Sorted Array Test
void ArrayTest::removeDuplicates26Test() {
    cout << "26. Remove Duplicates from Sorted Array test starts\n";

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Unique # of items is " << implObj->removeDuplicates26(nums) << "\n\n";
    return;
}

// 31. Next Permutation Test
void ArrayTest::nextPermutation31Test() {
    cout << "31. Next Permutation test starts\n";

    vector<int> nums = {1, 2, 7, 4, 3, 1};
    implObj->nextPermutation31(nums);
    cout << "Next Permutation is [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << "; ";
    }
    cout << "].\n\n";
    return;
}

// 53. Maximum Subarray Test
void ArrayTest::maxSubArray53Test() {
    cout << "53. Maximum Subarray test starts (Divide and Conquer method)\n";

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = implObj->maxSubArray53(nums);
    cout << "Current max SubArray = " << result << "\n\n";

    return;
}

// 66. Plus One Test
void ArrayTest::plusOne66Test() {
    cout << "66. Plus One test starts\n";

    vector<int> nums = {9, 9, 9, 9};
    vector<int> result = implObj->plusOne66(nums);

    cout << "Result digits are: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << "; ";
    }
    cout << "\n\n";

    return;
}