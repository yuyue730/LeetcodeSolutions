// Leetcode Backtracking Problems main function
#include "backtracking_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode Backtracking Problem Solution Application starts.\n";
    BacktrackingTest *testObj = new BacktrackingTest();
    cout << "\nTest for problems starts.\n";

    testObj->letterCombinations17Test();
    testObj->generateParenthesis22Test();
    testObj->solveSudoku37Test();

    return 0;
}