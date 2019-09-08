#ifndef _HASHMAP_TEST_H
#define _HASHMAP_TEST_H

#include "hashmap_impl.h"

#include <iostream>
using namespace std;

class HashMapTest {
public:
    HashMapTest() {
        cout << "Test object for Leetcode HashMap problems constructed.\n";
        implObj = new HashMapImpl();
    }

    // 1. Two Sum Test
    void twoSum1Test() {
        cout << "1. Two Sum test starts.\n";
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;

        vector<int> result = implObj->twoSum1(nums, target);
        cout << "{2, 7, 11, 15} and 9 will return " << result[0] << " and " << result[1] << "\n\n";
        return;
    }

    // 30. Substring with Concatenation of All Words Test
    void findSubstring30Test() {
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
    void isValidSudoku36Test() {
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
    void groupAnagrams49Test() {
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
    void minWindow76Test() {
        cout << "76. Minimum Window Substring test starts.\n";
        string S = "ADOBECODEBANC", T = "ABC";
        string result = implObj->minWindow76(S, T);
        cout << "Minimum Window Substring is " << result << ".\n\n";
        return;
    }

    // 128. Longest Consecutive Sequence Test
    void longestConsecutive128Test() {
        cout << "128. Longest Consecutive Sequence test starts.\n";
        vector<int> nums = {100, 4, 200, 1, 3, 2};
        cout << "Longest Consecutive Sequence = [" << implObj->longestConsecutive128(nums) 
            << "].\n\n";
        return;
    }

    // 149. Max Points on a Line Test
    void maxPoints149Test() {
        cout << "149. Max Points on a Line test starts.\n";
        vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
        cout << "Max points on a line = [" << implObj->maxPoints149(points) << "].\n\n";
        return; 
    }

    // 159. Longest Substring with At Most Two Distinct Characters Test
    void lengthOfLongestSubstringTwoDistinct159Test() {
        cout << "159. Longest Substring with At Most Two Distinct Characters test starts.\n";
        string str = "eceba";
        cout << "Length = [" << implObj->lengthOfLongestSubstringTwoDistinct159(str) << "]\n\n";
        return;
    }

    // 187. Repeated DNA Sequences Test
    void findRepeatedDnaSequences187Test() {
        cout << "187. Repeated DNA Sequences test starts.\n";
        vector<string> result 
            = implObj->findRepeatedDnaSequences187("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
    }

    // 202. Happy Number Test
    void isHappy202Test() {
        cout << "202. Happy Number test starts.\n";
        cout << "19 is happy number = [" << implObj->isHappy202(19) << "]\n\n";
        return;
    }

    // 205. Isomorphic Strings Test
    void isIsomorphic205Test() {
        cout << "205. Isomorphic Strings test starts.\n";
        cout << "paper and title are [" << implObj->isIsomorphic205("paper", "title") 
            << "]\n\n";
        return;
    }

    // 242. Valid Anagram Test
    void isAnagram242Test() {
        cout << "242. Valid Anagram test starts.\n";
        cout << "anagram and nagaram = [" 
            << (implObj->isAnagram242("anagram", "nagaram") ? "True" : "False")
            << "]\n\n";
        return;
    }

    // 316. Remove Duplicate Letters Test
    void removeDuplicateLetters316Test() {
        cout << "316. Remove Duplicate Letters test starts.\n";
        cout << "Result = [" << implObj->removeDuplicateLetters316("cbacdcbc") << "]\n\n";
        return;
    }

    // 336. Palindrome Pairs Test
    void palindromePairs336Test() {
        cout << "336. Palindrome Pairs test starts.\n";
        vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
        vector<vector<int>> result = implObj->palindromePairs336(words);

        cout << "Result = [\n";
        for (int i = 0; i < result.size(); ++i) {
            cout << "  [" << result[i][0] << ", " << result[i][1] << "]\n";
        }
        cout << "]\n\n";
        return;
    }

    // 340. Longest Substring with At Most K Distinct Characters Test
    void lengthOfLongestSubstringKDistinct340Test() {
        cout << "340. Longest Substring with At Most K Distinct Characters test starts.\n";
        cout << "eceba and 2 will have max length = [" 
            << implObj->lengthOfLongestSubstringKDistinct340("eceba", 2)
            << "]\n\n";
        return;
    }

    // 347. Top K Frequent Elements Test
    void topKFrequent347Test() {
        cout << "347. Top K Frequent Elements test starts.\n";
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        vector<int> result = implObj->topKFrequent347(nums, 2);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 349. Intersection of Two Arrays Test
    void intersection349Test() {
        cout << "349. Intersection of Two Arrays test starts.\n";
        vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
        vector<int> result = implObj->intersection349(nums1, nums2);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 350. Intersection of Two Arrays II Test
    void intersect350Test() {
        cout << "350. Intersection of Two Arrays II test starts.\n";
        vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
        vector<int> result = implObj->intersect350(nums1, nums2);
        cout << "Result = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i == result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

private:
    HashMapImpl* implObj;
};

#endif