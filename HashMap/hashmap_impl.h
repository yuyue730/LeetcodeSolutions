#ifndef _HASHMAP_IMPL_H
#define _HASHMAP_IMPL_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class HashMapImpl {
public:
    HashMapImpl();

    // 1. Two Sum
    vector<int> twoSum1(vector<int>& nums, int target);

    // 30. Substring with Concatenation of All Words
    vector<int> findSubstring30(string s, vector<string>& words);

    // 36. Valid Sudoku
    bool isValidSudoku36(vector<vector<char>>& board);

    // 49. Group Anagrams
    vector<vector<string>> groupAnagrams49(vector<string>& strs);

    // 76. Minimum Window Substring
    string minWindow76(string s, string t);

    // 128. Longest Consecutive Sequence
    int longestConsecutive128(vector<int>& nums);
};

#endif