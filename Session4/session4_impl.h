#ifndef _SESSION_4_IMPL_H
#define _SESSION_4_IMPL_H

#include <iostream>
#include <vector>
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
        for (char c: num)
        {
            while (k > 0 && result.size() > 0 && c < result.back())
            {
                result.pop_back();
                k--;
            }

            result.push_back(c);
        }

        result.resize(keep);

        while (!result.empty() && result[0] == '0')
        {
            result.erase(result.begin());
        }
        
        return result.empty() ? "0" : result;
    }

    // 403. Frog Jump
    bool canCross403(vector<int>& stones)
    {
        return canCross403_rec(stones, 0, 0);
    }

    bool canCross403_rec(vector<int> const &stones, int curPos, int prevJump)
    {
        if (curPos == stones.size() - 1)
        {
            return true;
        }

        for (int i = prevJump - 1; i <= prevJump + 1; ++i)
        {

        }
    }
};

#endif