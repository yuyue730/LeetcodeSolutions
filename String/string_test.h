#ifndef _STRING_TEST_H
#define _STRING_TEST_H

#include "string_impl.h"

#include <iostream>
#include <vector>
using namespace std;

class StringTest {
public:
    StringTest() {
        cout << "Test object for Leetcode String problems constructed.\n";
        implObj = new StringImpl();
    }

    // 3. Longest Substring Without Repeating Characters Test
    void lengthOfLongestSubstring3Test() {
        cout << "3. Longest Substring Without Repeating Characters test starts.\n";

        string str = "abcabcbb";
        cout << "Test string has longest non-repeating chars at " << implObj->lengthOfLongestSubstring3(str) << ".\n\n";

        return;
    }

    // 5. Longest Palindromic Substring Test
    void longestPalindrome5Test() {
        cout << "5. Longest Palindromic Substring test starts.\n";

        string str = "babad";
        cout << "Longest Palindromic substring is " << implObj->longestPalindrome5(str) << ".\n\n";

        return;
    }

    // 6. ZigZag Conversion Test
    void convert6Test() {
        cout << "6. ZigZag Conversion test starts.\n";

        string str = "PAYPALISHIRING";
        cout << "ZigZag conversion = " << implObj->convert6(str, 4) << ".\n\n";

        return;
    }

    // 10. Regular Expression Matching Test
    void isMatch10Test() {
        cout << "10. Regular Expression Matching test starts.\n";
        cout << "isMatch between 'aab' and 'c*a*b' is " << implObj->isMatch10("aab", "c*a*b") << ".\n\n";
        return;
    }

    // 14. Longest Common Prefix Test
    void longestCommonPrefix14Test() {
        cout << "14. Longest Common Prefix test starts.\n";
        vector<string> strArr = {"flower", "flow", "flight"};
        cout << "Longest Common Prefix is " << implObj->longestCommonPrefix14(strArr) << ".\n\n";
        return;
    }

    // 28. Implement strStr() Test
    void strStr28Test() {
        cout << "28. Implement strStr() test starts.\n";
        cout << "hello and ll will return " << implObj->strStr28("hello", "ll") << ".\n\n";
        return;
    }

    // 38. Count and Say Test
    void countAndSay38Test() {
        cout << "38. Count and Say test starts.\n";
        cout << "6 will generate " << implObj->countAndSay38(6) << ".\n\n";
        return;
    }

    // 68. Text Justification Test
    void fullJustify68Test() {
        cout << "68. Text Justification test starts.\n";
        vector<string> words = {
            "This", "is", "an", "example", "of", "text", "justification."
        };
        vector<string> results = implObj->fullJustify68(words, 16);
        cout << "Result is [\n";
        for (int i = 0; i < results.size(); ++i) {
            cout << results[i] << ",\n";
        }
        cout << "]\n\n";
        return;
    }

    // 71. Simplify Path Test
    void simplifyPath71Test() {
        cout << "71. Simplify Path test starts.\n";
        cout << "'/a//b////c/d//././/..' will generate " << implObj->simplifyPath71("/a//b////c/d//././/..") << "\n\n";
        return;
    }


    // 125. Valid Palindrome Test
    void isPalindrome125Test() {
        cout << "125. Valid Palindrome test starts.\n";
        cout << "'A man, a plan, a canal: Panama' = " 
            << (implObj->isPalindrome125("A man, a plan, a canal: Panama") ? "True" : "False")
            << "\n\n";
        return;
    }

    // 151. Reverse Words in a String Test
    void reverseWords151Test() {
        cout << "151. Reverse Words in a String test starts.\n";
        cout << "Reverse result [" << implObj->reverseWords151("a good   example") << "]\n\n";
        return;
    }

    // 157. Read N Characters Given Read4 Test
    void read157Test() {
        cout << "157. Read N Characters Given Read4 test starts.\n";
        implObj->setFileStr("abc");
        char * result1 = new char[1];
        int ct1 = implObj->read157(result1, 4);
        cout << "abc read 3 [" << string(result1).substr(0, ct1) << "]; ct1 = [" << ct1 << "]\n";

        implObj->setFileStr("abcde");
        char * result2 = new char[1];
        int ct2 = implObj->read157(result2, 5);
        cout << "abcde read 5 [" << string(result2).substr(0, ct2) << "]; ct2 = [" << ct2 << "]\n";

        implObj->setFileStr("abcdABCD1234");
        char * result3 = new char[1];
        int ct3 = implObj->read157(result3, 12);
        cout << "abcdABCD1234 read 12 [" << string(result3).substr(0, ct3) << "]; ct3 = [" << ct3 << "]\n";

        implObj->setFileStr("leetcode");
        char * result4 = new char[1];
        int ct4 = implObj->read157(result4, 5);
        cout << "leetcode read 5 [" << string(result4).substr(0, ct4) << "]; ct4 = [" << ct4 << "]\n\n";
        return;
    }

    // 158. Read N Characters Given Read4 II - Call multiple times Test
    void read158Test() {
        cout << "158. Read N Characters Given Read4 II - Call multiple times Test starts.\n";
        implObj->setFileStr("abcdABCD1234");
        char * result5 = new char[16];
        int ct5 = implObj->read158(result5, 5);
        cout << "abcdABCD1234 read 5 [" << string(result5).substr(0, ct5) << "]\n";

        char * result4 = new char[16];
        int ct4 = implObj->read158(result4, 4);
        cout << "abcdABCD1234 read 4 [" << string(result4).substr(0, ct4) << "]\n";

        char * result6 = new char[16];
        int ct6 = implObj->read158(result6, 6);
        cout << "abcdABCD1234 read 4 [" << string(result6).substr(0, ct6) << "]\n\n";
        return;
    }

    // 161. One Edit Distance Test
    void isOneEditDistance161Test() {
        cout << "161. One Edit Distance test starts.\n";
        cout << "1213 and 1203 are the same? [" 
            << (implObj->isOneEditDistance161("1213", "1203") ? "True" : "False")
            << "]\n\n";
        return;
    }

    // 165. Compare Version Numbers Test
    void compareVersion165Test() {
        cout << "165. Compare Version Numbers test starts.\n";
        string ver_1 = "1.0.1";
        string ver_2 = "1";
        cout << "Compare result = [" << implObj->compareVersion165(ver_1, ver_2) 
            << "]\n\n";
        return;
    }

private:
    StringImpl * implObj;
};

#endif