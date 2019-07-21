#ifndef _STACK_TEST_H
#define _STACK_TEST_H

#include "stack_impl.h"

class StackTest {
public:
    StackTest() {
        cout << "Test object for Leetcode Stack problems constructed.\n";
        implObj = new StackImpl();
    }

    // 20. Valid Parentheses Test
    void isValid20Test() {
        cout << "20. Valid Parentheses test starts.\n";   
        string s = "([)]";
        cout << "([)] isValid = " << implObj->isValid20(s) << ".\n\n";
        return;
    }

    // 32. Longest Valid Parentheses Test
    void longestValidParentheses32Test() {
        cout << "32. Longest Valid Parentheses test starts.\n";
        cout << "((())() will have max length = [" << implObj->longestValidParentheses32("((())()") << "]\n\n";
        return;
    }

    // 42. Trapping Rain Water Test
    void trap42Test() {
        cout << "42. Trapping Rain Water test starts.\n";
        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << "[0,1,0,2,1,0,1,3,2,1,2,1] will contain " << implObj->trap42(height) << " units of water.\n\n";
        return;
    }

    // 84. Largest Rectangle in Histogram Test
    void largestRectangleArea84Test() {
        cout << "84. Largest Rectangle in Histogram test starts.\n";
        vector<int> heights = {2, 1, 5, 6, 2, 3};
        cout << "Largest rectangle is [" << implObj->largestRectangleArea84(heights)
            << "].\n\n";
        return;
    }

    // 85. Maximal Rectangle Test
    void maximalRectangle85Test() {
        cout << "85. Maximal Rectangle test starts.\n";
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };

        cout << "Largest rectangle is [" << implObj->maximalRectangle85(matrix) 
            << "]\n\n";
        return;
    }

    // 150. Evaluate Reverse Polish Notation Test
    void evalRPN150Test() {
        cout << "150. Evaluate Reverse Polish Notation test starts.\n";
        vector<string> tokens = {"4", "13", "5", "/", "+"};
        cout << "Calculation result = [" << implObj->evalRPN150(tokens) << "]\n\n";
        return;
    }

    // 224. Basic Calculator Test
    void calculate224Test() {
        cout << "224. Basic Calculator test starts.\n";
        cout << "(1+(4+5+2)-3)+(6+8) = [" << implObj->calculate224("(1+(4+5+2)-3)+(6+8)") 
            << "]\n\n";
        return;
    }

    // 227. Basic Calculator II Test
    void calculate227Test() {
        cout << "227. Basic Calculator II test starts.\n";
        cout << "3+5 / 2 = " << implObj->calculate227("3+5 / 2") << "\n\n";
        return;
    }

    // 255. Verify Preorder Sequence in Binary Search Tree Test
    void verifyPreorder255Test() {
        cout << "255. Verify Preorder Sequence in Binary Search Tree test starts.\n";
        vector<int> preorder = {5, 2, 1, 3, 6};
        cout << "[5,2,1,3,6] can generate BST = [" 
            << (implObj->verifyPreorder255(preorder) ? "True" : "False")
            << "]\n\n";
        return;
    }

private:
    StackImpl * implObj;
};

#endif