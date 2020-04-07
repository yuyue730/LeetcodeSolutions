#ifndef _SESSION_6_IMPL_H
#define _SESSION_6_IMPL_H

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Session6Impl {
public:
    Session6Impl() {
        cout << "Impl object for Leetcode Session 6 problems constructed.\n";
    }

    // 604. Design Compressed String Iterator
    class StringIterator604 {
    public:
        StringIterator604(string compressedString) {
            istringstream iss(compressedString);
            char curChar = ' ';
            int curFreq = 0;
            while (iss >> curChar >> curFreq) {
                charFreqQ.push({curChar, curFreq});
            }
        }
        
        char next() {
            if (!hasNext()) {
                return ' ';
            }

            int curChar = charFreqQ.front().first;
            charFreqQ.front().second--;
            if (charFreqQ.front().second == 0) {
                charFreqQ.pop();
            }
            return curChar;
        }
        
        bool hasNext() {
            return !charFreqQ.empty();
        }
    
    private:
        queue<pair<char, int>> charFreqQ;
    };

    // 605. Can Place Flowers
    bool canPlaceFlowers605(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) {
            return 0;
        }
        if (flowerbed[0] == 0) {
            flowerbed.insert(flowerbed.begin(), 0);
        }
        if (flowerbed.back() == 0) {
            flowerbed.push_back(0);
        }

        int count = 0, result = 0;
        for (int i = 0; i <= flowerbed.size(); ++i) {
            if (i < flowerbed.size() && flowerbed[i] == 0) {
                count++;
            }
            else {
                result += (count - 1) / 2;
                count = 0;
            }
        }
        return (result >= n);
    }

    // 611. Valid Triangle Number
    int triangleNumber611(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        int result = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int left = j + 1, right = n;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (nums[i] + nums[j] > nums[mid]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid;
                    }
                }
                result += right - j - 1;
            }
        }

        return result;
    }

    // 616. Add Bold Tag in String
    string addBoldTag616(string s, vector<string>& dict) {
        const int strLen = s.size();
        vector<bool> isBold(strLen, false);

        for (int i = 0; i < strLen; ++i) {
            for (auto word: dict) {
                const int wordLen = word.size();
                if (i + wordLen <= strLen && s.substr(i, wordLen) == word) {
                    for (int j = i; j < i + wordLen; ++j) {
                        isBold[j] = true;
                    }
                }
            }
        }

        string result = "";
        bool isInBold = false;
        for (int i = 0; i < strLen; ++i) {
            if ((i == 0 && isBold[0]) 
                || (i > 0 && !isBold[i - 1] && isBold[i])) {
                result += "<b>";
            }
            result += s[i];
            if ((i == strLen - 1 && isBold[i]) 
                || (i < strLen && isBold[i] && !isBold[i + 1])) {
                result += "</b>";
            }
        }
        return result;
    }

    // 617. Merge Two Binary Trees
    TreeNode* mergeTrees617(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return NULL;
        }
        TreeNode* cur = new TreeNode(
            (t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        cur->left = mergeTrees617(
            (t1 ? t1->left : NULL), (t2 ? t2->left : NULL));
        cur->right = mergeTrees617(
            (t1 ? t1->right : NULL), (t2 ? t2->right : NULL));
        return cur;
    }

    // 621. Task Scheduler
    int leastInterval621(vector<char>& tasks, int n) {
        vector<int> taskFreqMap(26, 0);
        int maxFreq = 0, maxCnt = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            taskFreqMap[tasks[i] - 'A']++;
            if (taskFreqMap[tasks[i] - 'A'] == maxFreq) {
                maxCnt++;
            }
            else if (taskFreqMap[tasks[i] - 'A'] > maxFreq) {
                maxFreq = taskFreqMap[tasks[i] - 'A'];
                maxCnt = 1;
            }
        }

        int proposedEmpty = (n - (maxCnt - 1)) * (maxFreq - 1);
        int remainingTasks = tasks.size() - maxFreq * maxCnt;
        int idlePosition = max(0, proposedEmpty - remainingTasks);
        return tasks.size() + idlePosition;
    }
};

#endif