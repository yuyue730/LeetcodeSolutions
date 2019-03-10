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

private:
    StringImpl * implObj;
};

#endif