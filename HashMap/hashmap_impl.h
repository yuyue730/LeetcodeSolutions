#ifndef _HASHMAP_IMPL_H
#define _HASHMAP_IMPL_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
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

    // 202. Happy Number
    bool isHappy202(int n) {
        unordered_set<int> visited_number;
        while (n != 1) {
            int next = 0;
            while (n > 0) {
                next += (n % 10) * (n % 10);
                n /= 10;
            }

            n = next;
            if (visited_number.count(n)) {
                break;
            }

            visited_number.insert(n);
        }

        return n == 1;
    }

    // 205. Isomorphic Strings
    bool isIsomorphic205(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> char_idx_map1;
        unordered_map<char, int> char_idx_map2;
        for (int i = 0; i < s.length(); ++i) {
            if (!char_idx_map1.count(s[i]) && !char_idx_map2.count(t[i])) {
                char_idx_map1[s[i]] = i;
                char_idx_map2[t[i]] = i;
            } else if (char_idx_map1.count(s[i]) && char_idx_map2.count(t[i])) {
                if (char_idx_map1[s[i]] != char_idx_map2[t[i]]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    // 242. Valid Anagram
    bool isAnagram242(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> charFreqMap;
        for (int i = 0; i < s.size(); ++i) {
            charFreqMap[s[i]]++;
        }

        for (int i = 0; i < t.size(); ++i) {
            charFreqMap[t[i]]--;
            if (charFreqMap[t[i]] < 0) {
                return false;
            }
        }
        return true;
    }

    // 316. Remove Duplicate Letters
    string removeDuplicateLetters316(string s) {
        unordered_map<char, int> freq_map;
        unordered_map<char, bool> visited_map;
        string result = "0";

        for (auto ch : s) {
            freq_map[ch]++;
        }

        for (auto ch : s) {
            freq_map[ch]--;

            if (visited_map[ch]) {
                continue;
            }

            while (freq_map[result.back()] && ch < result.back()) {
                visited_map[result.back()] = false;
                result.pop_back();
            }

            result += ch;
            visited_map[ch] = true;
        }

        return result.substr(1);
    }

    // 336. Palindrome Pairs
    vector<vector<int>> palindromePairs336(vector<string>& words) {
        unordered_map<string, int> word_idx_map;
        set<int> len_set;

        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i) {
            word_idx_map[words[i]] = i;
            len_set.insert(words[i].size());
        }

        for (int i = 0; i < words.size(); ++i) {
            string cur_word_reverse = words[i];
            const int word_len = words[i].size();
            reverse(cur_word_reverse.begin(), cur_word_reverse.end());

            if (word_idx_map.count(cur_word_reverse) 
                && word_idx_map[cur_word_reverse] != i) {
                result.push_back({i, word_idx_map[cur_word_reverse]});
            }

            for (auto iter = len_set.begin(); *iter != word_len; ++iter) {
                int cur_len = *iter;
                if (word_idx_map.count(cur_word_reverse.substr(0, cur_len)) 
                    && is_palin(cur_word_reverse, cur_len, word_len - 1)) {
                    result.push_back({word_idx_map[cur_word_reverse.substr(0, cur_len)], i});
                }

                if (word_idx_map.count(cur_word_reverse.substr(word_len - cur_len)) 
                    && is_palin(cur_word_reverse, 0, word_len - cur_len - 1)) {
                    result.push_back({i, word_idx_map[cur_word_reverse.substr(word_len - cur_len)]});
                }
            }
        }

        return result;
    }

    bool is_palin(const string word, int left, int right) {
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }

    // 340. Longest Substring with At Most K Distinct Characters
    int lengthOfLongestSubstringKDistinct340(string s, int k) {
        int result = 0;
        unordered_map<char, int> charFreqMap;
        int left = 0;

        for (int i = 0; i < s.length(); ++i) {
            charFreqMap[s[i]]++;
            while (charFreqMap.size() > k) {
                charFreqMap[s[left]]--;
                if (charFreqMap[s[left]] == 0) {
                    charFreqMap.erase(s[left]);
                }
                ++left;
            }
            result = max(result, i - left + 1);
        }

        return result;
    }

    // 347. Top K Frequent Elements
    vector<int> topKFrequent347(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> num_freq_map;
        for (int i = 0; i < nums.size(); ++i) {
            num_freq_map[nums[i]]++;
        }
        
        map<int, vector<int>> freq_num_map;
        for (auto &iter : num_freq_map) {
            freq_num_map[iter.second].push_back(iter.first);
        }
        
        for (auto rit = freq_num_map.rbegin(); rit != freq_num_map.rend(); ++rit) {
            for (int i = 0; i < rit->second.size() && k > 0; ++i) {
                result.push_back(rit->second[i]);
                k--;
            }
            
            if (k == 0) {
                return result;
            }
        }
        
        return result;
    }
};

#endif