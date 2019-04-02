#ifndef _STACK_IMPL_H
#define _STACK_IMPL_H

#include <string>
using namespace std;

class StackImpl {
public:
    StackImpl();

    // 20. Valid Parentheses
    bool isValid20(string s);

    // 32. Longest Valid Parentheses
    int longestValidParentheses32(string s);
};

#endif