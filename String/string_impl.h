#ifndef _STRING_IMPL_H
#define _STRING_IMPL_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class StringImpl {
public:
    StringImpl() {
        cout << "Impl object for Leetcode String problems constructed.\n";
    }

    //  3. Longest Substring Without Repeating Characters
    int lengthOfLongestSubstring3(string s) {
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
    string longestPalindrome5(string s) {
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

    void findLongestPalindromeRec(
        const string str, 
        int left, 
        int right, 
        string & result
    ) {
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
    string convert6(string s, int numRows) {
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
    bool isMatch10(string s, string p) {
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
    string longestCommonPrefix14(vector<string>& strs) {
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
    int strStr28(string haystack, string needle) {
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
    string countAndSay38(int n) {
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
    vector<string> fullJustify68(vector<string>& words, int maxWidth) {
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
    string simplifyPath71(string path) {
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
    bool isPalindrome125(string s) {
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

    // 151. Reverse Words in a String
    string reverseWords151(string s) {
        if (s.empty()) {
            return "";
        }

        reverse(s.begin(), s.end());
        int curLastIndex = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (curLastIndex != 0) {
                    s[curLastIndex] = ' ';
                    curLastIndex++;
                }
                int curWordIdx = i;
                while (curWordIdx < s.size() && s[curWordIdx] != ' ') {
                    s[curLastIndex] = s[curWordIdx];
                    ++curLastIndex; ++curWordIdx;
                }

                reverse(
                    s.begin() + curLastIndex - (curWordIdx - i), 
                    s.begin() + curLastIndex
                );
                i = curWordIdx;
            }
        }

        return s.substr(0, curLastIndex);
    }

    // The following read4 implementation is used by Problem 157 and Problem 58
    string d_fileStr = "";
    int d_curPos = 0;

    void setFileStr(string str) {
        d_fileStr = str;
        d_curPos = 0;
    }

    int read4(char *buf) {
        if (d_curPos >= d_fileStr.size()) {
            return 0;
        }
        
        string toReturn = (d_curPos + 4 >= d_fileStr.size()) 
            ? d_fileStr.substr(d_curPos)
            : d_fileStr.substr(d_curPos, 4);
    
        for (int i = 0; i < toReturn.size(); ++i) {
            (*(buf + i)) = toReturn.at(i);
        }
        d_curPos += toReturn.size();
        return toReturn.size();
    }
    
    // 157. Read N Characters Given Read4
    int read157(char *buf, int n) {
        int nCharCt = 0;
        for (int i = 0; i <= n / 4; ++i) {
            int curReadSize = read4(buf + nCharCt);
            if (curReadSize == 0) {
                break;
            }
            nCharCt += curReadSize;
        }

        return min(nCharCt, n);
    }

    // 158. Read N Characters Given Read4 II - Call multiple times
    queue<char> d_bufferQ;
    bool isEndOfFile = false;
    int read158(char *buf, int n) {
        while (d_bufferQ.size() <= n && !isEndOfFile) {
            char * temp = new char[4];
            int curReadCt = read4(temp);
            if (curReadCt < 4) {
                isEndOfFile = true;
            }

            for (int i = 0; i < curReadCt; ++i) {
                d_bufferQ.push(temp[i]);
            }
        }

        int outLen = n < d_bufferQ.size() ? n : d_bufferQ.size();
        for (int i = 0; i < outLen; ++i) {
            buf[i] = d_bufferQ.front();
            d_bufferQ.pop();
        }
        return outLen;
    }

    // 161. One Edit Distance
    bool isOneEditDistance161(string s, string t) {
        if (s.length() < t.length()) {
            swap(s, t);
        }

        if (s.length() - t.length() >= 2) {
            return false;
        } else if (s.length() - t.length() == 1) {
            for (int i = 0; i < t.length(); ++i) {
                if (s[i] != t[i]) {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
            return true;
        } else {
            int ct = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != t[i]) {
                    ++ct;
                }
            }

            return ct == 1;
        }
    }

    // 165. Compare Version Numbers
    int compareVersion165(string version1, string version2) {
        int idx1 = 0, idx2 = 0, n1 = version1.size(), n2 = version2.size();
        while (idx1 < n1 || idx2 < n2) {
            string v1Str = "0", v2Str = "0"; 
                // Compiler throws when stoi is called with an empty string
            while (idx1 < n1 && version1[idx1] != '.') {
                v1Str.push_back(version1[idx1]);
                idx1++;
            }
            int cur_ver_1 = stoi(v1Str);

            while (idx2 < n2 && version2[idx2] != '.') {
                v2Str.push_back(version2[idx2]);
                idx2++;
            }
            int cur_ver_2 = stoi(v2Str);

            if (cur_ver_1 > cur_ver_2) {
                return 1;
            } else if (cur_ver_1 < cur_ver_2) {
                return -1;
            }

            ++idx1;
            ++idx2;
        }
        return 0;
    }

    // 179. Largest Number
    string largestNumber179(vector<int>& nums) {
        string result;
        struct numStrComparator {
            bool operator() (int a, int b) {
                return to_string(a) + to_string(b) > to_string(b) + to_string(a);
            }
        } myNumStrComp;
        sort(nums.begin(), nums.end(), myNumStrComp);
        for (int i = 0; i < nums.size(); ++i) {
            result += to_string(nums[i]);
        }
        return result[0] == '0' ? "0" : result;
    }
};

#endif