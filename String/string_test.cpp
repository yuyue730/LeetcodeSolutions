#include "string_test.h"

#include <iostream>
using namespace std;

StringTest::StringTest() {
    cout << "Test object for Leetcode String problems constructed.\n";
    implObj = new StringImpl();
}

//  3. Longest Substring Without Repeating Characters Test
void StringTest::lengthOfLongestSubstring3Test() {
    cout << "3. Longest Substring Without Repeating Characters test starts.\n";

    string str = "abcabcbb";
    cout << "Test string has longest non-repeating chars at " << implObj->lengthOfLongestSubstring3(str) << ".\n\n";

    return;
}

// 5. Longest Palindromic Substring Test
void StringTest::longestPalindrome5Test() {
    cout << "5. Longest Palindromic Substring test starts.\n";

    string str = "babad";
    cout << "Longest Palindromic substring is " << implObj->longestPalindrome5(str) << ".\n\n";

    return;
}

// 6. ZigZag Conversion Test
void StringTest::convert6Test() {
    cout << "6. ZigZag Conversion test starts.\n";

    string str = "PAYPALISHIRING";
    cout << "ZigZag conversion = " << implObj->convert6(str, 4) << ".\n\n";

    return;
}