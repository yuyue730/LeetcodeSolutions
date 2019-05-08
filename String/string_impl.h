#ifndef _STRING_IMPL_H
#define _STRING_IMPL_H

#include <iostream>
#include <string>
using namespace std;

class StringImpl {
public:
    StringImpl();

    //  3. Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring3(string s);

    // 5. Longest Palindromic Substring
    string longestPalindrome5(string s);

    // 6. ZigZag Conversion
    string convert6(string s, int numRows);

    // 10. Regular Expression Matching
    bool isMatch10(string s, string p);

    // 14. Longest Common Prefix
    string longestCommonPrefix14(vector<string>& strs);

    // 28. Implement strStr()
    int strStr28(string haystack, string needle);

    // 38. Count and Say
    string countAndSay38(int n);

    // 68. Text Justification
    vector<string> fullJustify68(vector<string>& words, int maxWidth);

private:
    // 5. Longest Palindromic Substring helper
    void findLongestPalindromeRec(const string str, int left, int right, string & result);
};

#endif