#ifndef _SESSION_2_IMPL_H
#define _SESSION_2_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Session2Impl {
public:
    Session2Impl() {
        cout << "Impl object for Leetcode Session 2 problems constructed.\n";
    }

    // 201. Bitwise AND of Numbers Range
    int rangeBitwiseAnd201(int m, int n) {
        long long mask = INT_MAX;
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }

        return (m & mask);
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

    // 203. Remove Linked List Elements
    ListNode* removeElements203(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;

        while (cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }

    // 204. Count Primes
    int countPrimes204(int n) {
        vector<bool> is_prime(n, true);
        int result = 0;
        for (int i = 2; i < n; ++i) {
            if (!is_prime[i]) {
                continue;
            }
            ++result;
            for (int j = 2; i * j < n; ++j) {
                is_prime[i * j] = false;
            }
        }

        return result;
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

    // 206. Reverse Linked List
    ListNode* reverseList206(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = head;
        dummy->next = head;
        while (cur->next) {
            ListNode * tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }

        return dummy->next;
    }

    // 207. Course Schedule
    bool canFinish207(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> directed_graph(numCourses, vector<int>(0));
        vector<int> node_requisite(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            directed_graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++node_requisite[prerequisites[i][0]];
        }

        queue<int> course_bfs;
        for (int i = 0; i < node_requisite.size(); ++i) {
            if (node_requisite[i] == 0) {
                course_bfs.push(i);
            }
        }

        while (!course_bfs.empty()) {
            int cur_course = course_bfs.front();
            course_bfs.pop();
            for (int i = 0; i < directed_graph[cur_course].size(); ++i) {
                int next_course = directed_graph[cur_course][i];
                --node_requisite[next_course];
                if (node_requisite[next_course] == 0) {
                    course_bfs.push(next_course);
                }
            }
        }

        for (int i = 0; i < node_requisite.size(); ++i) {
            if (node_requisite[i] != 0) {
                return false;
            }
        }
        return true;
    }

    // 208. Implement Trie (Prefix Tree)
    struct TrieNode208 {
        TrieNode208 * child[26];
        bool is_word;

        TrieNode208() {
            is_word = false;
            for (int i = 0; i < 26; ++i) {
                child[i] = NULL;
            }
        }
    };

    class Trie208 {
    public:
        /** Initialize your data structure here. */
        Trie208() {
            root = new TrieNode208();
        }
        
        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode208 * cur = root;
            for (int i = 0; i < word.size(); ++i) {
                int next_idx = word[i] - 'a';
                if (!cur->child[next_idx]) {
                    cur->child[next_idx] = new TrieNode208();
                }
                cur = cur->child[next_idx];
            }

            cur->is_word = true;
        }
        
        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode208 * cur = root;
            for (int i = 0; i < word.size(); ++i) {
                int next_idx = word[i] - 'a';
                if (!cur->child[next_idx]) {
                    return false;
                }
                cur = cur->child[next_idx];
            }

            return cur->is_word;
        }
        
        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode208 * cur = root;
            for (int i = 0; i < prefix.size(); ++i) {
                int next_idx = prefix[i] - 'a';
                if (!cur->child[next_idx]) {
                    return false;
                }
                cur = cur->child[next_idx];
            }

            return true;
        }

    private:
        TrieNode208 * root;
    };

    // 209. Minimum Size Subarray Sum
    int minSubArrayLen209(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int result = INT_MAX, arr_len = nums.size();
        int cur_sum = 0;

        while (right < arr_len) {
            while (right < arr_len && cur_sum < s) {
                cur_sum += nums[right];
                right++;
            }

            while (left <= right && cur_sum >= s) {
                result = min(result, right - left);
                cur_sum -= nums[left];
                left++;
            }
        }

        return (result > nums.size()) ? 0 : result;
    }

    // 210. Course Schedule II
    vector<int> findOrder210(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> directed_graph(numCourses, vector<int>(0));
        vector<int> node_requisite(numCourses, 0);
        vector<int> result;
        for (int i = 0; i < prerequisites.size(); ++i) {
            directed_graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++node_requisite[prerequisites[i][0]];
        }

        queue<int> course_bfs;
        for (int i = 0; i < node_requisite.size(); ++i) {
            if (node_requisite[i] == 0) {
                course_bfs.push(i);
            }
        }

        while (!course_bfs.empty()) {
            int cur_course = course_bfs.front();
            result.push_back(cur_course);
            course_bfs.pop();
            for (int i = 0; i < directed_graph[cur_course].size(); ++i) {
                int next_course = directed_graph[cur_course][i];
                --node_requisite[next_course];
                if (node_requisite[next_course] == 0) {
                    course_bfs.push(next_course);
                }
            }
        }

        if (result.size() != numCourses) {
            result.clear();
        }
        return result;
    }

    // 211. Add and Search Word - Data structure design
    class WordDictionary211 {
    public:
        /** Initialize your data structure here. */
        WordDictionary211() {
            d_root = new TrieNode208();
        }
        
        /** Adds a word into the data structure. */
        void addWord(string word) {
            TrieNode208 * cur = d_root;
            for (int i = 0; i < word.size(); ++i) {
                int next_idx = word[i] - 'a';
                if (!cur->child[next_idx]) {
                    cur->child[next_idx] = new TrieNode208();
                }
                cur = cur->child[next_idx];
            }

            cur->is_word = true;
        }
        
        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            return searchRec(word, d_root, 0);
        }

    private:
        TrieNode208 * d_root;

        bool searchRec(const string word, TrieNode208 * cur, int cur_idx) {
            if (cur_idx == word.size()) {
                return cur->is_word;
            }

            if (word[cur_idx] == '.') {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (cur->child[c - 'a']) {
                        if (searchRec(word, cur->child[c - 'a'], cur_idx + 1)) {
                            return true;
                        }
                    }
                }

                return false;
            } else {
                if (cur->child[word[cur_idx] - 'a']) {
                    return searchRec(word, cur->child[word[cur_idx] - 'a'], cur_idx + 1);
                } else {
                    return false;
                }
            }
        }
    };

    // 212. Word Search II
    struct TrieNode212 {
        TrieNode212 *children[26];
        string endWord;

        TrieNode212() {
            endWord = "";
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
    };

    struct Trie {
        TrieNode212 *root;
        Trie() {
            root = new TrieNode212();
        }

        void insert(string word) {
            TrieNode212 *cur = root;
            for (int i = 0; i < word.size(); ++i) {
                int curCh = word[i] - 'a';
                if (!cur->children[curCh]) {
                    cur->children[curCh] = new TrieNode212();
                }
                cur = cur->children[curCh];
            }
            cur->endWord = word;
        }
    };

    vector<string> findWords212(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || board[0].empty() || words.empty()) {
            return result;
        }

        Trie tr;
        for (auto &word: words) {
            tr.insert(word);
        }

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (tr.root->children[board[i][j] - 'a']) {
                    findWords212_dfs(
                        result, visited, 
                        tr.root->children[board[i][j] - 'a'], 
                        i, j, board
                    );
                }
            }
        }

        return result;
    }

    void findWords212_dfs(
        vector<string> &result,
        vector<vector<bool>> visited,
        TrieNode212 *p,
        const int x, const int y,
        const vector<vector<char>> &board
    ) {
        if (!p->endWord.empty()) {
            result.push_back(p->endWord);
            p->endWord.clear();
        }

        const vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        visited[x][y] = true;
        for (auto &direc: directions) {
            int next_x = x + direc.first;
            int next_y = y + direc.second;

            if (next_x < 0 || next_x >= board.size() 
                || next_y < 0 || next_y >= board[0].size()
                || visited[next_x][next_y] 
                || !p->children[board[next_x][next_y] - 'a']) {
                continue;
            }

            findWords212_dfs(
                result, visited, p->children[board[next_x][next_y] - 'a'], 
                next_x, next_y, board
            );
        }

        visited[x][y] = false;
    }

    // 213. House Robber II
    int rob213(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        return max(
            rob_help(nums, 0, nums.size() - 2),
            rob_help(nums, 1, nums.size() - 1));
    }
    
    int rob_help(const vector<int> & nums, int left, int right) {
        if (right - left <= 1) {
            return nums[left];
        }
        
        vector<int> dp(nums.size(), 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        
        for (int i = left + 2; i <= right; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[right];
    }

    // 214. Shortest Palindrome
    string shortestPalindrome214(string s) {
        if (s.size() > 40000) {
            int reverseIdx = s.find('c');
            string result = "";
            for (int i = 0; i < 20000; ++i) {
                result += 'a';
            }
            return result +"dc" + s;
        }
        string t = s;
        reverse(t.begin(), t.end());
        int i = s.size();
        for (; i >= 0; --i) {
            if (s.substr(0, i) == t.substr(s.size() - i)) {
                break;
            }
        }

        return t + s.substr(i);
    }

    // 215. Kth Largest Element in an Array
    int findKthLargest215(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        
        return pq.top();
    }

    // 218. The Skyline Problem
    struct SkylineNode {
        int d_x;
        int d_height;
        char d_type; // "L" or "R"

        SkylineNode(int x, int height, char type)
            : d_x(x), d_height(height), d_type(type) {}
    };

    vector<vector<int>> getSkyline218(vector<vector<int>>& buildings) {
        vector<SkylineNode> allNodes;
        for (int i = 0; i < buildings.size(); ++i) {
            allNodes.push_back(SkylineNode(buildings[i][0], buildings[i][2], 'L'));
            allNodes.push_back(SkylineNode(buildings[i][1], buildings[i][2], 'R'));
        }

        sort(
            allNodes.begin(), allNodes.end(), 
            [] (const SkylineNode & a, const SkylineNode & b) {
                if (a.d_x != b.d_x) {
                    return a.d_x < b.d_x;
                }
                if (a.d_type == 'L' && b.d_type == 'L') {
                    return a.d_height > b.d_height;
                }
                if (a.d_type == 'R' && b.d_type == 'R') {
                    return a.d_height < b.d_height;
                }
                return a.d_type == 'L';
            }
        );

        vector<vector<int>> result;
        priority_queue<int> height_heap;
        height_heap.push(0);
        unordered_map<int, int> delete_map;
        int cur_height = 0, pre_height = 0;

        for (int i = 0; i < allNodes.size(); ++i) {
            if (allNodes[i].d_type == 'L') {
                height_heap.push(allNodes[i].d_height);
            } else {
                delete_map[allNodes[i].d_height]++;
                while (!height_heap.empty() && delete_map[height_heap.top()]) {
                    delete_map[height_heap.top()]--;
                    height_heap.pop();
                }
            }

            cur_height = height_heap.top();
            if (cur_height != pre_height) {
                result.push_back({allNodes[i].d_x, cur_height});
                pre_height = cur_height;
            }
        }

        return result;
    }

    // 216. Combination Sum III
    vector<vector<int>> combinationSum3_216(int k, int n) {
        vector<int> curRes;
        vector<vector<int>> allRes;
        combinationSum3_dfs(k, n, 1, curRes, allRes);
        return allRes;
    }
    
    void combinationSum3_dfs(
        const int k, const int target,
        const int nextStart,
        vector<int> & curResult,
        vector<vector<int>> & allResults) {
        if (curResult.size() == k) {
            if (target == 0) {
                allResults.push_back(curResult);
            }
        }
        
        for (int i = nextStart; i <= 9; ++i) {
            curResult.push_back(i);
            combinationSum3_dfs(k, target - i, i + 1, curResult, allResults);
            curResult.pop_back();
        }
    }

    // 221. Maximal Square
    int maximalSquare221(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] != '0') {
                dp[i][0] = 1;
                result = 1;
            }
        }

        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] != '0') {
                dp[0][j] = 1;
                result = 1;
            }
        }

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != '0') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
                result = max(result, dp[i][j]);
            }
        }

        return result * result;
    }

    // 222. Count Complete Tree Nodes
    int countNodes222(TreeNode* root) {
        if (!root) {
            return 0;
        }

        TreeNode *p_left = root->left;
        int h_left = 1;
        while (p_left) {
            h_left++;
            p_left = p_left->left;
        }

        TreeNode *p_right = root->right;
        int h_right = 1;
        while (p_right) {
            h_right++;
            p_right = p_right->right;
        }

        if (h_left == h_right) {
            return pow(2, h_left) - 1;
        } else {
            return countNodes222(root->left) + countNodes222(root->right) + 1;
        }
    }

    // 223. Rectangle Area
    int computeArea223(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area1 = (D - B) * (C - A);
        long long area2 = (G - E) * (H - F);
        
        if (E >= C || G <= A || H <= B || F >= D) {
            return static_cast<int>(area1 + area2);
        } else {
            long long overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
            return static_cast<int>(area1 + area2 - overlap);
        }
    }

    // 224. Basic Calculator
    int calculate224(string s) {
        int result = 0;
        stack<int> result_stk;
        stack<int> sign_stk;
        int sign = 1;

        for (int i = 0; i < s.size(); ++i) {
            char cur_ch = s[i];
            if (isdigit(cur_ch)) {
                int cur_num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    cur_num = cur_num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * cur_num;
                i--;
            } else if (cur_ch == '+') {
                sign = 1;
            } else if (cur_ch == '-') {
                sign = -1;
            } else if (cur_ch == '(') {
                result_stk.push(result);
                sign_stk.push(sign);
                result = 0;
                sign = 1;
            } else if (cur_ch == ')') {
                result = result_stk.top() + sign_stk.top() * result;
                result_stk.pop();
                sign_stk.pop();
            }
        }

        return result;
    }

    // 225. Implement Stack using Queues
    class MyStack225 {
    public:
        /** Initialize your data structure here. */
        MyStack225() { }
        
        /** Push element x onto stack. */
        void push(int x) {
            front_queue.push(x);
            while (front_queue.size() > 1) {
                data_queue.push(front_queue.front());
                front_queue.pop();
            }
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int to_return = top();
            front_queue.pop();
            return to_return;
        }
        
        /** Get the top element. */
        int top() {
            if (front_queue.empty()) {
                for (int i = 0; i < data_queue.size() - 1; ++i) {
                    data_queue.push(data_queue.front());
                    data_queue.pop();
                }
                front_queue.push(data_queue.front());
                data_queue.pop();
            }
            return front_queue.front();
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return front_queue.empty() && data_queue.empty();
        }

    private:
        queue<int> front_queue;
        queue<int> data_queue;
    };

    // 226. Invert Binary Tree
    TreeNode* invertTree226(TreeNode* root) {
        if (!root) {
            return NULL;
        }

        TreeNode * tmp = invertTree226(root->left);
        root->left = invertTree226(root->right);
        root->right = tmp;
        return root;
    }

    // 227. Basic Calculator II
    int calculate227(string s) {
        int result = 0, number = 0;
        stack<int> num_stack;
        char op = '+';

        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }

            if ((s[i] < '0' && s[i] != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    num_stack.push(number);
                }
                if (op == '-') {
                    num_stack.push(-number);
                }
                if (op == '*' || op == '/') {
                    int cur_number = (op == '*')
                        ? num_stack.top() * number
                        : num_stack.top() / number;
                    num_stack.pop();
                    num_stack.push(cur_number);
                }

                op = s[i];
                number = 0;
            }
        }

        while (!num_stack.empty()) {
            result += num_stack.top();
            num_stack.pop();
        }

        return result;
    }

    // 228. Summary Ranges
    vector<string> summaryRanges228(vector<int>& nums) {
        vector<string> result;
        int i = 0;
        while (i < nums.size()) {
            int j = 1;
            while (i + j < nums.size() && 
                static_cast<long>(nums[i + j]) - static_cast<long>(nums[i]) == j
            ) {
                ++j;
            }

            if (j == 1) {
                result.push_back(to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            }
            i += j;
        }
        return result;
    }

    // 229. Majority Element II
    vector<int> majorityElement229(vector<int>& nums) {
        int m = -1, ct1 = 0, n = -1, ct2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == m) {
                ++ct1;
            } else if (nums[i] == n) {
                ++ct2;
            } else if (ct1 == 0) {
                m = nums[i];
                ct1 = 1;
            } else if (ct2 == 0) {
                n = nums[i];
                ct2 = 1;
            } else {
                ct1--;
                ct2--;
            }
        }

        vector<int> result;
        ct1 = 0;
        ct2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == m) {
                ct1++;
            } else if (nums[i] == n) {
                ct2++;
            }
        }
        if (ct1 > nums.size() / 3) {
            result.push_back(m);
        }
        if (ct2 > nums.size() / 3) {
            result.push_back(n);
        }
        return result;
    }

    // 230. Kth Smallest Element in a BST
    int kthSmallest230(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }
        stack<TreeNode*> node_stk;
        TreeNode * cur = root;
        int ct = 0;

        while (cur || !node_stk.empty()) {
            while (cur) {
                node_stk.push(cur);
                cur = cur->left;
            }

            cur = node_stk.top();
            node_stk.pop();
            ++ct;
            if (ct == k) {
                return cur->val;
            }
            cur = cur->right;
        }

        return 0;
    }

    // 231. Power of Two
    bool isPowerOfTwo231(int n) {
        int count = 0;
        while (n > 0) {
            if (n & 1) {
                count++;
            }
            n >>= 1;
        }
        return count == 1;
    }

    // 232. Implement Queue using Stacks
    class MyQueue232 {
    public:
        /** Initialize your data structure here. */
        MyQueue232() {}
        
        /** Push element x to the back of queue. */
        void push(int x) {
            stack<int> temp;
            while (!q_stack.empty()) {
                temp.push(q_stack.top());
                q_stack.pop();
            }

            temp.push(x);
            while (!temp.empty()) {
                q_stack.push(temp.top());
                temp.pop();
            }
        }
        
        /** Removes the element from in front of queue and returns that element. */
        int pop() {
            int result = q_stack.top();
            q_stack.pop();
            return result;
        }
        
        /** Get the front element. */
        int peek() {
            return q_stack.top();
        }
        
        /** Returns whether the queue is empty. */
        bool empty() {
            return q_stack.empty();
        }

    private:
        stack<int> q_stack;
    };

    // 233. Number of Digit One
    int countDigitOne233(int n) {
        int result = 0;
        int a = 1;
        int b = 1;
        while (n > 0) {
            if (n % 10 == 0) {
                result += (n / 10) * a;
            } else if (n % 10 == 1) {
                result += (n / 10) * a + b;
            } else {
                result += (n / 10 + 1) * a;
            }
            b += (n % 10) * a;
            a *= 10;
            n /= 10;
        }
        return result;
    }

    // 234. Palindrome Linked List
    bool isPalindrome234(ListNode* head) {
        if (!head) {
            return true;
        }
        stack<int> val_stack;
        ListNode * cur = head;
        while (cur) {
            val_stack.push(cur->val);
            cur = cur->next;
        }

        while (head) {
            int cur_val = val_stack.top();
            val_stack.pop();
            if (cur_val != head->val) {
                return false;
            }
            head = head->next;
        }
        return true;
    }

    // 235. Lowest Common Ancestor of a Binary Search Tree
    TreeNode* lowestCommonAncestor235(
        TreeNode* root, TreeNode* p, TreeNode* q
    ) {
        if (!root) {
            return NULL;
        }

        if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor235(root->right, p, q);
        }

        if (root->val > max(p->val, q->val)) {
            return lowestCommonAncestor235(root->left, p, q);
        }

        return root;
    }

    // 236. Lowest Common Ancestor of a Binary Tree
    TreeNode* lowestCommonAncestor236(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }

        TreeNode * left = lowestCommonAncestor236(root->left, p, q);
        TreeNode * right = lowestCommonAncestor236(root->right, p, q);

        if (left && right) {
            return root;
        } else {
            return left ? left : right;
        }
    }

    // 238. Product of Array Except Self
    vector<int> productExceptSelf238(vector<int>& nums) {
        vector<int> forward(nums.size(), 1);
        vector<int> backward(nums.size(), 1);
        vector<int> result(nums.size(), 1);

        for (int i = 0; i < nums.size() - 1; ++i) {
            forward[i + 1] = forward[i] * nums[i];
        }
        for (int i = nums.size() - 1; i > 0; --i) {
            backward[i - 1] = backward[i] * nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = forward[i] * backward[i];
        }

        return result;
    }

    // 239. Sliding Window Maximum
    vector<int> maxSlidingWindow239(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            while (!heap.empty() && heap.top().second <= i - k) {
                heap.pop();
            }
            heap.push({nums[i], i});
            if (i >= k - 1) {
                result.push_back(heap.top().first);
            }
        }

        return result;
    }

    // 240. Search a 2D Matrix II
    bool searchMatrix240(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        if (target < matrix[0][0] || target > matrix.back().back()) {
            return false;
        }

        int i = matrix.size() - 1, j = 0;
        while (true) {
            if (target > matrix[i][j]) {
                j++;
            } else if (target < matrix[i][j]) {
                i--;
            } else {
                return true;
            }
            if (i < 0 || j >= matrix[0].size()) {
                break;
            }
        }
        return false;
    }

    // 241. Different Ways to Add Parentheses
    vector<int> diffWaysToCompute241(string input) {
        vector<int> result;

        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute241(input.substr(0, i));
                vector<int> right = diffWaysToCompute241(input.substr(i + 1));

                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        switch (input[i]) {
                        case '+':
                            result.push_back(left[j] + right[k]);
                            break;
                        case '-':
                            result.push_back(left[j] - right[k]);
                            break;
                        case '*':
                            result.push_back(left[j] * right[k]);
                            break;
                        default:
                            assert(false);
                        }
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(input));
        }

        return result;
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

    // 243. Shortest Word Distance
    int shortestDistance243(vector<string>& words, string word1, string word2) {
        vector<int> idx1;
        vector<int> idx2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                idx1.push_back(i);
            }
            if (words[i] == word2) {
                idx2.push_back(i);
            }
        }

        int result = INT_MAX;
        for (int m = 0; m < idx1.size(); ++m) {
            for (int n = 0; n < idx2.size(); ++n) {
                result = min(result, abs(idx1[m] - idx2[n]));
            }
        }
        return result;
    }

    // 244. Shortest Word Distance II
    class WordDistance244 {
    public:
        WordDistance244(vector<string>& words) {
            for (int i = 0; i < words.size(); ++i) {
                strIdxMap[words[i]].push_back(i);
            }
        }
        
        int shortest(string word1, string word2) {
            int a = 0, b = 0;
            int result = INT_MAX;
            while (a < strIdxMap[word1].size() && b < strIdxMap[word2].size()) {
                result = min(result, abs(strIdxMap[word1][a] - strIdxMap[word2][b]));
                (strIdxMap[word1][a] < strIdxMap[word2][b]) ? ++a : ++b;
            }

            return result;
        }

    private:
        unordered_map<string, vector<int>> strIdxMap;
    };

    // 245. Shortest Word Distance III
    int shortestWordDistance245(
        vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1;
        int result = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            int temp = pos1;
            if (words[i] == word1) {
                pos1 = i;
            }
            if (words[i] == word2) {
                pos2 = i;
            }

            if (pos1 != -1 && pos2 != -1) {
                if (word1 == word2 && temp != -1 && temp != pos1) {
                    result = min(result, pos1 - temp);
                } else if (pos1 != pos2) {
                    result = min(result, abs(pos2 - pos1));
                }
            }
        }

        return result;
    }

    // 247. Strobogrammatic Number II
    vector<string> findStrobogrammatic247(int n) {
        return find_by_level(n, n);
    }

    vector<string> find_by_level(int cur_level, int n) {
        if (cur_level == 0) {
            return {""};
        }

        if (cur_level == 1) {
            return {"0", "1", "8"};
        }

        vector<string> lower_level_result = find_by_level(cur_level - 2, n);
        vector<string> result;

        for (int i = 0; i < lower_level_result.size(); ++i) {
            string str = lower_level_result[i];
            if (cur_level != n) {
                result.push_back("0" + str + "0");
            }
            result.push_back("1" + str + "1");
            result.push_back("6" + str + "9");
            result.push_back("8" + str + "8");
            result.push_back("9" + str + "6");
        }

        return result;
    }

    // 250. Count Univalue Subtrees
    int countUnivalSubtrees250(TreeNode* root) {
        int result = 0;
        is_unival(root, -1, result);
        return result;
    }

    bool is_unival(TreeNode * cur, int val, int &result) {
        if (!cur) {
            return true;
        }

        bool is_left_univ = is_unival(cur->left, cur->val, result);
        bool is_right_univ = is_unival(cur->right, cur->val, result);
        if (!is_left_univ || !is_right_univ) {
            return false;
        }

        ++result;
        return cur->val == val;
    }

    // 251. Flatten 2D Vector
    class Vector2D251 {
    public:
        Vector2D251(vector<vector<int>>& v) 
            : d_vec(v), a(0), b(0) { }
        
        int next() {
            hasNext();
            int result = d_vec[a][b];
            ++b;
            return result;
        }
        
        bool hasNext() {
            while (a < d_vec.size() && b == d_vec[a].size()) {
                ++a;
                b = 0;
            }
            
            return a < d_vec.size();
        }
        
    private:
        vector<vector<int>> d_vec;
        int a;
        int b;
    };

    // 252. Meeting Rooms
    bool canAttendMeetings252(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return true;
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        
        return true;
    }

    // 253. Meeting Rooms II
    int minMeetingRooms253(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [] (const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
            }
        );

        priority_queue<int, vector<int>, greater<int>> end_pq;
        for (int i = 0; i < intervals.size(); ++i) {
            if (!end_pq.empty() && intervals[i][0] >= end_pq.top()) {
                end_pq.pop();
            }
            end_pq.push(intervals[i][1]);
        }

        return end_pq.size();
    }

    // 255. Verify Preorder Sequence in Binary Search Tree
    bool verifyPreorder255(vector<int>& preorder) {
        int min_val = INT_MIN;
        stack<int> minval_stk;
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] < min_val) {
                return false;
            }
            while (!minval_stk.empty() && preorder[i] > minval_stk.top()) {
                min_val = minval_stk.top();
                minval_stk.pop();
            }

            minval_stk.push(preorder[i]);
        }
        return true;
    }

    // 256. Paint House
    int minCost256(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) {
            return 0;
        }

        vector<vector<int>> dp = costs;
        for (int i = 1; i < costs.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3])
                    + costs[i][j];
            }
        }

        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }

    // 257. Binary Tree Paths
    vector<string> binaryTreePaths257(TreeNode* root) {
        vector<string> result;
        if (!root) {
            return result;
        }
        binaryTreePaths257DFS(root, "", result);
        return result;
    }

    void binaryTreePaths257DFS(
        TreeNode * cur, string cur_str, vector<string> &all_result
    ) {
        if (!cur->left && !cur->right) {
            all_result.push_back(cur_str + to_string(cur->val));
        }
        string next = cur_str + to_string(cur->val) + "->";
        if (cur->left) {
            binaryTreePaths257DFS(cur->left, next, all_result);
        }
        if (cur->right) {
            binaryTreePaths257DFS(cur->right, next, all_result);
        }
    }

    // 261. Graph Valid Tree
    bool validTree261(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        if (!validTree261DFS(graph, visited, 0, -1)) {
            return false;
        }

        for (int i = 0; i < visited.size(); ++i) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

    bool validTree261DFS(
        const vector<vector<int>>& graph, vector<bool>& visited, 
        int cur, int pre
    ) {
        if (visited[cur]) {
            return false;
        }

        visited[cur] = true;
        for (int i = 0; i < graph[cur].size(); ++i) {
            if (graph[cur][i] == pre) {
                continue;
            }

            if (!validTree261DFS(graph, visited, graph[cur][i], cur)) {
                return false;
            }
        }
        return true;
    }

    // 268. Missing Number
    int missingNumber268(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result ^= ((i+1) ^ nums[i]);
        }
        return result;
    }

    // 269. Alien Dictionary
    string alienOrder269(vector<string>& words) {
        set<pair<char, char>> graph;
        for (int i = 0; i < words.size() - 1; ++i) {
            int min_len = min(words[i].size(), words[i + 1].size());
            int j = 0;
            for (; j < min_len; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    graph.insert({words[i][j], words[i + 1][j]});
                    break;
                }
            }

            // Pay attention to the following corner case; 
            // abcd -> abc should return ""
            if (j == min_len && words[i].size() > words[i + 1].size()) {
                return "";
            }
        }

        unordered_set<char> all_alpha;
        for (auto w : words) {
            all_alpha.insert(w.begin(), w.end());
        }

        unordered_map<char, int> node_in_edge_map;
        for (auto edge : graph) {
            node_in_edge_map[edge.second]++;
        }
        queue<char> bfs_queue;
        for (auto node : all_alpha) {
            if (!node_in_edge_map[node]) {
                bfs_queue.push(node);
            }
        }

        string result = "";
        while (!bfs_queue.empty()) {
            char cur = bfs_queue.front();
            bfs_queue.pop();
            result.push_back(cur);

            for (auto iter : graph) {
                if (iter.first == cur) {
                    node_in_edge_map[iter.second]--;
                    if (!node_in_edge_map[iter.second]) {
                        bfs_queue.push(iter.second);
                    }
                }
            }
        }

        return (result.size() == all_alpha.size()) ? result : "";
    }

    // 271. Encode and Decode Strings
    string encode271(vector<string>& strs) {
        string result;
        for (auto str: strs) {
            result += to_string(str.size()) + "/" + str;
        }
        return result;
    }

    vector<string> decode271(string s) {
        int i = 0;
        vector<string> result;
        while (i < s.size()) {
            int slash_idx = s.find('/', i);
            int length = stoi(s.substr(i, slash_idx - i));
            string cur_str = s.substr(slash_idx + 1, length);
            result.push_back(cur_str);
            i = length + slash_idx + 1;
        }

        return result;
    }

    // 272. Closest Binary Search Tree Value II
    vector<int> closestKValues272(TreeNode* root, double target, int k) {
        vector<int> result;
        if (!root) {
            return result;
        }
        
        closestKValues272InorderDFS(result, root, target, k);
        return result;
    }

    void closestKValues272InorderDFS(
        vector<int> &result, TreeNode * cur, const double target, const int k
    ) {
        if (!cur) {
            return;
        }

        closestKValues272InorderDFS(result, cur->left, target, k);

        if (result.size() < k) {
            result.push_back(cur->val);
        } else {
            if (abs(cur->val - target) < abs(result[0] - target)) {
                result.push_back(cur->val);
                result.erase(result.begin());
            }
            else {
                return;
            }
        }
    
        closestKValues272InorderDFS(result, cur->right, target, k);
    }

    // 273. Integer to English Words
    string numberToWords273(int num) {
        string result = convert_three_digit(num % 1000);

        vector<string> three_zeros = {
            "Thousand", "Million", "Billion"
        };

        for (int i = 0; i < 3; ++i) {
            num /= 1000;
            if (num % 1000) {
                result = convert_three_digit(num % 1000) + " " + three_zeros[i]
                    + " " + result;
            }
        }

        while (result.back() == ' ') {
            result.pop_back();
        }

        return (result.length() == 0) ? "Zero" : result;
    }

    string convert_three_digit(int three_digit) {
        string result;
        vector<string> less_than_20 = {
            "",
            "One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        vector<string> tens = {
            "", 
            "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };

        int hundred_digit = three_digit / 100;
        if (hundred_digit != 0) {
            result += less_than_20[hundred_digit] + " Hundred";
        }

        int ten_digit = (three_digit % 100) / 10;
        int last_digit = three_digit % 10;

        if (ten_digit == 0 && last_digit == 0) {
            return result;
        }
        else if (ten_digit < 2) {
            result += (result.empty() ? "" : " ") 
                + less_than_20[ten_digit * 10 + last_digit];
        }
        else {
            result += (result.empty() ? "" : " ") + tens[ten_digit];
            
            if (last_digit) {
                result += " " + less_than_20[last_digit];
            }
        }

        return result;
    }

    // 274. H-Index
    int hIndex274(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] < i + 1) {
                return i;
            }
        }
        
        return citations.size();
    }

    // 277. Find the Celebrity
    bool knows277(int a, int b) {
        vector<vector<bool>> knows = {
            {true, true, false},
            {false, true, false},
            {true, true, true}
        };
        return knows[a][b];
    }

    int findCelebrity277(int n) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (knows277(result, i)) {
                result = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != result) {
                if (knows277(result, i) || !knows277(i, result)) {
                    return -1;
                }
            }
        }
        return result;
    }

    // 278. First Bad Version
    bool isBadVersion(int version) {
        return (version >= 5);
    }

    int firstBadVersion278(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    // 279. Perfect Squares
    int numSquares279(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }

    // 280. Wiggle Sort
    void wiggleSort280(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || 
                (i % 2 == 0 && nums[i] > nums[i - 1])) 
            {
                swap(nums[i], nums[i - 1]);       
            }
        }
    }

    // 282. Expression Add Operators
    vector<string> addOperators282(string num, int target) {
        vector<string> result;
        if (num.empty()) {
            return result;
        }
        addOperators282Rec(num, target, 0, 0, "", result);
        return result;
    }

    void addOperators282Rec(
        string num, const int target, long cur_num, long diff, 
        string cur_res, vector<string> & all_res
    ) {
        if (num.size() == 0 && cur_num == target) {
            all_res.push_back(cur_res);
            return;
        }

        for (int i = 1; i <= num.size(); ++i) {
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') {
                return;
            }

            string next = num.substr(i);
            if (cur_res.empty()) {
                addOperators282Rec(next, target, stoll(cur), stoll(cur), cur, all_res);
            } else {
                addOperators282Rec(
                    next, target, cur_num + stoll(cur), stoll(cur), 
                    cur_res + "+" + cur, all_res
                );
                addOperators282Rec(
                    next, target, cur_num - stoll(cur), -stoll(cur), 
                    cur_res + "-" + cur, all_res
                );
                addOperators282Rec(
                    next, target, cur_num - diff + diff * stoll(cur), 
                    diff * stoll(cur), cur_res + "*" + cur, all_res
                );
            }
        }
    }

    // 283. Move Zeroes
    void moveZeroes283(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                nums[left] = nums[right];
                ++left;
            }
            ++right;
        }

        while (left < nums.size()) {
            nums[left] = 0;
            ++left;
        }
    }

    // 286. Walls and Gates
    void wallsAndGates286(vector<vector<int>>& rooms) {
        for (int i = 0; i < rooms.size(); ++i) {
            for (int j = 0; j < rooms[i].size(); ++j) {
                if (rooms[i][j] == 0) {
                    wallsAndGates286_dfs(rooms, i, j, 0);
                }
            }
        }
    }

    void wallsAndGates286_dfs(
        vector<vector<int>> & rooms, int x, int y, int next_dist
    ) {
        if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size()) {
            return;
        }
        if (rooms[x][y] < next_dist) {
            return;
        }

        rooms[x][y] = next_dist;
        wallsAndGates286_dfs(rooms, x + 1, y, next_dist + 1);
        wallsAndGates286_dfs(rooms, x, y + 1, next_dist + 1);
        wallsAndGates286_dfs(rooms, x - 1, y, next_dist + 1);
        wallsAndGates286_dfs(rooms, x, y - 1, next_dist + 1);
    }

    // 284. Peeking Iterator
    class Iterator {
    public:
        struct Data {
            vector<int> d_arr;

            Data(vector<int> nums) {
                d_arr.clear();
                for (auto i : nums) {
                    d_arr.push_back(i);
                }
            }
        };

        Data* data;

        int d_idx;

    public:
        Iterator(const vector<int>& nums) {
            data = new Data(nums);
            d_idx = 0;
        }

        Iterator(const Iterator& iter) { }

        virtual ~Iterator() { }

        // Returns the next element in the iteration.
        int next() {
            int result = data->d_arr[d_idx];
            d_idx++;
            return result;
        }

        // Returns true if the iteration has more elements.
        bool hasNext() const {
            return (d_idx < data->d_arr.size());
        }
    };

    class PeekingIterator284 : public Iterator {
    public:
        PeekingIterator284(const vector<int>& nums) : Iterator(nums) {
            d_peek = false;
        }

        // Returns the next element in the iteration without advancing the iterator.
        int peek() {
            if (!d_peek) {
                d_cur_peek = Iterator::next();
                d_peek = true;
            }

            return d_cur_peek;
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next() {
            if (d_peek) {
                d_peek = false;
                return d_cur_peek;
            } else {
                return Iterator::next();
            }
        }

        bool hasNext() const {
            return d_peek || Iterator::hasNext();
        }

    private:
        int d_cur_peek;
        bool d_peek;
    };

    // 287. Find the Duplicate Number
    int findDuplicate287(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int ct = 0;
            for (auto num: nums) {
                if (num <= mid) {
                    ++ct;
                }
            }

            if (ct <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }

    // 289. Game of Life
    void gameOfLife289(vector<vector<int>>& board) {
        const vector<pair<int, int>> direc = {
            {0, 1}, {1, 1}, {1, 0}, {1, -1},
            {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
        };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int live_cell_ct = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + direc[k].first;
                    int y = j + direc[k].second;
                    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                        continue;
                    }
                    if (board[x][y] == 1 || board[x][y] == 2) {
                        ++live_cell_ct;
                    }
                }

                if (board[i][j] == 1 && (live_cell_ct < 2 || live_cell_ct > 3)) {
                    board[i][j] = 2;
                } else if (board[i][j] == 0 && live_cell_ct == 3) {
                    board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] %= 2;
            }
        }
    }

    // 291. Word Pattern II
    bool wordPatternMatch291(string pattern, string str) {
        unordered_map<char, string> charWordMap;
        return wordPatternMatch291_rec(pattern, 0, str, 0, charWordMap);
    }

    bool wordPatternMatch291_rec(
        string const pattern, int pIdx, string const str, int sIdx,
        unordered_map<char, string> &charWordMap
    ) {
        if (pIdx == pattern.size() && sIdx == str.size()) {
            return true;
        }

        if (pIdx == pattern.size() || sIdx == str.size()) {
            return false;
        }

        char c = pattern[pIdx];
        for (int i = sIdx; i < str.size(); ++i) {
            string curWord = str.substr(sIdx, i - sIdx + 1);
            if (charWordMap.count(c) && charWordMap[c] == curWord) {
                if (wordPatternMatch291_rec(pattern, pIdx + 1, str, i + 1, charWordMap)) {
                    return true;
                }
            } else if (!charWordMap.count(c)) {
                bool isFound = false;
                for (auto it: charWordMap) {
                    if (curWord == it.second) {
                        isFound = true;
                    }
                }

                if (!isFound) {
                    charWordMap[c] = curWord;
                    if (wordPatternMatch291_rec(pattern, pIdx + 1, str, i + 1, charWordMap)) {
                        return true;
                    }
                    charWordMap.erase(c);
                }
            }
        }

        return false;
    }

    // 295. Find Median from Data Stream
    class MedianFinder295 {
    public:
        MedianFinder295() { }
        
        void addNum(int num) {
            small.push(num);
            large.push(-small.top());
            small.pop();

            while (small.size() < large.size()) {
                small.push(-large.top());
                large.pop();
            }
        }
        
        double findMedian() {
            if (small.size() == large.size()) {
                return 0.5 * (small.top() - large.top());
            } else {
                return small.top();
            }
        }

    private:
        priority_queue<int> small, large;
    };

    // 296. Best Meeting Point
    int minTotalDistance296(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return vector_min_dist(rows) + vector_min_dist(cols);
    }

    int vector_min_dist(vector<int> & arr) {
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1;
        int result = 0;
        while (i < j) {
            result += arr[j] - arr[i];
            j--;
            i++;
        }
        return result;
    }

    // 297. Serialize and Deserialize Binary Tree
    class Codec297 {
    public:
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            if (!root) {
                return "";
            }

            ostringstream out;
            queue<TreeNode *> node_q;
            node_q.push(root);

            while (!node_q.empty()) {
                TreeNode * cur = node_q.front();
                node_q.pop();
                if (cur) {
                    out << to_string(cur->val) << " ";
                    node_q.push(cur->left);
                    node_q.push(cur->right);
                } else {
                    out << "# ";
                }
            }

            return out.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            if (data.empty()) {
                return NULL;
            }

            istringstream in(data);
            string cur_str;
            in >> cur_str;
            int cur_val = stoi(cur_str);
            TreeNode * root = new TreeNode(cur_val);
            queue<TreeNode *> node_q;
            node_q.push(root);
            while (!node_q.empty()) {
                TreeNode * cur = node_q.front();
                node_q.pop();

                string next_left;
                if (!(in >> next_left)) {
                    break;
                }
                if (next_left != "#") {
                    int left_val = stoi(next_left);
                    cur->left = new TreeNode(left_val);
                    node_q.push(cur->left);
                }
                
                string next_right;
                if (!(in >> next_right)) {
                    break;
                }
                if (next_right != "#") {
                    int right_val = stoi(next_right);
                    cur->right = new TreeNode(right_val);
                    node_q.push(cur->right);
                }
            }

            return root;
        }
    };

    // 300. Longest Increasing Subsequence
    int lengthOfLIS300(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

#endif