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