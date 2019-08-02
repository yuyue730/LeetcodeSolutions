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
    testObj->canCompleteCircuit134Test();
    testObj->candy135Test();
    testObj->findMin153Test();
    testObj->findPeakElement162Test();
    testObj->findMissingRanges163Test();
    testObj->twoSum167Test();
    testObj->majorityElement169Test();
    testObj->rotate189Test();
    testObj->minSubArrayLen209Test();
    testObj->summaryRanges228Test();
    testObj->majorityElement229Test();
    testObj->productExceptSelf238Test();
    testObj->maxSlidingWindow239Test();
    testObj->searchMatrix240Test();
    testObj->shortestDistance243Test();
    testObj->findCelebrity277Test();
    testObj->firstBadVersion278Test();
    testObj->wiggleSort280Test();
    testObj->moveZeroes283Test();

    return 0;
}