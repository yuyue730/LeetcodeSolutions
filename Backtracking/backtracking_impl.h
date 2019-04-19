#ifndef _BACKTRACKING_IMPL_H
#define _BACKTRACKING_IMPL_H

#include <iostream>
#include <vector>
using namespace std;

class BacktrackingImpl {
public:
    BacktrackingImpl();

    // 17. Letter Combinations of a Phone Number
    vector<string> letterCombinations17(string digits);

    // 22. Generate Parentheses
    vector<string> generateParenthesis22(int n);

    // 37. Sudoku Solver
    void solveSudoku37(vector<vector<char>>& board);

    // 39. Combination Sum
    vector<vector<int>> combinationSum39(vector<int>& candidates, int target);

private:
    // 17. Letter Combinations of a Phone Number helper
    void generateLetterCombRec(
            const vector<string>& digitLetterMap, const string digits, 
            int curIdx, string curResult, vector<string> & result);

    // 22. Generate Parentheses helper
    void generateParenthesisRec(int left, int right, string curStr, vector<string> & result);

    // 37. Sudoku Solver helper
    bool solveSudokuRec(vector<vector<char>>& board, int iRow, int iCol);

    bool isValidSudokuPerUnit(const vector<vector<char>>& board, int iRow, int iCol);

    // 39. Combination Sum helper
    void combinationSumRec(int startIdx, const vector<int> & candidate, 
            vector<int> & curRes, vector<vector<int>> & allRes, int remain);
};

#endif