// Leetcode Stack Problems main function
#include "stack_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode Stack Problem Solution Application starts.\n";
    StackTest * testObj = new StackTest();
    cout << "\nTest for problems starts.\n";

    testObj->isValid20Test();
    testObj->longestValidParentheses32Test();
    testObj->trap42Test();
    testObj->largestRectangleArea84Test();
    testObj->maximalRectangle85Test();
    testObj->evalRPN150Test();
    testObj->calculate224Test();
    testObj->calculate227Test();
    testObj->verifyPreorder255Test();

    return 0;
}