#ifndef _SESSION_0_IMPL_H
#define _SESSION_0_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Session0Impl {
public:
    Session0Impl() {
        cout << "Impl object for Leetcode Session 0 problems constructed.\n";
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

    // 2. Add Two Numbers (Reverse Order case)
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;

        ListNode * dummy = new ListNode(-1);
        ListNode * tmp = dummy;
        bool isPlusOne = false;

        while (l1 && l2) {
            int curNewVal = l1->val + l2->val + (isPlusOne ? 1 : 0);
            cout << "curVal = " << curNewVal << "\n";
            isPlusOne = curNewVal >= 10;
            tmp->next = new ListNode(curNewVal % 10);
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode * remainListNode = l1 ? l1 : (l2 ? l2: NULL);
        while (remainListNode) {
            int curNewVal = remainListNode->val + (isPlusOne ? 1 : 0);
            isPlusOne = curNewVal >= 10;
            tmp->next = new ListNode(curNewVal % 10);
            tmp = tmp->next;
            remainListNode = remainListNode->next;
        }

        if (isPlusOne) tmp->next = new ListNode(1);
        ListNode * newHead = dummy->next;
        delete dummy;
        return newHead;
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

    // 4. Median of Two Sorted Arrays
    double findMedianSortedArrays4(
        vector<int>& nums1, vector<int>& nums2
    ) {
        int m = nums1.size(), n = nums2.size();
        double left = findKthInTwoArray(nums1, 0, nums2, 0, (m + n + 1) / 2);
        double right = findKthInTwoArray(nums1, 0, nums2, 0, (m + n + 2) / 2);

        return (left + right) / 2;
    }

    double findKthInTwoArray(
        const vector<int>& nums1, int i, 
        const vector<int>& nums2, int j, int k)
    {
        if (i >= nums1.size()) {
            return static_cast<double>(nums2[j + k - 1]);
        }
        if (j >= nums2.size()) {
            return static_cast<double>(nums1[i + k - 1]);
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int midVal1 = i + k / 2 - 1 < nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = j + k / 2 - 1 < nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;

        if (midVal1 < midVal2) {
            return findKthInTwoArray(nums1, i + k / 2, nums2, j, k - k /2);
        } else {
            return findKthInTwoArray(nums1, i, nums2, j + k / 2, k - k /2);
        }
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

    // 7. Reverse Integer
    int reverse7(int x) {
        bool isPositive = (x > 0);
        long long absX = abs(static_cast<long long>(x));
        long long result = 0;

        while (absX > 0) {
            result = result * 10 + absX % 10;
            absX /= 10;
        }

        if (result > INT_MAX) {
            return 0;
        } else {
            return (isPositive ? 1 : -1) * static_cast<int>(result);
        }
    }

    // 8. String to Integer (atoi)
    int myAtoi8(string str) {
        if (str.empty()) {
            return 0;
        }

        int curIdx = 0;
        bool isPositive = true;
        while (curIdx < str.size() && str[curIdx] == ' ') {
            curIdx++;
        }
        if (curIdx < str.size() && (str[curIdx] == '+' || str[curIdx] == '-')) {
            isPositive = (str[curIdx] == '+');
            curIdx++;
        }

        long long resultAbs = 0;
        while (curIdx < str.size() && isdigit(str[curIdx])) {
            resultAbs = resultAbs * 10 + (str[curIdx] - '0');
            if (resultAbs > INT_MAX) {
                return isPositive ? INT_MAX : INT_MIN;
            }
            curIdx++;
        }

        return (isPositive ? 1 : -1) * static_cast<int>(resultAbs);
    }

    // 9. Palindrome Number
    bool isPalindrome9(int num) {
        if (num < 0) {
            return false;
        }

        int magnitude = log10(num);
        int div = pow(10, magnitude);

        while (num > 0) {
            int left = num / div;
            int right = num % 10;
            if (left != right) {
                return false;
            }

            num = (num % div) / 10;
            div /= 100;
        }

        return true;
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

    // 11. Container With Most Water
    int maxArea11(vector<int>& heights) {
        if (!heights.size()) return -1;

        int left = 0, right = heights.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            maxArea = max(maxArea, min(heights[left], heights[right]) * (right - left));
            if (heights[left] < heights[right]) ++left;
            else --right;
        }
        
        return maxArea;
    }

    // 12. Integer to Roman
    string intToRoman12(int num) {
        const vector<pair<char, int> > romanIntPairVec = {
            make_pair('M', 1000),
            make_pair('D', 500), 
            make_pair('C', 100), 
            make_pair('L', 50), 
            make_pair('X', 10), 
            make_pair('V', 5), 
            make_pair('I', 1)
        };
        string result = "";

        for (int i = 0; i < romanIntPairVec.size(); i += 2) {
            int count = num / romanIntPairVec[i].second;

            if (count == 0) {
                continue;
            } else if (count < 4) {
                for (int j = 0; j < count; ++j) {
                    result += romanIntPairVec[i].first;
                }
            } else if (count == 4) {
                result = result + romanIntPairVec[i].first + romanIntPairVec[i - 1].first;
            } if (count == 5) {
                result += romanIntPairVec[i - 1].first;
            } else if (count > 5 && count < 9) {
                result += romanIntPairVec[i - 1].first;
                for (int j = 6; j <= count; ++j) {
                    result += romanIntPairVec[i].first;
                }
            } else if (count == 9) {
                result = result + romanIntPairVec[i].first + romanIntPairVec[i - 2].first;
            }

            num %= romanIntPairVec[i].second;
        }

        return result;
    }

    // 13. Roman to Integer
    int romanToInt13(string s) {
        unordered_map<char, int> charIntMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            int curVal = charIntMap[s[i]];
            if (i == s.length() - 1 || charIntMap[s[i]] >= charIntMap[s[i + 1]]) {
                result += curVal;
            } else {
                result -= curVal;
            }
        }

        return result;
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

    // 15. 3Sum
    vector<vector<int>> threeSum15(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
            return {};
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left]) {
                        ++left;
                    }
                    while (right > left && nums[right - 1] == nums[right]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }

    // 16. 3Sum Closest
    int threeSumClosest16(vector<int>& nums, int target) {
        assert(nums.size() > 2);
        int minSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(minSum - target);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int curSum = nums[i] + nums[left] + nums[right];
                int curDiff = abs(curSum - target);
                if (curDiff < minDiff) {
                    minDiff = curDiff;
                    minSum = curSum;
                }
                if (curSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return minSum;
    }

    // 17. Letter Combinations of a Phone Number
    vector<string> letterCombinations17(string digits) {
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

    void generateLetterCombRec(
        const vector<string>& digitLetterMap, const string digits, 
        int curIdx, string curResult, vector<string> & result
    ) {
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

    // 18. 4Sum
    vector<vector<int>> fourSum18(vector<int>& nums, int target) {
        if (nums.size() <= 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> resultSet;
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int curSum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (curSum == target) {
                        resultSet.insert({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                    } else if (curSum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }

    // 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd19(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode * cur = head, * prev = head;
        for (int i = 0; i < n; ++i) {
            if (cur == NULL) {
                return NULL;
            } else {
                cur = cur->next;
            }
        }

        if (cur == NULL) {
            return head->next;
        }

        while (cur->next) {
            prev = prev->next;
            cur = cur->next;
        }

        prev->next = prev->next->next;
        return head;
    }

    // 20. Valid Parentheses
    bool isValid20(string s) {
        if (s.empty()) {
            return true;
        }

        stack <char> chStk;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                chStk.push(s[i]);
            } else {
                if (chStk.empty()) {
                    return false;
                }

                if (s[i] == ')' && chStk.top() != '(') {
                    return false;
                }
                if (s[i] == ']' && chStk.top() != '[') {
                    return false;
                }
                if (s[i] == '}' && chStk.top() != '{') {
                    return false;
                }

                chStk.pop();
            }
        }

        return chStk.empty();
    }

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists21(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            return (l2 == NULL) ? l1 : l2;
        } 

        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1) {
            cur->next = l1;
        } else if (l2) {
            cur->next = l2;
        }

        return dummy->next;
    }

    // 22. Generate Parentheses
    vector<string> generateParenthesis22(int n) {
        vector<string> result;
        if (n == 0) {
            return result;
        }

        generateParenthesisRec(n, n, "", result);
        return result;
    }

    void generateParenthesisRec(
        int left, int right, string curStr, vector<string> & result
    ) {
        if (left > right) {
            // We have insert ')' before '('
            return;
        }

        if (left == 0 && right == 0) {
            result.push_back(curStr);
            return;
        }

        if (left > 0) {
            generateParenthesisRec(left - 1, right, curStr + '(', result);
        }
        if (right > 0) {
            generateParenthesisRec(left, right - 1, curStr + ')', result);
        }
    }

    // 23. Merge k Sorted Lists
    ListNode* mergeKLists23(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        int n = lists.size();
        while (n > 1) {
            int k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists21(lists[i], lists[i + k]);
            }
            n = k;
        }

        return lists[0];
    }

    // 24. Swap Nodes in Pairs
    ListNode* swapPairs24(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;

        while (cur->next && cur->next->next) {
            ListNode* nextNext = cur->next->next;
            cur->next->next = nextNext->next;
            nextNext->next = cur->next;
            cur->next = nextNext;
            cur = nextNext->next;
        }

        return dummy->next;
    }

    // 25. Reverse Nodes in k-Group
    ListNode* reverseKGroup25(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = dummy;

        for (int i = 1; cur; ++i) {
            if (i % k == 0) {
                prev = reverseOneGroup(prev, cur->next);
                cur = prev->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }

    ListNode* reverseOneGroup(
        ListNode* prevEnd, ListNode* nextStart
    ) {
        ListNode* first = prevEnd->next;
        ListNode* cur = first->next;

        while (cur != nextStart) {
            first->next = cur->next;
            cur->next = prevEnd->next;
            prevEnd->next = cur;
            cur = first->next;
        }

        return first;
    }

    // 26. Remove Duplicates from Sorted Array
    int removeDuplicates26(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int curIdx = 0;
        for (int right = 1; right < nums.size(); ++right) {
            if (nums[right] != nums[right - 1]) {
                curIdx++;
                nums[curIdx] = nums[right];
            }
        }

        return curIdx + 1;
    }

    // 27. Remove Element
    int removeElement27(vector<int>& nums, int val) {
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[pre] = nums[i];
                pre++;
            }
        }
        
        nums.resize(pre);
        return pre;
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

    // 29. Divide Two Integers
    int divide29(int dividend, int divisor) {
        long long absDividend = abs(static_cast<long long>(dividend));
        long long absDivisor = abs(static_cast<long long>(divisor));

        if (absDivisor > absDividend) {
            return 0;
        }

        long long result = 0;

        while (absDividend >= absDivisor) {
            int p = 1;
            long long t = absDivisor;

            while (absDividend > (t << 1)) {
                p <<= 1;
                t <<= 1;
            }

            result += p;
            absDividend -= t;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        if (isNegative) {
            result = -result;
        }

        return result > INT_MAX ? INT_MAX : result;
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

    // 31. Next Permutation
    void nextPermutation31(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }

        int smallIdx = -1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                smallIdx = i;
                break;
            }
        }

        if (smallIdx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int largeIdx = -1;
        for (int j = nums.size() - 1; j >= smallIdx; --j) {
            if (nums[j] > nums[smallIdx]) {
                largeIdx = j;
                break;
            }
        }

        swap(nums[smallIdx], nums[largeIdx]);

        reverse(nums.begin() + smallIdx + 1, nums.end());
        return;
    }

    // 32. Longest Valid Parentheses
    int longestValidParentheses32(string s) {
        if (s.empty()) {
            return 0;
        }

        stack<int> idxStk;
        int curStart = -1;
        int result = 0;

        for (int i = 0;i < s.length(); ++i) {
            if (s[i] == '(') {
                idxStk.push(i);
            } else {
                if (idxStk.empty()) {
                    curStart = i;
                } else {
                    idxStk.pop();
                    if (idxStk.empty()) {
                        result = max(result, i - curStart);
                    } else {
                        result = max(result, i - idxStk.top());
                    }
                }
            }
        }

        return result;
    }

    // 33. Search in Rotated Sorted Array
    int search33(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int pivot = left + (right - left) / 2;
            if (nums[pivot] == target) {
                return pivot;
            }

            if (nums[pivot] > nums[right]) {
                if (target < nums[pivot] && target >= nums[left]) {
                    right = pivot - 1;
                } else {
                    left = pivot + 1;
                }
            } else {
                if (target > nums[pivot] && target <= nums[right]) {
                    left = pivot + 1;
                } else {
                    right = pivot - 1;
                }
            }
        }

        return -1;
    }

    // 34. Find First and Last Position of Element in Sorted Array
    vector<int> searchRange34(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.size() == 0) {
            return result;
        }

        int left = 0, right = nums.size() - 1;
        int idxFound = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                idxFound = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (idxFound == -1) {
            return result;
        }

        int lIdx = idxFound, rIdx = idxFound;
        while (lIdx >= 0 && nums[lIdx] == target) {
            --lIdx;
        }
        while (rIdx < nums.size() && nums[rIdx] == target) {
            ++rIdx;
        }

        result = {lIdx + 1, rIdx - 1};
        return result;
    }

    // 35. Search Insert Position
    int searchInsert35(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
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

    // 37. Sudoku Solver
    void solveSudoku37(vector<vector<char>>& board) {
        assert(board.size() == 9 && board[0].size() == 9);
        solveSudokuRec(board, 0, 0);
    }

    bool solveSudokuRec(
        vector<vector<char>>& board, int iRow, int iCol
    ) {
        if (iRow == 9) {
            return true;
        }
        if (iCol == 9) {
            return solveSudokuRec(board, iRow + 1, 0);
        }

        if (board[iRow][iCol] == '.') {
            for (int i = 0; i < 9; ++i) {
                board[iRow][iCol] = static_cast<char>('1' + i);
                if (isValidSudokuPerUnit(board, iRow, iCol)) {
                    if(solveSudokuRec(board, iRow, iCol + 1)) {
                        return true;
                    }
                }
            }
            board[iRow][iCol] = '.';
        } else {
            return solveSudokuRec(board, iRow, iCol + 1);
        }

        return false;
    }

    bool isValidSudokuPerUnit(
        const vector<vector<char>>& board, int iRow, int iCol
    ) {
        for (int i = 0; i < 9; ++i) {
            if (i != iRow && board[i][iCol] == board[iRow][iCol]) {
                return false;
            }
        }

        for (int j = 0; j < 9; ++j) {
            if (j != iCol && board[iRow][j] == board[iRow][iCol]) {
                return false;
            }
        }

        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                int curRow = (iRow / 3) * 3 + m;
                int curCol = (iCol / 3) * 3 + n;

                if ((curRow != iRow || curCol != iCol) 
                    && board[curRow][curCol] == board[iRow][iCol]) {
                    return false;
                }
            }
        }

        return true;
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

    // 39. Combination Sum
    vector<vector<int>> combinationSum39(
        vector<int>& candidates, 
        int target
    ) {
        vector<vector<int>> allRes;
        vector<int> curRes;
        combinationSumRec(0, candidates, curRes, allRes, target);
        return allRes;
    }

    void combinationSumRec(
        int startIdx, const vector<int> & candidate, 
        vector<int> & curRes, vector<vector<int>> & allRes, int remain
    ) {
        if (remain < 0) {
            return;
        }
        if (remain == 0) {
            allRes.push_back(curRes);
            return;
        }

        for (int i = startIdx; i < candidate.size(); ++i) {
            curRes.push_back(candidate[i]);
            combinationSumRec(i, candidate, curRes, allRes, remain - candidate[i]);
            curRes.pop_back();
        }
    }

    // 40. Combination Sum II
    vector<vector<int>> combinationSum2_40(
        vector<int>& candidates, int target
    ) {
        vector<vector<int>> allResults;
        vector<int> curResult;
        sort(candidates.begin(), candidates.end());
        combinationSum2Rec(curResult, allResults, 0, target, candidates);
        return allResults;
    }

    void combinationSum2Rec(
        vector<int> & curResult,
        vector<vector<int>> & allResults,
        int startIdx,
        int remain,
        const vector<int> & candidates
    ) {
        if (remain < 0) {
            return;
        } else if (remain == 0) {
            allResults.push_back(curResult);
        } else {
            for (int i = startIdx; i < candidates.size(); ++i) {
                if (i > startIdx && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                curResult.push_back(candidates[i]);
                combinationSum2Rec(curResult, allResults, i + 1, 
                    remain - candidates[i], candidates);
                curResult.pop_back();
            }
        }
    }

    // 41. First Missing Positive
    int firstMissingPositive41(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    // 42. Trapping Rain Water
    int trap42(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        stack<int> idxStk;
        idxStk.push(0);
        int result = 0;

        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > height[idxStk.top()]) {
                int curButtom = height[idxStk.top()];
                idxStk.pop();

                while (!idxStk.empty() && height[i] >= height[idxStk.top()]) {
                    result += (i - idxStk.top() - 1) * (height[idxStk.top()] - curButtom);
                    curButtom = height[idxStk.top()];
                    idxStk.pop();
                }

                if (!idxStk.empty()) { 
                    // Meaning we can not remove current top index since it is taller
                    result += (i - idxStk.top() - 1) * (height[i] - curButtom);
                }
            }

            idxStk.push(i);
        }

        return result;
    }

    // 43. Multiply Strings
    string multiply43(string num1, string num2) {
        int totalLen = num1.size() + num2.size();
        vector<int> resVec(totalLen, 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                int pos1 = i + j, pos2 = i + j + 1;
                int val = (num1[i] - '0') * (num2[j] - '0');
                int curSum = val + resVec[pos2];

                resVec[pos1] += curSum / 10;
                resVec[pos2] = curSum % 10;
            }
        }

        string resStr = "";
        int i = 0;
        while (i < resVec.size() && resVec[i] == 0) {
            ++i;
        }
        for (; i < resVec.size(); ++i) {
            resStr.push_back('0' + resVec[i]);
        }

        return resStr == "" ? "0" : resStr;
    }

    // 44. Wildcard Matching
    bool isMatch44(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= p.size(); ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
                }
            }
        }

        return dp[s.size()][p.size()];
    }

    // 45. Jump Game II
    int jump45(vector<int>& nums)
    {
        int cur = 0, i = 0, step = 0;
        while (cur < nums.size() - 1) {
            int pre = cur;
            while (i <= pre) {
                cur = max(cur, nums[i] + i);
                ++i;
            }
            ++step;
            if (cur == pre) {
                return -1;
            }
        }

        return step;
    }

    // 46. Permutations
    vector<vector<int>> permute46(vector<int>& nums)
    {
        vector<vector<int>> results;
        vector<int> curRes;
        vector<bool> visited(nums.size(), false);
        permute46Rec(results, curRes, visited, nums);
        return results;
    }

    void permute46Rec(
        vector<vector<int>> &results,
        vector<int> &curRes,
        vector<bool> &visited,
        const vector<int> &nums)
    {
        if (curRes.size() == nums.size()) {
            results.push_back(curRes);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            curRes.push_back(nums[i]);
            visited[i] = true;
            permute46Rec(results, curRes, visited, nums);
            curRes.pop_back();
            visited[i] = false;
        }
    }

    // 47. Permutations II
    vector<vector<int>> permuteUnique47(vector<int>& nums) {
        vector<vector<int>> allResult;
        if (nums.size() == 0) {
            return allResult;
        }
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> curResult;
        permuteUnique47DFS(nums, 0, curResult, allResult, visited);
        return allResult;
    }

    void permuteUnique47DFS(
        const vector<int> & nums,
        int level, 
        vector<int> & curResult,
        vector<vector<int>> & allResult,
        vector<bool> & visited
    ) {
        if (level >= nums.size()) {
            allResult.push_back(curResult);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            visited[i] = true;
            curResult.push_back(nums[i]);
            permuteUnique47DFS(nums, level + 1, curResult, allResult, visited);
            curResult.pop_back();
            visited[i] = false;
        }
    }

    // 48. Rotate Image
    void rotate48(vector<vector<int>>& matrix)
    {
        int edgeSize = matrix[0].size();
        for (int i = 0; i < edgeSize / 2; ++i) {
            for (int j = i; j < edgeSize - 1 - i; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[edgeSize - 1 - j][i];
                matrix[edgeSize - 1 - j][i] = matrix[edgeSize - 1 - i][edgeSize - 1 - j];
                matrix[edgeSize - 1 - i][edgeSize - 1 - j] = matrix[j][edgeSize - 1 - i];
                matrix[j][edgeSize - 1 - i] = temp;
            }
        }
        return;
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

    // 50. Pow(x, n)
    double myPow50(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = myPow50(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return (n > 0) ? half * half * x : half * half / x;
        }
    }

    // 51. N-Queens
    vector<vector<string>> solveNQueens51(int n)
    {
        vector<vector<string>> results;
        if (n == 0) {
            return results;
        }

        vector<string> curRes(n, string(n, '.'));
        solveNQueens51Rec(results, curRes, 0, n);
        return results;
    }

    void solveNQueens51Rec(
        vector<vector<string>> &results,
        vector<string> &curRes,
        int curRow,
        const int nSize
    ) {
        if (curRow  == nSize) {
            results.push_back(curRes);
        }

        for (int i = 0; i < nSize; ++i) {
            if (isCurrentBoardValid(curRes, curRow, i, nSize)) {
                curRes[curRow][i] = 'Q';
                solveNQueens51Rec(results, curRes, curRow + 1, nSize);
                curRes[curRow][i] = '.';
            }
        }
    }

    bool isCurrentBoardValid(
        const vector<string> &board,
        const int curRow,
        const int curCol,
        const int nSize
    ) {
        for (int i = 0; i < curRow; ++i) {
            if (board[i][curCol] == 'Q') {
                return false;
            }
        }

        for (int i = curRow - 1, j = curCol + 1; i >= 0 && j < nSize; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = curRow - 1, j = curCol - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    // 53. Maximum Subarray
    int maxSubArray53(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        return maxSubArrayRec(nums, 0, nums.size() - 1);
    }

    int maxSubArrayRec(const vector<int>& nums, int left, int right)
    {
        if (left >= right) return nums[left];
        int pivot = left + (right - left) / 2;
        int lmax = maxSubArrayRec(nums, left, pivot - 1);
        int rmax = maxSubArrayRec(nums, pivot + 1, right);

        int curMax = nums[pivot], temp = nums[pivot];
        for (int i = pivot - 1; i >= left; --i) {
            temp += nums[i];
            curMax = max(temp, curMax);
        }
        temp = curMax;
        for (int j = pivot + 1; j <= right; ++j) {
            temp += nums[j];
            curMax = max(temp, curMax);
        }

        return max(curMax, max(lmax, rmax));
    }

    // 54. Spiral Matrix
    vector<int> spiralOrder54(vector<vector<int>>& matrix)
    {
        vector<int> result;

        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }

        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;

        while (true) {
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[up][i]);
            }
            ++up;
            if (up > down) break;

            for (int j = up; j <= down; ++j) {
                result.push_back(matrix[j][right]);
            }
            --right;
            if (right < left) break;

            for (int m = right; m >= left; --m) {
                result.push_back(matrix[down][m]);
            }
            --down;
            if (down < up) break;

            for (int n = down; n >= up; --n) {
                result.push_back(matrix[n][left]);
            }
            ++left;
            if (left > right) break;
        }

        return result;
    }

    // 55. Jump Game
    bool canJump55(vector<int>& nums)
    {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach || maxReach >= nums.size() - 1) {
                break;
            } else {
                maxReach = max(maxReach, i + nums[i]);
            }
        }

        return (maxReach >= nums.size() - 1);
    }

    // 56. Merge Intervals
    vector<vector<int>> merge56(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            return result;
        }

        sort(intervals.begin(), intervals.end(), 
            [] (const vector<int> &a, const vector<int> &b){
                return a[0] < b[0];
            }
        );

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }

    // 57. Insert Interval
    vector<vector<int>> insert57(
        vector<vector<int>>& intervals, 
        vector<int>& newInterval
    ) {
        vector<vector<int>> results;
        int cur = 0;
        while (cur < intervals.size() && intervals[cur][1] < newInterval[0]) {
            results.push_back(intervals[cur]);
            cur++;
        }

        while (cur < intervals.size() && newInterval[1] >= intervals[cur][0]) {
            newInterval[0] = min(intervals[cur][0], newInterval[0]);
            newInterval[1] = max(intervals[cur][1], newInterval[1]);
            cur++;
        }
        results.push_back(newInterval);

        while (cur < intervals.size()) {
            results.push_back(intervals[cur]);
            cur++;
        }

        return results;
    }

    // 59. Spiral Matrix II
    vector<vector<int>> generateMatrix59(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int left = 0, right = n - 1, up = 0, down = n - 1;
        int curVal = 1;

        while (true) {
            for (int i = left; i <= right; ++i) {
                result[up][i] = curVal++;
            }
            if (++up > down) {
                break;
            }

            for (int j = up; j <= down; ++j) {
                result[j][right] = curVal++;
            }
            if (--right < left) {
                break;
            }

            for (int m = right; m >= left; --m) {
                result[down][m] = curVal++;
            }
            if (--down < up) {
                break;
            }

            for (int n = down; n >= up; --n) {
                result[n][left] = curVal++;
            }
            if (++left > right) {
                break;
            }
        }

        return result;
    }

    // 60. Permutation Sequence
    string getPermutation60(int n, int k) {
        string res;
        string nums("123456789");
        nums.substr(0, n);
        vector<int> f(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }

        --k;
        for (int i = n; i >= 1; --i) {
            int a = k / f[i - 1];
            k = k % f[i - 1];
            res.push_back(nums[a]);
            nums.erase(a, 1);
        }

        return res;
    }

    // 61. Rotate List
    ListNode* rotateRight61(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }

        int length = 0;
        ListNode * cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        k %= length;
        if (k == 0) {
            return head;
        }

        ListNode * fast = head, * slow = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode * new_head = slow->next;
        fast->next = head;
        slow->next = NULL;
        return new_head;
    }

    // 62. Unique Paths
    int uniquePaths62(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    // 63. Unique Paths II
    int uniquePathsWithObstacles63(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>> dp(
            obstacleGrid.size(), 
            vector<long long>(obstacleGrid[0].size())
        );

        if (obstacleGrid[0][0] == 1) {
            return 0;
        } else {
            dp[0][0] = 1;
        }

        for (int i = 1; i < obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i]) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int j = 1; j < obstacleGrid.size(); ++j) {
            if (obstacleGrid[j][0]) {
                dp[j][0] = 0;
            } else {
                dp[j][0] = dp[j - 1][0];
            }
        }

        for (int i = 1; i < obstacleGrid.size(); ++i) {
            for (int j = 1; j < obstacleGrid[0].size(); ++j) {
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return static_cast<int>(dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1]);
    }

    // 64. Minimum Path Sum
    int minPathSum64(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];

        // Deal with border row and column
        for (int j = 1; j < grid[0].size(); ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < grid.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Go to center elements
        for (int m = 1; m < grid.size(); ++m) {
            for (int n = 1; n < grid[0].size(); ++n) {
                dp[m][n] = min(dp[m - 1][n], dp[m][n - 1]) + grid[m][n];
            }
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }

    // 65. Valid Number
    bool isNumber65(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right && s[left] == ' ') {
            ++left;
        }

        while (right >= left && s[right] == ' ') {
            --right;
        }

        if (left == right) {
            // Only one character in string
            return isdigit(s[left]);
        }

        bool isDotExist = false;
        bool isEExist = false;
        bool isDigitExist = false;

        // Process the first non space character
        if (s[left] == '.') {
            isDotExist = true;
        } else if (isdigit(s[left])) {
            isDigitExist = true;
        } else if (s[left] != '+' && s[left] != '-') {
            return false;
        }

        // Process [left + 1, right - 1]
        for (int i = left + 1; i <= right - 1; ++i) {
            if (isdigit(s[i])) {
                isDigitExist = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (isEExist) {
                    return false;
                } else if (isDigitExist) {
                    isEExist = true;
                } else {
                    return false;
                }
            } else if (s[i] == '.') {
                if (isEExist || isDotExist) {
                    return false;
                } else {
                    isDotExist = true;
                }
            } else if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else return false;
        }

        // Process right
        if (isdigit(s[right])) {
            return true;
        } else if (s[right] == '.' && !isDotExist && !isEExist && isDigitExist) {
            return true;
        } else return false;
    }

    // 66. Plus One
    vector<int> plusOne66(vector<int>& digits)
    {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }

        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }

    // 67. Add Binary
    string addBinary67(string a, string b) {
        string result = "";
        if (a.empty() && b.empty()) {
            return result;
        }

        int nSize = max(a.size(), b.size());
        while (a.size() < nSize) {
            a.insert(a.begin(), '0');
        }
        while (b.size() < nSize) {
            b.insert(b.begin(), '0');
        }

        bool carry = false;
        for (int i = nSize - 1; i >= 0; --i) {
            if (a[i] == '1' && b[i] == '1') {
                result.insert(result.begin(), carry ? '1': '0');
                carry = true;
            } else if (a[i] == '1' || b[i] == '1') {
                result.insert(result.begin(), carry ? '0' : '1');
            } else {
                result.insert(result.begin(), carry ? '1' : '0');
                carry = false;
            }
        }

        if (carry) {
            result.insert(result.begin(), '1');
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

    // 69. Sqrt(x)
    int mySqrt69(int x) {
        if (x <= 3) {
            return 1;
        }

        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x / mid >= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right - 1;
    }

    // 70. Climbing Stairs
    int climbStairs70(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> dp(n, 0);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
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

    // 72. Edit Distance
    int minDistance72(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= word2.size(); ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }

    // 73. Set Matrix Zeroes
    void setZeroes73(vector<vector<int>>& matrix) {
        bool firstColZero = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
            }
        }
        
        bool firstRowZero = false;
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
            }
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }   
        }
        
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }   
        }
        
        if (firstColZero) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;   
            }
        }
        
        if (firstRowZero) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;   
            }
        }
    }

    // 74. Search a 2D Matrix
    bool searchMatrix74(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1;

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }

        while (up <= down) {
            int mid = (up + down) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                up = mid + 1;
            } else {
                down = mid - 1;
            }
        }

        int targetRow = down;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }

    // 75. Sort Colors
    void sortColors75(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return;
        }

        int left = 0, right = nums.size() - 1;
        int cur = 0;

        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[left]);
                ++left;
                ++cur;
            } else if (nums[cur] == 1) {
                ++cur;
            } else { // nums[cur] == 2
                swap(nums[cur], nums[right]);
                --right;
            }
        }

        return;
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

    // 77. Combinations
    vector<vector<int>> combine77(int n, int k) {
        vector<int> curRes;
        vector<vector<int>> allRes;
        combine77helper(n, k, 1, curRes, allRes);
        return allRes;
    }

    void combine77helper(
        const int n, const int k,
        int curVal, vector<int> & curRes,
        vector<vector<int>> & allRes
    ) {
        if (curRes.size() == k) {
            allRes.push_back(curRes);
            return;
        }

        for (int i = curVal; i <= n; ++i) {
            curRes.push_back(i);
            combine77helper(n, k, i + 1, curRes, allRes);
            curRes.pop_back();
        }
    }

    // 78. Subsets
    vector<vector<int>> subsets78(vector<int>& nums) {
        vector<vector<int>> allResult;
        vector<int> curResult;
        subsets78Rec(curResult, allResult, 0, nums);
        return allResult;
    }

    void subsets78Rec(
        vector<int> & curRes,
        vector<vector<int>> & allRes,
        const int curPos,
        const vector<int> & nums
    ) {
        allRes.push_back(curRes);
        for (int i = curPos; i < nums.size(); ++i) {
            curRes.push_back(nums[i]);
            subsets78Rec(curRes, allRes, i + 1, nums);
            curRes.pop_back();
        }
    }

    // 79. Word Search
    bool exist79(vector<vector<char>>& board, string word)
    {
        // Corner pressure test case: Recursion should be avoided
        // Iteration solution should be used in order to pass these cases 
        // if (word.size() > 100) {
        //     return true;
        // }
            
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (exist79Rec(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool exist79Rec(
        vector<vector<char>>& board,
        const string word,
        const int curWordPos,
        const int curX,
        const int curY
    ) {
        if (curWordPos == word.size()) {
            return true;
        }

        if (curX < 0 || curX >= board.size() 
            || curY < 0 || curY >= board[0].size()
            || board[curX][curY] == '#'
            || board[curX][curY] != word[curWordPos]) {
            return false;
        }
        
        char curBoardChar = board[curX][curY];
        board[curX][curY] = '#';
        bool down = exist79Rec(board, word, curWordPos + 1, curX + 1, curY);
        bool up = exist79Rec(board, word, curWordPos + 1, curX - 1, curY);
        bool right = exist79Rec(board, word, curWordPos + 1, curX, curY + 1);
        bool left = exist79Rec(board, word, curWordPos + 1, curX, curY - 1);
        board[curX][curY] = curBoardChar;

        return (down || up || right || left);
    } 

    // 81. Search in Rotated Sorted Array II
    bool search81(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) {
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right--;
            }
        }
        return false;
    }

    // 82. Remove Duplicates from Sorted List II
    ListNode* deleteDuplicates82(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode * dummy = new ListNode(-1);
        ListNode * prev = dummy;
        ListNode * cur = head;
        
        while (cur) {
            ListNode * next = cur;
            int count = 1;

            while (next->next && next->next->val == next->val) {
                count++;
                next = next->next;
            }

            if (count == 1) {
                prev->next = cur;
                prev = prev->next;
            }

            cur = next->next;
        }

        prev->next = NULL;
        return dummy->next;
    }

    // 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates83(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode *pre = head, *cur = head->next;
        while (cur != NULL) {
            if (cur->val == pre->val) {
                pre->next = cur->next;
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }

        return head;
    }

    // 84. Largest Rectangle in Histogram
    int largestRectangleArea84(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        stack<int> idxStack;
        heights.push_back(0);
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!idxStack.empty() && heights[i] < heights[idxStack.top()]) {
                int curIdx = idxStack.top(); idxStack.pop();
                int curRes = (idxStack.empty() ? i : (i - idxStack.top() - 1)) * heights[curIdx];
                result = max(result, curRes);
            }
            idxStack.push(i);
        }
        return result;
    }

    // 85. Maximal Rectangle
    int maximalRectangle85(vector<vector<char>>& matrix) {
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> heights(matrix[i].size(), 0);
            for (int j = 0; j < matrix[i].size(); ++j) {
                int curHeight = 0, curX = i;
                while (curX < matrix.size() && matrix[curX][j] == '1') {
                    ++curHeight;
                    ++curX;
                }
                heights[j] = curHeight;
            }

            int curRowResult = largestRectangleArea84(heights);
            result = max(curRowResult, result);
        }

        return result;
    }

    // 86. Partition List
    ListNode* partition86(ListNode* head, int x) {
        if (head == NULL) {
            return head;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;

        while (slow->next && slow->next->val < x) {
            slow = slow->next;
        }
        fast = slow;

        while (fast->next != NULL) {
            if (fast->next->val < x) {
                ListNode *tmp = fast->next;
                fast->next = fast->next->next;
                tmp->next = slow->next;
                slow->next = tmp;
                slow = slow->next;
            } else {
                fast = fast->next;
            }
        }

        return dummy->next;
    }

    // 88. Merge Sorted Array
    void merge88(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int mergeIdx = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[mergeIdx] = nums1[i];
                i--;
            } else {
                nums1[mergeIdx] = nums2[j];
                j--;
            }

            mergeIdx--;
        }

        while (j >= 0) {
            nums1[mergeIdx] = nums2[j];
            j--;
            mergeIdx--;
        }

        return;
    }

    // 90. Subsets II
    vector<vector<int>> subsetsWithDup90(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        vector<int> curResult;
        subsetsWithDup_rec(0, nums, curResult, result);
        return result;
    }
    
    void subsetsWithDup_rec(int idx, const vector<int>& nums,
        vector<int>& curRes, vector<vector<int>>& allRes) {
        allRes.push_back(curRes);
        for (int i = idx; i < nums.size(); ++i) {
            curRes.push_back(nums[i]);
            subsetsWithDup_rec(i + 1, nums, curRes, allRes);
            curRes.pop_back();
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }

    // 91. Decode Ways
    int numDecodings91(string s) {
        if (s[0] == '0') {
            return 0;
        } else if (s.size() == 1) {
            return 1;
        }
        
        vector<long long> dp(s.size() + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= s.size(); ++i) {
            int numOneStepBack = (s[i - 1] == '0') ? 0 : dp[i - 1];
            int numTwoStepBack = (
                i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
                ) ? dp[i - 2] : 0;
            dp[i] = numOneStepBack + numTwoStepBack;
        }
        return static_cast<int>(dp[s.size()]);
    }

    // 92. Reverse Linked List II
    ListNode* reverseBetween92(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;

        for (int i = 1; i < m; ++i) {
            pre = pre->next;
        }

        ListNode *cur = pre->next;
        for (int i = m; i < n; ++i) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }

        return dummy->next;
    }

    // 93. Restore IP Addresses
    vector<string> restoreIpAddresses93(string s)
    {
        vector<string> results;
        if (s.size() < 4) {
            return results;
        }

        vector<string> curRes;
        restoreIpAddresses93Rec(results, curRes, 0, s);
        return results;
    }

    void restoreIpAddresses93Rec(
        vector<string> & allResults,
        vector<string> & curResult,
        const int curPos,
        const string & ipStr
    ) {
        if (curResult.size() == 4) {
            if (curPos == ipStr.size()) {
                string curResStr = "";
                for (int i = 0; i < curResult.size(); ++i) {
                    curResStr += curResult[i] + (i == 3 ? "" : ".");
                }
                allResults.push_back(curResStr);
            }
            return;
        }

        for (int i = curPos; i < curPos + 4 && i < ipStr.size(); ++i) {
            string curNumStr = ipStr.substr(curPos, i - curPos + 1);
            if (isValidIpNumStr(curNumStr)) {
                curResult.push_back(curNumStr);
                restoreIpAddresses93Rec(allResults, curResult, i + 1, ipStr);
                curResult.pop_back();
            }
        }
    }

    bool isValidIpNumStr(string & ipNumStr)
    {
        if (ipNumStr.empty() || ipNumStr.size() > 3) {
            return false;
        }
        if (ipNumStr[0] == '0' && ipNumStr.size() > 1) {
            return false;
        }
        if (stoi(ipNumStr) > 255) {
            return false;
        }
        return true;
    }

    // 94. Binary Tree Inorder Traversal
    vector<int> inorderTraversal94(TreeNode* root) {
        vector<int> results;
        if (root == NULL) {
            return results;
        }
        inorderTraversal94DFS(root, results);
        return results;
    }

    void inorderTraversal94DFS(
        TreeNode *curNode, vector<int> & result
    ) {
        if (curNode->left) {
            inorderTraversal94DFS(curNode->left, result);
        }
        result.push_back(curNode->val);
        if (curNode->right) {
            inorderTraversal94DFS(curNode->right, result);
        }
    }

    // 95. Unique Binary Search Trees II 
    // (Unique Binary Search Trees is a Dynamic Programming problem)
    vector<TreeNode *> generateTrees95(int n) {
        vector<TreeNode *> result;
        if (n == 0) {
            return result;
        }
        return generateTrees95Rec(1, n);
    }

    vector<TreeNode *> generateTrees95Rec(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> left = generateTrees95Rec(start, i - 1);
            vector<TreeNode *> right = generateTrees95Rec(i + 1, end);

            for (int m = 0; m < left.size(); ++m) {
                for (int n = 0; n < right.size(); ++n) {
                    TreeNode * cur = new TreeNode(i);
                    cur->left = left[m];
                    cur->right = right[n];
                    result.push_back(cur);
                }
            }
        }
        
        return result;
    }

    // 96. Unique Binary Search Trees
    int numTrees96(int n) {
        if (n < 2) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp.back();
    }

    // 97. Interleaving String
    bool isInterleave97(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        int mSize = s1.size(), nSize = s2.size();
        vector<vector<bool>> dp(mSize + 1, vector<bool>(nSize + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= mSize && s1[i - 1] == s3[i - 1]; ++i) {
            dp[i][0] = true;
        }

        for (int j = 1; j <= nSize && s2[j - 1] == s3[j - 1]; ++j) {
            dp[0][j] = true;
        }

        for (int i = 1; i <= mSize; ++i) {
            for (int j = 1; j <= nSize; ++j) {
                if (dp[i - 1][j]) {
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1]);
                } else if (dp[i][j - 1]) {
                    dp[i][j] = (s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[mSize][nSize];
    }

    // 98. Validate Binary Search Tree
    bool isValidBST98(TreeNode* root)
    {
        if (root == NULL) {
            return true;
        }

        return isValidBST98PreOrder(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST98PreOrder(
        TreeNode *cur, long minVal, long maxVal
    ) {
        if (cur == NULL) {
            return true;
        }

        if (cur->val < minVal || cur->val > maxVal) {
            return false;
        }

        return isValidBST98PreOrder(cur->left, minVal, cur->val)
            && isValidBST98PreOrder(cur->right, cur->val, maxVal);
    }

    // 99. Validate Binary Search Tree
    void recoverTree99(TreeNode* root)
    {
        if (root == NULL) {
            return;
        }

        vector<TreeNode *> allNodes;
        vector<int> allValues;
        recoverTree99InOrder(root, allNodes, allValues);

        sort(allValues.begin(), allValues.end());
        for (int i = 0; i < allValues.size(); ++i) {
            allNodes[i]->val = allValues[i];
        }
        return;
    }

    void recoverTree99InOrder(
        TreeNode * cur, 
        vector<TreeNode *> & allNodes, 
        vector<int> & allValues
    ) {
        if (cur == NULL) {
            return;
        }

        if (cur->left) {
            recoverTree99InOrder(cur->left, allNodes, allValues);
        }

        allNodes.push_back(cur);
        allValues.push_back(cur->val);

        if (cur->right) {
            recoverTree99InOrder(cur->right, allNodes, allValues);
        } 
    }
};

#endif