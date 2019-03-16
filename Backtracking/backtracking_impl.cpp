#include "backtracking_impl.h"

BacktrackingImpl::BacktrackingImpl() {
    cout << "Impl object for Leetcode Backtracking problems constructed.\n";
}

// 17. Letter Combinations of a Phone Number
vector<string> BacktrackingImpl::letterCombinations17(string digits) {
    if (digits.empty()) {
        return {};
    }
    const vector<string> digitLetterMap = {
        "", 
        "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> result = {};
    generateLetterCombRec(digitLetterMap, digits, 0, "", result);

    return result;
}

void BacktrackingImpl::generateLetterCombRec(
            const vector<string>& digitLetterMap, const string digits, 
            int curIdx, string curResult, vector<string> & result) {
    if (curIdx == digits.length()) {
        result.push_back(curResult);
        return;
    }

    string curDigitLetters = digitLetterMap[digits[curIdx] - '0'];
    for (int i = 0; i < curDigitLetters.length(); ++i) {
        string next = curResult + curDigitLetters[i];
        generateLetterCombRec(digitLetterMap, digits, curIdx + 1, next, result);
    }
}