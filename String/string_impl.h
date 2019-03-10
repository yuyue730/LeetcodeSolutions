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

private:
    // 5. Longest Palindromic Substring helper
    void findLongestPalindromeRec(const string str, int left, int right, string & result);
};

#endif