#include "hashmap_impl.h"

HashMapImpl::HashMapImpl() {
    cout << "Impl object for Leetcode HashMap problems constructed.\n";
}

// 1. Two Sum
vector<int> HashMapImpl::twoSum1(vector<int>& nums, int target)
{
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
vector<int> HashMapImpl::findSubstring30(string s, vector<string>& words) {
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
bool HashMapImpl::isValidSudoku36(vector<vector<char>>& board) {
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
vector<vector<string>> HashMapImpl::groupAnagrams49(
    vector<string>& strs) {
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
string HashMapImpl::minWindow76(string s, string t)
{
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