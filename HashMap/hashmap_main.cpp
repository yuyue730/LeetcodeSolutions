// Leetcode HashMap Problems main function
#include "hashmap_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode HashMap Problem Solution Application starts.\n";
    HashMapTest* testObj = new HashMapTest();
    cout << "\nTest for problems starts.\n";

    testObj->twoSum1Test();
    testObj->findSubstring30Test();
    testObj->isValidSudoku36Test();
    testObj->groupAnagrams49Test();
    testObj->minWindow76Test();
    testObj->longestConsecutive128Test();
    testObj->maxPoints149Test();
    testObj->lengthOfLongestSubstringTwoDistinct159Test();
    testObj->findRepeatedDnaSequences187Test();
    testObj->isHappy202Test();

    return 0;
}