#include "backtracking_impl.h"

BacktrackingImpl::BacktrackingImpl() {
    cout << "Impl object for Leetcode Backtracking problems constructed.\n";
}

// 17. Letter Combinations of a Phone Number
vector<string> BacktrackingImpl::letterCombinations17(string digits) {
    if (digits.empty()) {
        return {};
    }
    const vector<string> digitLetterMap = {
        "", 
        "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> result = {};
    generateLetterCombRec(digitLetterMap, digits, 0, "", result);

    return result;
}

void BacktrackingImpl::generateLetterCombRec(
            const vector<string>& digitLetterMap, const string digits, 
            int curIdx, string curResult, vector<string> & result) {
    if (curIdx == digits.length()) {
        result.push_back(curResult);
        return;
    }

    string curDigitLetters = digitLetterMap[digits[curIdx] - '0'];
    for (int i = 0; i < curDigitLetters.length(); ++i) {
        string next = curResult + curDigitLetters[i];
        generateLetterCombRec(digitLetterMap, digits, curIdx + 1, next, result);
    }
}

// 22. Generate Parentheses
vector<string> BacktrackingImpl::generateParenthesis22(int n) {
    vector<string> result;
    if (n == 0) {
        return result;
    }

    generateParenthesisRec(n, n, "", result);
    return result;
}

void BacktrackingImpl::generateParenthesisRec(
        int left, int right, string curStr, vector<string> & result) {
    if (left > right) {
        // We have insert ')' before '('
        return;
    }

    if (left == 0 && right == 0) {
        result.push_back(curStr);
        return;
    }

    if (left > 0) {
        generateParenthesisRec(left - 1, right, curStr + '(', result);
    }
    if (right > 0) {
        generateParenthesisRec(left, right - 1, curStr + ')', result);
    }
}

// 37. Sudoku Solver
void BacktrackingImpl::solveSudoku37(vector<vector<char>>& board) {
    assert(board.size() == 9 && board[0].size() == 9);
    solveSudokuRec(board, 0, 0);
}

bool BacktrackingImpl::solveSudokuRec(vector<vector<char>>& board, int iRow, int iCol) {
    if (iRow == 9) {
        return true;
    }
    if (iCol == 9) {
        return solveSudokuRec(board, iRow + 1, 0);
    }

    if (board[iRow][iCol] == '.') {
        for (int i = 0; i < 9; ++i) {
            board[iRow][iCol] = static_cast<char>('1' + i);
            if (isValidSudokuPerUnit(board, iRow, iCol)) {
                if(solveSudokuRec(board, iRow, iCol + 1)) {
                    return true;
                }
            }
        }
        board[iRow][iCol] = '.';
    } else {
        return solveSudokuRec(board, iRow, iCol + 1);
    }

    return false;
}

bool BacktrackingImpl::isValidSudokuPerUnit(const vector<vector<char>>& board, int iRow, int iCol) {
    for (int i = 0; i < 9; ++i) {
        if (i != iRow && board[i][iCol] == board[iRow][iCol]) {
            return false;
        }
    }

    for (int j = 0; j < 9; ++j) {
        if (j != iCol && board[iRow][j] == board[iRow][iCol]) {
            return false;
        }
    }

    for (int m = 0; m < 3; ++m) {
        for (int n = 0; n < 3; ++n) {
            int curRow = (iRow / 3) * 3 + m;
            int curCol = (iCol / 3) * 3 + n;

            if ((curRow != iRow || curCol != iCol) && board[curRow][curCol] == board[iRow][iCol]) {
                return false;
            }
        }
    }

    return true;
}

// 39. Combination Sum
vector<vector<int>> BacktrackingImpl::combinationSum39(vector<int>& candidates, int target) {
    vector<vector<int>> allRes;
    vector<int> curRes;
    combinationSumRec(0, candidates, curRes, allRes, target);
    return allRes;
}

void BacktrackingImpl::combinationSumRec(int startIdx, const vector<int> & candidate, 
        vector<int> & curRes, vector<vector<int>> & allRes, int remain) {
    if (remain < 0) {
        return;
    }
    if (remain == 0) {
        allRes.push_back(curRes);
        return;
    }

    for (int i = startIdx; i < candidate.size(); ++i) {
        curRes.push_back(candidate[i]);
        combinationSumRec(i, candidate, curRes, allRes, remain - candidate[i]);
        curRes.pop_back();
    }
}