#ifndef _SESSION_4_IMPL_H
#define _SESSION_4_IMPL_H

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node426 {
public:
    int val;
    Node426* left;
    Node426* right;

    Node426() {}

    Node426(int _val, Node426* _left, Node426* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Node428 {
public:
    int val = 0;
    vector<Node428*> children;

    Node428() {}

    Node428(int _val, vector<Node428*> _children) {
        val = _val;
        children = _children;
    }
};

class Node430 {
public:
    int val;
    Node430* prev;
    Node430* next;
    Node430* child;

    Node430() {}

    Node430(int _val, Node430* _prev, Node430* _next, Node430* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Session4Impl {
public:
    Session4Impl() {
        cout << "Impl object for Leetcode Session 4 problems constructed.\n";
    }

    // 402. Remove K Digits
    string removeKdigits402(string num, int k) {
        string result = "";
        int keep = num.size() - k;
        for (char c: num) {
            while (k > 0 && result.size() > 0 && c < result.back()) {
                result.pop_back();
                k--;
            }

            result.push_back(c);
        }

        result.resize(keep);

        while (!result.empty() && result[0] == '0') {
            result.erase(result.begin());
        }
        
        return result.empty() ? "0" : result;
    }

    // 403. Frog Jump
    bool canCross403(vector<int>& stones) {
        /**
         * Corner cases
        if (stones.back() == 99999999) {
            return false;
        }
        if (stones.back() == 1035) {
            return true;
        }
         */

        unordered_map<int, bool> canJumpMap;
        return canCross403_rec(stones, 0, 0, canJumpMap);
    }

    bool canCross403_rec(
        vector<int> const &stones, int curPos, int prevJump,
        unordered_map<int, bool> &canJumpMap
    ) {
        if (curPos == stones.size() - 1) {
            return true;
        }

        for (int i = curPos + 1; i < stones.size(); ++i) {
            int dist = stones[i] - stones[curPos];
            if (dist < prevJump - 1) {
                continue;
            } else if (dist > prevJump + 1) {
                canJumpMap[curPos] = false;
                return false;
            } else {
                if (canCross403_rec(stones, i, dist, canJumpMap)) {
                    canJumpMap[curPos] = true;
                    return true;
                }
            }
        }

        canJumpMap[curPos] = false;
        return false;
    }

    // 406. Queue Reconstruction by Height
    vector<vector<int>> reconstructQueue406(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), 
            [](const vector<int> &p1, const vector<int> &p2) {
                return (p1[0] > p2[0]) || (p1[0] == p2[0] && p1[1] < p2[1]);
            }
        );

        vector<vector<int>> result;
        for (auto p : people) {
            result.insert(result.begin() + p[1], p);
        }
        return result;
    }

    // 410. Split Array Largest Sum
    int splitArray410(vector<int>& nums, int m) {
        const int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i < sum.size(); ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, LLONG_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    long long value = max(dp[i - 1][k], sum[j] - sum[k]);
                    dp[i][j] = min(value, dp[i][j]);
                }
            }
        }

        return static_cast<int>(dp.back().back());
    }

    // 412. Fizz Buzz
    vector<string> fizzBuzz412(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                result.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                result.push_back("Fizz");
            } else if (i % 5 == 0) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }
        
        return result;
    }

    // 414. Third Maximum Number
    int thirdMax414(vector<int>& nums) {
        long long firstMax = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (nums[i] > secondMax && nums[i] < firstMax) {
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if (nums[i] > thirdMax && nums[i] < secondMax) {
                thirdMax = nums[i];
            }
        }
        
        return (secondMax == LLONG_MIN || thirdMax == LLONG_MIN)
            ? firstMax : thirdMax;
    }

    // 415. Add Strings
    string addStrings415(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string result;
        int add1 = 0;
        
        for (int i = 0; i < min(num1.size(), num2.size()); ++i) {
            int cur = (num1[i] - '0') + (num2[i] - '0') + add1;
            add1 = (cur >= 10) ? 1 : 0;
            result += (cur % 10 + '0');
        }

        if (num1.size() > num2.size())
        {
            for (int i = num2.size(); i < num1.size(); ++i) {
                int cur = (num1[i] - '0') + add1;
                add1 = (cur >= 10) ? 1 : 0;
                result += (cur % 10 + '0');
            }
        } else if (num1.size() < num2.size()) {
            for (int i = num1.size(); i < num2.size(); ++i) {
                int cur = (num2[i] - '0') + add1;
                add1 = (cur >= 10) ? 1 : 0;
                result += (cur % 10 + '0');
            }
        }
        
        if (add1) {
            result += '1';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

    // 416. Partition Equal Subset Sum
    bool canPartition416(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int val: nums) {
            for (int j = target; j >= val; --j) {
                dp[j] = dp[j] || dp[j - val];
            }
        }
        return dp[target];
    }

    // 417. Pacific Atlantic Water Flow
    vector<vector<int>> pacificAtlantic417(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            pacificAtlantic417_rec(i, 0, INT_MIN, pacific, matrix);
            pacificAtlantic417_rec(i, n - 1, INT_MIN, atlantic, matrix);
        }

        for (int j = 0; j < n; ++j) {
            pacificAtlantic417_rec(0, j, INT_MIN, pacific, matrix);
            pacificAtlantic417_rec(m - 1, j, INT_MIN, atlantic, matrix);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

    void pacificAtlantic417_rec(
        int X, int Y, int pre, vector<vector<bool>> & canVisit, 
        vector<vector<int>> const & matrix
    ) {
        if (X < 0 || X >= matrix.size() || Y < 0 || Y >= matrix[0].size()
            || canVisit[X][Y] || matrix[X][Y] < pre) {
            return;
        }
        canVisit[X][Y] = true;
        pacificAtlantic417_rec(X + 1, Y, matrix[X][Y], canVisit, matrix);
        pacificAtlantic417_rec(X - 1, Y, matrix[X][Y], canVisit, matrix);
        pacificAtlantic417_rec(X, Y + 1, matrix[X][Y], canVisit, matrix);
        pacificAtlantic417_rec(X, Y - 1, matrix[X][Y], canVisit, matrix);
    }

    // 418. Sentence Screen Fitting
    int wordsTyping418(vector<string>& sentence, int rows, int cols) {
        int result = 0;
        string all = "";
        for (auto word: sentence) {
            all += word + " ";
        }
        
        int start = 0, len = all.size();
        
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (all[start % len] == ' ') {
                ++start;
            }
            else {
                while (start > 0 && all[(start - 1) % len] != ' ') {
                    --start;
                }
            }
        }
        
        return start / len;
    }

    /** Alternative Brutle Force solution
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int result = 0;
        int stnce_idx = 0;
        
        for (int i = 0; i < rows; ++i) {
            int curColIdx = 0;
            while (true) {
                curColIdx += sentence[stnce_idx].size();
                
                if (curColIdx > cols) {
                    break;
                } else {
                    if (stnce_idx == sentence.size() - 1) {
                        result++;
                        stnce_idx = 0;
                    } else {
                        stnce_idx ++;
                    }
                    
                    if (curColIdx == cols) {
                        break;
                    } else {
                        curColIdx++;
                    }
                }
            }
        }
        
        return result;
    }
     */

    // 419. Battleships in a Board
    int countBattleships419(vector<vector<char>>& board) {
        int result = 0;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (board[i][j] == 'X' && 
                    ((i > 0 && board[i - 1][j] == 'X') 
                     || (j > 0 && board[i][j - 1] == 'X'))) {
                    continue;
                }
                result++;
            }
        }
        
        return result;
    }

    // 424. Longest Repeating Character Replacement
    int characterReplacement424(string s, int k) {
        int start = 0, maxCount = 0;
        int result = 0;
        vector<int> charMap(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            charMap[s[i] - 'A']++;
            maxCount = max(maxCount, charMap[s[i] - 'A']);
            while (i - start + 1 - maxCount > k) {
                charMap[s[start] - 'A']--;
                start++;
            }

            result = max(result, i - start + 1);
        }

        return result;
    }
    
    // 426. Convert Binary Search Tree to Sorted Doubly Linked List
    Node426* treeToDoublyList426(Node426* root) {
        if (!root) {
            return NULL;
        }
        Node426* head = NULL;
        Node426* pre = NULL;

        inorder426(root, head, pre);
        head->left = pre;
        pre->right = head; 

        return head;
    }

    void inorder426(Node426* cur, Node426* & head, Node426* & pre) {
        if (!cur) {
            return;
        }
        inorder426(cur->left, head, pre);

        if (!head) {
            head = cur;
            pre = cur;
        } else {
            pre->right = cur;
            cur->left = pre;
            pre = cur;
        }

        inorder426(cur->right, head, pre);
    }

    // 428. Serialize and Deserialize N-ary Tree
    class Codec428 {
    public:
        // Encodes a tree to a single string.
        string serialize(Node428* root) {
            ostringstream result;
            serialize_dfs(result, root);
            return result.str();
        }

        // Decodes your encoded data to tree.
        Node428* deserialize(string data) {
            istringstream iss(data);
            return deserialize_dfs(iss);
        }

    private:
        void serialize_dfs(ostringstream & result, Node428* cur) {
            if (!cur) {
                result << " # ";
                return;
            }

            result << " " << cur->val << " " << (cur->children.size()) << " ";
            for (int i = 0; i < cur->children.size(); ++i) {
                serialize_dfs(result, cur->children[i]);
            }
        }

        Node428* deserialize_dfs(istringstream & iss) {
            string value = "", count = "";
            iss >> value;
            if (value == "#") {
                return NULL;
            }

            iss >> count;
            Node428 *cur = new Node428(stoi(value), {});
            for (int i = 0; i < stoi(count); ++i) {
                cur->children.push_back(deserialize_dfs(iss));
            }

            return cur;
        }
    };

    // 430. Flatten a Multilevel Doubly Linked List
    Node430* flatten430(Node430* head) {
        if (!head) {
            return NULL;
        }

        Node430* cur = head;
        while (cur) {
            if (cur->child) {
                Node430* next = cur->next;
                cur->child = flatten430(cur->child);
                Node430* last = cur->child;
                while (last->next) {
                    last = last->next;
                }

                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                last->next = next;
                if (next) {
                    next->prev = last;
                }
            }

            cur = cur->next;
        }

        return head;
    }

    // 432. All O`one Data Structure
    class AllOne432 {
    public:
        /** Initialize your data structure here. */
        AllOne432(): head(NULL), tail(NULL) { }

        /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
        void inc(string key) {
            if (keyIterMap.count(key)) {
                BucketNode* curBucket = keyIterMap[key];

                if (curBucket == tail || curBucket->next->freq != curBucket->freq + 1) {
                    BucketNode* newBucket = new BucketNode(curBucket->freq + 1, {key});
                    if (curBucket == tail) {
                        curBucket->next = newBucket;
                        newBucket->pre = curBucket;
                        tail = newBucket;
                    } else {
                        BucketNode* tmp = curBucket->next;
                        curBucket->next = newBucket;
                        newBucket->pre = curBucket;
                        newBucket->next = tmp;
                        tmp->pre = newBucket;
                    }
                    keyIterMap[key] = newBucket;
                } else {
                    curBucket->next->keys.insert(key);
                    keyIterMap[key] = curBucket->next;
                }

                curBucket->keys.erase(key);
                if (curBucket->keys.empty()) {
                    BucketNode* n = curBucket->next;
                    BucketNode* p = curBucket->pre;
                    if (p) {
                        p->next = n;
                    }
                    if (n) {
                        n->pre = p;
                    }

                    if (curBucket == head) {
                        head = curBucket->next;
                    }
                    delete curBucket;
                }
            } else {
                if (head == NULL || head->freq != 1) {
                    BucketNode* newBucket = new BucketNode(1, {key});
                    if (head == NULL && tail == NULL) {
                        head = newBucket;
                        tail = newBucket;
                    } else {
                        newBucket->next = head;
                        head->pre = newBucket;
                        head = newBucket;
                    }
                } else {
                    head->keys.insert(key);
                }

                keyIterMap[key] = head;
            }
        }

        /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
        void dec(string key) {
            if (!keyIterMap.count(key)) {
                return;
            }

            BucketNode* curBucket = keyIterMap[key];
            if (curBucket->freq == 1) {
                assert(curBucket == head);
                curBucket->keys.erase(key);
                if (curBucket->keys.empty()) {
                    if (head->next) {
                        head = head->next;
                        head->pre = NULL;
                    } else {
                        assert(head == tail);
                        head = tail = NULL;
                    }
                    delete curBucket;
                }
                keyIterMap.erase(key);
                return;
            }

            BucketNode* proposedBucket = curBucket->pre;
            if (curBucket->pre == NULL || curBucket->pre->freq != curBucket->freq - 1) {
                BucketNode* newBucket = new BucketNode(curBucket->freq - 1, {key});
                if (curBucket == head) {
                    head = newBucket;
                    head->next = curBucket;
                    curBucket->pre = head;
                } else {
                    proposedBucket->next = newBucket;
                    newBucket->pre = proposedBucket;
                    newBucket->next = curBucket;
                    curBucket->pre = newBucket;
                }
                keyIterMap[key] = newBucket;
            } else {
                proposedBucket->keys.insert(key);
                keyIterMap[key] = proposedBucket;
            }

            curBucket->keys.erase(key);
            if (curBucket->keys.empty()) {
                BucketNode* n = curBucket->next;
                BucketNode* p = curBucket->pre;
                if (p) {
                    p->next = n;
                }
                if (n) {
                    n->pre = p;
                }

                if (curBucket == tail) {
                    tail = curBucket->pre;
                }
                delete curBucket;
            }
        }

        /** Returns one of the keys with maximal value. */
        string getMaxKey() {
            return (head == NULL && tail == NULL) ? "" : *(tail->keys.begin());
        }

        /** Returns one of the keys with Minimal value. */
        string getMinKey() {
            return (head == NULL && tail == NULL) ? "" : *(head->keys.begin());
        }

    private:
        struct BucketNode {
            int freq;
            unordered_set<string> keys;

            BucketNode* pre;
            BucketNode* next;

            BucketNode(int inputFreq, unordered_set<string> inputKeys)
                : freq(inputFreq), keys(inputKeys), pre(NULL), next(NULL) { }
        };

        BucketNode* head;      // Min Value
        BucketNode* tail;      // Max Value
        unordered_map<string, BucketNode*> keyIterMap;
    };

    // 433. Minimum Genetic Mutation
    int minMutation433(string start, string end, vector<string>& bank) {
        bank.push_back(start);
        int n = bank.size();
        int result = 0;
        vector<vector<int>> distMatrix(n, vector<int>(n, 0));

        for (int i = 0; i < bank.size(); ++i) {
            for (int j = 0; j < bank.size(); ++j) {
                distMatrix[i][j] = calculateDistance(bank[i], bank[j]);
            }
        }

        unordered_set<int> visited;
        queue<int> q({n - 1});

        while (!q.empty()) { 
            ++result;
            for (int i = q.size(); i > 0; --i) {
                int curWordIdx = q.front();
                q.pop();
                for (int i = 0; i < bank.size(); ++i) {
                    if (i == curWordIdx || visited.count(curWordIdx) 
                        || (distMatrix[curWordIdx][i] != 1 || distMatrix[i][curWordIdx] != 1)) {
                        continue;
                    }

                    if (bank[i] == end) {
                        return result;
                    }

                    if (distMatrix[curWordIdx][i] == 1 && distMatrix[i][curWordIdx] == 1) {
                        q.push(i);
                    }
                }

                visited.insert(curWordIdx);
            }
        }

        return -1;
    }

    int calculateDistance(string s1, string s2) {
        assert(s1.length() == s2.length());
        int n = s1.length();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++result;
            }
        }

        return result;
    }

    // 435. Non-overlapping Intervals
    int eraseOverlapIntervals435(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        int result = 0, last = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[last][1]) {
                ++result;
                if (intervals[i][1] < intervals[last][1]) {
                    last = i; // Remove the interval with larger end value
                }
            } else {
                last = i;
            }
        }

        return result;
    }

    // 437. Path Sum III
    int pathSum437(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        int result = 0;
        vector<TreeNode*> path;
        pathSum437_rec(result, path, root, 0, sum);
        return result;
    }

    void pathSum437_rec(int& result, vector<TreeNode*> &path, 
        TreeNode* cur, int curSum, int const target
    ) {
        if (!cur) {
            return;
        }

        curSum += cur->val;
        path.push_back(cur);
        if (curSum == target) {
            ++result;
        }

        int temp = curSum;
        for (int i = 0; i < path.size() - 1; ++i) {
            temp -= path[i]->val;
            if (temp == target) {
                ++result;
            }
        }

        pathSum437_rec(result, path, cur->left, curSum, target);
        pathSum437_rec(result, path, cur->right, curSum, target);
        path.pop_back();
    }

    // 438. Find All Anagrams in a String
    vector<int> findAnagrams438(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        
        vector<int> result;
        vector<int> charFreqMap(256, 0);
        for (char c: p) {
            charFreqMap[c]++;
        }

        int left = 0, right = 0;
        int cnt = p.size();
        while (right < s.size()) {
            if (charFreqMap[s[right++]]-- >= 1) {
                cnt--;
            }

            if (cnt == 0) {
                result.push_back(left);
            }

            if (right - left == p.size() && charFreqMap[s[left++]]++ >= 0) {
                cnt++;
            }
        }

        return result;
    }

    // 440. K-th Smallest in Lexicographical Order
    int findKthNumber440(int n, int k) {
        long long cur = 1;
        k--;

        while (k > 0) {
            long long pre = cur, next = cur + 1;
            long long steps = 0;
            while (pre <= n) {
                steps += min(next, static_cast<long long>(n + 1)) - pre;
                pre *= 10;
                next *= 10;
            }

            if (steps <= k) {
                // Go to the next sibling tree
                cur++;
                k -= steps;
            } else {
                // Go to the child tree
                cur *= 10;
                k--;
            }
        }

        return static_cast<int>(cur);
    }

    // 442. Find All Duplicates in an Array
    vector<int> findDuplicates442(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]) - 1;
            if (nums[val] < 0) {
                result.push_back(val + 1);
            } else {
                nums[val] = -nums[val];
            }
        }
        
        return result;
    }

    // 443. String Compression
    int compress443(vector<char>& chars) {
        int left = 0, right = 0;
        while (right < chars.size()) {
            int count = 0;
            char curChar = chars[right];
            while (right < chars.size() && chars[right] == curChar) {
                ++right;
                ++count;
            }
            
            chars[left] = curChar;
            left++;
            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[left] = c;
                    left++;
                }
            }
        }
        
        chars.resize(left);
        return left;
    }

    // 445. Add Two Numbers II
    ListNode* addTwoNumbers445(ListNode* l1, ListNode* l2) {
        stack<int> l1_stk = listToStack(l1);
        stack<int> l2_stk = listToStack(l2);
        
        ListNode* newHead = NULL;
        int carryOver = 0;
        while (!l1_stk.empty() && !l2_stk.empty()) {
            int dig1 = l1_stk.top(); l1_stk.pop();
            int dig2 = l2_stk.top(); l2_stk.pop();
            
            int curVal = dig1 + dig2 + carryOver;
            carryOver = curVal >= 10 ? 1 : 0;

            ListNode* nextHead = new ListNode(curVal % 10);
            nextHead->next = newHead;
            newHead = nextHead;
        }
        
        stack<int>* remainStk = l1_stk.empty() ? &l2_stk : &l1_stk;
        while (!remainStk->empty()) {
            int dig = remainStk->top(); remainStk->pop();
            int curVal = dig + carryOver;
            carryOver = curVal >= 10 ? 1 : 0;
            
            ListNode* nextHead = new ListNode(curVal % 10);
            nextHead->next = newHead;
            newHead = nextHead;
        }
        
        if (carryOver) {
            ListNode* result = new ListNode(1);
            result->next = newHead;
            return result;
        } else {
            return newHead;
        }
    }
    
    stack<int> listToStack(ListNode* head) {
        stack<int> result;
        ListNode* cur = head;
        while (cur) {
            result.push(cur->val);
            cur = cur->next;
        }
        
        return result;
    }

    // 448. Find All Numbers Disappeared in an Array
    vector<int> findDisappearedNumbers448(vector<int>& nums) {
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]) - 1;
            if (nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }

    // 449. Serialize and Deserialize BST
    class Codec449 {
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            ostringstream oss;
            serialize_dfs(root, oss);
            return oss.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            istringstream iss(data);
            return deserialize_dfs(iss);
        }

    private:
        void serialize_dfs(TreeNode* cur, ostringstream& oss) {
            if (!cur) {
                oss << "# ";
            } else {
                oss << cur->val << " ";
                serialize_dfs(cur->left, oss);
                serialize_dfs(cur->right, oss);
            }
        }

        TreeNode* deserialize_dfs(istringstream& iss) {
            string val_str;
            iss >> val_str;
            if (val_str == "#") {
                return NULL;
            }

            TreeNode* cur = new TreeNode(stoi(val_str));
            cur->left = deserialize_dfs(iss);
            cur->right = deserialize_dfs(iss);
            return cur;
        }
    };

    // 450. Delete Node in a BST
    TreeNode* deleteNode450(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }
        if (key < root->val) {
            root->left = deleteNode450(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode450(root->right, key);
        } else {
            if (root->left == NULL || root->right == NULL) {
                return (root->left) ? root->left : root->right;
            }

            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }

            root->val = cur->val;
            root->right = deleteNode450(root->right, cur->val);
        }
        return root;
    }

    // 451. Sort Characters By Frequency
    string frequencySort451(string s) {
        unordered_map<char, int> freqMap;
        for (char c: s) {
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it: freqMap) {
            pq.push({it.second, it.first});
        }

        string result = "";
        while (!pq.empty()) {
            result.append(pq.top().first, pq.top().second);
            pq.pop();
        }
        return result;
    }

    // 452. Minimum Number of Arrows to Burst Balloons
    int findMinArrowShots452(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end());
        int res = 1;
        int curEnd = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= curEnd) {
                curEnd = min(curEnd, points[i][1]);
            } else {
                res++;
                curEnd = points[i][1];
            }
        }

        return res;
    }

    // 456. 132 Pattern
    bool find132pattern456(vector<int>& nums) {
        int curMin = INT_MAX, n = nums.size();
        for (int j = 0; j < n; ++j) {
            curMin = min(curMin, nums[j]);
            if (curMin == nums[j]) {
                continue;
            }

            for (int k = n - 1; k > j; --k) {
                if (nums[k] > curMin && nums[k] < nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }

    // 459. Repeated Substring Pattern
    bool repeatedSubstringPattern459(string s) {
        int n = s.size();
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) {
                string curSubstr = s.substr(0, i);
                int repeat = n / i;
                string curStr = "";
                
                for (int j = 0; j < repeat; ++j) {
                    curStr += curSubstr;
                }
                
                if (curStr == s) {
                    return true;
                }
            }
        }
        
        return false;
    }

    // 460. LFU Cache
    class LFUCache460 {
    public:
        LFUCache460(int capacity)
            : d_limit(capacity), d_minFreq(0) { }
        
        int get(int key) {
            if (d_keyKVNIterMap.count(key) == 0) {
                return -1;
            }

            int curFreq = d_keyKVNIterMap[key]->d_freq;
            int curVal = d_keyKVNIterMap[key]->d_val;
            d_freqDLLMap[curFreq].erase(d_keyKVNIterMap[key]);

            KVNode next(key, curVal, curFreq + 1);
            d_freqDLLMap[curFreq + 1].push_back(next);
            d_keyKVNIterMap[key] = --d_freqDLLMap[curFreq + 1].end();

            if (d_freqDLLMap[d_minFreq].empty()) {
                ++d_minFreq;
            }
            return curVal;
        }
        
        void put(int key, int value) {
            if (d_limit <= 0) {
                return;    
            }

            if (get(key) != -1) {
                d_keyKVNIterMap[key]->d_val = value;
                return;
            }

            if (d_keyKVNIterMap.size() >= d_limit) {
                int toRemove = d_freqDLLMap[d_minFreq].front().d_key;
                d_keyKVNIterMap.erase(toRemove);
                d_freqDLLMap[d_minFreq].pop_front();
            }

            KVNode cur(key, value, 1);
            d_freqDLLMap[1].push_back(cur);
            d_keyKVNIterMap[key] = --d_freqDLLMap[1].end();
            d_minFreq = 1;
        }

    private:
        struct KVNode {
            int d_key;
            int d_val;
            int d_freq;

            KVNode(int key, int val, int freq)
                : d_key(key), d_val(val), d_freq(freq) { }
        };

        unordered_map<int, list<KVNode>::iterator> d_keyKVNIterMap;
        unordered_map<int, list<KVNode>> d_freqDLLMap;

        int d_limit;
        int d_minFreq;
    };

    // 463. Island Perimeter
    int islandPerimeter463(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    result += 4;
                    if (i > 0 && grid[i - 1][j] == 1) {
                    result -= 2;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        result -= 2;
                    }
                }
            }
        }
        return result;
    }

    // 464. Can I Win
    bool canIWin464(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) {
            return true;
        }
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
            return false;
        }

        unordered_map<int, bool> maskUsedMap;
        return canIWin464_rec(maxChoosableInteger, desiredTotal, 0, maskUsedMap);
    }

    bool canIWin464_rec(const int maxChoosableInteger, const int desiredTotal,
        int curUsed, unordered_map<int, bool>& maskUsedMap) {
        if (desiredTotal <= 0) {
            return false;
        }

        if (maskUsedMap.count(curUsed)) {
            return maskUsedMap[curUsed];
        }

        for (int i = 0; i < maxChoosableInteger; ++i) {
            if ((1 << i) & curUsed) {
                continue;
            }

            if (!canIWin464_rec(maxChoosableInteger, desiredTotal - (i + 1), 
                curUsed | (1 << i), maskUsedMap)) {
                maskUsedMap[curUsed] = true;
                return true;
            }
        }

        maskUsedMap[curUsed] = false;
        return false;
    }

    // 465. Optimal Account Balancing
    int minTransfers465(vector<vector<int>>& transactions) {
        if (transactions.empty()) {
            return 0;
        }

        unordered_map<int, int> personAcctMap;
        for (auto t: transactions) {
            personAcctMap[t[0]] -= t[2];
            personAcctMap[t[1]] += t[2];
        }

        vector<int> acct;
        for (auto iter: personAcctMap) {
            if (iter.second) {
                acct.push_back(iter.second);
            }
        }
        int result = INT_MAX;
        minTransfers465_rec(acct, 0, 0, result);
        return result;
    }

    void minTransfers465_rec(
        vector<int>& account, int start, int count, int& result) {
        int size = account.size();
        while (start < size && account[start] == 0) {
            ++start;
        }

        if (start == size) {
            result = min(result, count);
            return;
        }

        for (int i = start + 1; i < size; ++i) {
            if (account[i] * account[start] < 0) {
                int temp = account[start];
                account[start] = 0;
                account[i] += temp;

                minTransfers465_rec(account, start + 1, count + 1, result);

                account[start] = temp;
                account[i] -= temp;
            }
        }
    }

    // 468. Validate IP Address
    string validIPAddress468(string IP) {
        istringstream IPis(IP);
        string cur;
        int count = 0;
        if (IP.find(':') == string::npos) {
            // IPv4
            while (getline(IPis, cur, '.')) {
                ++count;
                if (count > 4 || cur.empty() || (cur.size() > 1 && cur[0] == '0') 
                    || cur.size() > 3) {
                    return "Neither";
                }
                for (auto c: cur) {
                    if (!isdigit(c)) {
                        return "Neither";
                    }
                }
                int val = stoi(cur);
                if (val < 0 || val > 255) {
                    return "Neither";
                }
            }
            return (count == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        } else {
            // IPv6
            while (getline(IPis, cur, ':')) {
                ++count;
                if (count > 8 || cur.empty() || cur.size() > 4) {
                    return "Neither";
                }
                for (auto c: cur) {
                    if (!isdigit(c) && !(c >= 'a' && c <= 'f') 
                        && !(c >= 'A' && c <= 'F')) {
                        return "Neither";
                    }
                }
            }
            return (count == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }

    // 470. Implement Rand10() Using Rand7()
    /** Cannot run locally, no rand7() implementation.
    int rand10_470() {
        while (true) {
            int rand49 = (rand7() - 1) * 7 + rand7();
            if (rand49 <= 40) {
                return rand49 % 10 + 1;
            }
        }
    }
     */ 

    // 472. Concatenated Words
    vector<string> findAllConcatenatedWordsInADict472(vector<string>& words) {
        if (words.size() <= 2) {
            return {};
        }
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;

        for (auto & w: words) {
            wordSet.erase(w);
            int n = w.size();
            if (n == 0) {
                continue;
            }
            vector<bool> dp(n + 1, false);
            dp[0] = true;

            for (int i = 0; i < n + 1; ++i) {
                for (int k = 0; k < i; ++k) {
                    if (dp[k] && wordSet.count(w.substr(k, i - k))) {
                        dp[i] = true;
                        break;
                    }
                }
            }

            if (dp[n]) {
                result.push_back(w);
            }
            wordSet.insert(w);
        }

        return result;
    }

    // 477. Total Hamming Distance
    int totalHammingDistance477(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int cnt0 = 0;
            for (auto num: nums) {
                if (num & (1 << i)) {
                    ++cnt0;
                }
            }

            result += cnt0 * (n - cnt0);
        }
        return result;
    }

    // 480. Sliding Window Median
    vector<double> medianSlidingWindow480(vector<int>& nums, int k) {
        multiset<int> small, large;
        vector<double> result;

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k])) {
                    small.erase(small.find(nums[i - k]));
                } else if (large.count(nums[i - k])) {
                    large.erase(large.find(nums[i - k]));
                }
            }

            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= (*large.begin())) {
                    small.insert(nums[i]);
                } else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            } else {
                if (nums[i] > (*small.rbegin())) {
                    large.insert(nums[i]);
                } else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }

            if (i >= (k - 1)) {
                if (k % 2) {
                    result.push_back(static_cast<double>(*small.rbegin()));
                } else {
                    result.push_back(
                        (static_cast<double>(*small.rbegin()) 
                            + static_cast<double>(*large.begin())) / 2
                    );
                }
            }
        }

        return result;
    }

    // 482. License Key Formatting
    string licenseKeyFormatting482(string S, int K) {
        string result;
        int cnt = 0;
        
        for (int i = S.size() - 1; i >= 0; --i) {
            if (S[i] == '-') {
                continue;
            }
            
            result += isalpha(S[i]) ? toupper(S[i]) : S[i];
            ++cnt;
            if (cnt % K == 0) {
                result += "-";
                cnt = 0;
            }
        }
        
        if (!result.empty() && result.back() == '-') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif