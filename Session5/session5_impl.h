#ifndef _SESSION_5_IMPL_H
#define _SESSION_5_IMPL_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
};

#endif