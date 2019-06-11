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

// 33. Search in Rotated Sorted Array Test
void ArrayTest::search33Test() {
    cout << "33. Search in Rotated Sorted Array test starts.\n";
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Find 0 will have idx = [" << implObj->search33(nums, 0) << "]\n\n";
    return;
}

// 34. Find First and Last Position of Element in Sorted Array Test
void ArrayTest::searchRange34Test() {
    cout << "34. Find First and Last Position of Element in Sorted Array test starts.\n";
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> result = implObj->searchRange34(nums, 8);
    cout << "Find 8 will have idxes " << result[0] << "; " << result[1] << ".\n\n";
    return; 
}

// 35. Search Insert Position Test
void ArrayTest::searchInsert35Test() {
    cout << "35. Search Insert Position test starts.\n";
    vector<int> nums = {1, 3, 5, 6};
    cout << "Insert 2 into index = " << implObj->searchInsert35(nums, 2) << ".\n\n";
    return;
}

// 41. First Missing Positive Test
void ArrayTest::firstMissingPositive41Test() {
    cout << "41. First Missing Positive test starts.\n";
    vector<int> nums = {3, 4, -1, 1};

    cout << "First missing postive is " << implObj->firstMissingPositive41(nums) << ".\n\n";
    return;
}

// 45. Jump Game II Test
void ArrayTest::jump45Test() {
    cout << "45. Jump Game II test starts.\n";
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Min step to jump is [" << implObj->jump45(nums) << "].\n\n";
    return;
}

// 48. Rotate Image Test
void ArrayTest::rotate48Test() {
    cout << "48. Rotate Image test.\n";
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    implObj->rotate48(matrix);
    cout << "After rotation, matrix is \n";
    for (int i = 0; i < matrix.size(); ++i) {
        cout << "Row " << i << "[";
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << "; ";
        }
        cout << "]\n";
    }
    cout << "\n";
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

// 54. Spiral Matrix Test
void ArrayTest::spiralOrder54Test() {
    cout << "54. Spiral Matrix test starts.\n";
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result = implObj->spiralOrder54(matrix);

    cout << "Spiral order vector [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ((i == result.size() - 1) ? "" : "; ");
    }
    cout << "]\n\n";
    return;
}

// 55. Jump Game Test
void ArrayTest::canJump55Test() {
    cout << "55. Jump Game test starts.\n";
    vector<int> case1 = {2, 3, 1, 1, 4};
    cout << "Case 1 [2,3,1,1,4] canJump = " 
        << (implObj->canJump55(case1) ? "true" : "false") << ".\n";
    vector<int> case2 = {3, 2, 1, 0, 4};
    cout << "Case 2 [3,2,1,0,4] canJump = " 
        << (implObj->canJump55(case2) ? "true" : "false") << ".\n\n";
    return;
}

// 56. Merge Intervals Test
void ArrayTest::merge56Test() {
    cout << "56. Merge Intervals test starts.\n";
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    vector<vector<int>> result = implObj->merge56(intervals);
    cout << "Merge result is ";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]"
            << ((i == result.size() - 1) ? "" : "; ");
    }
    cout << "\n\n";
    return;
}

// 57. Insert Interval Test
void ArrayTest::insert57Test() {
    cout << "57. Insert Interval test starts.\n";
    vector<vector<int>> intervals = {
        {1, 3}, {6, 9}
    };
    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = implObj->insert57(intervals, newInterval);
    cout << "Insert result is ";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]"
            << ((i == result.size() - 1) ? "" : "; ");
    }
    cout << "\n\n";
    return;
}

// 59. Spiral Matrix II Test
void ArrayTest::generateMatrix59Test() {
    cout << "59. Spiral Matrix II test.\n";
    vector<vector<int>> result = implObj->generateMatrix59(3);

    cout << "Generate result [\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "  [";
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << (j == result.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }
    cout << "]\n";
    return;
}

// 66. Plus One Test
void ArrayTest::plusOne66Test() {
    cout << "66. Plus One test starts.\n";

    vector<int> nums = {9, 9, 9, 9};
    vector<int> result = implObj->plusOne66(nums);

    cout << "Result digits are: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << "; ";
    }
    cout << "\n\n";

    return;
}

// 74. Search a 2D Matrix Test
void ArrayTest::searchMatrix74Test() {
    cout << "74. Search a 2D Matrix test starts.\n";

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    cout << "Find 3 result in [" << (implObj->searchMatrix74(matrix, 3) ? "True" : "False") 
        << "].\n\n";
    return;
}

// 75. Sort Colors Test
void ArrayTest::sortColors75Test() {
    cout << "75. Sort Colors test starts.\n";
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    implObj->sortColors75(nums);
    
    cout << "Sorted array is [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ((i == nums.size() - 1) ? "" : ", ");
    }
    cout << "]\n\n";
    return;
}

// 81. Search in Rotated Sorted Array II Test
void ArrayTest::search81Test() {
    cout << "81. Search in Rotated Sorted Array II test starts.\n";
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << "Search for 0 is [" << (implObj->search81(nums, 0) ? "True" : "False")
        << "].\n";
    cout << "Search for 8 is [" << (implObj->search81(nums, 8) ? "True" : "False")
        << "].\n\n";
    return;
}

// 88. Merge Sorted Array Test
void ArrayTest::merge88Test() {
    cout << "88. Merge Sorted Array test starts.\n";
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    implObj->merge88(nums1, 3, nums2, 3);
    cout << "Merged array is [";
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << ((i == nums1.size() - 1) ? "" : ", ");
    }
    cout << "]\n\n";
    return;
}

// 118. Pascal's Triangle Test
void ArrayTest::generate118Test() {
    cout << "118. Pascal's Triangle test starts.\n";
    vector<vector<int>> result = implObj->generate118(5);
    cout << "result = [\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "  [";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
        }
        cout << "]\n";
    }
    cout << "].\n\n";
    return;
}

// 121. Best Time to Buy and Sell Stock Test
void ArrayTest::maxProfit121Test() {
    cout << "121. Best Time to Buy and Sell Stock test starts.\n";
    vector<int> nums = {7,1,5,3,6,4};
    cout << "Max Profit = " << implObj->maxProfit121(nums) << "\n\n";
    return;
}

// 122. Best Time to Buy and Sell Stock II Test
void ArrayTest::maxProfit122Test() {
    cout << "122. Best Time to Buy and Sell Stock II test starts.\n";
    vector<int> nums = {7,1,5,3,6,4};
    cout << "Max Profit = " << implObj->maxProfit122(nums) << "\n\n";
    return;
}

// 134. Gas Station Test
void ArrayTest::canCompleteCircuit134Test() {
    cout << "134. Gas Station test starts.\n";
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << "Starting Index = [" << implObj->canCompleteCircuit134(gas, cost)
        << "].\n\n";
    return;
}