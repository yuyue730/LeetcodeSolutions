#ifndef _BIT_IMPL_H
#define _BIT_IMPL_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class BitManipulationImpl {
public:
    BitManipulationImpl() {
        cout << "Impl object for Leetcode Bit Manipulation problems constructed.\n";
    }

    // 136. Single Number
    int singleNumber136(vector<int>& nums) {
        int andValue = 0;
        for (int i = 0; i < nums.size(); ++i) {
            andValue ^= nums[i];
        }

        return andValue;
    }

    // 137. Single Number II
    int singleNumber137(vector<int>& nums) {
        int result = 0;
        for (int pos = 0; pos < 32; ++pos) {
            int curBitVal = 0;
            for (int i = 0; i < nums.size(); ++i) {
                curBitVal += (nums[i] >> pos) & 1;
            }

            result += (curBitVal % 3) << pos;
        }

        return result;
    }
};

#endif