#include <iostream>
#include <algorithm>

#include "array_impl.h"

using namespace std;

ArrayImpl::ArrayImpl() {
    cout << "Impl object for Leetcode Array problems constructed.\n";
}

int ArrayImpl::maxArea11(vector<int>& heights) {
    if (!heights.size()) return -1;

    int left = 0, right = heights.size() - 1;
    int maxArea = 0;
    
    while (left < right) {
        maxArea = max(maxArea, min(heights[left], heights[right]) * (right - left));
        if (heights[left] < heights[right]) ++left;
        else --right;
    }
    
    return maxArea;
}

int ArrayImpl::maxSubArray53(vector<int>& nums) {
    if (nums.empty()) return 0;
    return maxSubArrayRec(nums, 0, nums.size() - 1);
}

int ArrayImpl::maxSubArrayRec(const vector<int>& nums, int left, int right) {
    if (left >= right) return nums[left];
    int pivot = left + (right - left) / 2;
    int lmax = maxSubArrayRec(nums, left, pivot - 1);
    int rmax = maxSubArrayRec(nums, pivot + 1, right);

    int curMax = nums[pivot], temp = nums[pivot];
    for (int i = pivot - 1; i >= left; --i) {
        temp += nums[i];
        curMax = max(temp, curMax);
     }
    temp = curMax;
    for (int j = pivot + 1; j <= right; ++j) {
        temp += nums[j];
        curMax = max(temp, curMax);
    }

    return max(curMax, max(lmax, rmax));
}

vector<int> ArrayImpl::plusOne66(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i]++;
            return digits;
        }
    }

    if (digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}