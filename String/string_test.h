#ifndef _STRING_TEST_H
#define _STRING_TEST_H

#include "string_impl.h"

class StringTest {
public:
    StringTest();

    //  3. Longest Substring Without Repeating Characters
    void lengthOfLongestSubstring3Test();

    // 5. Longest Palindromic Substring
    void longestPalindrome5Test();

private:
    StringImpl * implObj;
};

#endif