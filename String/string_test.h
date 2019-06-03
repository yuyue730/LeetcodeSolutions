#ifndef _STRING_TEST_H
#define _STRING_TEST_H

#include "string_impl.h"

class StringTest {
public:
    StringTest();

    // 3. Longest Substring Without Repeating Characters Test
    void lengthOfLongestSubstring3Test();

    // 5. Longest Palindromic Substring Test
    void longestPalindrome5Test();

    // 6. ZigZag Conversion Test
    void convert6Test();

    // 10. Regular Expression Matching Test
    void isMatch10Test();

    // 14. Longest Common Prefix Test
    void longestCommonPrefix14Test();

    // 28. Implement strStr() Test
    void strStr28Test();

    // 38. Count and Say Test
    void countAndSay38Test();

    // 68. Text Justification Test
    void fullJustify68Test();

    // 71. Simplify Path Test
    void simplifyPath71Test();

    // 125. Valid Palindrome Test
    void isPalindrome125Test();

private:
    StringImpl * implObj;
};

#endif