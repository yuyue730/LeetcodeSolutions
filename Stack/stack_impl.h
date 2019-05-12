#ifndef _STACK_IMPL_H
#define _STACK_IMPL_H

#include <string>
#include <vector>
using namespace std;

class StackImpl {
public:
    StackImpl();

    // 20. Valid Parentheses
    bool isValid20(string s);

    // 32. Longest Valid Parentheses
    int longestValidParentheses32(string s);

    // 42. Trapping Rain Water
    int trap42(vector<int>& height);

    // 84. Largest Rectangle in Histogram
    int largestRectangleArea84(vector<int>& heights);
};

#endif