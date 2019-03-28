// Leetcode Backtracking Problems main function
#include "baccktracking_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode Backtracking Problem Solution Application starts.\n";
    BacktrackingTest *testObj = new BacktrackingTest();
    cout << "\nTest for problems starts.\n";

    testObj->letterCombinations17Test();
    testObj->generateParenthesis22Test();

    return 0;
}