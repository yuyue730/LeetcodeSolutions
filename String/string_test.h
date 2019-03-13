#ifndef _STRING_TEST_H
#define _STRING_TEST_H

#include "string_impl.h"

class StringTest {
public:
    StringTest();

    //  3. Longest Substring Without Repeating Characters Test
    void lengthOfLongestSubstring3Test();

    // 5. Longest Palindromic Substring Test
    void longestPalindrome5Test();

    // 6. ZigZag Conversion Test
    void convert6Test();

    // 10. Regular Expression Matching Test
    void isMatch10Test();

    // 14. Longest Common Prefix Test
    void longestCommonPrefix14Test();

private:
    StringImpl * implObj;
};

#endif