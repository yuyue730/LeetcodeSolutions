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