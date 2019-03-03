#ifndef _ARRAY_IMPL_H
#define _ARRAY_IMPL_H

#include <vector>
using namespace std;

class ArrayImpl {
public:
    ArrayImpl();

    // 11. Container With Most Water Test
    int maxArea11(vector<int>& heights);

    // 53. Maximum Subarray
    int maxSubArray53(vector<int>& nums);

    // 66. Plus One
    vector<int> plusOne66(vector<int>& digits);

private:
    // 53. Maximum Subarray helper
    int maxSubArrayRec(const vector<int>& nums, int left, int right);
};

#endif