// Leetcode Array Problems main function
#include <iostream>
#include "array_test.h"
using namespace std;

int main() {
    cout << "Leetcode Array Problem Solution Application starts.\n";
    ArrayTest * testObj = new ArrayTest();
    cout << "\nTest for problems starts.\n";

    testObj->findMedianSortedArrays3Test();
    testObj->maxArea11Test();
    testObj->maxSubArray53Test();
    testObj->plusOne66Test();

    return 0;
}