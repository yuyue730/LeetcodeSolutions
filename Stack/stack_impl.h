#ifndef _STACK_IMPL_H
#define _STACK_IMPL_H

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class StackImpl {
public:
    StackImpl() {
        cout << "Impl object for Leetcode Stack problems constructed.\n";
    }

    // 20. Valid Parentheses
    bool isValid20(string s) {
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
    int longestValidParentheses32(string s) {
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
    int trap42(vector<int>& height) {
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

                if (!idxStk.empty()) { 
                    // Meaning we can not remove current top index since it is taller
                    result += (i - idxStk.top() - 1) * (height[i] - curButtom);
                }
            }

            idxStk.push(i);
        }

        return result;
    }

    // 84. Largest Rectangle in Histogram
    int largestRectangleArea84(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        stack<int> idxStack;
        heights.push_back(0);
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!idxStack.empty() && heights[i] < heights[idxStack.top()]) {
                int curIdx = idxStack.top(); idxStack.pop();
                int curRes = (idxStack.empty() ? i : (i - idxStack.top() - 1)) * heights[curIdx];
                result = max(result, curRes);
            }
            idxStack.push(i);
        }
        return result;
    }

    // 85. Maximal Rectangle
    int maximalRectangle85(vector<vector<char>>& matrix) {
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> heights(matrix[i].size(), 0);
            for (int j = 0; j < matrix[i].size(); ++j) {
                int curHeight = 0, curX = i;
                while (curX < matrix.size() && matrix[curX][j] == '1') {
                    ++curHeight;
                    ++curX;
                }
                heights[j] = curHeight;
            }

            int curRowResult = largestRectangleArea84(heights);
            result = max(curRowResult, result);
        }

        return result;
    }

    // 150. Evaluate Reverse Polish Notation
    int evalRPN150(vector<string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }

        stack<int> valueStk;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" 
                || tokens[i] == "*" || tokens[i] == "/") {
                int second = valueStk.top(); valueStk.pop();
                int first = valueStk.top(); valueStk.pop();
                int curValue = 0;
                if (tokens[i] == "+") {
                    curValue = first + second;
                } else if (tokens[i] == "-") {
                    curValue = first - second;
                } else if (tokens[i] == "*") {
                    curValue = first * second;
                } else if (tokens[i] == "/") {
                    curValue = first / second;
                }
                valueStk.push(curValue);
            } else {
                valueStk.push(stoi(tokens[i]));
            }
        }

        return valueStk.top();
    }
};

#endif