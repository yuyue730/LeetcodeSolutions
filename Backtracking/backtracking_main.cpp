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
    testObj->combinationSum39Test();
    testObj->combinationSum2_40Test();
    testObj->permute46Test();
    testObj->solveNQueens51Test();
    testObj->combine77Test();
    testObj->subsets78Test();
    testObj->exist79Test();
    testObj->restoreIpAddresses93Test();

    return 0;
}