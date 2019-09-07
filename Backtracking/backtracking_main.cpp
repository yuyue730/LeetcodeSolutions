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
    testObj->permuteUnique47Test();
    testObj->solveNQueens51Test();
    testObj->combine77Test();
    testObj->subsets78Test();
    testObj->exist79Test();
    testObj->restoreIpAddresses93Test();
    testObj->solve130Test();
    testObj->partition131Test();
    testObj->wordBreak140Test();
    testObj->numIslands200Test();
    testObj->findWords212Test();
    testObj->addOperators282Test();
    testObj->wallsAndGates286Test();
    testObj->longestIncreasingPath329Test();

    return 0;
}