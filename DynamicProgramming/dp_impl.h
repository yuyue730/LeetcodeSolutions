#ifndef _DP_IMPL_H
#define _DP_IMPL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class DpImpl {
public:
    DpImpl() {
        cout << "Impl object for Leetcode Dynamic Programming problems constructed.\n";
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

    // 120. Triangle
    int minimumTotal120(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        vector<int> * dp = &(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; --i) {
            vector<int> * nextDp = new vector<int>(i + 1);
            for (int j = 0; j < nextDp->size(); ++j) {
                nextDp->at(j) = min(dp->at(j), dp->at(j + 1)) + triangle[i][j];
            }
            dp = nextDp;
        }
        return dp->at(0);
    }

    // 123. Best Time to Buy and Sell Stock III
    int maxProfit123(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        vector<int> leftMaxProfit(prices.size(), 0);
        int localMinPrice = prices[0];
        int curMaxLeftProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < localMinPrice) {
                localMinPrice = prices[i];
            }
            else {
                curMaxLeftProfit = max(
                    curMaxLeftProfit, prices[i] - localMinPrice
                );
            }
            leftMaxProfit[i] = curMaxLeftProfit;
        }

        int result = leftMaxProfit.back();
        int localMaxPrice = prices.back();
        int curMaxRightProfit = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            if (prices[i] > localMaxPrice) {
                localMaxPrice = prices[i];
            } else {
                curMaxRightProfit = max(
                    curMaxRightProfit, localMaxPrice - prices[i]
                );
            }
            result = max(result, leftMaxProfit[i] + curMaxRightProfit);
        }

        return result;
    }
    
    // 132. Palindrome Partitioning II
    int minCut132(string s) {
        if (s.empty()) {
            return 0;
        }

        int nSize = s.size();
        vector<vector<bool>> palinState(nSize, vector<bool>(nSize, false));
        vector<int> dp(nSize);

        for (int i = 0; i < nSize; ++i) {
            dp[i] = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || palinState[j + 1][i - 1])) {
                    palinState[j][i] = true;
                    dp[i] = (j == 0 ? 0 : min(dp[j - 1] + 1, dp[i]));
                }
            }
        }
        return dp[nSize - 1];
    }

    // 139. Word Break
    bool wordBreak139(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> dictSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string curWord = s.substr(j, i - j);
                dp[i] = dp[j] && dictSet.count(curWord);
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp.back();
    }

    // 152. Maximum Product Subarray
    int maxProduct152(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<int> smallDp(nums.size(), 0);
        vector<int> largeDp(nums.size(), 0);
        smallDp[0] = largeDp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            smallDp[i] = min(
                smallDp[i - 1] * nums[i], min(largeDp[i - 1] * nums[i], nums[i])
            );
            largeDp[i] = max(
                smallDp[i - 1] * nums[i], max(largeDp[i - 1] * nums[i], nums[i])
            );
            result = max(result, largeDp[i]);
        }

        return result;
    }

    // 188. Best Time to Buy and Sell Stock IV
    int maxProfit188(int k, vector<int>& prices) {
        int n = prices.size();

        if (n == 0) {
            return 0;
        }

        if (k > n) {
            int max_profit = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
        }

        vector<int> local(k + 1, 0);
        vector<int> global(k + 1, 0);

        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; --j) {
                local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
                global[j] = max(global[j], local[j]);
            }
        }

        return global.back();
    }

    // 198. House Robber
    int rob198(vector<int>& nums) {
        if (nums.size() <= 1) {
            return (nums.size() == 1) ? nums[0] : 0;
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
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