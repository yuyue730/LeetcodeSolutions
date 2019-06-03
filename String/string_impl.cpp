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

// 28. Implement strStr()
int StringImpl::strStr28(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }

    int hSize = haystack.length();
    int nSize = needle.length();
    if (nSize > hSize) {
        return -1;
    }

    for (int i = 0; i <= hSize - nSize; ++i) {
        int j = 0;
        while (j < nSize) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
            j++;
        }

        if (j == nSize) {
            return i;
        }
    }

    return -1;
}

// 38. Count and Say
string StringImpl::countAndSay38(int n) {
    if (n <= 0) {
        return "";
    }

    string result = "1";
    while (n > 1) {
        string curRes = "";
        for (int i = 0; i < result.size(); ++i) {
            int cnt = 1;
            while (i < result.size() - 1 && result[i] == result[i + 1]) {
                cnt++;
                i++;
            }
            curRes += to_string(cnt) + result[i];
        }
        result = curRes;
        n--;
    }

    return result;
}

// 68. Text Justification
vector<string> StringImpl::fullJustify68(vector<string>& words, int maxWidth)
{
    vector<string> result;
    int pre = 0, cur = 0;

    while (cur < words.size()) {
        int curWordLen = 0;
        while (cur < words.size() 
            && curWordLen + words[cur].size() + cur - pre <= maxWidth) {
            curWordLen += words[cur].size();
            ++cur;
        }

        int allSpace = maxWidth - curWordLen;
        string curRes = "";
        
        for (int i = pre; i < cur; ++i) {
            curRes += words[i];

            if (allSpace > 0) {
                int curSpace = 0;
                if (cur == words.size()) {
                    // Deal with last line
                    curSpace = (i != cur - 1) ? 1 : allSpace;
                } else {
                    // Other situations
                    if (i < cur - 1) {
                        curSpace = (allSpace % (cur - i - 1) == 0)
                                ? allSpace / (cur - i - 1)
                                : allSpace / (cur - i - 1) + 1;
                    } else {
                        curSpace = allSpace;
                    }
                }

                curRes.append(curSpace, ' ');
                allSpace -= curSpace;
            }
        }
        
        result.push_back(curRes);
        pre = cur;
    }

    return result;
}

// 71. Simplify Path
string StringImpl::simplifyPath71(string path) {
    vector<string> allDirectories;
    int pre = 0, cur = 1;
    
    // Parse path into allDirec
    while (cur < path.size()) {
        while (cur < path.size() && path[cur] != '/')
        {
            ++cur;
        }

        string curDirec = path.substr(pre + 1, cur - pre - 1);
        if (curDirec == "." || curDirec == "") {
            ;
        } else if (curDirec == "..") {
            if (!allDirectories.empty())
                allDirectories.pop_back();
        } else {
            allDirectories.push_back(curDirec);
        }

        pre = cur;
        cur = pre + 1;
    }

    // Construct the output string
    string result = "";

    for (int i = 0; i < allDirectories.size(); ++i) {
        result += "/" + allDirectories[i];
    }

    return result.empty() ? "/" : result;
}

// 125. Valid Palindrome
bool StringImpl::isPalindrome125(string s)
{
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        if (!isalpha(s[left]) && !isdigit(s[left])) {
            ++left;
        } else if (!isalpha(s[right]) && !isdigit(s[right])) {
            --right;
        } else {
            if (toupper(s[left]) != toupper(s[right])) {
                return false;
            } else {
                ++left; --right;
            }
        }
    }
    return true;
}