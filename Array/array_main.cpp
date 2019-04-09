// Leetcode Array Problems main function
#include <iostream>
#include "array_test.h"
using namespace std;

int main() {
    cout << "Leetcode Array Problem Solution Application starts.\n";
    ArrayTest * testObj = new ArrayTest();
    cout << "\nTest for problems starts.\n";

    testObj->findMedianSortedArrays4Test();
    testObj->maxArea11Test();
    testObj->threeSum15Test();
    testObj->threeSumClosest16Test();
    testObj->fourSum18Test();
    testObj->removeDuplicates26Test();
    testObj->nextPermutation31Test();
    testObj->search33Test();
    testObj->searchRange34Test();
    testObj->maxSubArray53Test();
    testObj->plusOne66Test();

    return 0;
}