#include "backtracking_test.h"

#include <vector>
using namespace std;

BacktrackingTest::BacktrackingTest() {
    cout << "Test object for Leetcode Array problems constructed.\n";
    implObj = new BacktrackingImpl();
}

// 17. Letter Combinations of a Phone Number Test
void BacktrackingTest::letterCombinations17Test() {
    cout << "17. Letter Combinations of a Phone Number test starts.\n";
    vector<string> result = implObj->letterCombinations17("23");
    for (int i = 0; i < result.size(); ++i) {
        cout << "index " << i << "--" << result[i] << "; ";
    }

    cout << "\n\n";
    return;
}

// 22. Generate Parentheses Test
void BacktrackingTest::generateParenthesis22Test() {
    cout << "22. Generate Parentheses test starts.\n";
    vector<string> result = implObj->generateParenthesis22(3);
    for (int i = 0; i < result.size(); ++i) {
        cout << "index " << i << "--" << result[i] << "; ";
    }

    cout << "\n\n";
    return;
}

// 37. Sudoku Solver Test
void BacktrackingTest::solveSudoku37Test() {
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
void BacktrackingTest::combinationSum39Test() {
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

// 46. Permutations Test
void BacktrackingTest::permute46Test() {
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