#ifndef _SESSION_6_IMPL_H
#define _SESSION_6_IMPL_H

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <math.h>
#include <unordered_set>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for TrieNode
struct TrieNode {
    bool isEnd;
    TrieNode * children[26];

    TrieNode() : isEnd(false) {
        for (auto & each : children) {
            each = NULL;
        }
    }
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

    // 622. Design Circular Queue
    class MyCircularQueue622 {
    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        MyCircularQueue622(int k) : d_size(k) {}
        
        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value) {
            if (isFull()) {
                return false;
            }
            data.push_back(value);
            return true;
        }
        
        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            data.erase(data.begin());
            return true;
        }
        
        /** Get the front item from the queue. */
        int Front() {
            if (isEmpty()) {
                return -1;
            }
            return data.front();
        }
        
        /** Get the last item from the queue. */
        int Rear() {
            if (isEmpty()) {
                return -1;
            }
            return data.back();
        }
        
        /** Checks whether the circular queue is empty or not. */
        bool isEmpty() {
            return data.empty();
        }
        
        /** Checks whether the circular queue is full or not. */
        bool isFull() {
            return data.size() >= d_size;
        }
        
    private:
        int d_size;
        vector<int> data;
    };

    // 623. Add One Row to Tree
    TreeNode* addOneRow623(TreeNode* root, int v, int d) {
        if (!root) {
            return NULL;
        }
        if (d == 1) {
            TreeNode * newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        else {
            queue<TreeNode *> q({root});
            while (!q.empty()) {
                --d;
                if (d == 0) {
                    return root;
                }
                int curLevelSize = q.size();
                for (int i = 0; i < curLevelSize; ++i) {
                    TreeNode * front = q.front();
                    q.pop();
                    if (d == 1) {
                        TreeNode * nextLeft = front->left;
                        TreeNode * nextright = front->right;
                        front->left = new TreeNode(v);
                        front->left->left = nextLeft;
                        front->right = new TreeNode(v);
                        front->right->right = nextright;
                    }
                    else {
                        if (front->left) {
                            q.push(front->left);
                        }
                        if (front->right) {
                            q.push(front->right);
                        }
                    }
                }
            }
            return root;
        }
    }

    // 624. Maximum Distance in Arrays
    int maxDistance624(vector<vector<int>>& arrays) {
        priority_queue<pair<int, int>> minPq, maxPq;
        for (int i = 0; i < arrays.size(); ++i) {
            minPq.push({-arrays[i][0], i});
            maxPq.push({arrays[i].back(), i});
        }

        if (minPq.top().second != maxPq.top().second) {
            return minPq.top().first + maxPq.top().first;
        }
        else {
            int maxTop = maxPq.top().first; maxPq.pop();
            int minTop = minPq.top().first; minPq.pop();
            return (maxTop + minPq.top().first > minTop + maxPq.top().first) ?
                maxTop + minPq.top().first : minTop + maxPq.top().first;
        }
    }

    // 625. Minimum Factorization
    int smallestFactorization625(int a) {
        if (a == 1) {
            return 1;
        }
        string result;
        for (int k = 9; k >= 2; --k) {
            while (a % k == 0) {
                result = to_string(k) + result;
                a /= k;
            }
        }

        if (a > 1) {
            return 0;
        }
        long long resInLL = stoll(result);
        return resInLL > INT_MAX ? 0 : static_cast<int>(resInLL);
    }

    // 628. Maximum Product of Three Numbers
    int maximumProduct628(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[n - 1],
            nums[n - 3] * nums[n - 2] * nums[n - 1]);
    }

    // 629. K Inverse Pairs Array
    int kInversePairs629(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        int MAX = 1000000007;

        for (int i = 1; i < n + 1; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MAX;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MAX) % MAX;
                }
            }
        }
        return dp.back().back();
    }

    // 630. Course Schedule III
    int scheduleCourse630(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        int curTime = 0;
        sort(courses.begin(), courses.end(),
            [](const vector<int> &courseA, const vector<int> &courseB) {
                return courseA[1] < courseB[1];
            });
        
        for (int i = 0; i < courses.size(); ++i) {
            curTime += courses[i][0];
            pq.push(courses[i][0]);
            if (curTime > courses[i][1]) {
                curTime -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }

    // 633. Sum of Square Numbers
    bool judgeSquareSum633(int c) {
        for (int i = static_cast<int>(sqrt(c)); i >= 0; --i) {
            if (i * i == c) {
                return true;
            }
            int b = c - i * i, t = static_cast<int>(sqrt(b));
            if (t * t == b) {
                return true;
            }
        }
        return false;
    }

    // 632. Smallest Range Covering Elements from K Lists
    vector<int> smallestRange632(vector<vector<int>>& nums) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }

        vector<pair<int, int>> numIdxArr;
        int K = nums.size();
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                numIdxArr.push_back({nums[i][j], i});
            }
        }
        sort(numIdxArr.begin(), numIdxArr.end());

        int left = 0, count = 0, diff = INT_MAX;
        unordered_map<int, int> idxFreqMap;
        for (int right = 0; right < numIdxArr.size(); ++right) {
            if (idxFreqMap[numIdxArr[right].second] == 0) {
                count++;
            }
            idxFreqMap[numIdxArr[right].second]++;
            while (count == K && left <= right) {
                if (diff > numIdxArr[right].first - numIdxArr[left].first) {
                    diff = numIdxArr[right].first - numIdxArr[left].first;
                    result = {numIdxArr[left].first, numIdxArr[right].first};
                }
                idxFreqMap[numIdxArr[left].second]--;
                if (idxFreqMap[numIdxArr[left].second] == 0) {
                    count--;
                }
                left++;
            }
        }
        return result;
    }

    // 634. Find the Derangement of An Array
    int findDerangement634(int n) {
        if (n == 1) {
            return 0;
        }
        vector<long long> dp(n + 1);
        dp[1] = 0; dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return static_cast<int>(dp.back());
    }

    // 635. Design Log Storage System
    class LogSystem635 {
    public:
        LogSystem635() {
            units = {"Year", "Month", "Day", "Hour", "Minute", "Second"};
            unitsLength = {4, 7, 10, 13, 16, 19};
        }
        
        void put(int id, string timestamp) {
            idTimestampArr.push_back({id, timestamp});
        }
        
        vector<int> retrieve(string s, string e, string gra) {
            int unitLen = unitsLength[
                find(units.begin(), units.end(), gra) - units.begin()];
            string startTruncate = s.substr(0, unitLen);
            string endTruncate = e.substr(0, unitLen);
            vector<int> result;
            for (int i = 0; i < idTimestampArr.size(); ++i) {
                string curTimestampTruncate
                    = idTimestampArr[i].second.substr(0, unitLen);
                if (curTimestampTruncate.compare(startTruncate) >= 0
                    && curTimestampTruncate.compare(endTruncate) <= 0) {
                    result.push_back(idTimestampArr[i].first);
                }
            }
            return result;
        }

    private:
        vector<pair<int, string>> idTimestampArr;
        vector<string> units;
        vector<int> unitsLength;
    };

    // 637. Average of Levels in Binary Tree
    vector<double> averageOfLevels637(TreeNode* root) {
        vector<double> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode *> levelQ;
        levelQ.push(root);
        while (!levelQ.empty()) {
            long long sum = 0, levelSize = levelQ.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode * front = levelQ.front();
                sum += front->val;
                levelQ.pop();
                if (front->left) {
                    levelQ.push(front->left);
                }
                if (front->right) {
                    levelQ.push(front->right);
                }
            }
            
            result.push_back(static_cast<double>(sum) / levelSize);
        }
        return result;
    }

    // 638. Shopping Offers
    int shoppingOffers638(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int result = 0;
        for (int i = 0; i < needs.size(); ++i) {
            result += (price[i] * needs[i]);
        }

        for (int i = 0; i < special.size(); ++i) {
            bool isValid = true;
            for (int j = 0; j < needs.size(); ++j) {
                if (needs[j] < special[i][j]) {
                    isValid = false;
                }
                needs[j] -= special[i][j];
            }

            if (isValid) {
                result = min(
                    result,
                    shoppingOffers638(price, special, needs) + special[i].back());
            }

            for (int j = 0; j < needs.size(); ++j) {
                needs[j] += special[i][j];
            }
        }

        return result;
    }

    // 641. Design Circular Deque
    class MyCircularDeque641 {
    public:
        /** Initialize your data structure here. Set the size of the deque to be k. */
        MyCircularDeque641(int k) : d_size(k) { }
        
        /** Adds an item at the front of Deque. Return true if the operation is successful. */
        bool insertFront(int value) {
            if (isFull()) {
                return false;
            }
            d_data.insert(d_data.begin(), value);
            return true;
        }
        
        /** Adds an item at the rear of Deque. Return true if the operation is successful. */
        bool insertLast(int value) {
            if (isFull()) {
                return false;
            }
            d_data.push_back(value);
            return true;
        }
        
        /** Deletes an item from the front of Deque. Return true if the operation is successful. */
        bool deleteFront() {
            if (isEmpty()) {
                return false;
            }
            d_data.erase(d_data.begin());
            return true;
        }
        
        /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
        bool deleteLast() {
            if (isEmpty()) {
                return false;
            }
            d_data.pop_back();
            return true;
        }
        
        /** Get the front item from the deque. */
        int getFront() {
            if (isEmpty()) {
                return -1;
            }
            return d_data[0];
        }
        
        /** Get the last item from the deque. */
        int getRear() {
            if (isEmpty()) {
                return -1;
            }
            return d_data.back();
        }
        
        /** Checks whether the circular deque is empty or not. */
        bool isEmpty() {
            return d_data.empty();
        }
        
        /** Checks whether the circular deque is full or not. */
        bool isFull() {
            return d_data.size() >= d_size;
        }

    private:
        vector<int> d_data;
        int d_size;
    };

    // 642. Design Search Autocomplete System
    // Solution 1: Using Hashmap and Priority Queue
    // class AutocompleteSystem642 {
    // public:
    //     AutocompleteSystem642(vector<string>& sentences, vector<int>& times)
    //       : d_data("") {
    //         int size = sentences.size();
    //         for (int i = 0; i < size; ++i) {
    //             d_sentenceFreqMap[sentences[i]] += times[i];
    //         }
    //     }
        
    //     vector<string> input(char c) {
    //         vector<string> result;
    //         if (c == '#') {
    //             d_sentenceFreqMap[d_data]++;
    //             d_data = "";
    //             return result;
    //         }

    //         d_data += c;
    //         auto comparatorFunc = [](
    //             const pair<string, int> & a, const pair<string, int> & b) {
    //             return (a.second > b.second) 
    //                 || (a.second == b.second && a.first < b.first);
    //         };
    //         priority_queue<pair<string, int>, 
    //             vector<pair<string, int>>, decltype(comparatorFunc)> pq(comparatorFunc);
            
    //         for (auto iter : d_sentenceFreqMap) {
    //             string sentence = iter.first;
    //             if (d_data.size() > sentence.size()) {
    //                 continue;
    //             }
    //             bool isMatch = true;
    //             for (int i = 0; i < d_data.size(); ++i) {
    //                 if (d_data[i] != sentence[i]) {
    //                     isMatch = false;
    //                     break;
    //                 }
    //             }

    //             if (isMatch) {
    //                 pq.push(iter);
    //                 if (pq.size() > 3) {
    //                     pq.pop();
    //                 }
    //             }
    //         }

    //         result.resize(pq.size());
    //         for (int i = pq.size() - 1; i >= 0; --i) {
    //             result[i] = pq.top().first;
    //             pq.pop();
    //         }

    //         return result;
    //     }

    // private:
    //     string d_data;
    //     unordered_map<string, int> d_sentenceFreqMap;
    // };

    // Solution 2: Using Trie Tree
    struct AutoCompTrieNode {
        int freq;
        AutoCompTrieNode * children[27];

        AutoCompTrieNode() : freq(0) {
            for (auto & each : children) {
                each = NULL;
            }
        }
    };

    class AutocompleteSystem642 {
    public:
        AutocompleteSystem642(vector<string>& sentences, vector<int>& times) :
          d_curSentence("") {
            d_root = new AutoCompTrieNode();
            int size = sentences.size();
            for (int i = 0; i < size; ++i) {
                insertSentence(sentences[i], times[i]);
            }
        }
        
        vector<string> input(char c) {
            vector<string> result;
            if (c == '#') {
                insertSentence(d_curSentence, 1);
                d_curSentence = "";
            }
            else {
                d_curSentence += c;
                vector<pair<string, int>> sentenceFreqArr;
                lookUpPrefix(d_curSentence, sentenceFreqArr);
                sort(sentenceFreqArr.begin(), sentenceFreqArr.end(), 
                    [](pair<string, int> &a, pair<string, int> &b) {
                        return a.second > b.second &&
                            (a.second == b.second && a.first < b.first);;
                    }
                );
                int resultSize = min(3, (int)sentenceFreqArr.size());
                for (int i = 0; i < resultSize; ++i) {
                    result.push_back(sentenceFreqArr[i].first);
                }
            }

            return result;
        }

    private:
        void insertSentence(string sentence, int time) {
            AutoCompTrieNode * cur = d_root;
            for (char &c : sentence) {
                int nextIdx = (c != ' ' ? (int)(c - 'a') : 26);
                if (!cur->children[nextIdx]) {
                    cur->children[nextIdx] = new AutoCompTrieNode();
                }
                cur = cur->children[nextIdx];
            }
            cur->freq += time;
        }

        void lookUpPrefix(string prefix,
            vector<pair<string, int>> & sentenceFreqArr) {
            sentenceFreqArr.clear();
            AutoCompTrieNode * cur = d_root;
            for (char & c: prefix) {
                int nextIdx = (c != ' ' ? (int)(c - 'a') : 26);
                if (!cur->children[nextIdx]) {
                    return;
                }
                cur = cur->children[nextIdx];
            }
            
            lookUpPrefix_rec(prefix, cur, sentenceFreqArr);
        }

        void lookUpPrefix_rec(string str, AutoCompTrieNode * cur,
            vector<pair<string, int>> & sentenceFreqArr) {
            if (cur->freq > 0) {
                sentenceFreqArr.push_back({str, cur->freq});
            }
            for (int i = 0; i < 26; ++i) {
                if (cur->children[i]) {
                    lookUpPrefix_rec(str + (char)('a' + i), cur->children[i], 
                        sentenceFreqArr);
                }
            }

            if (cur->children[26]) {
                lookUpPrefix_rec(str + ' ', cur->children[26], sentenceFreqArr);
            }
        }

        AutoCompTrieNode * d_root;
        string d_curSentence;
    };

    // 643. Maximum Average Subarray I
    double findMaxAverage643(vector<int>& nums, int k) {
        int curSum = 0;
        double result = 0.0;
        int left = 0, right = 0;
        for (; right < k; ++right) {
            curSum += nums[right];
            result = (double)curSum / k;
        }
        
        int size = nums.size();
        for (; right < size; ++right) {
            curSum = curSum - nums[left] + nums[right];
            result = max(result, (double)curSum / k);
            left++;
        }
        return result;
    }

    // 644. Maximum Average Subarray II
    double findMaxAverage644(vector<int>& nums, int k) {
        double minNum = INT_MAX, maxNum = INT_MIN;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            minNum = nums[i] < minNum ? (double)nums[i] : minNum;
            maxNum = nums[i] > maxNum ? (double)nums[i] : maxNum;
        }

        double error = INT_MAX, prev_mid = maxNum;
        while (error > 1e-5) {
            double mid = 0.5 * (minNum + maxNum);
            if (isMidCorrectEstimate(mid, nums, k)) {
                minNum = mid;
            }
            else {
                maxNum = mid;
            }
            error = abs(prev_mid - mid);
            prev_mid = mid;
        }
        return minNum;
    }

    bool isMidCorrectEstimate(
        double mid, const vector<int>& nums, int k) {
        int size = nums.size();
        vector<double> cumulativeSum(size + 1, 0);
        double minSum = 0;

        for (int i = 1; i <= size; ++i) {
            cumulativeSum[i] = cumulativeSum[i - 1] + (nums[i - 1] - mid);
            if (i >= k) {
                minSum = min(minSum, cumulativeSum[i - k]);
            }
            if (i >= k && cumulativeSum[i] > minSum) {
                return true;
            }
        }

        return false;
    }

    // 645. Set Mismatch
    vector<int> findErrorNums645(vector<int>& nums) {
        unordered_set<int> numsSet;
        int dupNum, arrSum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (!numsSet.count(nums[i])) {
                numsSet.insert(nums[i]);
            }
            else {
                dupNum = nums[i];
            }
            arrSum += nums[i];
        }

        int missingNum = (1 + n) * n / 2 - (arrSum - dupNum);
        return {dupNum, missingNum};
    }

    // 646. Maximum Length of Pair Chain
    int findLongestChain646(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
            [](const vector<int> & a, const vector<int> & b){
                return a[1] < b[1];
            }
        );
        stack<vector<int>> pairStk;
        for (auto iter : pairs) {
            if (pairStk.empty()) {
                pairStk.push(iter);
            }
            if (iter[0] > pairStk.top()[1]) {
                pairStk.push(iter);
            }
        }
        return pairStk.size();
    }

    // 647. Palindromic Substrings
    int countSubstrings647(string s) {
        int strLen = s.size();
        int result = 0;
        for (int i = 0; i < strLen; ++i) {
            countSubstrings647_rec(s, strLen, i, i, result);
            countSubstrings647_rec(s, strLen, i, i + 1, result);
        }
        return result;
    }

    void countSubstrings647_rec(const string & s, const int strLen, int left, 
        int right, int &result) {
        while (left >= 0 && right < strLen && s[left] == s[right]) {
            left--;
            right++;
            result++;
        }
    }

    // 648. Replace Words
    string replaceWords648(vector<string>& dict, string sentence) {
        TrieNode * root = new TrieNode();
        // Insert all words in the dict into Trie Tree
        for (auto word: dict) {
            insertWord(word, root);
        }

        string result;
        istringstream iss(sentence);
        string curWord;
        while (iss >> curWord) {
            if (!result.empty()) {
                result += " ";
            }
            result += findRoot(curWord, root);
        }

        return result;
    }

    void insertWord(const string word, TrieNode * root) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = (int)(word[i] - 'a');
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    string findRoot(const string word, TrieNode * root) {
        string curRoot = "";
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!cur->children[idx]) {
                break;
            }
            curRoot += (char)('a' + idx);
            cur = cur->children[idx];
            
            if (cur->isEnd) {
                return curRoot;
            }
        }
        return word;
    }

    // 649. Dota2 Senate
    string predictPartyVictory649(string senate) {
        // `R` - 0 and `D` - 1
        queue<int> actionQ;
        vector<int> banPair(2, 0), senatePair(2, 0);
        for (char & c : senate) {
            int role = (c == 'R' ? 0 : 1);
            actionQ.push(role);
            senatePair[role]++;
        }

        while (senatePair[0] > 0 && senatePair[1] > 0) {
            int x = actionQ.front();  actionQ.pop();
            if (banPair[x] > 0) {
                banPair[x]--;
                senatePair[x]--;
            }
            else {
                banPair[x ^ 1]++;
                actionQ.push(x);
            }
        }
        return senatePair[0] > 0 ? "Radiant" : "Dire";
    }

    // 650. 2 Keys Keyboard
    int minSteps650(int n) {
        int d = 2, result = 0;
        while (n > 1) {
            while (n % d == 0) {
                result += d;
                n /= d;
            }
            d++;
        }
        return result;
    }

    // 651. 4 Keys Keyboard
    int maxA651(int N) {
        if (N == 0) {
            return 0;
        }
        vector<int> dp(N + 1, 0);
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int x = 0; x < i - 1; ++x) {
                dp[i] = max(dp[i], dp[x] * (i - 1 - x));
            }
        }
        return dp.back();
    }

    // 652. Find Duplicate Subtrees
    vector<TreeNode*> findDuplicateSubtrees652(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> subtreeEncodeFreqMap;
        findDuplicateSubtrees652_rec(root, result, subtreeEncodeFreqMap);
        return result;
    }

    string findDuplicateSubtrees652_rec(TreeNode* cur, vector<TreeNode*>& result,
        unordered_map<string, int>& subtreeEncodeFreqMap) {
        if (cur == NULL) {
            return "#";
        }

        string curEncode = to_string(cur->val) + ","
            + findDuplicateSubtrees652_rec(cur->left, result, subtreeEncodeFreqMap)
            + "," + findDuplicateSubtrees652_rec(cur->right, result, subtreeEncodeFreqMap);
        if (subtreeEncodeFreqMap[curEncode] == 0) {
            subtreeEncodeFreqMap[curEncode] = 1;
        }
        else {
            if (subtreeEncodeFreqMap[curEncode] == 1) {
                result.push_back(cur);
            }
            subtreeEncodeFreqMap[curEncode]++;
        } 
        return curEncode;
    }

    // 653. Two Sum IV - Input is a BST
    bool findTarget653(TreeNode* root, int k) {
        unordered_set<int> targetNumSet;
        bool isFound = false;
        constructInorderArr(root,isFound, targetNumSet, k);
        return isFound;
    }
    
    void constructInorderArr(TreeNode* cur, bool& isFound, unordered_set<int>& targetNumSet, const int k) {
        if (cur == NULL || isFound) {
            return;
        }
        
        if (targetNumSet.count(cur->val) > 0) {
            isFound = true;
            return;
        }
        targetNumSet.insert(k - cur->val);
        constructInorderArr(cur->left, isFound, targetNumSet, k);
        constructInorderArr(cur->right, isFound, targetNumSet, k);
    }

    // 654. Maximum Binary Tree
    TreeNode* constructMaximumBinaryTree654(vector<int>& nums) {
        return constructMBT_rec(nums, 0, nums.size() - 1);
    }
    
    TreeNode* constructMBT_rec(vector<int>& nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        
        int maxIdx = -1, maxVal = INT_MIN;
        for (int i = left; i <= right; ++i) {
            if (nums[i] > maxVal) {
                maxIdx = i;
                maxVal = nums[i];
            }
        }
        
        TreeNode* cur = new TreeNode(maxVal);
        cur->left = constructMBT_rec(nums, left, maxIdx - 1);
        cur->right = constructMBT_rec(nums, maxIdx + 1, right);
        return cur;
    }

    // 656. Coin Path
    vector<int> cheapestJump656(vector<int>& A, int B) {
        vector<int> next(A.size(), -1);
        vector<long long> dp(A.size(), 0);
        for (int i = A.size() - 2; i >= 0; --i) {
            long long cost = INT_MAX;
            for (int j = i + 1; j < A.size() & j <= i + B; ++j) {
                if (A[j] >= 0) {
                    // We only want to jump to A if it can move forward
                    long long curCost = min(cost, dp[j] + A[i]);
                    if (curCost < cost) {
                        cost = curCost;
                        next[i] = j;
                    }
                }
            }
            dp[i] = cost;
        }

        int i = 0;
        vector<int> result;
        for (; i < A.size() && next[i] > 0; i = next[i]) {
            result.push_back(i + 1);
        }

        if (i == A.size() - 1 && A[i] >= 0) {
            result.push_back(A.size());
        }
        else {
            result.clear();
        }

        return result;
    }

    // 657. Robot Return to Origin
    bool judgeCircle657(string moves) {
        vector<int> position = {0, 0};
        for (char c: moves) {
            switch (c) {
            case 'U':
                position[1]++; break;
            case 'D':
                position[1]--; break;
            case 'R':
                position[0]++; break;
            case 'L':
                position[0]--; break;
            default: break;
            }
        }
        
        return position[0] == 0 && position[1] == 0;
    }

    // 658. Find K Closest Elements
    vector<int> findClosestElements658(vector<int>& arr, int k, int x) {
        vector<int> result;
        const int size = arr.size();
        if (x <= arr[0]) {
            for (int i = 0; i < k; ++i) {
                result.push_back(arr[i]);
            }
        }
        else if (x >= arr.back()) {
            for (int i = size - k; i < size; ++i) {
                result.push_back(arr[i]);
            }
        }
        else {
            int left = 0, right = size - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (arr[mid] <= x) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }
            int low = right - 1, high = right;
            while (result.size() < k) {
                if (low < 0 || (abs(arr[low] - x) > abs(arr[high] - x))) {
                    result.push_back(arr[high]);
                    high++;
                }
                else if (high >= size || (abs(arr[low] - x) <= abs(arr[high] - x))) {
                    result.insert(result.begin(), arr[low]);
                    low--;
                }
                else {
                    assert(false);
                }
            }
        }
        return result;
    }

    // 659. Split Array into Consecutive Subsequences
    bool isPossible659(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        unordered_map<int, int> needMap;
        for (int v : nums) {
            freqMap[v]++;
        }
        
        for (int v: nums) {
            if (freqMap[v] == 0) {
                continue;
            }
            if (needMap[v] > 0) {
                needMap[v]--;  needMap[v + 1]++;
            }
            else if (freqMap[v + 1] > 0 && freqMap[v + 2] > 0) {
                freqMap[v + 1]--;  freqMap[v + 2]--;
                needMap[v + 3]++;
            }
            else {
                return false;
            }
            freqMap[v]--;
        }
        return true;
    }

    // 662. Maximum Width of Binary Tree
    int widthOfBinaryTree662(TreeNode* root) {
        int width = 0;
        queue<TreeNode *> nodeQ;
        nodeQ.push(root);
        vector<long long>* levelIdxVecPtr = new vector<long long>();
        levelIdxVecPtr->push_back(0);
        
        while (!nodeQ.empty()) {
            int curWidth = static_cast<int>(
                levelIdxVecPtr->back() - levelIdxVecPtr->at(0) + 1);
            width = max(width, curWidth);
            
            int curLevelSize = nodeQ.size();
            vector<long long>* prevLevelIdxVecPtr = levelIdxVecPtr;
            levelIdxVecPtr = new vector<long long>();
            for (int i = 0; i < curLevelSize; ++i) {
                TreeNode *curNode = nodeQ.front();  nodeQ.pop();
                if (curNode->left) {
                    levelIdxVecPtr->push_back((prevLevelIdxVecPtr->at(i) * 2) % INT_MAX);
                    nodeQ.push(curNode->left);
                }
                if (curNode->right) {
                    levelIdxVecPtr->push_back((prevLevelIdxVecPtr->at(i) * 2) % INT_MAX + 1);
                    nodeQ.push(curNode->right);
                }
            }
            prevLevelIdxVecPtr->clear();
        }
        
        return width;
    }

    // 663. Equal Tree Partition
    bool checkEqualTree663(TreeNode* root) {
        vector<int> allSubSumArr;
        int total = sumRecord(root, allSubSumArr);
        if (total % 2 != 0) {
            return false;
        }
        allSubSumArr.pop_back();
            // We need to remove the last one since it represents total, 
            // which will lead to a bug if total = 0
        for (int val : allSubSumArr) {
            if (val == total / 2) {
                return true;
            }
        }
        return false;
    }
    
    int sumRecord(TreeNode* cur, vector<int>& allSubSum) {
        if (!cur) {
            return 0;
        }
        int result = sumRecord(cur->left, allSubSum) + sumRecord(cur->right, allSubSum) + cur->val;
        allSubSum.push_back(result);
        return result;
    }

    // 664. Strange Printer
    int strangePrinter664(string s) {
        if (s.empty()) {
            return 0;
        }
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                dp[i][j] = (i == j) ? 1 : 1 + dp[i + 1][j];
                for (int k = i + 1; k <= j; ++k) {
                    if (s[i] == s[k]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][size - 1];
    }

    // 665. Non-decreasing Array
    bool checkPossibility665(vector<int>& nums) {
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (count == 0) {
                    return false;
                }
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                }
                else {
                    nums[i] = nums[i - 1];
                }
                count--;
            }
        }
        return true;
    }

    // 668. Kth Smallest Number in Multiplication Table
    int findKthNumber668(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (enough(mid, m, n, k)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

    int enough(int x, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(n, x / i);
        }
        return count >= k;
    }

    // 669. Trim a Binary Search Tree
    TreeNode* trimBST669(TreeNode* root, int L, int R) {
        if (!root) {
            return NULL;
        }
        if (root->val < L) {
            return trimBST669(root->right, L, R);
        }
        if (root->val > R) {
            return trimBST669(root->left, L, R);
        }

        root->left = trimBST669(root->left, L, R);
        root->right = trimBST669(root->right, L, R);
        return root;
    }
};

#endif