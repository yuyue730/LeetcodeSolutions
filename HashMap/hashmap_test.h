#ifndef _HASHMAP_TEST_H
#define _HASHMAP_TEST_H

#include "hashmap_impl.h"

#include <iostream>
using namespace std;

class HashMapTest {
public:
    HashMapTest();

    // 1. Two Sum Test
    void twoSum1Test();

    // 30. Substring with Concatenation of All Words Test
    void findSubstring30Test();

    // 36. Valid Sudoku Test
    void isValidSudoku36Test();

    // 49. Group Anagrams Test
    void groupAnagrams49Test();

    // 76. Minimum Window Substring Test
    void minWindow76Test();

    // 128. Longest Consecutive Sequence Test
    void longestConsecutive128Test();

private:
    HashMapImpl* implObj;
};

#endif