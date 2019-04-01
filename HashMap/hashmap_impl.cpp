#include "hashmap_impl.h"

HashMapImpl::HashMapImpl() {
    cout << "Impl object for Leetcode HashMap problems constructed.\n";
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