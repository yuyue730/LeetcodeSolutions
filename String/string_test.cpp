#include "string_test.h"

#include <iostream>
using namespace std;

StringTest::StringTest() {
    cout << "Test object for Leetcode String problems constructed.\n";
    implObj = new StringImpl();
}

void StringTest::lengthOfLongestSubstringTest() {
    cout << "3. Longest Substring Without Repeating Characters starts.\n";

    string str = "abcabcbb";
    cout << "Test string has longest non-repeating chars at " << implObj->lengthOfLongestSubstring3(str) << ".\n";

    return;
}