#include "string_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode Array Problem Solution Application starts.\n";
    StringTest * testObj = new StringTest();
    cout << "\nTest for problems starts.\n";

    testObj->lengthOfLongestSubstring3Test();
    testObj->longestPalindrome5Test();
    testObj->convert6Test();
    testObj->isMatch10Test();
    testObj->longestCommonPrefix14Test();
    testObj->strStr28Test();
    testObj->countAndSay38Test();
    testObj->fullJustify68Test();
    testObj->simplifyPath71Test();
    testObj->isPalindrome125Test();
    testObj->reverseWords151Test();
    testObj->read157Test();
    testObj->read158Test();

    return 0;
}
