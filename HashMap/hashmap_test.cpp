#include "hashmap_test.h"

HashMapTest::HashMapTest() {
    cout << "Test object for Leetcode HashMap problems constructed.\n";
    implObj = new HashMapImpl();
}

// 30. Substring with Concatenation of All Words Test
void HashMapTest::findSubstring30Test() {
    cout << "30. Substring with Concatenation of All Words test starts.\n";
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = implObj->findSubstring30(s, words);
    cout << "barfoothefoobarman and {foo, bar} will generate [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ";";
    }
    cout << "].\n\n";
}

// 36. Valid Sudoku Test
void HashMapTest::isValidSudoku36Test() {
    cout << "36. Valid Sudoku test starts.\n";
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

    cout << "Current board is [" << implObj->isValidSudoku36(board) << "].\n\n";
    return;
}