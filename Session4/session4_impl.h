#ifndef _SESSION_4_IMPL_H
#define _SESSION_4_IMPL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

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
        for (int val: nums) {
            for (int j = target; j >= val; --j) {
                dp[j] = dp[j] || dp[j - val];
            }
        }
        return dp[target];
    }
};

#endif