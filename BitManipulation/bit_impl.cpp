#include "bit_impl.h"

BitManipulationImpl::BitManipulationImpl() {
    cout << "Impl object for Leetcode Bit Manipulation problems constructed.\n";
}

// 136. Single Number
int BitManipulationImpl::singleNumber136(vector<int>& nums) {
    int andValue = 0;
    for (int i = 0; i < nums.size(); ++i) {
        andValue ^= nums[i];
    }

    return andValue;
}

// 137. Single Number II
int BitManipulationImpl::singleNumber137(vector<int>& nums) {
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