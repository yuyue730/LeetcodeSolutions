#include "backtracking_impl.h"

BacktrackingImpl::BacktrackingImpl()
{
    cout << "Impl object for Leetcode Backtracking problems constructed.\n";
}

// 17. Letter Combinations of a Phone Number
vector<string> BacktrackingImpl::letterCombinations17(string digits)
{
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
    int curIdx, string curResult, vector<string> & result)
{
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
vector<string> BacktrackingImpl::generateParenthesis22(int n)
{
    vector<string> result;
    if (n == 0) {
        return result;
    }

    generateParenthesisRec(n, n, "", result);
    return result;
}

void BacktrackingImpl::generateParenthesisRec(
    int left, int right, string curStr, vector<string> & result)
{
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
void BacktrackingImpl::solveSudoku37(vector<vector<char>>& board)
{
    assert(board.size() == 9 && board[0].size() == 9);
    solveSudokuRec(board, 0, 0);
}

bool BacktrackingImpl::solveSudokuRec(
    vector<vector<char>>& board, int iRow, int iCol)
{
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

bool BacktrackingImpl::isValidSudokuPerUnit(
    const vector<vector<char>>& board, int iRow, int iCol)
{
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

            if ((curRow != iRow || curCol != iCol) 
                && board[curRow][curCol] == board[iRow][iCol]) {
                return false;
            }
        }
    }

    return true;
}

// 39. Combination Sum
vector<vector<int>> BacktrackingImpl::combinationSum39(
    vector<int>& candidates, 
    int target
) {
    vector<vector<int>> allRes;
    vector<int> curRes;
    combinationSumRec(0, candidates, curRes, allRes, target);
    return allRes;
}

void BacktrackingImpl::combinationSumRec(
    int startIdx, const vector<int> & candidate, 
    vector<int> & curRes, vector<vector<int>> & allRes, int remain
) {
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

// 46. Permutations
vector<vector<int>> BacktrackingImpl::permute46(vector<int>& nums)
{
    vector<vector<int>> results;
    vector<int> curRes;
    vector<bool> visited(nums.size(), false);
    permute46Rec(results, curRes, visited, nums);
    return results;
}

void BacktrackingImpl::permute46Rec(
    vector<vector<int>> &results,
    vector<int> &curRes,
    vector<bool> &visited,
    const vector<int> &nums)
{
    if (curRes.size() == nums.size()) {
        results.push_back(curRes);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]) {
            continue;
        }

        curRes.push_back(nums[i]);
        visited[i] = true;
        permute46Rec(results, curRes, visited, nums);
        curRes.pop_back();
        visited[i] = false;
    }
}

// 51. N-Queens
vector<vector<string>> BacktrackingImpl::solveNQueens51(int n)
{
    vector<vector<string>> results;
    if (n == 0) {
        return results;
    }

    vector<string> curRes(n, string(n, '.'));
    solveNQueens51Rec(results, curRes, 0, n);
    return results;
}

void BacktrackingImpl::solveNQueens51Rec(
    vector<vector<string>> &results,
    vector<string> &curRes,
    int curRow,
    const int nSize
) {
    if (curRow  == nSize) {
        results.push_back(curRes);
    }

    for (int i = 0; i < nSize; ++i) {
        if (isCurrentBoardValid(curRes, curRow, i, nSize)) {
            curRes[curRow][i] = 'Q';
            solveNQueens51Rec(results, curRes, curRow + 1, nSize);
            curRes[curRow][i] = '.';
        }
    }
}

bool BacktrackingImpl::isCurrentBoardValid(
    const vector<string> &board,
    const int curRow,
    const int curCol,
    const int nSize
) {
    for (int i = 0; i < curRow; ++i) {
        if (board[i][curCol] == 'Q') {
            return false;
        }
    }

    for (int i = curRow - 1, j = curCol + 1; i >= 0 && j < nSize; --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    for (int i = curRow - 1, j = curCol - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// 78. Subsets
vector<vector<int>> BacktrackingImpl::subsets78(vector<int>& nums) {
    vector<vector<int>> allResult;
    vector<int> curResult;
    subsets78Rec(curResult, allResult, 0, nums);
    return allResult;
}

void BacktrackingImpl::subsets78Rec(
    vector<int> & curRes,
    vector<vector<int>> & allRes,
    const int curPos,
    const vector<int> & nums
) {
    allRes.push_back(curRes);
    for (int i = curPos; i < nums.size(); ++i) {
        curRes.push_back(nums[i]);
        subsets78Rec(curRes, allRes, i + 1, nums);
        curRes.pop_back();
    }
}

// 79. Word Search
bool BacktrackingImpl::exist79(vector<vector<char>>& board, string word)
{
    // Corner pressure test case: Recursion should be avoided 
    // if (word.size() > 100) {
    //     return true;
    // }
        
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (exist79Rec(board, word, 0, i, j)) {
                return true;
            }
        }
    }

    return false;
}

bool BacktrackingImpl::exist79Rec(
    vector<vector<char>>& board,
    const string word,
    const int curWordPos,
    const int curX,
    const int curY
) {
    if (curWordPos == word.size()) {
        return true;
    }

    if (curX < 0 || curX >= board.size() 
        || curY < 0 || curY >= board[0].size()
        || board[curX][curY] == '#'
        || board[curX][curY] != word[curWordPos]) {
        return false;
    }
    
    char curBoardChar = board[curX][curY];
    board[curX][curY] = '#';
    bool down = exist79Rec(board, word, curWordPos + 1, curX + 1, curY);
    bool up = exist79Rec(board, word, curWordPos + 1, curX - 1, curY);
    bool right = exist79Rec(board, word, curWordPos + 1, curX, curY + 1);
    bool left = exist79Rec(board, word, curWordPos + 1, curX, curY - 1);
    board[curX][curY] = curBoardChar;

    return (down || up || right || left);
} 