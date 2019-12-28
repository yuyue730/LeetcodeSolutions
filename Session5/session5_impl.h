#ifndef _SESSION_5_IMPL_H
#define _SESSION_5_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
using namespace std;

// Definition for a Binary Tree Node with pointer to parent.
class Node510 {
public:
    int val;
    Node510* left;
    Node510* right;
    Node510* parent;
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Session5Impl {
public:
    Session5Impl() {
        cout << "Impl object for Leetcode Session 5 problems constructed.\n";
    }

    // 503. Next Greater Element II
    vector<int> nextGreaterElements503(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> stk;

        for (int i = 0; i < n * 2; ++i) {
            int curNum = nums[i % n];
            while (!stk.empty() && nums[stk.top()] < curNum) {
                result[stk.top()] = curNum;
                stk.pop();
            }

            if (i < n) {
                stk.push(i);
            }
        }

        return result;
    }

    // 505. The Maze II
    int shortestDistance505(
        vector<vector<int>>& maze, vector<int>& start, 
        vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) {
            return -1;
        }

        const int m = maze.size();
        const int n = maze[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        vector<vector<int>> const direction = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
        };
        distance[start[0]][start[1]] = 0;
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (auto iter: direction) {
                int x = cur.first;
                int y = cur.second;
                int curDist = distance[cur.first][cur.second];
                
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                    x += iter[0];
                    y += iter[1];
                    curDist++;
                }

                x -= iter[0];
                y -= iter[1];
                curDist--;

                if (curDist < distance[x][y]) {
                    distance[x][y] = curDist;
                    if (x != destination[0] || y != destination[1]) {
                        q.push({x, y});
                    }
                }
            }
        }

        return (distance[destination[0]][destination[1]] == INT_MAX) 
            ? -1 : distance[destination[0]][destination[1]];
    }

    // 508. Most Frequent Subtree Sum
    vector<int> findFrequentTreeSum508(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> sumFreqMap;
        int curCnt = 0;
        findFrequentTreeSum508_postorder(root, sumFreqMap, curCnt, result);
        return result;
    }

    int findFrequentTreeSum508_postorder(
        TreeNode *cur, unordered_map<int, int> &sumFreqMap, 
        int &curCnt, vector<int> &result) {
        if (!cur) {
            return 0;
        }

        int left = findFrequentTreeSum508_postorder(cur->left, sumFreqMap, curCnt, result);
        int right = findFrequentTreeSum508_postorder(cur->right, sumFreqMap, curCnt, result);

        int curSum = left + right + cur->val;
        sumFreqMap[curSum]++;
        if (sumFreqMap[curSum] >= curCnt) {
            if (sumFreqMap[curSum] > curCnt) {
                result.clear();
            }

            curCnt = sumFreqMap[curSum];
            result.push_back(curSum);
        }

        return curSum;
    }

    // 509. Fibonacci Number
    int fib509(int N) {
        if (N == 0) {
            return 0;
        }
        
        vector<int> result(N + 1, -1);
        result[0] = 0; result[1] = 1;
        for (int i = 2; i <= N; ++i) {
            result[i] = result[i - 1] + result[i - 2];
        }
        
        return result[N];
    }

    // 510. Inorder Successor in BST II
    Node510* inorderSuccessor510(Node510* node) {
        if (!node) {
            return nullptr;
        }

        if (node->right) {
            Node510 * cur = node->right;
            while (cur->left) {
                cur = cur->left;
            }

            return cur;
        }

        Node510* cur = node;
        while (cur) {
            if (!cur->parent) {
                return nullptr;
            }
            if (cur == cur->parent->left) {
                return cur->parent;
            }
            cur = cur->parent;
        }

        return nullptr;
    }

    // 513. Find Bottom Left Tree Value
    int findBottomLeftValue513(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        TreeNode* result = root;
        queue<TreeNode*> q({root});
        
        while (!q.empty()) {
            int qSize = q.size();
            result = q.front();
            
            for (int i = 0; i < qSize; ++i) {
                TreeNode * tmp = q.front();
                q.pop();
                if (tmp->left) {
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    q.push(tmp->right);
                }
            }
        }
        
        return result->val;
    }

    // 514. Freedom Trail
    int findRotateSteps514(string ring, string key) {
        if (key.empty() || ring.empty()) {
            return 0;
        }

        vector<vector<int>> charPosMap(26);
        for (int i = 0; i < ring.size(); ++i) {
            charPosMap[ring[i] - 'A'].push_back(i);
        }

        int rSize = ring.size(), kSize = key.size();
        vector<vector<int>> state(rSize, vector<int>(kSize, 0));
        return findRotateSteps514_dfs(ring, key, 0, 0, charPosMap, state);
    }

    int findRotateSteps514_dfs(
        const string& ring, const string& key, int x, int y,
        const vector<vector<int>> & charPosMap,
        vector<vector<int>> & state)
    {
        if (y == key.size()) {
            return 0;
        }
        if (state[x][y]) {
            return state[x][y];
        }
        const int rSize = ring.size();
        int result = INT_MAX;
        for (int nextPos: charPosMap[key[y] - 'A']) {
            int dist = abs(nextPos - x);
            int step = min(dist, rSize - dist);
            result = min(
                result, 
                step + findRotateSteps514_dfs(
                    ring, key, nextPos, y + 1, charPosMap, state));
        }
        state[x][y] = result + 1;
        return state[x][y];
    }

    // 515. Find Largest Value in Each Tree Row
    vector<int> largestValues515(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        
        queue<TreeNode *> q({root});
        while (!q.empty()) {
            int qSize = q.size();
            int curMax = INT_MIN;
            for (int i = 0; i < qSize; ++i) {
                TreeNode * cur = q.front();
                if (cur->val > curMax) {
                    curMax = cur->val;
                }
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            
            result.push_back(curMax);
        }
        
        return result;
    }

    // 516. Longest Palindromic Subsequence
    int longestPalindromeSubseq516(string s) {
        int sSize = s.size();
        vector<vector<int>> dp(sSize, vector<int>(sSize, 0));
        for (int i = sSize - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < sSize; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][sSize - 1];
    }

    // 517. Super Washing Machines
    int findMinMoves517(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int mSize = machines.size();
        if (sum % mSize != 0) {
            return -1;
        }
        int average = sum / mSize;
        int cnt = 0, result = 0;
        for (int curLoad: machines) {
            int curDiff = curLoad - average;
            cnt += curDiff;
            result = max(result, max(abs(cnt), curDiff));
        }
        return result;
    }

    // 518. Coin Change 2
    int change518(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); ++i) {
            dp[i][0] = 1;
            for (int j = 1; j < amount + 1; ++j) {
                dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
            }
        }
        return dp[coins.size()][amount];
    }

    // 519. Random Flip Matrix
    class Solution519 {
    public:
        Solution519(int n_rows, int n_cols)
          : d_row(n_rows), d_col(n_cols) { }
        
        vector<int> flip() {
            while (true) {
                int randIdx = rand() % (d_row * d_col);
                if (!d_inserted.count(randIdx)) {
                    d_inserted.insert(randIdx);
                    return {randIdx / d_col, randIdx % d_col};
                }
            }
        }
        
        void reset() {
            d_inserted.clear();
        }

    private:
        int d_row, d_col;
        unordered_set<int> d_inserted;
    };

    // 523. Continuous Subarray Sum
    bool checkSubarraySum523(vector<int>& nums, int k) {
        int pre = 0, sum = 0;
        unordered_set<int> remainSet;
        for (auto num: nums) {
            sum += num;
            int curRemain = (k == 0) ? sum : (sum % k);
            if (remainSet.count(curRemain)) {
                return true;
            }
            remainSet.insert(pre);
            pre = curRemain;
        }

        return false;
    }

    // 524. Longest Word in Dictionary through Deleting
    string findLongestWord524(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string a, string b) {
            if (a.size() == b.size()) {
                return a < b;
            } 
            return a.size() > b.size();
        });

        for (auto word: d) {
            int wIdx = 0, sIdx = 0;
            while (sIdx < s.length() && wIdx < word.length()) {
                if (s[sIdx] == word[wIdx]) {
                    wIdx++;
                }
                sIdx++;
            }

            if (wIdx == word.length()) {
                return word;
            }
        }

        return "";
    }

    // 525. Contiguous Array
    int findMaxLength525(vector<int>& nums) {
        unordered_map<int, int> offsetMap;
        offsetMap[0] = -1;
        int sum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 1) ? 1 : -1;
            if (offsetMap.count(sum)) {
                result = max(result, i - offsetMap[sum]);
            }
            else {
                offsetMap[sum] = i;
            }
        }
        
        return result;
    }

    // 526. Beautiful Arrangement
    int countArrangement526(int N) {
        int result = 0;
        vector<bool> visited(N + 1, false);
        countArrangement_dfs(N, 1, visited, result);
        return result;
    }
    
    void countArrangement_dfs(int N, int curPos, vector<bool> &visited, int &result) {
        if (curPos > N) {
            result++;
            return;
        }
        
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && (i % curPos == 0 || curPos % i == 0)) {
                visited[i] = true;
                countArrangement_dfs(N, curPos + 1, visited, result);
                visited[i] = false;
            }
        }
    }

    // 527. Word Abbreviation
    vector<string> wordsAbbreviation527(vector<string>& dict) {
        const int nDict = dict.size();
        vector<string> result(nDict);
        vector<int> lengthPre(nDict, 1);

        for (int i = 0; i < nDict; ++i) {
            result[i] = abbreviate(dict[i], 1);
        }

        for (int i = 0; i < nDict; ++i) {
            while (true) {
                unordered_set<int> duplicateSet;
                for (int j = i + 1; j < nDict; ++j) {
                    if (result[j] == result[i]) {
                        duplicateSet.insert(j);
                    }
                }

                if (duplicateSet.empty()) {
                    break;
                }
                duplicateSet.insert(i);
                for (auto dupIndex: duplicateSet) {
                    lengthPre[dupIndex]++;
                    result[dupIndex] = abbreviate(dict[dupIndex], lengthPre[dupIndex]);
                }
            }
        }

        return result;
    }

    string abbreviate(const string word, int preLength) {
        return (preLength >= (word.size() - 2))
            ? word
            : word.substr(0, preLength) + to_string(word.size() - preLength - 1)
                + word.back();
    }

    // 528. Random Pick with Weight
    class Solution528 {
    public:
        Solution528(vector<int>& w) {
            sumWeight.resize(w.size());
            sumWeight[0] = w[0];
            
            for (int i = 1; i < w.size(); ++i) {
                sumWeight[i] = sumWeight[i - 1] + w[i];
            }
        }
        
        int pickIndex() {
            int x = rand() * sumWeight.back();
            int left = 0, right = sumWeight.size() - 1;

            while (left < right) {
                int mid = (left + right) / 2;
                if (sumWeight[mid] <= x) {
                    left = mid + 1;
                }
                else {
                    right = mid;
                }
            }

            return right;
        }
    
    private:
        vector<int> sumWeight;
    };

    // 529. Minesweeper
    vector<vector<char>> updateBoard529(
        vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) {
            return {};
        }

        int x = click[0], y = click[1];
        int m = board.size(), n = board[0].size();
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        }
        else {
            int countMine = 0;
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int nextX = x + i, nextY = y + j;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
                        continue;
                    }

                    if (board[nextX][nextY] == 'M') {
                        countMine++;
                    }
                }
            }

            if (countMine > 0) {
                board[x][y] = '0' + countMine;
            }
            else {
                board[x][y] = 'B';
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        int nextX = x + i, nextY = y + j;
                        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
                            continue;
                        }

                        if (board[nextX][nextY] == 'E') {
                            vector<int> nextClick = {nextX, nextY};
                            updateBoard529(board, nextClick);
                        }
                    }
                }
            }
        }

        return board;
    }
};

#endif