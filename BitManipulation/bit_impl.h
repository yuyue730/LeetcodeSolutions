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

    // 201. Bitwise AND of Numbers Range
    int rangeBitwiseAnd201(int m, int n) {
        long long mask = INT_MAX;
        while ((m & mask) != (n & mask)) {
            mask <<= 1;
        }

        return (m & mask);
    }

    // 268. Missing Number
    int missingNumber268(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result ^= ((i+1) ^ nums[i]);
        }
        return result;
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
};

#endif