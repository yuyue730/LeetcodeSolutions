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

    // 40. Combination Sum II
    vector<vector<int>> combinationSum2_40(vector<int>& candidates, int target);

    // 46. Permutations
    vector<vector<int>> permute46(vector<int>& nums);

    // 51. N-Queens
    vector<vector<string>> solveNQueens51(int n);

    // 77. Combinations
    vector<vector<int>> combine77(int n, int k);

    // 78. Subsets
    vector<vector<int>> subsets78(vector<int>& nums);
    
    // 79. Word Search
    bool exist79(vector<vector<char>>& board, string word);

    // 93. Restore IP Addresses
    vector<string> restoreIpAddresses93(string s);

    // 130. Surrounded Regions
    void solve130(vector<vector<char>>& board);

    // 131. Palindrome Partitioning
    vector<vector<string>> partition131(string s);

private:
    // 17. Letter Combinations of a Phone Number helper
    void generateLetterCombRec(
        const vector<string>& digitLetterMap, const string digits, 
        int curIdx, string curResult, vector<string> & result
    );

    // 22. Generate Parentheses helper
    void generateParenthesisRec(
        int left, int right, 
        string curStr, vector<string> & result
    );

    // 37. Sudoku Solver helper
    bool solveSudokuRec(vector<vector<char>>& board, int iRow, int iCol);

    bool isValidSudokuPerUnit(const vector<vector<char>>& board, int iRow, int iCol);

    // 39. Combination Sum helper
    void combinationSumRec(int startIdx, const vector<int> & candidate, 
        vector<int> & curRes, vector<vector<int>> & allRes, int remain
    );

    // 40. Combination Sum II helper
    void combinationSum2Rec(
        vector<int> & curResult,
        vector<vector<int>> & allResults,
        int startIdx,
        int remain,
        const vector<int> & candidates
    );

    // 46. Permutations helper
    void permute46Rec(
        vector<vector<int>> &results,
        vector<int> &curRes,
        vector<bool> &visited,
        const vector<int> &nums
    );

    // 51. N-Queens helper
    void solveNQueens51Rec(
        vector<vector<string>> &results,
        vector<string> &curRes,
        int curRow,
        const int nSize
    );

    bool isCurrentBoardValid(
        const vector<string> &board,
        const int curRow,
        const int curCol,
        const int nSize
    );

    // 77. Combinations helpers
    void combine77helper(
        const int n, const int k,
        int curVal, vector<int> & curRes,
        vector<vector<int>> & allRes
    );

    // 78. Subsets helpers
    void subsets78Rec(
        vector<int> & curRes,
        vector<vector<int>> & allRes,
        const int curPos,
        const vector<int> & nums
    );

    // 79. Word Search helpers
    bool exist79Rec(
        vector<vector<char>>& board,
        const string word,
        const int curWordPos,
        const int curX,
        const int curY
    );

    // 93. Restore IP Addresses helper
    void restoreIpAddresses93Rec(
        vector<string> & allResults,
        vector<string> & curResult,
        const int curPos,
        const string & ipStr
    );

    bool isValidIpNumStr(string & ipNumStr);

    // 130. Surrounded Regions helper
    void solve130DFS(vector<vector<char>>& board, int iIdx, int jIdx);

    // 131. Palindrome Partitioning helper
    void partition131helper(
        const string s, int startIdx, 
        vector<string> & curRes, 
        vector<vector<string>> & allRes
    );

    bool isPalindrome(const string s, int left, int right);
};

#endif