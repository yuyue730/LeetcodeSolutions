#ifndef _SESSION_4_IMPL_H
#define _SESSION_4_IMPL_H

#include <iostream>
#include <vector>
#include <algorithm>
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
};

#endif