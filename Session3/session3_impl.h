#ifndef _SESSION_3_IMPL_H
#define _SESSION_3_IMPL_H

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Session3Impl {
public:
    Session3Impl() {
        cout << "Impl object for Leetcode Session 3 problems constructed.\n";
    }

    // 301. Remove Invalid Parentheses
    vector<string> removeInvalidParentheses301(string s) {
        vector<string> result;
        if (s.empty()) {
            return result;
        }

        queue<string> str_q;
        unordered_set<string> visited;
        str_q.push(s);
        bool is_found = false;

        while (!str_q.empty()) {
            string cur_str = str_q.front();
            str_q.pop();

            if (is_valid_parentheses(cur_str))
            {
                result.push_back(cur_str);
                is_found = true;
            }

            if (is_found) {
                continue;
            }

            for (int i = 0; i < cur_str.size(); ++i) {
                if (cur_str[i] != '(' && cur_str[i] != ')') {
                    continue;
                }

                string next_str = cur_str.substr(0, i) + cur_str.substr(i + 1);
                if (visited.find(next_str) == visited.end()) {
                    visited.insert(next_str);
                    str_q.push(next_str);
                }
            }
        }

        return result;
    }

    bool is_valid_parentheses(string s) {
        int ct = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ct++;
            } else if (s[i] == ')') {
                ct--;
                if (ct < 0) {
                    return false;
                }
            }
        }

        return (ct == 0);
    }

    // 302. Smallest Rectangle Enclosing Black Pixels
    int minArea302(vector<vector<char>>& image, int x, int y) {
        if (image.size() == 0 && image[0].size() == 0) {
            return 0;
        }
        int m = image.size(), n = image[0].size();
        int up = minArea_binarySearch(image, true, 0, x, 0, n, true);
        int down = minArea_binarySearch(image, true, x + 1, m, 0, n, false);
        int left = minArea_binarySearch(image, false, 0, y, up, down, true);
        int right = minArea_binarySearch(image, false, y + 1, n, up, down, false);
        return (down - up) * (right - left);
    }

    int minArea_binarySearch(const vector<vector<char>>& image, bool isHeight, 
        int i, int j, int low, int high, bool isLowToHigh) {
        while (i < j) {
            int K = low, mid = (i + j) / 2;
            while (K < high 
                && (isHeight ? image[mid][K] : image[K][mid]) == '0') {
                ++K;
            }
            if (K < high == isLowToHigh) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }

    // 303. Range Sum Query - Immutable
    class NumArray303 {
    public:
        NumArray303(vector<int>& nums) {
            int n = nums.size();
            d_sumVec.resize(n);
            if (n != 0) {
                d_sumVec[0] = nums[0];
                for (int i = 1; i < n; ++i) {
                    d_sumVec[i] = nums[i] + d_sumVec[i - 1];
                }
            }
        }
        
        int sumRange(int i, int j) {
            if (i >= d_sumVec.size() || j >= d_sumVec.size()) {
                return 0;
            }
            if (i == 0) {
                return d_sumVec[j];
            }
            return d_sumVec[j] - d_sumVec[i - 1];
        }
        
    private:
        vector<int> d_sumVec;
    };

    // 304. Range Sum Query 2D - Immutable
    class NumMatrix304 {
    public:
        NumMatrix304(vector<vector<int>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return;
            }

            d_dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

            for (int i = 1; i <= matrix.size(); ++i) {
                for (int j = 1; j <= matrix[0].size(); ++j) {
                    d_dp[i][j] = d_dp[i - 1][j] + d_dp[i][j - 1] - d_dp[i - 1][j - 1]
                        + matrix[i - 1][j - 1];
                }
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            return d_dp[row2 + 1][col2 + 1] - d_dp[row1][col2 + 1] - d_dp[row2 + 1][col1]
                + d_dp[row1][col1];
        }
    
    private:
        vector<vector<int>> d_dp;
    };

    // 305. Number of Islands II
    class UnionFind {
    public:
        UnionFind(int x) : d_count(0) {
            for (int i = 0; i < x; ++i) {
                d_ranks.push_back(0);
                d_parents.push_back(-1);
            }
        }

        int isValid(int x) {
            return d_parents[x] >= 0;
        }

        void setParent(int x) {
            if (isValid(x)) {
                return;
            }
            d_parents[x] = x;
            d_count++;
        }

        int findRoot(int x) {
            if (d_parents[x] != x) {
                d_parents[x] = findRoot(d_parents[x]);
            }
            return d_parents[x];
        }

        void unionNodes(int x, int y) {
            int rootX = findRoot(x);
            int rootY = findRoot(y);
            if (rootX != rootY) {
                if (d_ranks[rootX] > d_ranks[rootY]) {
                    d_parents[rootY] = rootX;
                }
                else if (d_ranks[rootX] < d_ranks[rootY]) {
                    d_parents[rootX] = rootY;
                }
                else {
                    d_ranks[rootY]++;
                    d_parents[rootX] = rootY;
                }
                d_count--;
            }
        }

        int getCount() {
            return d_count;
        }
        
    private:
        vector<int> d_ranks;
        vector<int> d_parents;
        int d_count;
    };

    vector<int> numIslands2_305(int m, int n, vector<vector<int>>& positions) {
        vector<int> result;
        UnionFind uf(m * n);

        for (auto & pos : positions) {
            vector<int> overlap;
            int posX = pos[0], posY = pos[1];
            if (posX - 1 >= 0 && uf.isValid((posX - 1) * n + posY)) {
                overlap.push_back((posX - 1) * n + posY);
            }
            if (posX + 1 < m && uf.isValid((posX + 1) * n + posY)) {
                overlap.push_back((posX + 1) * n + posY);
            }
            if (posY - 1 >= 0 && uf.isValid(posX * n + posY - 1)) {
                overlap.push_back(posX * n + posY - 1);
            }
            if (posY + 1 < n && uf.isValid(posX * n + posY + 1)) {
                overlap.push_back(posX * n + posY + 1);
            }

            int idx = posX * n + posY;
            uf.setParent(idx);
            for (auto & i : overlap) {
                uf.unionNodes(i, idx);
            }
            result.push_back(uf.getCount());
        } 

        return result;
    }

    // 306. Additive Number
    bool isAdditiveNumber306(string num) {
        if (num.size() < 3) {
            return false;
        }

        for (int i = 1; i < num.size(); ++i) {
            string num1_str = num.substr(0, i);
            if (num1_str.size() > 1 && num1_str[0] == '0') {
                break;
            }

            for (int j = i; j < num.size() - 1; ++j) {
                string num2_str = num.substr(i, j - i + 1);
                if (num2_str.size() > 1 && num2_str[0] == '0') {
                    break;
                }

                if (isAdditiveNumber306_dfs(num1_str, num2_str, num.substr(j + 1))) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isAdditiveNumber306_dfs(
        const string num1_str, const string num2_str, const string remain_str)
    {
        if ((num1_str.size() > 1 && num1_str[0] == '0')
            || (num2_str.size() > 1 && num2_str[0] == '0'))
        {
            return false;
        }

        string sum_str = to_string(stol(num1_str) + stol(num2_str));
        if (sum_str == remain_str) {
            return true;
        }

        if (sum_str.size() > remain_str.size()) {
            return false;
        }

        int size = sum_str.size();
        if (sum_str == remain_str.substr(0, size))
        {
            return isAdditiveNumber306_dfs(num2_str, sum_str, remain_str.substr(size));
        }
        else 
        {
            return false;
        }
    }

    // 307. Range Sum Query - Mutable
    class NumArray307 {
    public:
        NumArray307(vector<int>& nums) {
            d_size = nums.size();
            segTreeArr.resize(d_size * 2);
            for (int i = d_size, j = 0; i < segTreeArr.size(); ++i, ++j) {
                segTreeArr[i] = nums[j];
            }
            for (int k = d_size - 1; k > 0; --k) {
                segTreeArr[k] = segTreeArr[k * 2] + segTreeArr[k * 2 + 1];
            }
        }
        
        void update(int i, int val) {
            int pos = i + d_size;
            segTreeArr[pos] = val;
            while (pos > 0) {
                int left = pos, right = pos;
                if (pos % 2 == 0) {
                    right = pos + 1;
                }
                else {
                    left = pos - 1;
                }
                segTreeArr[pos / 2] = segTreeArr[left] + segTreeArr[right];
                pos /= 2;
            }
        }
        
        int sumRange(int i, int j) {
            int left = i + d_size, right = j + d_size;
            int sum = 0;
            while (left <= right) {
                if (left % 2 == 1) {
                    sum += segTreeArr[left];
                    left++;
                }
                if (right % 2 == 0) {
                    sum += segTreeArr[right];
                    right--;
                }
                left /= 2; right /= 2;
            }
            return sum;
        }

    private:
        vector<int> segTreeArr;
        int d_size;
    };

    // 308. Range Sum Query 2D - Mutable
    class NumMatrix308 {
    public:
        NumMatrix308(vector<vector<int>>& matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return;
            }

            // Initialize d_bitMat and d_valMat
            const int m = matrix.size(), n = matrix[0].size();
            d_bitMat.resize(m + 1, vector<int>(n + 1, 0));
            d_valMat.resize(m + 1, vector<int>(n + 1, 0));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    update(i, j, matrix[i][j]);
                }
            }
        }
        
        void update(int row, int col, int val) {
            int diff = val - d_valMat[row + 1][col + 1];
            for (int i = row + 1; i < d_bitMat.size(); i += (i & -i)) {
                for (int j = col + 1; j < d_bitMat[i].size(); j += (j & -j)) {
                    d_bitMat[i][j] += diff;
                }
            }
            d_valMat[row + 1][col + 1] = val;
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            return getSum(row2, col2) - getSum(row1 - 1, col2) - getSum(row2, col1 - 1) 
                + getSum(row1 - 1, col1 - 1);
        }

        int getSum(int row, int col) {
            int result = 0;
            for (int i = row + 1; i > 0; i -= (i & -i)) {
                for (int j = col + 1; j > 0; j -= (j & -j)) {
                    result += d_bitMat[i][j];
                }
            }
            return result;
        }
    
    private:
        vector<vector<int>> d_bitMat;
        vector<vector<int>> d_valMat;
    };


    // 309. Best Time to Buy and Sell Stock with Cooldown
    int maxProfit309(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int n = prices.size();
        vector<int> buy(n);
        vector<int> sell(n);
        vector<int> rest(n);
        
        buy[0] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            int cur_price = prices[i];
            buy[i] = max(rest[i - 1] - cur_price, buy[i - 1]);
            sell[i] = max(buy[i - 1] + cur_price, sell[i - 1]);
            rest[i] = max(max(rest[i - 1], buy[i - 1]), sell[i - 1]);
        }

        return max(buy.back(), max(sell.back(), rest.back()));
    }

    // 310. Minimum Height Trees
    vector<int> findMinHeightTrees310(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        unordered_map<int, unordered_set<int>> adjacentMatrix;
        for (auto & e: edges) {
            adjacentMatrix[e[0]].insert(e[1]);
            adjacentMatrix[e[1]].insert(e[0]);
        }
        queue<int> visitQ;
        for (auto & iter: adjacentMatrix) {
            if (iter.second.size() == 1) {
                visitQ.push(iter.first);
            }
        }

        while (n > 2) {
            int levelSize = visitQ.size();
            n -= levelSize;
            for (int i = 0; i < levelSize; ++i) {
                int curNode = visitQ.front(); visitQ.pop();
                for (auto & nextNode : adjacentMatrix[curNode]) {
                    adjacentMatrix[nextNode].erase(curNode);
                    if (adjacentMatrix[nextNode].size() == 1) {
                        visitQ.push(nextNode);
                        
                    }
                }
            }
        }

        vector<int> result;
        while (!visitQ.empty()) {
            result.push_back(visitQ.front());
            visitQ.pop();
        }
        return result;
    }

    // 311. Sparse Matrix Multiplication
    vector<vector<int>> multiply311(
        vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
    
        if (A[0].size() != B.size()) {
            return result;
        }

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (A[i][j] != 0) {
                    for (int k = 0; k < B[0].size(); ++k) {
                        if (B[j][k] != 0) {
                            result[i][k] += A[i][j] * B[j][k];
                        }
                    }
                }
            }
        }

        return result;
    }

    // 312. Burst Balloons
    int maxCoins312(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int size = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(size + 2, vector<int>(size + 2));

        for (int len = 1; len <= size; ++len) {
            for (int i = 1; i <= size - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(
                        dp[i][j], 
                        dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]
                    );
                }
            }
        }

        return dp[1][size];
    }

    // 313. Super Ugly Number
    int nthSuperUglyNumber313(int n, vector<int>& primes) {
        vector<int> dp(n, 1), idx(primes.size(), 0);
        int primeSize = primes.size();
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < primeSize; ++j) {
                dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
            }
            for (int j = 0; j < primeSize; ++j) {
                if (dp[i] == dp[idx[j]] * primes[j]) {
                    ++idx[j];
                }
            }
        }
        return dp.back();
    }

    // 314. Binary Tree Vertical Order Traversal
    vector<vector<int>> verticalOrder314(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        map<int, vector<int>> idx_value_map;
        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int cur_idx = cur.first;
            TreeNode * cur_node = cur.second;

            idx_value_map[cur_idx].push_back(cur_node->val);

            if (cur_node->left) {
                q.push({cur_idx - 1, cur_node->left});
            }
            if (cur_node->right) {
                q.push({cur_idx + 1, cur_node->right});
            }
        }

        for (auto iter: idx_value_map) {
            result.push_back(iter.second);
        }

        return result;
    }

    // 315. Count of Smaller Numbers After Self
    vector<int> countSmaller315(vector<int>& nums) {
        vector<int> sort_arr;
        vector<int> result(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0;
            int right = sort_arr.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (sort_arr[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            result[i] = right;
            sort_arr.insert(sort_arr.begin() + right, nums[i]);
        }

        return result;
    }

    // 316. Remove Duplicate Letters
    string removeDuplicateLetters316(string s) {
        unordered_map<char, int> freq_map;
        unordered_map<char, bool> visited_map;
        string result = "0";

        for (auto ch : s) {
            freq_map[ch]++;
        }

        for (auto ch : s) {
            freq_map[ch]--;

            if (visited_map[ch]) {
                continue;
            }

            while (freq_map[result.back()] && ch < result.back()) {
                visited_map[result.back()] = false;
                result.pop_back();
            }

            result += ch;
            visited_map[ch] = true;
        }

        return result.substr(1);
    }

    // 317. Shortest Distance from All Buildings
    int shortestDistance317(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = INT_MAX;
        int cur_val = 0;

        vector<vector<int>> sum = grid;
        const vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    result = INT_MAX;
                    vector<vector<int>> distance = grid;
                    queue<pair<int, int>> point_q;
                    point_q.push({i, j});
                    while (!point_q.empty()) {
                        int cur_x = point_q.front().first;
                        int cur_y = point_q.front().second;
                        point_q.pop();
                        for (auto direc : directions) {
                            int next_x = cur_x + direc.first;
                            int next_y = cur_y + direc.second;

                            if (next_x < 0 || next_x >= grid.size() 
                                || next_y < 0 || next_y >= grid[0].size()
                                || grid[next_x][next_y] != cur_val 
                                || grid[next_x][next_y] == 2) {
                                continue;
                            }

                            distance[next_x][next_y] = distance[cur_x][cur_y] + 1;
                            sum[next_x][next_y] += (distance[next_x][next_y] - 1);
                            result = min(sum[next_x][next_y], result);

                            point_q.push({next_x, next_y});
                            grid[next_x][next_y]--;
                        }
                    }
                    cur_val--;
                }
            }
        }

        return (result == INT_MAX) ? -1 : result;
    }

    // 318. Maximum Product of Word Lengths
    int maxProduct318(vector<string>& words) {
        unordered_map<int, int> maskLenMap;
        int result = 0;
        for (auto & w: words) {
            int curMask = 0;
            for (int i = 0; i < w.size(); ++i) {
                curMask |= (1 << static_cast<int>(w[i] - 'a'));
            }
            maskLenMap[curMask] = max(maskLenMap[curMask],
                static_cast<int>(w.size()));
            for (auto & iter : maskLenMap) {
                if (!(iter.first & curMask)) {
                    result = max(result, maskLenMap[curMask] * iter.second);
                }
            }
        }

        return result;
    }

    // 319. Bulb Switcher
    int bulbSwitch319(int n) {
        int result = 0;
        for (int i = 1; i * i <= n; ++i) {
            result++;
        }
        return result;

        /** Brutal force method
            int result = 0;
            for (int i = 1; i <= n; ++i) {
                int count = 0;
                for (int j = 1; j <= i; ++j) {
                    if (i % j == 0) {
                        count++;
                    }
                }
                if (count % 2 == 1) {
                    result++;
                }
            }
            
            return result;
         */
    }

    // 320. Generalized Abbreviation
    vector<string> generateAbbreviations320(string word) {
        vector<string> result{word};
        generateAbbreviations320_rec(result, word, 0);
        return result;
    }

    void generateAbbreviations320_rec(vector<string>& result, string word,
        int curPos) {
        for (int i = curPos; i < word.size(); ++i) {
            for (int j = 1; i + j <= word.size(); ++j) {
                string curResult = word.substr(0, i) + to_string(j) + word.substr(i + j);
                result.push_back(curResult);
                generateAbbreviations320_rec(result, curResult, i + 1 + to_string(j).size());
            }
        }
    }

    // 321. Create Maximum Number
    vector<int> maxNumber321(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> result;
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            int j = k - i;
            vector<int> cur = mergeMaxVector(getMaxVector(nums1, i), getMaxVector(nums2, j));
            result = max(cur, result);
        }

        return result;
    }

    vector<int> getMaxVector(const vector<int> & nums, int k)
    {
        int drop = nums.size() - k;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            while (!result.empty() && nums[i] > result.back() && drop > 0) {
                result.pop_back();
                drop--;
            }
            result.push_back(nums[i]);
        }

        result.resize(k);
        return result;
    }

    vector<int> mergeMaxVector(vector<int> res1, vector<int> res2)
    {
        vector<int> cur_res;
        while (!res1.empty() || !res2.empty()) {
            vector<int> & tmp = (res1 > res2) ? res1 : res2;
            cur_res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        
        return cur_res;
    }

    // 322. Coin Change
    int coinChange322(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }

        return (dp.back() == amount + 1) ? -1 : dp.back();
    }

    // 323. Number of Connected Components in an Undirected Graph
    int countComponents323(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjacentMatrix;
        for (auto & e: edges) {
            adjacentMatrix[e[0]].push_back(e[1]);
            adjacentMatrix[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                countComponents323_rec(visited, i, adjacentMatrix);
                ++result;
            }
        }
        return result;
    }

    void countComponents323_rec(vector<bool>& visited, int curNode,
        unordered_map<int, vector<int>>& adjacentMatrix) {
        if (visited[curNode]) {
            return;
        }
        visited[curNode] = true;
        for (int i = 0; i < adjacentMatrix[curNode].size(); ++i) {
            countComponents323_rec(visited, adjacentMatrix.at(curNode)[i],
                adjacentMatrix);
        }
    }

    // 324. Wiggle Sort II
    void wiggleSort324(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int size = nums.size(), j = (size - 1) / 2, k = size - 1;
        for (int i = 0; i < size; ++i) {
            if (i % 2 == 0) {
                nums[i] = tmp[j--];
            }
            else {
                nums[i] = tmp[k--];
            }
        }
    }

    // 325. Maximum Size Subarray Sum Equals k
    int maxSubArrayLen325(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_map<int, vector<int>> sumIdxMap;
        vector<int> sums = nums;
        sumIdxMap[sums[0]].push_back(0);
        for (int i = 1; i < nums.size(); ++i) {
            sums[i] += sums[i - 1];
            sumIdxMap[sums[i]].push_back(i);
        }

        int result = 0;
        for (auto iter: sumIdxMap) {
            if (iter.first == k) {
                result = max(result, iter.second.back() + 1);
            }
            else {
                int target = iter.first - k;
                if (sumIdxMap.find(target) != sumIdxMap.end()) {
                    result = max(result, iter.second.back() - sumIdxMap[target][0]);
                }
            }
        }
        return result;
    }

    // 326. Power of Three
    bool isPowerOfThree326(int n) {
        while (n >= 3) {
            if (n % 3 == 0) {
                n /= 3;
            }
            else {
                return false;
            }
        }
        return (n == 1);
    }

    // 327. Count of Range Sum
    int countRangeSum327(vector<int>& nums, int lower, int upper) {
        int result = 0;
        multiset<int> sumMS; 
            // Multiset is a STL Data Structure that store elements following a 
            // specific order. Elements can have equivalent values.
        sumMS.insert(0);
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            result += distance(sumMS.lower_bound(curSum - upper),
                sumMS.upper_bound(curSum - lower));
                // `distance(first, last)` API calculates the number of elements 
                // between first and last.
            sumMS.insert(curSum);
        }
        return result;
    }

    // 329. Longest Increasing Path in a Matrix
    int longestIncreasingPath329(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<pair<int, int>> direc = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur_len = longestIncreasingPath329_dfs(
                    dp, matrix, direc, i, j
                );
                result = max(result, cur_len);
            }
        }

        return result;
    }

    int longestIncreasingPath329_dfs(
        vector<vector<int>> & dp,
        const vector<vector<int>> & matrix,
        const vector<pair<int, int>> & direc,
        const int i, const int j) {
        if (dp[i][j]) {
            return dp[i][j];
        }

        int m = matrix.size(), n = matrix[0].size();
        int cur_max = 1;

        for (auto iter : direc) {
            int next_x = i + iter.first, next_y = j + iter.second;
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n
                || matrix[next_x][next_y] <= matrix[i][j]) {
                continue;
            }

            int len = 1 + longestIncreasingPath329_dfs(dp, matrix, direc, next_x, next_y);
            cur_max = max(cur_max, len);
        }

        dp[i][j] = cur_max;
        return cur_max;
    }

    // 330. Patching Array
    int minPatches330(vector<int>& nums, int n) {
        int patch = 0, curIdx = 0;
        long long miss = 1;

        while (miss <= n) {
            if (curIdx < nums.size() && nums[curIdx] <= miss) {
                miss += nums[curIdx];
                curIdx++;
            }
            else {
                patch++;
                miss += miss;
            }
        }

        return patch;
    }

    // 332. Reconstruct Itinerary
    vector<string> findItinerary332(vector<vector<string>>& tickets) {
        vector<string> result;
        unordered_map<string, multiset<string>> dest_map;
        for (auto iter : tickets) {
            dest_map[iter[0]].insert(iter[1]);
        }
        findItinerary332_dfs(result, dest_map, "JFK");

        return result;
    }

    void findItinerary332_dfs(
        vector<string> &result,
        unordered_map<string, multiset<string>> &dest_map,
        string cur) {
        while (dest_map[cur].size() > 0) {
            string next = *(dest_map[cur].begin());
            dest_map[cur].erase(dest_map[cur].begin());
            findItinerary332_dfs(result, dest_map, next);
        }

        result.insert(result.begin(), cur);
    }

    // 333. Largest BST Subtree
    int largestBSTSubtree333(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (is_valid_BST(root, INT_MIN, INT_MAX)) {
            return count_node(root);
        } else {
            return max(
                largestBSTSubtree333(root->left),
                largestBSTSubtree333(root->right)
            );
        }
    }

    bool is_valid_BST(TreeNode *cur, int min, int max) {
        if (!cur) {
            return true;
        }

        if (cur->val <= min || cur->val >= max) {
            return false;
        }

        return is_valid_BST(cur->left, min, cur->val) 
            && is_valid_BST(cur->right, cur->val, max);
    }

    int count_node(TreeNode *cur) {
        if (!cur) {
            return 0;
        }

        return count_node(cur->left) + count_node(cur->right) + 1;
    }

    // 334. Increasing Triplet Subsequence
    bool increasingTriplet334(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int n = nums.size();
        vector<int> forward(n, nums[0]);
        vector<int> backward(n, nums[n - 1]);

        for (int i = 1; i < n; ++i) {
            forward[i] = min(forward[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
            backward[i] = max(backward[i + 1], nums[i]);
        }

        for (int i = 1; i <= n - 1; ++i) {
            if (nums[i] > forward[i] && nums[i] < backward[i]) {
                return true;
            }
        }

        return false;
    }

    // 336. Palindrome Pairs
    vector<vector<int>> palindromePairs336(vector<string>& words) {
        unordered_map<string, int> word_idx_map;
        set<int> len_set;

        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i) {
            word_idx_map[words[i]] = i;
            len_set.insert(words[i].size());
        }

        for (int i = 0; i < words.size(); ++i) {
            string cur_word_reverse = words[i];
            const int word_len = words[i].size();
            reverse(cur_word_reverse.begin(), cur_word_reverse.end());

            if (word_idx_map.count(cur_word_reverse) 
                && word_idx_map[cur_word_reverse] != i) {
                result.push_back({i, word_idx_map[cur_word_reverse]});
            }

            for (auto iter = len_set.begin(); *iter != word_len; ++iter) {
                int cur_len = *iter;
                if (word_idx_map.count(cur_word_reverse.substr(0, cur_len)) 
                    && is_palin(cur_word_reverse, cur_len, word_len - 1)) {
                    result.push_back({word_idx_map[cur_word_reverse.substr(0, cur_len)], i});
                }

                if (word_idx_map.count(cur_word_reverse.substr(word_len - cur_len)) 
                    && is_palin(cur_word_reverse, 0, word_len - cur_len - 1)) {
                    result.push_back({i, word_idx_map[cur_word_reverse.substr(word_len - cur_len)]});
                }
            }
        }

        return result;
    }

    bool is_palin(const string word, int left, int right) {
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            ++left;
            --right;
        }

        return true;
    }

    // 339. Nested List Weight Sum (Cannot build locally)
    /*
    int depthSum339(vector<NestedInteger>& nestedList) {
        return depthSum_dfs(nestedList, 1);
    }
    
    int depthSum_dfs(vector<NestedInteger>& nestedList, int cur_depth) {
        int result = 0;
        
        for (int i = 0; i < nestedList.size(); ++i) {
            if (nestedList[i].isInteger()) {
                result += cur_depth * nestedList[i].getInteger();
            } else {
                result += depthSum_dfs(nestedList[i].getList(), cur_depth + 1);
            }
        }
        
        return result;
    }
    */

    // 340. Longest Substring with At Most K Distinct Characters
    int lengthOfLongestSubstringKDistinct340(string s, int k) {
        int result = 0;
        unordered_map<char, int> charFreqMap;
        int left = 0;

        for (int i = 0; i < s.length(); ++i) {
            charFreqMap[s[i]]++;
            while (charFreqMap.size() > k) {
                charFreqMap[s[left]]--;
                if (charFreqMap[s[left]] == 0) {
                    charFreqMap.erase(s[left]);
                }
                ++left;
            }
            result = max(result, i - left + 1);
        }

        return result;
    }

    // 341. Flatten Nested List Iterator
    /*
    class NestedIterator {
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            for (int i = nestedList.size() - 1; i >= 0; --i) {
                st.push(nestedList[i]);
            }
        }

        int next() {
            int result = st.top().getInteger();
            st.pop();
            return result;
        }

        bool hasNext() {
            while (!st.empty()) {
                NestedInteger cur = st.top();
                if (cur.isInteger()) {
                    return true;
                }
                st.pop();
                
                for (int i = cur.getList().size() - 1; i >= 0; --i) {
                    st.push(cur.getList()[i]);
                }
            }
            return false;
        }
        
    private:
        stack<NestedInteger> st;
    };
    */

    // 344. Reverse String
    void reverseString344(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    // 346. Moving Average from Data Stream
    class MovingAverage346 {
    public:
        /** Initialize your data structure here. */
        MovingAverage346(int size) {
            m_size = size;
            m_curSum = 0;
        }
        
        double next(int val) {
            if (m_window.size() == m_size) {
                m_curSum -= m_window.front();
                m_window.pop();
            }

            m_curSum += val;
            m_window.push(val);
            return static_cast<double>(m_curSum) / m_window.size();
        }

    private:
        int m_size;
        int m_curSum;
        queue<int> m_window;
    };

    // 347. Top K Frequent Elements
    vector<int> topKFrequent347(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> num_freq_map;
        for (int i = 0; i < nums.size(); ++i) {
            num_freq_map[nums[i]]++;
        }
        
        map<int, vector<int>> freq_num_map;
        for (auto &iter : num_freq_map) {
            freq_num_map[iter.second].push_back(iter.first);
        }
        
        for (auto rit = freq_num_map.rbegin(); rit != freq_num_map.rend(); ++rit) {
            for (int i = 0; i < rit->second.size() && k > 0; ++i) {
                result.push_back(rit->second[i]);
                k--;
            }
            
            if (k == 0) {
                return result;
            }
        }
        
        return result;
    }

    // 348. Design Tic-Tac-Toe
    class TicTacToe348 {
    public:
        /** Initialize your data structure here. */
        TicTacToe348(int n) {
            board.resize(n, vector<int>(n, 0));
            m_size = n;
        }
        
        /** Player {player} makes a move at ({row}, {col}).
            @param row The row of the board.
            @param col The column of the board.
            @param player The player, can be either 1 or 2.
            @return The current winning condition, can be either:
                    0: No one wins.
                    1: Player 1 wins.
                    2: Player 2 wins. */
        int move(int row, int col, int player) {
            if (board[row][col] != 0) {
                throw "Cannot play on non zero grid";
            }

            board[row][col] = player;
            int i = 1;
            while (i < m_size) {
                if (board[i][col] != board[i - 1][col]) {
                    break;
                }
                ++i;
            }
            if (i == m_size) {
                return player;
            }

            int j = 1;
            while (j < m_size) {
                if (board[row][j] != board[row][j - 1]) {
                    break;
                }
                ++j;
            }
            if (j == m_size) {
                return player;
            }

            if (col == row) {
                int m = 1;
                while (m < m_size) {
                    if (board[m][m] != board[m - 1][m - 1]) {
                        break;
                    }
                    ++m;
                }
                if (m == m_size) {
                    return player;
                }
            }

            if (row + col == m_size - 1) {
                int n = 1;
                while (n < m_size) {
                    if (board[n][m_size - n - 1] != board[n - 1][m_size - n]) {
                        break;
                    }
                    ++n;
                }
                if (n == m_size) {
                    return player;
                }
            }

            return 0;
        }

    private:
        vector<vector<int>> board;
        int m_size;
    };

    // 349. Intersection of Two Arrays
    vector<int> intersection349(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums1_set.count(nums2[i])) {
                result.push_back(nums2[i]);
                nums1_set.erase(nums2[i]);
            }
        }
        
        return result;
    }

    // 350. Intersection of Two Arrays II
    vector<int> intersect350(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> nums1Freq_map;
        
        for (int i = 0; i < nums1.size(); ++i) {
            nums1Freq_map[nums1[i]]++;
        }
        
        for (int i = 0; i < nums2.size(); ++i) {
            if (nums1Freq_map[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                nums1Freq_map[nums2[i]]--;
            }
        }
        
        return result;
    }

    // 352. Data Stream as Disjoint Intervals
    class SummaryRanges352 {
    public:
        /** Initialize your data structure here. */
        SummaryRanges352() { }
        
        void addNum(int val) {
            vector<int> newInterval = {val, val};
            vector<vector<int>> result;
            int pos = 0;

            for (auto intv : intervals) {
                if (newInterval[0] > intv[1] + 1) {
                    result.push_back(intv);
                    pos++;
                } else if (newInterval[1] + 1 < intv[0]) {
                    result.push_back(intv);
                } else {
                    newInterval[0] = min(intv[0], newInterval[0]);
                    newInterval[1] = max(intv[1], newInterval[1]);
                }
            }

            result.insert(result.begin() + pos, newInterval);
            intervals = result;
        }
        
        vector<vector<int>> getIntervals() {
            return intervals;
        }

    private:
        vector<vector<int>> intervals;
    };

    // 353. Design Snake Game
    class SnakeGame353 {
    public:
        /** Initialize your data structure here.
            @param width - screen width
            @param height - screen height 
            @param food - A list of food positions
            E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
        SnakeGame353(int width, int height, vector<vector<int>>& food) {
            m_height = height;
            m_width = width;
            m_score = 0;

            for (int i = 0; i < food.size(); ++i) {
                m_food.push_back({food[i][0], food[i][1]});
            }

            m_snake.push_back({0, 0});
        }
        
        /** Moves the snake.
            @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
            @return The game's score after the move. Return -1 if game over. 
            Game over when snake crosses the screen boundary or bites its body. */
        int move(string direction) {
            auto head = m_snake.front(), tail = m_snake.back();
            m_snake.pop_back();

            if (direction == "U") {
                head.first--;
            } else if (direction == "D") {
                head.first++;
            } else if (direction == "L") {
                head.second--;
            } else if (direction == "R") {
                head.second++;
            }

            if (head.first < 0 || head.first >= m_height || 
                head.second < 0 || head.second >= m_width || 
                count(m_snake.begin(), m_snake.end(), head))
            {
                return -1;
            }

            m_snake.insert(m_snake.begin(), head);
            if (!m_food.empty() && m_food.front() == head) {
                ++m_score;
                m_food.erase(m_food.begin());
                m_snake.push_back(tail);
            }

            return m_score;
        }

    private:
        vector<pair<int, int>> m_food, m_snake;
        int m_height, m_width, m_score;
    };

    // 354. Russian Doll Envelopes
    int maxEnvelopes354(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), 
            [](const vector<int> &e1, const vector<int> &e2) {
                if (e1[0] == e2[0]) {
                    return e1[1] > e2[1];
                }
                return e1[0] < e2[0];
            }
        );

        vector<int> dp;

        for (auto e: envelopes) {
            int left = 0, right = dp.size(), pivot = e[1];
            while (left < right) {
                int mid = (left + right) / 2;
                if (pivot > dp[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            if (right >= dp.size()) {
                dp.push_back(pivot);
            } else {
                dp[right] = pivot;
            }
        }

        return dp.size();
    }

    // 355. Design Twitter
    class Twitter355 {
    public:
        /** Initialize your data structure here. */
        Twitter355() {
            m_time = 0;
        }
        
        /** Compose a new tweet. */
        void postTweet(int userId, int tweetId) {
            m_person_tweets_map[userId].insert({m_time, tweetId});
            m_time++;
        }
        
        /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
        vector<int> getNewsFeed(int userId) {
            m_person_friends_map[userId].insert(userId);

            map<int, int> latest10;

            for (auto each_friend: m_person_friends_map[userId]) {
                for (auto each_tweet: m_person_tweets_map[each_friend]) {
                    latest10.insert(each_tweet);
                    while (latest10.size() > 10) {
                        latest10.erase(latest10.begin());
                    }
                }
            }

            vector<int> result;
            for (auto each: latest10) {
                result.push_back(each.second);
            }
            reverse(result.begin(), result.end());

            return result;
        }
        
        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        void follow(int followerId, int followeeId) {
            m_person_friends_map[followerId].insert(followeeId);
        }
        
        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        void unfollow(int followerId, int followeeId) {
            m_person_friends_map[followerId].erase(followeeId);
        }

    private:
        unordered_map<int, unordered_set<int>> m_person_friends_map;
        unordered_map<int, unordered_map<int, int>> m_person_tweets_map;
        int m_time;
    };

    // 359. Logger Rate Limiter
    class Logger359 {
    public:
        /** Initialize your data structure here. */
        Logger359() { }
        
        /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
            If this method returns false, the message will not be printed.
            The timestamp is in seconds granularity. */
        bool shouldPrintMessage(int timestamp, string message) {
            if (!msg_time_map.count(message)) {
                msg_time_map[message] = timestamp;
                return true;
            }
            else {
                bool isPrint = (timestamp - 10) >= msg_time_map[message];
                if (isPrint) {
                    msg_time_map[message] = timestamp;
                }
                return isPrint;
            }
        }
        
    private:
        map<string ,int> msg_time_map;
    };

    // 362. Design Hit Counter
    class HitCounter362 {
    public:
        /** Initialize your data structure here. */
        HitCounter362() { }
        
        /** Record a hit.
            @param timestamp - The current timestamp (in seconds granularity). */
        void hit(int timestamp) {
            q.push(timestamp);
        }
        
        /** Return the number of hits in the past 5 minutes.
            @param timestamp - The current timestamp (in seconds granularity). */
        int getHits(int timestamp) {
            while (!q.empty() && timestamp - q.front() >= 5 * 60) {
                q.pop();
            }
            
            return q.size();
        }

    private:
        queue<int> q;
    };

    // 363. Max Sum of Rectangle No Larger Than K
    int maxSumSubmatrix363(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int result = INT_MIN;
        for (int left = 0; left < n; ++left) {
            vector<int> sum(m, 0);
            for (int j = left; j < n; ++j) {
                for (int i = 0; i < m; ++i) {
                    sum[i] += matrix[i][j];
                }

                for (int i = 0; i < sum.size(); ++i) {
                    int curSum = 0;
                    for (int j = i; j < sum.size(); ++j) {
                        curSum += sum[j];
                        if (curSum <= k) {
                            result = max(result, curSum);
                        }
                    }
                }
            }
        }
        
        return result;
    }

    // 364. Nested List Weight Sum II
    /** This problem can only be run online
    int depthSumInverse364(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) {
            return 0;
        }
        
        vector<vector<int>> level;
        queue<NestedInteger> q;
        
        for (int i = 0; i < nestedList.size(); ++i) {
            q.push(nestedList[i]);
        }
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> curLevel;
            
            for (int i = 0; i < levelSize; ++i) {
                auto cur = q.front();
                q.pop();
                
                if (cur.isInteger()) {
                    curLevel.push_back(cur.getInteger());
                } else {
                    auto nextLevel = cur.getList();
                    for (int j = 0; j < nextLevel.size(); ++j) {
                        q.push(nextLevel[j]);
                    }
                }
            }
            
            level.push_back(curLevel);
        }
        
        int levelCt = 1;
        int result = 0;
        for (int i = level.size() - 1; i >= 0; --i) {
            int curSum = 0;
            for (int j = 0; j < level[i].size(); ++j) {
                curSum += level[i][j];
            }
            
            result += levelCt * curSum;
            ++levelCt;
        }
        
        return result;
    }*/

    // 366. Find Leaves of Binary Tree
    vector<vector<int>> findLeaves366(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        
        findLeaves_dfs(root, result);
        
        return result;
    }
    
    int findLeaves_dfs(TreeNode* cur, vector<vector<int>> &result) {
        if (!cur) {
            return -1;
        }
        
        int depth = max(findLeaves_dfs(cur->left, result), findLeaves_dfs(cur->right, result)) + 1;
        if (depth >= result.size()) {
            result.resize(depth + 1);
        }
        
        result[depth].push_back(cur->val);
        return depth;
    }

    // 371. Sum of Two Integers
    int getSum371(int a, int b) {
        if (b == 0) {
            return a;
        }
        
        int curSum = a ^ b;
        int carry = (a & b & 0x7ffffffff) << 1;
        return getSum371(curSum, carry);
    }

    // 378. Kth Smallest Element in a Sorted Matrix
    int kthSmallest378(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if (count < k) {
                left = mid + 1;
            }
            else right = mid;
        }
        
        return left;
    }

    // 379. Design Phone Directory
    class PhoneDirectory379 {
    public:
        /** Initialize your data structure here
            @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
        PhoneDirectory379(int maxNumbers) {
            isAvailable.resize(maxNumbers, true);
            for (int i = 0; i < maxNumbers; ++i) {
                pq.push(i);
            }
        }
        
        /** Provide a number which is not assigned to anyone.
            @return - Return an available number. Return -1 if none is available. */
        int get() {
            if (!pq.size()) {
                return -1;
            }
            int result = pq.top();
            pq.pop();
            isAvailable[result] = false;
            return result;
        }
        
        /** Check if a number is available or not. */
        bool check(int number) {
            return isAvailable[number];
        }
        
        /** Recycle or release a number. */
        void release(int number) {
            if (isAvailable[number]) {
                return;
            }
            
            isAvailable[number] = true;
            pq.push(number);
        }
        
    private:
        vector<bool> isAvailable;
        priority_queue<int, vector<int>, greater<int>> pq;
    };

    // 380. Insert Delete GetRandom O(1)
    class RandomizedSet380 {
    public:
        /** Initialize your data structure here. */
        RandomizedSet380() {}
        
        /** Inserts a value to the set. Returns true if the set did not already 
         * contain the specified element. */
        bool insert(int val) {
            if (num_idx_map.count(val)) {
                return false;
            }

            nums.push_back(val);
            num_idx_map[val] = nums.size() - 1;
            return true;
        }
        
        /** Removes a value from the set. Returns true if the set contained the 
         * specified element. */
        bool remove(int val) {
            if (!num_idx_map.count(val)) {
                return false;
            }

            int last = nums.back();
            int val_idx = num_idx_map[val];
            nums[val_idx] = last;
            num_idx_map[last] = val_idx;
            num_idx_map.erase(val);
            nums.pop_back();
            return true;
        }
        
        /** Get a random element from the set. */
        int getRandom() {
            return nums[rand() % nums.size()];
        }

    private:
        vector<int> nums;
        unordered_map<int, int> num_idx_map;
    };

    // 381. Insert Delete GetRandom O(1) - Duplicates allowed
    class RandomizedCollection381 {
    public:
        /** Initialize your data structure here. */
        RandomizedCollection381() { }
        
        /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
        bool insert(int val) {
            int newIdx = nums.size();
            idxHeapMap[val].push(newIdx);
            nums.push_back(val);
            return idxHeapMap[val].size() == 1;
        }
        
        /** Removes a value from the collection. Returns true if the collection contained the specified element. */
        bool remove(int val) {
            if (idxHeapMap[val].empty()) {
                return false;
            }
            
            int maxIdx = idxHeapMap[val].top();
            idxHeapMap[val].pop();
            if (maxIdx != nums.size() - 1) {
                int swapVal = nums.back();
                idxHeapMap[swapVal].pop();
                idxHeapMap[swapVal].push(maxIdx);
                nums[maxIdx] = swapVal;
            }

            nums.pop_back();
            return true;
        }
        
        /** Get a random element from the collection. */
        int getRandom() {
            return nums[rand() % nums.size()];
        }

    private:
        vector<int> nums;
        unordered_map<int, priority_queue<int>> idxHeapMap;
    };

    // 384. Shuffle an Array
    class Solution384 {
    public:
        Solution384(vector<int>& nums)
          : d_nums(nums) { }
        
        /** Resets the array to its original configuration and return it. */
        vector<int> reset() {
            return d_nums;
        }

        /** Returns a random shuffling of the array. */
        vector<int> shuffle() {
            vector<int> shuffle(d_nums);
            for (int i = 0; i < shuffle.size(); ++i) {
                int nextRandomIdx = i + rand() % (shuffle.size() - i);
                swap(shuffle[nextRandomIdx], shuffle[i]);
            }

            return shuffle;
        }

    private:
        vector<int> d_nums;
    };

    // 386. Lexicographical Numbers
    vector<int> lexicalOrder386(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            lexicalOrder386Rec(i, n, result);
        }
        return result;
    }

    void lexicalOrder386Rec(int cur, const int n, vector<int> &result) {
        if (cur > n) {
            return;
        }
        result.push_back(cur);
        for (int i = 0; i <= 9; ++i) {
            int next = cur * 10 + i;
            if (cur <= n) {
                lexicalOrder386Rec(next, n, result);
            }
            else break;
        }
    }

    // 387. First Unique Character in a String
    int firstUniqChar387(string s) {
        unordered_map<char, int> charFreqMap;
        for (char &c : s) {
            charFreqMap[c]++;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (charFreqMap[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }

    // 388. Longest Absolute File Path
    int lengthLongestPath388(string input) {
        if (input.empty()) {
            return 0;
        }

        int result = 0;
        istringstream iss(input);
        string curLine;
        unordered_map<int, int> levelLenMap { {0, 0} };

        while (getline(iss, curLine)) {
            if (curLine.find('\t') == string::npos) {
                if (curLine.find('.') != string::npos) {
                    result = max((int)curLine.length(), result);
                } else {
                    levelLenMap[0] = curLine.length();
                }
                continue;
            }

            int level = curLine.find_last_of('\t') + 1;
            string curFileDirec = curLine.substr(level);
            if (curFileDirec.find('.') != string::npos) {
                result = max(
                    levelLenMap[level - 1] + 1 + (int)curFileDirec.length(), result);
            } else {
                levelLenMap[level] = levelLenMap[level - 1] + 1 + curFileDirec.length();
            }
        }

        return result;
    }

    // 393. UTF-8 Validation
    bool validUtf8_393(vector<int>& data) {
        int n = data.size();
        for (int i = 0; i < n; ++i) {
            if (data[i] < 0b10000000) {
                continue;
            } else {
                int cnt1 = 0;
                int curVal = data[i];
                for (int j = 7; j >= 0; --j) {
                    if (curVal >= pow(2, j)) {
                        cnt1++;
                    } else {
                        break;
                    }

                    curVal -= pow(2, j);
                }

                if (cnt1 == 1 || cnt1 > 4 || i + cnt1 > n) {
                    return false;
                }

                for (int j = i + 1; j < i + cnt1; ++j) {
                    if (data[j] > 0b10111111 || data[j] < 0b10000000) {
                        return false;
                    }
                }

                i += (cnt1 - 1);
            }
        }
        return true;
    }

    // 394. Decode String
    string decodeString394(string s) {
        int idx = 0;
        return decodeString394Rec(s, idx);
    }

    string decodeString394Rec(const string s, int &idx) {
        string result = "";
        while (idx < s.length() && s[idx] != ']') {
            if (s[idx] < '0' || s[idx] > '9') {
                result += s[idx];
                ++idx;
            } else {
                int cnt = 0;
                while (idx < s.length() && s[idx] >= '0' && s[idx] <= '9') {
                    cnt = (cnt * 10 + (s[idx] - '0'));
                    idx++;
                }
                assert(s[idx] == '[');
                idx++;
                string inner = decodeString394Rec(s, idx);
                assert(s[idx] == ']');
                idx++;

                for (int j = 0; j < cnt; ++j) {
                    result += inner;
                }
            }
        }

        return result;
    }

    // 395. Longest Substring with At Least K Repeating Characters
    int longestSubstring395(string s, int k) {
        return longestSubstring395_rec(s, k, 0, s.size() - 1);
    }

    int longestSubstring395_rec(string const &s, int const k, int start, int end)
    {
        if (start > end)
        {
            return 0;
        }

        vector<int> charFreqMap(26, 0);
        for (int i = start; i <= end; ++i)
        {
            charFreqMap[s[i] - 'a']++;
        }

        for (int i = 0; i < charFreqMap.size(); ++i)
        {
            int freq = charFreqMap[i];
            if (freq > 0 && freq < k)
            {
                int firstIndex = s.find_first_of(('a' + i), start);
                return max(
                    longestSubstring395_rec(s, k, start, firstIndex - 1),
                    longestSubstring395_rec(s, k, firstIndex + 1, end)
                );
            }
        }

        return end - start + 1;
    }

    // 399. Evaluate Division
    vector<double> calcEquation399(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> parents;

        assert(equations.size() == values.size());
        for (int i = 0; i < equations.size(); ++i)
        {
            string A = equations[i][0];
            string B = equations[i][1];
            double K = values[i];

            if (!parents.count(A) && !parents.count(B))
            {
                parents[A] = {B, K};
                parents[B] = {B, 1.0};
            }
            else if (!parents.count(A))
            {
                parents[A] = {B, K};
            }
            else if (!parents.count(B))
            {
                parents[B] = {A, 1.0 / K};
            }
            else
            {
                pair<string, double> rootA = findParent(A, parents);
                pair<string, double> rootB = findParent(B, parents);
                parents[rootA.first] = {rootB.first, K * rootB.second / rootA.second};
            }
        }

        vector<double> results;
        for (auto &it: queries)
        {
            const string& X = it[0];
            const string& Y = it[1];

            if (!parents.count(X) || !parents.count(Y))
            {
                results.push_back(-1.0);
                continue;
            }

            pair<string, double> rootX = findParent(X, parents);
            pair<string, double> rootY = findParent(Y, parents);
            if (rootX.first != rootY.first)
            {
                results.push_back(-1.0);
            }
            else
            {
                results.push_back(rootX.second / rootY.second);
            }
        }

        return results;
    }

    pair<string, double> findParent(
        string const &in, unordered_map<string, pair<string, double>> &parents)
    {
        if (in != parents[in].first)
        {
            const auto &it = findParent(parents[in].first, parents);
            parents[in].first = it.first;
            parents[in].second *= it.second;
        }
        return parents[in];
    }
};

#endif