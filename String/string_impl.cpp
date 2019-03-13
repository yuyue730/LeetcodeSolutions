#include "string_impl.h"

#include <unordered_set>
#include <vector>
using namespace std;

StringImpl::StringImpl() {
    cout << "Impl object for Leetcode String problems constructed.\n";
}

//  3. Longest Substring Without Repeating Characters
int StringImpl::lengthOfLongestSubstring3(string s) {
    if (s.empty()) {
        return 0;
    }

    int left = 0, right = 0;
    int result = 0;
    unordered_set<char> charSet;

    while (right < s.length()) {
        if (!charSet.count(s[right])) {
            charSet.insert(s[right]);
            result = max(result, right - left + 1);
            ++right;
        } else {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                ++left;
            }
        }
    }

    return result;
}

// 5. Longest Palindromic Substring
string StringImpl::longestPalindrome5(string s) {
    if (s.empty()) {
        return "";
    }

    string result;
    for (int i = 0; i < s.length(); ++i) {
        findLongestPalindromeRec(s, i, i, result);
        findLongestPalindromeRec(s, i, i + 1, result);
    }

    return result;
}

void StringImpl::findLongestPalindromeRec(const string str, int left, int right, string & result) {
    while (left >= 0 && right < str.length() && str[left] == str[right]) {
        --left;
        ++right;
    }

    int curLen = right - left - 1;
    if (curLen > result.size()) {
        result = str.substr(left + 1, curLen);
    }

    return;
}

// 6. ZigZag Conversion
string StringImpl::convert6(string s, int numRows) {
    if (s.length() <= numRows || numRows == 1) {
        return s;
    }

    vector<string> strArr(numRows);
    const int nElemInIteration = 2 * numRows - 2;
    for (int i = 0; i < s.length(); ++i) {
        int curIterationIdx = i % nElemInIteration;
        int curRow = curIterationIdx < numRows ? curIterationIdx : 2 * numRows - curIterationIdx - 2;
        strArr[curRow].push_back(s[i]);
    }

    string result;
    for (int j = 0; j < strArr.size(); ++j) {
        result += strArr[j];
    }
    return result;
}

// 10. Regular Expression Matching
bool StringImpl::isMatch10(string s, string p) {
    if (p.empty()) {
        return s.empty();
    }

    bool isFirstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
    if (p.length() > 1 && p[1] == '*') {
        return isMatch10(s, p.substr(2)) || (isFirstMatch && isMatch10(s.substr(1), p));
    } else {
        return isFirstMatch && isMatch10(s.substr(1), p.substr(1));
    }
}

// 14. Longest Common Prefix
string StringImpl::longestCommonPrefix14(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    }
    string result = "";

    for (int i = 0; i < strs[0].length(); ++i) {
        char curCh = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            if (i >= strs[j].length() || strs[j][i] != curCh) {
                return result;
            }
        }
        result.push_back(strs[0][i]);
    }

    return result;
}