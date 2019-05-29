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
    testObj->searchInsert35Test();
    testObj->firstMissingPositive41Test();
    testObj->jump45Test();
    testObj->rotate48Test();
    testObj->maxSubArray53Test();
    testObj->spiralOrder54Test();
    testObj->canJump55Test();
    testObj->merge56Test();
    testObj->insert57Test();
    testObj->generateMatrix59Test();
    testObj->plusOne66Test();
    testObj->searchMatrix74Test();
    testObj->sortColors75Test();
    testObj->search81Test();
    testObj->merge88Test();
    testObj->generate118Test();
    testObj->maxProfit121Test();
    testObj->maxProfit122Test();

    return 0;
}