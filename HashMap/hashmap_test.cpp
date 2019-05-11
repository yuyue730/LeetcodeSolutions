#include "hashmap_test.h"

HashMapTest::HashMapTest() {
    cout << "Test object for Leetcode HashMap problems constructed.\n";
    implObj = new HashMapImpl();
}

// 1. Two Sum Test
void HashMapTest::twoSum1Test() {
    cout << "1. Two Sum test starts.\n";
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = implObj->twoSum1(nums, target);
    cout << "{2, 7, 11, 15} and 9 will return " << result[0] << " and " << result[1] << "\n\n";
    return;
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

// 49. Group Anagrams Test
void HashMapTest::groupAnagrams49Test() {
    cout << "49. Group Anagrams test starts.\n";
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = implObj->groupAnagrams49(strs);
    cout << "Result is \n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Patch " << i << ": [";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ((j < result[i].size() - 1) ? "; " : "");
        }
        cout << "]\n";
    }
    cout << "\n";
    return;
}

// 76. Minimum Window Substring Test
void HashMapTest::minWindow76Test() {
    cout << "76. Minimum Window Substring test starts.\n";
    string S = "ADOBECODEBANC", T = "ABC";
    string result = implObj->minWindow76(S, T);
    cout << "Minimum Window Substring is " << result << ".\n\n";
    return;
}