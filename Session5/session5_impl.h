#ifndef _SESSION_5_IMPL_H
#define _SESSION_5_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <sstream>
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

// Definition for a N-ary Tree Node.
class Node559 {
public:
    int val;
    vector<Node559*> children;

    Node559() {}

    Node559(int _val) {
        val = _val;
    }

    Node559(int _val, vector<Node559*> _children) {
        val = _val;
        children = _children;
    }
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

    // 530. Minimum Absolute Difference in BST
    int getMinimumDifference530(TreeNode* root) {
        int result = INT_MAX, preVal = -1;
        getMinimumDifference530_inorder(root, preVal, result);
        return result;
    }

    void getMinimumDifference530_inorder(TreeNode* cur, int& pre, int& result) {
        if (!cur) {
            return;
        }

        getMinimumDifference530_inorder(cur->left, pre, result);
        if (pre != -1) {
            result = min(result, cur->val - pre);
        }
        pre = cur->val;
        getMinimumDifference530_inorder(cur->right, pre, result);
    }

    // 531. Lonely Pixel I
    int findLonelyPixel531(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rowBlackMap(m, 0);
        vector<int> colBlackMap(n, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    rowBlackMap[i]++;
                    colBlackMap[j]++;
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' 
                    && rowBlackMap[i] == 1 && colBlackMap[j] == 1) {
                    result++;
                }
            }
        }
        return result;
    }

    // 536. Construct Binary Tree from String
    TreeNode* str2tree536(string s) {
        if (s.empty()) {
            return NULL;
        }

        int firstLeftBracket = s.find_first_of('(');
        int curVal = (firstLeftBracket == string::npos)
            ? stoi(s) : stoi(s.substr(0, firstLeftBracket));
        
        TreeNode* root = new TreeNode(curVal);
        if (firstLeftBracket == string::npos) {
            return root;
        }

        int left = firstLeftBracket;
        int count = 0;

        for (int i = firstLeftBracket; i < s.size(); ++i) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }

            if (count == 0 && left == firstLeftBracket) {
                root->left = str2tree536(s.substr(left + 1, i - left - 1));
                left = i + 1;
            } else if (count == 0) {
                root->right = str2tree536(s.substr(left + 1, i - left - 1));
            }
        }

        return root;
    }

    // 538. Convert BST to Greater Tree
    TreeNode* convertBST538(TreeNode* root) {
        int sum = 0;
        convertBST_inorder_reverse(root, sum);
        return root;
    }
    
    void convertBST_inorder_reverse(TreeNode* cur, int& sum) {
        if (!cur) {
            return;
        }
        
        convertBST_inorder_reverse(cur->right, sum);
        sum += cur->val;
        cur->val = sum;
        convertBST_inorder_reverse(cur->left, sum);
    }

    // 539. Minimum Time Difference
    int findMinDifference539(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int result = INT_MAX;
        int ptsSize = timePoints.size();
        
        for (int i = 0; i < ptsSize; ++i) {
            int l = i, r = (i + 1) % ptsSize;
            int h_l = (timePoints[l][0] - '0') * 10 + (timePoints[l][1] - '0');
            int m_l = (timePoints[l][3] - '0') * 10 + (timePoints[l][4] - '0');
            int h_r = (timePoints[r][0] - '0') * 10 + (timePoints[r][1] - '0');
            int m_r = (timePoints[r][3] - '0') * 10 + (timePoints[r][4] - '0');
            
            int diff = (h_r - h_l) * 60 + (m_r - m_l);
            if (i == ptsSize - 1) {
                diff += 24 * 60;
            }
            
            result = min(result, diff);
        }
        
        return result;
    }

    // 540. Single Element in a Sorted Array
    int singleNonDuplicate540(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int left = 0, right = nums.size() - 1;
        int nSize = nums.size();

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == nums[mid + 1]) {
                if ((nSize - mid - 1) % 2 == 1) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (mid == 0 || nums[mid] != nums[mid - 1]) {
                    return nums[mid];
                }
                if ((nSize - mid - 1) % 2 == 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }

        return nums[left];
    }

    // 542. 01 Matrix
    vector<vector<int>> updateMatrix542(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        const vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        queue<pair<int, int>> gridQ;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    gridQ.push({i, j});
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        while (!gridQ.empty()) {
            pair<int, int> cur = gridQ.front();
            gridQ.pop();
            for (int k = 0; k < directions.size(); ++k) {
                int nextX = cur.first + directions[k][0];
                int nextY = cur.second + directions[k][1];
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n
                    || matrix[nextX][nextY] < matrix[cur.first][cur.second] + 1)
                {
                    continue;
                }

                matrix[nextX][nextY] = matrix[cur.first][cur.second] + 1;
                gridQ.push({nextX, nextY});
            }
        }

        return matrix;
    }

    // 543. Diameter of Binary Tree
    int diameterOfBinaryTree543(TreeNode* root) {
        int result = 0;
        diameterOfBinaryTree_postorder(root, result);
        return result;
    }
    
    int diameterOfBinaryTree_postorder(TreeNode* cur, int& result) {
        if (!cur) {
            return 0;
        }
        
        int leftDepth = diameterOfBinaryTree_postorder(cur->left, result);
        int rightDepth = diameterOfBinaryTree_postorder(cur->right, result);
        
        result = max(result, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }

    // 544. Output Contest Matches
    string findContestMatch544(int n) {
        vector<string> strArr(n, "");
        for (int i = 1; i <= n; ++i) {
            strArr[i - 1] = to_string(i);
        }
        
        while (n > 0) {
            for (int i = 0; i < n / 2; ++i) {
                strArr[i] = '(' + strArr[i] + ',' + strArr[n - i - 1] + ')';
            }
            n /= 2;
        }
        
        return strArr[0];
    }

    // 546. Remove Boxes
    int removeBoxes546(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return removeBoxes546_rec(boxes, 0, n - 1, 0, dp);
    }

    int removeBoxes546_rec(
        const vector<int>& boxes, int i, int j, int k,
        vector<vector<vector<int>>> & dp)
    {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] > 0) {
            return dp[i][j][k];
        }

        while (i + 1 <= j && boxes[i + 1] == boxes[i]) {
            i++; k++;
        }

        int result = (k + 1) * (k + 1) + removeBoxes546_rec(boxes, i + 1, j, 0, dp);
        for (int m = i + 1; m <= j; ++m) {
            if (boxes[m] == boxes[i]) {
                result = max(
                    result,
                    removeBoxes546_rec(boxes, i + 1, m - 1, 0, dp) 
                        + removeBoxes546_rec(boxes, m, j, k + 1, dp)
                );
            }
        }

        dp[i][j][k] = result;
        return result;
    }

    // 547. Friend Circles
    int findCircleNum547(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) {
            return 0;
        }

        int result = 0;
        int n = M.size();
        vector<bool> visited(n, false);
        queue<int> Mq;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            
            Mq.push(i);
            while (!Mq.empty()) {
                int cur = Mq.front(); Mq.pop();
                visited[cur] = true;
                for (int j = 0; j < n; ++j) {
                    if (i != j && !visited[j] && (M[cur][j] || M[j][cur]))
                    {
                        Mq.push(j);
                    }
                }
            }
            
            result++;
        }
        
        return result;
    }

    // 548. Split Array with Equal Sum
    bool splitArray548(vector<int>& nums) {
        if (nums.size() < 7) {
            return false;
        }
        
        int n = nums.size();
        vector<int> allSum(n, 0);
        allSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            allSum[i] = allSum[i - 1] + nums[i];
        }
        
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> sumSet;
            for (int i = 1; i < j - 1; ++i) {
                int leftSum = allSum[i - 1];
                int rightSum = allSum[j - 1] - allSum[i];
                if (leftSum == rightSum) {
                    sumSet.insert(leftSum);
                }
            }
            
            for (int k = j + 1; k < n - 1; ++k) {
                int leftSum = allSum[k - 1] - allSum[j];
                int rightSum = allSum[n - 1] - allSum[k];
                if (leftSum == rightSum && sumSet.count(leftSum)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    // 549. Binary Tree Longest Consecutive Sequence II
    int longestConsecutive549(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int maxLength = 1;
        longestConsecutive_rec(root, maxLength);
        return maxLength;
    }
    
    pair<int, int> longestConsecutive_rec(TreeNode * cur, int & maxLength) {
        if (!cur) {
            return {0, 0};
        }
        
        int inc = 1, dec = 1;
        
        if (cur->left) {
            pair<int, int> leftResult
                = longestConsecutive_rec(cur->left, maxLength);
            if (cur->val == cur->left->val + 1) {
                inc = leftResult.first + 1;
            }
            if (cur->val == cur->left->val - 1) {
                dec = leftResult.second + 1;
            }
        }
        
        if (cur->right) {
            pair<int, int> rightResult
                = longestConsecutive_rec(cur->right, maxLength);
            if (cur->val == cur->right->val + 1) {
                inc = max(inc, rightResult.first + 1);
            }
            if (cur->val == cur->right->val - 1) {
                dec = max(dec, rightResult.second + 1);
            }
        }
        
        maxLength = max(maxLength, inc + dec - 1);
        return {inc, dec};
    }

    // 552. Student Attendance Record II
    int checkRecord552(int n) {
        int LIMIT = 1e9 + 7;
        vector<int> total(n, 0);
        vector<int> P(n, 0);
        vector<int> L(n, 0);
        vector<int> A(n, 0);

        P[0] = 1;
        L[0] = 1;
        A[0] = 1;
        
        if (n >= 2) {
            L[1] = 3;
            A[1] = 2;
        }
        
        if (n >= 3) {
            A[2] = 4;
        }

        for (int i = 1; i < n; ++i) {
            P[i] = ((A[i - 1] + P[i - 1]) % LIMIT + L[i - 1]) % LIMIT;
            if (i >= 2) {
                L[i] = ((P[i - 1] + A[i - 1]) % LIMIT 
                    + (P[i - 2] + A[i - 2]) % LIMIT) % LIMIT;
            }
            if (i >= 3) {
                A[i] = ((A[i - 1] + A[i - 2]) % LIMIT + A[i - 3]) % LIMIT;
            }
        }
        
        return ((P[n - 1] + L[n - 1]) % LIMIT + A[n - 1]) % LIMIT;
    }

    // 554. Brick Wall
    int leastBricks554(vector<vector<int>>& wall) {
        unordered_map<int, int> breakHash;
        int maxGap = 0;
        
        for (int i = 0; i < wall.size(); ++i) {
            int curSum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                curSum += wall[i][j];
                ++breakHash[curSum];
                maxGap = max(maxGap, breakHash[curSum]);
            }
        }
        
        return wall.size() - maxGap;
    }

    // 556. Next Greater Element III
    int nextGreaterElement556(int n) {
        string numInStr = to_string(n);
        int pivot = numInStr.size() - 1;
        while (pivot > 0) {
            if (numInStr[pivot] > numInStr[pivot - 1]) {
                break;
            }
            pivot--;
        }

        if (pivot == 0) {
            return -1;
        }

        int toSwap = numInStr.size() - 1;
        while (toSwap >= pivot) {
            if (numInStr[toSwap] > numInStr[pivot - 1]) {
                swap(numInStr[toSwap], numInStr[pivot - 1]);
                break;
            }
            toSwap--;
        }

        reverse(numInStr.begin() + pivot, numInStr.end());
        return stoll(numInStr) > INT_MAX ? -1 : stoi(numInStr);
    }

    // 557. Reverse Words in a String III
    string reverseWords557(string s) {
        istringstream iss(s);
        string result = "", curWord = "";
        
        while (iss >> curWord) {
            reverse(curWord.begin(), curWord.end());
            result += curWord + " ";
        }
        
        result.pop_back();
        return result;
    }

    // 559. Maximum Depth of N-ary Tree
    int maxDepth559(Node559* root) {
        if (!root) {
            return 0;
        }

        queue<Node559*> qNode;
        qNode.push(root);
        int result = 0;

        while (!qNode.empty()) {
            result++;
            int curLevelSize = qNode.size();
            for (int i = 0; i < curLevelSize; ++i) {
                Node559* cur = qNode.front();
                qNode.pop();

                for (int j = 0; j < cur->children.size(); ++j) {
                    qNode.push(cur->children[j]);
                }
            }
        }

        return result;
    }

    // 560. Subarray Sum Equals K
    int subarraySum560(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreqMap;
        sumFreqMap.insert(pair<int, int>(0, 1));
        int curSum = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            result += sumFreqMap[curSum - k];
            ++sumFreqMap[curSum];
        }

        return result;
    }

    // 562. Longest Line of Consecutive One in Matrix
    int longestLine562(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) {
            return 0;
        }

        int result = 0;
        const vector<vector<int>> directions = {
            {1, 0}, {0, 1}, {-1, -1}, {-1, 1}
        };

        int rowSize = M.size(), colSize = M[0].size();

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (M[i][j] == 0) {
                    continue;
                }

                for (int k = 0; k < directions.size(); ++k) {
                    int count = 0;
                    int x = i, y = j;
                    while (x >= 0 && x < rowSize 
                        && y >= 0 && y < colSize && M[x][y] == 1) {
                        count++;
                        x += directions[k][0];
                        y += directions[k][1];
                    }

                    result = max(result, count);
                }
            }
        }

        return result;
    }
};

#endif