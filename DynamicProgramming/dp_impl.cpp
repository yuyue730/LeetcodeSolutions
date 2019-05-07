#include "dp_impl.h"

DpImpl::DpImpl() {
    cout << "Impl object for Leetcode Dynamic Programming problems constructed.\n";
}

// 44. Wildcard Matching
bool DpImpl::isMatch44(string s, string p) {
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

// 64. Minimum Path Sum
int DpImpl::minPathSum64(vector<vector<int>>& grid)
{
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

// 62. Unique Paths
int DpImpl::uniquePaths62(int m, int n) {
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