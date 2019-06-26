#ifndef _HASHMAP_IMPL_H
#define _HASHMAP_IMPL_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;

class HashMapImpl {
public:
    HashMapImpl() {
        cout << "Impl object for Leetcode HashMap problems constructed.\n";
    }

    // 1. Two Sum
    vector<int> twoSum1(vector<int>& nums, int target) {
        unordered_map<int, int> valuePairMap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            if (valuePairMap.find(nums[i]) != valuePairMap.end()) {
                result.push_back(valuePairMap[nums[i]]);
                result.push_back(i);
            } else {
                valuePairMap[target - nums[i]] = i;
            }
        }

        return result;
    }

    // 30. Substring with Concatenation of All Words
    vector<int> findSubstring30(string s, vector<string>& words) {
        vector<int> result;

        // Hacky way to get over stress test
        // if (words.size() == 5001) {    
        //     return result;
        // }

        if (s.empty() || words.empty()) {
            return result;
        }

        unordered_map<string, int> wordFreqMap;
        for (int i = 0; i < words.size(); ++i) {
            wordFreqMap[words[i]]++;
        }

        int vecSize = words.size();
        int wordLen = words[0].length();

        for (int i = 0; i < s.length(); ++i) {
            unordered_map<string, int> curWordMap;
            int j = 0;
            for (; j < vecSize; ++j) {
                string curWord = s.substr(i + j * wordLen, wordLen);
                if (wordFreqMap.find(curWord) == wordFreqMap.end()) {
                    break;
                }
                curWordMap[curWord]++;
                if (curWordMap[curWord] > wordFreqMap[curWord]) {
                    break;
                }
            }

            if (j == vecSize) {
                result.push_back(i);
            }
        }

        return result;
    }

    // 36. Valid Sudoku
    bool isValidSudoku36(vector<vector<char>>& board) {
        const int EDGE_SIZE = 9, SQUARE_SIZE = 3;
        assert(board.size() == EDGE_SIZE && board[0].size() == EDGE_SIZE);

        vector<vector<bool>> rowBooleanHash(EDGE_SIZE, vector<bool>(EDGE_SIZE, false));
        vector<vector<bool>> colBooleanHash(EDGE_SIZE, vector<bool>(EDGE_SIZE, false));
        vector<vector<bool>> sqrBooleanHash(EDGE_SIZE, vector<bool>(EDGE_SIZE, false));

        for (int iRow = 0; iRow < EDGE_SIZE; ++iRow) {
            for (int iCol = 0; iCol < EDGE_SIZE; ++iCol) {
                if (board[iRow][iCol] == '.') {
                    continue;
                }
                int sqrIdx = SQUARE_SIZE * (iRow / SQUARE_SIZE) + iCol / SQUARE_SIZE;
                int curNum = board[iRow][iCol] - '1';

                if (rowBooleanHash[iRow][curNum] || colBooleanHash[iCol][curNum] || sqrBooleanHash[sqrIdx][curNum]) {
                    return false;
                }

                rowBooleanHash[iRow][curNum] = true;
                colBooleanHash[iCol][curNum] = true;
                sqrBooleanHash[sqrIdx][curNum] = true;
            }
        }

        return true;
    }

    // 49. Group Anagrams
    vector<vector<string>> groupAnagrams49(vector<string>& strs) {
        unordered_map<string, vector<string>> strVecMap;
        for (int i = 0; i < strs.size(); ++i) {
            string p = strs[i];
            sort(p.begin(), p.end());
            strVecMap[p].push_back(strs[i]);
        }

        typedef unordered_map<string, vector<string>>::iterator Iter;
        vector<vector<string>> result;
        for (Iter it = strVecMap.begin(); it != strVecMap.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }

    // 76. Minimum Window Substring
    string minWindow76(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> charFreqMap;
        for (char c : t) {
            charFreqMap[c]++;
        }

        int cnt = t.size(), left = 0;
        string result = "";
        int minWindowSize = INT_MAX;
        for (int right = 0; right < s.size(); ++right) {
            if (charFreqMap.find(s[right]) != charFreqMap.end()) {
                charFreqMap[s[right]]--;
                if (charFreqMap[s[right]] >= 0) {
                    cnt--;
                }
            }

            while (cnt == 0) {
                string curResult = s.substr(left, right - left + 1);
                if (curResult.size() < minWindowSize) {
                    result = curResult;
                    minWindowSize = curResult.size();
                }

                if (charFreqMap.find(s[left]) != charFreqMap.end()) {
                    charFreqMap[s[left]]++;
                    if (charFreqMap[s[left]] > 0) {
                        cnt++;
                    }
                }
                left++;
            }
        }

        return result;
    }

    // 128. Longest Consecutive Sequence
    int longestConsecutive128(vector<int>& nums) {
        unordered_map<int, int> numLengthMap;
        int result = 0;
        for (int num : nums) {
            if (numLengthMap.count(num)) {
                continue;
            }
            int left = numLengthMap.count(num - 1) ? numLengthMap[num - 1] : 0;
            int right = numLengthMap.count(num + 1) ? numLengthMap[num + 1] : 0;
            int curLength = left + right + 1;
            numLengthMap[num - left] = curLength;
            numLengthMap[num + right] = curLength;
            result = max(result, curLength);
        }
        return result;
    }

    // 149. Max Points on a Line
    int maxPoints149(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        int result = 0;

        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> vecCtMap;
            int duplicate = 1;

            for (int j = i + 1; j < points.size(); ++j) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    duplicate++;
                } else {
                    int deltaX = points[j][0] - points[i][0];
                    int deltaY = points[j][1] - points[i][1];
                    int deltaGCD = greatestCommonFactor(deltaX, deltaY);

                    vecCtMap[make_pair(deltaX / deltaGCD, deltaY / deltaGCD)]++;
                }
            }

            result = max(result, duplicate);
            for (map<pair<int, int>, int>::iterator iter = vecCtMap.begin();
                iter != vecCtMap.end(); ++iter) {
                result = max(result, duplicate + iter->second);
            }
        }

        return result;
    }

    int greatestCommonFactor(int a, int b) {
        return b == 0 ? a : greatestCommonFactor(b, a % b);
    }

    // 159. Longest Substring with At Most Two Distinct Characters
    int lengthOfLongestSubstringTwoDistinct159(string s) {
        unordered_map<char, int> charFreqMap;
        int result = 0, left = 0;

        for (int i = 0; i < s.size(); ++i) {
            ++charFreqMap[s[i]];
            while (charFreqMap.size() > 2) {
                --charFreqMap[s[left]];
                if (charFreqMap[s[left]] == 0) {
                    charFreqMap.erase(s[left]);
                }
                ++left;
            }

            result = max(result, i - left + 1);
        }

        return result;
    }

    // 187. Repeated DNA Sequences
    vector<string> findRepeatedDnaSequences187(string s) {
        if (s.size() < 10) {
            vector<string> result;
            return result;
        }

        unordered_set<string> elementSet;
        unordered_set<string> resultSet;

        for (int i = 0; i <= s.size() - 10; ++i) {
            string curStr = s.substr(i, 10);
            if (elementSet.count(curStr)) {
                resultSet.insert(curStr);
            } else {
                elementSet.insert(curStr);
            }
        }
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};

#endif