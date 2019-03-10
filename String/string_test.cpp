#include "string_test.h"

#include <iostream>
using namespace std;

StringTest::StringTest() {
    cout << "Test object for Leetcode String problems constructed.\n";
    implObj = new StringImpl();
}

void StringTest::lengthOfLongestSubstring3Test() {
    cout << "3. Longest Substring Without Repeating Characters test starts.\n";

    string str = "abcabcbb";
    cout << "Test string has longest non-repeating chars at " << implObj->lengthOfLongestSubstring3(str) << ".\n\n";

    return;
}

void StringTest::longestPalindrome5Test() {
    cout << "5. Longest Palindromic Substring test starts.\n";

    // string str = "babad";
    string str = "a";
    cout << "Longest Palindromic substring is " << implObj->longestPalindrome5(str) << ".\n\n";

    return;
}