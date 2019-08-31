#ifndef _BACKTRACKING_TEST_H
#define _BACKTRACKING_TEST_H

#include "backtracking_impl.h"

#include <iostream>
using namespace std;

class BacktrackingTest {
public:
    BacktrackingTest() {
        cout << "Test object for Leetcode Array problems constructed.\n";
        implObj = new BacktrackingImpl();
    }

    // 17. Letter Combinations of a Phone Number Test
    void letterCombinations17Test() {
        cout << "17. Letter Combinations of a Phone Number test starts.\n";
        vector<string> result = implObj->letterCombinations17("23");
        for (int i = 0; i < result.size(); ++i) {
            cout << "index " << i << "--" << result[i] << "; ";
        }

        cout << "\n\n";
        return;
    }

    // 22. Generate Parentheses Test
    void generateParenthesis22Test() {
        cout << "22. Generate Parentheses test starts.\n";
        vector<string> result = implObj->generateParenthesis22(3);
        for (int i = 0; i < result.size(); ++i) {
            cout << "index " << i << "--" << result[i] << "; ";
        }

        cout << "\n\n";
        return;
    }

    // 37. Sudoku Solver Test
    void solveSudoku37Test() {
        cout << "37. Sudoku Solver test starts.\n";
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        implObj->solveSudoku37(board);
        cout << "Current board solution is \n";
        for (int i = 0; i < 9; ++i) {
            cout << "[";
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << "; ";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 39. Combination Sum Test
    void combinationSum39Test() {
        cout << "39. Combination Sum test starts.\n";
        vector<int> candidate = {2,3,5};
        vector<vector<int>> result = implObj->combinationSum39(candidate, 8);
        cout << "candidate = {2, 3, 5}, target 8 will have \n";

        for (int i = 0; i < result.size(); ++i) {
            cout << "row " << i << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ";";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 40. Combination Sum II Test
    void combinationSum2_40Test() {
        cout << "40. Combination Sum II test starts.\n";
        vector<int> candidates = {10,1,2,7,6,1,5};
        int target = 8;
        vector<vector<int>> result = implObj->combinationSum2_40(candidates, target);
        cout << "{10,1,2,7,6,1,5} and 8 will generate [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "[";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ",");
            }
            cout << "]" << ((i == result.size() - 1) ? "\n" : ",\n");
        }
        cout << "].\n\n";
    }

    // 46. Permutations Test
    void permute46Test() {
        cout << "46. Permutations test starts.\n";
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> results = implObj->permute46(nums);
        
        cout << "Result is \n";
        for (int i = 0; i < results.size(); ++i) {
            cout << "Item " << i << " -- [";
            for (int j = 0; j < results[i].size(); ++j) {
                cout << results[i][j] << "; ";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 47. Permutations II Test
    void permuteUnique47Test() {
        cout << "47. Permutations II test starts.\n";
        vector<int> nums = {1,1,2};
        vector<vector<int>> results = implObj->permuteUnique47(nums);
        cout << "Result is [\n";
        for (int i = 0; i < results.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < results[i].size(); ++j) {
                cout << results[i][j] << ((j == results[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n";
        return;
    }

    // 51. N-Queens Test
    void solveNQueens51Test() {
        cout << "51. N-Queens test starts.\n";

        vector<vector<string>> results = implObj->solveNQueens51(4);
        cout << "N = " << 4 << "; Results are ";
        for (int i = 0; i < results.size(); ++i) {
            cout << "Answer " << i << " [\n";
            for (int j = 0; j < results[i].size(); ++j) {
                cout << "  [" << results[i][j] << "]\n";
            }
            cout << "]\n";
        }
        cout << "\n";
        return;
    }

    // 78. Subsets Test
    void subsets78Test() {
        cout << "78. Subsets test starts.\n";
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> result = implObj->subsets78(nums);
        cout << "All subsets [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
    }

    // 77. Combinations Test
    void combine77Test() {
        cout << "77. Combinations test starts.\n";
        vector<vector<int>> result = implObj->combine77(4, 2);
        cout << "All subsets [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "]\n\n";
    }

    // 79. Word Search Test
    void exist79Test() {
        cout << "79. Word Search test starts.\n";
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        cout << "Find 'ABCCED' is [" 
            << (implObj->exist79(board, "ABCCED") ? "True" : "False") <<"]\n";
        cout << "Find 'ABCB' is [" 
            << (implObj->exist79(board, "ABCB") ? "True" : "False") << "]\n";
        return;
    }

    // 93. Restore IP Addresses Test
    void restoreIpAddresses93Test() {
        cout << "Restore IP Addresses test starts.\n";
        string s = "25525511135";
        vector<string> allIps = implObj->restoreIpAddresses93(s);
        cout << "All Ips [";
        for (int i = 0; i < allIps.size(); ++i) {
            cout << allIps[i] << ((i == allIps.size() - 1) ? "" : ", "); 
        }
        cout << "]\n\n";
        return;
    }

    // 130. Surrounded Regions Test
    void solve130Test() {
        cout << "130. Surrounded Regions test starts.\n";
        vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'},
            {'O', 'O', 'X', 'O'}
        };
        implObj->solve130(board);
        cout << "Board = [";
        for (int i = 0; i < board.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < board[0].size(); ++j) {
                cout << board[i][j] << ((j == board[0].size() - 1) ?"" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
        return;
    }

    // 131. Palindrome Partitioning Test
    void partition131Test() {
        cout << "131. Palindrome Partitioning test starts.\n";
        vector<vector<string>> result = implObj->partition131("aab");
        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < result[i].size(); ++j) {
                cout << result[i][j] << ((j == result[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
    }

    // 140. Word Break II Test
    void wordBreak140Test() {
        cout << "140. Word Break II test starts.\n";
        string s = "catsanddog";
        vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        vector<string> result = implObj->wordBreak140(s, wordDict);

        cout << "Word breaks into [";
        for (int i = 0; i < result.size(); ++i) {
            cout << "\"" << result[i] << "\"" << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 200. Number of Islands Test
    void numIslands200Test() {
        cout << "200. Number of Islands test starts.\n";
        vector<vector<char>> grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
        };
        cout << "Num of islands = [" << implObj->numIslands200(grid) << "]\n\n";
    }

    // 282. Expression Add Operators Test
    void addOperators282Test() {
        cout << "282. Expression Add Operators test starts.\n";
        string num = "105";
        int target = 5;
        vector<string> result = implObj->addOperators282(num, target);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << "\"" << result[i] << "\"" << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 286. Walls and Gates Test
    void wallsAndGates286Test() {
        cout << "286. Walls and Gates test starts.\n";
        vector<vector<int>> nums = {
            {INT_MAX, -1, 0, INT_MAX},
            {INT_MAX, INT_MAX, INT_MAX, -1},
            {INT_MAX, -1, INT_MAX, -1},
            {0, -1, INT_MAX, INT_MAX}
        };
        implObj->wallsAndGates286(nums);
        cout << "Result = [\n";
        for (int i = 0; i < nums.size(); ++i) {
            cout << "  [";
            for (int j = 0; j < nums[i].size(); ++j) {
                cout << nums[i][j] << ((j == nums[i].size() - 1) ? "" : ", ");
            }
            cout << "]\n";
        }
        cout << "].\n\n";
        return;
    }

    // 329. Longest Increasing Path in a Matrix Test
    void longestIncreasingPath329Test() {
        cout << "329. Longest Increasing Path in a Matrix test starts.\n";
        vector<vector<int>> nums = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
        };
        cout << "Max increasing length = [" << implObj->longestIncreasingPath329(nums) << "]\n\n";
        return;
    }

private:
    BacktrackingImpl * implObj;
};

#endif