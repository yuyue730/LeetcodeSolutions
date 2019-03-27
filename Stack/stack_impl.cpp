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