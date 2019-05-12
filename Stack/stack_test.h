#ifndef _STACK_TEST_H
#define _STACK_TEST_H

#include "stack_impl.h"

class StackTest {
public:
    StackTest();

    // 20. Valid Parentheses Test
    void isValid20Test();

    // 32. Longest Valid Parentheses Test
    void longestValidParentheses32Test();

    // 42. Trapping Rain Water Test
    void trap42Test();

    // 84. Largest Rectangle in Histogram Test
    void largestRectangleArea84Test();

    // 85. Maximal Rectangle Test
    void maximalRectangle85Test();

private:
    StackImpl * implObj;
};

#endif