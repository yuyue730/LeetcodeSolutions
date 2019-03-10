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