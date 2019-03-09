#include "string_impl.h"

#include <unordered_set>
using namespace std;

StringImpl::StringImpl() {
    cout << "Impl object for Leetcode String problems constructed.\n";
}

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