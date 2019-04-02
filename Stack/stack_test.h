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

private:
    StackImpl * implObj;
};

#endif