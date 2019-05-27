#ifndef _BACKTRACKING_TEST_H
#define _BACKTRACKING_TEST_H

#include "backtracking_impl.h"

#include <iostream>
using namespace std;

class BacktrackingTest {
public:
    BacktrackingTest();

    // 17. Letter Combinations of a Phone Number Test
    void letterCombinations17Test();

    // 22. Generate Parentheses Test
    void generateParenthesis22Test();

    // 37. Sudoku Solver Test
    void solveSudoku37Test();

    // 39. Combination Sum Test
    void combinationSum39Test();

    // 40. Combination Sum II Test
    void combinationSum2_40Test();

    // 46. Permutations Test
    void permute46Test();

    // 51. N-Queens Test
    void solveNQueens51Test();

    // 77. Combinations Test
    void combine77Test();

    // 78. Subsets Test
    void subsets78Test();

    // 79. Word Search Test
    void exist79Test();

    // 93. Restore IP Addresses Test
    void restoreIpAddresses93Test();

private:
    BacktrackingImpl * implObj;
};

#endif