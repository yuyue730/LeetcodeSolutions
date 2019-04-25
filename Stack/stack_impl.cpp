#include "stack_impl.h"

#include <iostream>
#include <stack>
using namespace std;

StackImpl::StackImpl() {
    cout << "Impl object for Leetcode Stack problems constructed.\n";
}

// 20. Valid Parentheses
bool StackImpl::isValid20(string s) {
    if (s.empty()) {
        return true;
    }

    stack <char> chStk;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            chStk.push(s[i]);
        } else {
            if (chStk.empty()) {
                return false;
            }

            if (s[i] == ')' && chStk.top() != '(') {
                return false;
            }
            if (s[i] == ']' && chStk.top() != '[') {
                return false;
            }
            if (s[i] == '}' && chStk.top() != '{') {
                return false;
            }

            chStk.pop();
        }
    }

    return chStk.empty();
}

// 32. Longest Valid Parentheses
int StackImpl::longestValidParentheses32(string s) {
    if (s.empty()) {
        return 0;
    }

    stack<int> idxStk;
    int curStart = -1;
    int result = 0;

    for (int i = 0;i < s.length(); ++i) {
        if (s[i] == '(') {
            idxStk.push(i);
        } else {
            if (idxStk.empty()) {
                curStart = i;
            } else {
                idxStk.pop();
                if (idxStk.empty()) {
                    result = max(result, i - curStart);
                } else {
                    result = max(result, i - idxStk.top());
                }
            }
        }
    }

    return result;
}

// 42. Trapping Rain Water
int StackImpl::trap42(vector<int>& height) {
    if (height.size() < 3) {
        return 0;
    }

    stack<int> idxStk;
    idxStk.push(0);
    int result = 0;

    for (int i = 1; i < height.size(); ++i) {
        if (height[i] > height[idxStk.top()]) {
            int curButtom = height[idxStk.top()];
            idxStk.pop();

            while (!idxStk.empty() && height[i] >= height[idxStk.top()]) {
                result += (i - idxStk.top() - 1) * (height[idxStk.top()] - curButtom);
                curButtom = height[idxStk.top()];
                idxStk.pop();
            }

            if (!idxStk.empty()) { // Meaning we can not remove current top index since it is taller
                result += (i - idxStk.top() - 1) * (height[i] - curButtom);
            }
        }

        idxStk.push(i);
    }

    return result;
}