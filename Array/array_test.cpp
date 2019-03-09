#include <iostream>
#include "array_test.h"
using namespace std;

ArrayTest::ArrayTest() {
    cout << "Test object for Leetcode Array problems constructed.\n";
    implObj = new ArrayImpl();
}

void ArrayTest::findMedianSortedArrays3Test() {
    cout << "4. Median of Two Sorted Arrays starts\n";

    vector<int> num1 = {1, 3, 5, 7, 9};
    vector<int> num2 = {2, 4, 6, 8, 10};

    cout << "Median of two array is " << implObj->findMedianSortedArrays4(num1, num2) << "\n\n";

    return;
}

void ArrayTest::maxArea11Test() {
    cout << "11. Container With Most Water test starts\n";

    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = implObj->maxArea11(heights);
    cout << "Current max Area = " << result << "\n\n";

    return;
}

void ArrayTest::maxSubArray53Test() {
    cout << "53. Maximum Subarray test starts (Divide and Conquer method)\n";

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = implObj->maxSubArray53(nums);
    cout << "Current max SubArray = " << result << "\n\n";

    return;
}

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