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

// 63. Unique Paths II
int DpImpl::uniquePathsWithObstacles63(vector<vector<int>>& obstacleGrid)
{
    vector<vector<long long>> dp(obstacleGrid.size(), vector<long long>(obstacleGrid[0].size()));

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

// 70. Climbing Stairs
int DpImpl::climbStairs70(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1; dp[1] = 2;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}