#ifndef _BACKTRACKING_IMPL_H
#define _BACKTRACKING_IMPL_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class BacktrackingImpl {
public:
    BacktrackingImpl() {
        cout << "Impl object for Leetcode Backtracking problems constructed.\n";
    }

    // 17. Letter Combinations of a Phone Number
    vector<string> letterCombinations17(string digits) {
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

    void generateLetterCombRec(
        const vector<string>& digitLetterMap, const string digits, 
        int curIdx, string curResult, vector<string> & result
    ) {
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
    vector<string> generateParenthesis22(int n) {
        vector<string> result;
        if (n == 0) {
            return result;
        }

        generateParenthesisRec(n, n, "", result);
        return result;
    }

    void generateParenthesisRec(
        int left, int right, string curStr, vector<string> & result
    ) {
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
    void solveSudoku37(vector<vector<char>>& board) {
        assert(board.size() == 9 && board[0].size() == 9);
        solveSudokuRec(board, 0, 0);
    }

    bool solveSudokuRec(
        vector<vector<char>>& board, int iRow, int iCol
    ) {
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

    bool isValidSudokuPerUnit(
        const vector<vector<char>>& board, int iRow, int iCol
    ) {
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
    vector<vector<int>> combinationSum39(
        vector<int>& candidates, 
        int target
    ) {
        vector<vector<int>> allRes;
        vector<int> curRes;
        combinationSumRec(0, candidates, curRes, allRes, target);
        return allRes;
    }

    void combinationSumRec(
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

    // 40. Combination Sum II
    vector<vector<int>> combinationSum2_40(
        vector<int>& candidates, int target
    ) {
        vector<vector<int>> allResults;
        vector<int> curResult;
        sort(candidates.begin(), candidates.end());
        combinationSum2Rec(curResult, allResults, 0, target, candidates);
        return allResults;
    }

    void combinationSum2Rec(
        vector<int> & curResult,
        vector<vector<int>> & allResults,
        int startIdx,
        int remain,
        const vector<int> & candidates
    ) {
        if (remain < 0) {
            return;
        } else if (remain == 0) {
            allResults.push_back(curResult);
        } else {
            for (int i = startIdx; i < candidates.size(); ++i) {
                if (i > startIdx && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                curResult.push_back(candidates[i]);
                combinationSum2Rec(curResult, allResults, i + 1, 
                    remain - candidates[i], candidates);
                curResult.pop_back();
            }
        }
    }

    // 46. Permutations
    vector<vector<int>> permute46(vector<int>& nums)
    {
        vector<vector<int>> results;
        vector<int> curRes;
        vector<bool> visited(nums.size(), false);
        permute46Rec(results, curRes, visited, nums);
        return results;
    }

    void permute46Rec(
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

    // 47. Permutations II
    vector<vector<int>> permuteUnique47(vector<int>& nums) {
        vector<vector<int>> allResult;
        if (nums.size() == 0) {
            return allResult;
        }
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> curResult;
        permuteUnique47DFS(nums, 0, curResult, allResult, visited);
        return allResult;
    }

    void permuteUnique47DFS(
        const vector<int> & nums,
        int level, 
        vector<int> & curResult,
        vector<vector<int>> & allResult,
        vector<bool> & visited
    ) {
        if (level >= nums.size()) {
            allResult.push_back(curResult);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            curResult.push_back(nums[i]);
            permuteUnique47DFS(nums, level + 1, curResult, allResult, visited);
            curResult.pop_back();
            visited[i] = false;
        }
    }

    // 51. N-Queens
    vector<vector<string>> solveNQueens51(int n)
    {
        vector<vector<string>> results;
        if (n == 0) {
            return results;
        }

        vector<string> curRes(n, string(n, '.'));
        solveNQueens51Rec(results, curRes, 0, n);
        return results;
    }

    void solveNQueens51Rec(
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

    bool isCurrentBoardValid(
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

    // 77. Combinations
    vector<vector<int>> combine77(int n, int k) {
        vector<int> curRes;
        vector<vector<int>> allRes;
        combine77helper(n, k, 1, curRes, allRes);
        return allRes;
    }

    void combine77helper(
        const int n, const int k,
        int curVal, vector<int> & curRes,
        vector<vector<int>> & allRes
    ) {
        if (curRes.size() == k) {
            allRes.push_back(curRes);
            return;
        }

        for (int i = curVal; i <= n; ++i) {
            curRes.push_back(i);
            combine77helper(n, k, i + 1, curRes, allRes);
            curRes.pop_back();
        }
    }

    // 78. Subsets
    vector<vector<int>> subsets78(vector<int>& nums) {
        vector<vector<int>> allResult;
        vector<int> curResult;
        subsets78Rec(curResult, allResult, 0, nums);
        return allResult;
    }

    void subsets78Rec(
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
    bool exist79(vector<vector<char>>& board, string word)
    {
        // Corner pressure test case: Recursion should be avoided
        // Iteration solution should be used in order to pass these cases 
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

    bool exist79Rec(
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

    // 93. Restore IP Addresses
    vector<string> restoreIpAddresses93(string s)
    {
        vector<string> results;
        if (s.size() < 4) {
            return results;
        }

        vector<string> curRes;
        restoreIpAddresses93Rec(results, curRes, 0, s);
        return results;
    }

    void restoreIpAddresses93Rec(
        vector<string> & allResults,
        vector<string> & curResult,
        const int curPos,
        const string & ipStr
    ) {
        if (curResult.size() == 4) {
            if (curPos == ipStr.size()) {
                string curResStr = "";
                for (int i = 0; i < curResult.size(); ++i) {
                    curResStr += curResult[i] + (i == 3 ? "" : ".");
                }
                allResults.push_back(curResStr);
            }
            return;
        }

        for (int i = curPos; i < curPos + 4 && i < ipStr.size(); ++i) {
            string curNumStr = ipStr.substr(curPos, i - curPos + 1);
            if (isValidIpNumStr(curNumStr)) {
                curResult.push_back(curNumStr);
                restoreIpAddresses93Rec(allResults, curResult, i + 1, ipStr);
                curResult.pop_back();
            }
        }
    }

    bool isValidIpNumStr(string & ipNumStr)
    {
        if (ipNumStr.empty() || ipNumStr.size() > 3) {
            return false;
        }
        if (ipNumStr[0] == '0' && ipNumStr.size() > 1) {
            return false;
        }
        if (stoi(ipNumStr) > 255) {
            return false;
        }
        return true;
    }

    // 130. Surrounded Regions
    void solve130(vector<vector<char>>& board)
    {
        if (board.size() == 0) {
            return;
        }
        int mSize = board.size(), nSize = board[0].size();
        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < nSize; ++j) {
                if (i == 0 || i == mSize - 1 || j == 0 || j == nSize - 1) {
                    solve130DFS(board, i, j);
                }
            }
        }

        for (int i = 0; i < mSize; ++i) {
            for (int j = 0; j < nSize; ++j) {
                if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void solve130DFS(
        vector<vector<char>>& board, int iIdx, int jIdx
    ) {
        int mSize = board.size(), nSize = board[0].size();
        if (board[iIdx][jIdx] == 'O') {
            board[iIdx][jIdx] = 'P';
            if (iIdx > 0 && board[iIdx - 1][jIdx] == 'O') {
                solve130DFS(board, iIdx - 1, jIdx);
            }
            if (iIdx < mSize - 1 && board[iIdx + 1][jIdx] == 'O') {
                solve130DFS(board, iIdx + 1, jIdx);
            }
            if (jIdx > 0 && board[iIdx][jIdx - 1] == 'O') {
                solve130DFS(board, iIdx, jIdx - 1);
            }
            if (jIdx < nSize - 1 && board[iIdx][jIdx + 1] == 'O') {
                solve130DFS(board, iIdx, jIdx + 1);
            }
        }
    }

    // 131. Palindrome Partitioning
    vector<vector<string>> partition131(string s)
    {
        vector<string> curRes;
        vector<vector<string>> allRes;
        partition131helper(s, 0, curRes, allRes);
        return allRes;
    }

    void partition131helper(
        const string s, int startIdx, 
        vector<string> & curRes, 
        vector<vector<string>> & allRes
    ) {
        if (startIdx == s.size()) {
            allRes.push_back(curRes);
            return;
        }

        for (int i = startIdx; i < s.size(); ++i) {
            if (isPalindrome(s, startIdx, i)) {
                curRes.push_back(s.substr(startIdx, i - startIdx + 1));
                partition131helper(s, i + 1, curRes, allRes);
                curRes.pop_back();
            }
        }
    }

    bool isPalindrome(const string s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++; right--;
        }
        return true;
    }

    // 140. Word Break II
    vector<string> wordBreak140(
        string s, vector<string>& wordDict
    ) {
        unordered_map<string, vector<string>> strVecMap;
        return wordBreak140helper(s, wordDict, strVecMap);
    }

    vector<string> wordBreak140helper(
        string s, const vector<string> & wordDict, 
        unordered_map<string, vector<string>> & strVecMap
    ) {
        if (strVecMap.count(s)) {
            return strVecMap[s];
        }
        if (s == "") {
            return {""};
        }

        vector<string> result;
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s.substr(0, wordDict[i].size()) != wordDict[i]) {
                continue;
            }

            vector<string> remainResult = wordBreak140helper(
                s.substr(wordDict[i].size()), wordDict, strVecMap
            );
            for (int remIdx = 0; remIdx < remainResult.size(); ++remIdx) {
                string curRemStr = remainResult[remIdx];
                result.push_back(
                    wordDict[i] + (curRemStr == "" ? "" : " ") + curRemStr
                );
            }
        }
        strVecMap[s] = result;
        return result;
    }

    // 200. Number of Islands
    int numIslands200(vector<vector<char>>& grid) {
        int result = 0;
        if (grid.empty() || grid[0].empty()) {
            return result;
        }

        int n_size = grid.size(), m_size = grid[0].size();
        vector<vector<bool>> visited_matrix(n_size, vector<bool>(m_size, false));

        for (int i = 0; i < n_size; ++i) {
            for (int j = 0; j < m_size; ++j) {
                if (grid[i][j] == '1' && !visited_matrix[i][j]) {
                    visitIslandDFS(grid, visited_matrix, i, j);
                    ++result;
                }
            }
        }

        return result;
    }

    void visitIslandDFS(
        const vector<vector<char>>& grid,
        vector<vector<bool>> & visitedMatrix,
        int curI, int curJ
    ) {
        if (curI < 0 || curI >= grid.size()) {
            return;
        }
        if (curJ < 0 || curJ >= grid[0].size()) {
            return;
        }
        if (visitedMatrix[curI][curJ] || grid[curI][curJ] != '1') {
            return;
        }

        visitedMatrix[curI][curJ] = true;
        visitIslandDFS(grid, visitedMatrix, curI + 1, curJ);
        visitIslandDFS(grid, visitedMatrix, curI - 1, curJ);
        visitIslandDFS(grid, visitedMatrix, curI, curJ + 1);
        visitIslandDFS(grid, visitedMatrix, curI, curJ - 1);
    }

    // 282. Expression Add Operators
    vector<string> addOperators282(string num, int target) {
        vector<string> result;
        if (num.empty()) {
            return result;
        }
        addOperators282Rec(num, target, 0, 0, "", result);
        return result;
    }

    void addOperators282Rec(
        string num, const int target, long cur_num, long diff, 
        string cur_res, vector<string> & all_res
    ) {
        if (num.size() == 0 && cur_num == target) {
            all_res.push_back(cur_res);
            return;
        }

        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') {
                return;
            }

            string next = num.substr(i);
            if (cur_res.empty()) {
                addOperators282Rec(next, target, stoll(cur), stoll(cur), cur, all_res);
            } else {
                addOperators282Rec(
                    next, target, cur_num + stoll(cur), stoll(cur), 
                    cur_res + "+" + cur, all_res
                );
                addOperators282Rec(
                    next, target, cur_num - stoll(cur), -stoll(cur), 
                    cur_res + "-" + cur, all_res
                );
                addOperators282Rec(
                    next, target, cur_num - diff + diff * stoll(cur), 
                    diff * stoll(cur), cur_res + "*" + cur, all_res
                );
            }
        }
    }

    // 286. Walls and Gates
    void wallsAndGates286(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) {
                    wallsAndGates286_dfs(rooms, i, j, 0);
                }
            }
        }
    }

    void wallsAndGates286_dfs(
        vector<vector<int>> & rooms, int x, int y, int next_dist
    ) {
        if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size()) {
            return;
        }
        if (rooms[x][y] < next_dist) {
            return;
        }

        rooms[x][y] = next_dist;
        wallsAndGates286_dfs(rooms, x + 1, y, next_dist + 1);
        wallsAndGates286_dfs(rooms, x, y + 1, next_dist + 1);
        wallsAndGates286_dfs(rooms, x - 1, y, next_dist + 1);
        wallsAndGates286_dfs(rooms, x, y - 1, next_dist + 1);
    }

    // 329. Longest Increasing Path in a Matrix
    int longestIncreasingPath329(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<pair<int, int>> direc = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur_len = longestIncreasingPath329_dfs(
                    dp, matrix, direc, i, j
                );
                result = max(result, cur_len);
            }
        }

        return result;
    }

    int longestIncreasingPath329_dfs(
        vector<vector<int>> & dp,
        const vector<vector<int>> & matrix,
        const vector<pair<int, int>> & direc,
        const int i, const int j
    ) {
        if (dp[i][j]) {
            return dp[i][j];
        }

        int m = matrix.size(), n = matrix[0].size();
        int cur_max = 1;

        for (auto iter : direc) {
            int next_x = i + iter.first, next_y = j + iter.second;
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n
                || matrix[next_x][next_y] <= matrix[i][j]) {
                continue;
            }

            int len = 1 + longestIncreasingPath329_dfs(dp, matrix, direc, next_x, next_y);
            cur_max = max(cur_max, len);
        }

        dp[i][j] = cur_max;
        return cur_max;
    }
};

#endif