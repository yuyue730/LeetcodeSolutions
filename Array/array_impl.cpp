#include <iostream>
#include <algorithm>
#include <set>

#include "array_impl.h"

using namespace std;

ArrayImpl::ArrayImpl() {
    cout << "Impl object for Leetcode Array problems constructed.\n";
}

// 4. Median of Two Sorted Arrays
double ArrayImpl::findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size(), n = nums2.size();
    double left = findKthInTwoArray(nums1, 0, nums2, 0, (m + n + 1) / 2);
    double right = findKthInTwoArray(nums1, 0, nums2, 0, (m + n + 2) / 2);

    return (left + right) / 2;
}

double ArrayImpl::findKthInTwoArray(
    const vector<int>& nums1, int i, 
    const vector<int>& nums2, int j, int k)
{
    if (i >= nums1.size()) {
        return static_cast<double>(nums2[j + k - 1]);
    }
    if (j >= nums2.size()) {
        return static_cast<double>(nums1[i + k - 1]);
    }
    if (k == 1) {
        return min(nums1[i], nums2[j]);
    }

    int midVal1 = i + k / 2 - 1 < nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = j + k / 2 - 1 < nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;

    if (midVal1 < midVal2) {
        return findKthInTwoArray(nums1, i + k / 2, nums2, j, k - k /2);
    } else {
        return findKthInTwoArray(nums1, i, nums2, j + k / 2, k - k /2);
    }
}

// 11. Container With Most Water
int ArrayImpl::maxArea11(vector<int>& heights)
{
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

// 15. 3Sum
vector<vector<int>> ArrayImpl::threeSum15(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
        return {};
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            break;
        }
        if (i >= 1 && nums[i] == nums[i - 1]) {
            continue;
        }
        int target = -nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left + 1] == nums[left]) {
                    ++left;
                }
                while (right > left && nums[right - 1] == nums[right]) {
                    --right;
                }
                ++left;
                --right;
            } else if (nums[left] + nums[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return result;
}

// 16. 3Sum Closest
int ArrayImpl::threeSumClosest16(vector<int>& nums, int target)
{
    assert(nums.size() > 2);
    int minSum = nums[0] + nums[1] + nums[2];
    int minDiff = abs(minSum - target);
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int curSum = nums[i] + nums[left] + nums[right];
            int curDiff = abs(curSum - target);
            if (curDiff < minDiff) {
                minDiff = curDiff;
                minSum = curSum;
            }
            if (curSum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    return minSum;
}

// 18. 4Sum
vector<vector<int>> ArrayImpl::fourSum18(vector<int>& nums, int target)
{
    if (nums.size() <= 3) {
        return {};
    }
    sort(nums.begin(), nums.end());
    set<vector<int>> resultSet;
    for (int i = 0; i < nums.size() - 3; ++i) {
        for (int j = i + 1; j < nums.size() - 2; ++j) {
            int left = j + 1, right = nums.size() - 1;
            while (left < right) {
                int curSum = nums[i] + nums[j] + nums[left] + nums[right];
                if (curSum == target) {
                    resultSet.insert({nums[i], nums[j], nums[left], nums[right]});
                    ++left;
                    --right;
                } else if (curSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }

    return vector<vector<int>>(resultSet.begin(), resultSet.end());
}

// 26. Remove Duplicates from Sorted Array
int ArrayImpl::removeDuplicates26(vector<int>& nums)
{
    if (nums.empty()) {
        return 0;
    }

    int curIdx = 0;
    for (int right = 1; right < nums.size(); ++right) {
        if (nums[right] != nums[right - 1]) {
            curIdx++;
            nums[curIdx] = nums[right];
        }
    }

    return curIdx + 1;
}

// 31. Next Permutation
void ArrayImpl::nextPermutation31(vector<int>& nums)
{
    if (nums.size() == 0) {
        return;
    }

    int smallIdx = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            smallIdx = i;
            break;
        }
    }

    if (smallIdx == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int largeIdx = -1;
    for (int j = nums.size() - 1; j >= smallIdx; --j) {
        if (nums[j] > nums[smallIdx]) {
            largeIdx = j;
            break;
        }
    }

    swap(nums[smallIdx], nums[largeIdx]);

    reverse(nums.begin() + smallIdx + 1, nums.end());
    return;
}

// 33. Search in Rotated Sorted Array
int ArrayImpl::search33(vector<int>& nums, int target)
{
    if (nums.empty()) {
        return -1;
    }

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int pivot = left + (right - left) / 2;
        if (nums[pivot] == target) {
            return pivot;
        }

        if (nums[pivot] > nums[right]) {
            if (target < nums[pivot] && target >= nums[left]) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        } else {
            if (target > nums[pivot] && target <= nums[right]) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
    }

    return -1;
}

// 34. Find First and Last Position of Element in Sorted Array
vector<int> ArrayImpl::searchRange34(vector<int> &nums, int target)
{
    vector<int> result = {-1, -1};
    if (nums.size() == 0) {
        return result;
    }

    int left = 0, right = nums.size() - 1;
    int idxFound = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            idxFound = mid;
            break;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (idxFound == -1) {
        return result;
    }

    int lIdx = idxFound, rIdx = idxFound;
    while (lIdx >= 0 && nums[lIdx] == target) {
        --lIdx;
    }
    while (rIdx < nums.size() && nums[rIdx] == target) {
        ++rIdx;
    }

    result = {lIdx + 1, rIdx - 1};
    return result;
}

// 35. Search Insert Position
int ArrayImpl::searchInsert35(vector<int>& nums, int target)
{
    if (nums.size() == 0) {
        return 0;
    }

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

// 41. First Missing Positive
int ArrayImpl::firstMissingPositive41(vector<int>& nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

// 45. Jump Game II
int ArrayImpl::jump45(vector<int>& nums)
{
    int cur = 0, i = 0, step = 0;
    while (cur < nums.size() - 1) {
        int pre = cur;
        while (i <= pre) {
            cur = max(cur, nums[i] + i);
            ++i;
        }
        ++step;
        if (cur == pre) {
            return -1;
        }
    }

    return step;
}

// 48. Rotate Image
void ArrayImpl::rotate48(vector<vector<int>>& matrix)
{
    int edgeSize = matrix[0].size();
    for (int i = 0; i < edgeSize / 2; ++i) {
        for (int j = i; j < edgeSize - 1 - i; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[edgeSize - 1 - j][i];
            matrix[edgeSize - 1 - j][i] = matrix[edgeSize - 1 - i][edgeSize - 1 - j];
            matrix[edgeSize - 1 - i][edgeSize - 1 - j] = matrix[j][edgeSize - 1 - i];
            matrix[j][edgeSize - 1 - i] = temp;
        }
    }
    return;
}

// 53. Maximum Subarray
int ArrayImpl::maxSubArray53(vector<int>& nums)
{
    if (nums.empty()) return 0;
    return maxSubArrayRec(nums, 0, nums.size() - 1);
}

int ArrayImpl::maxSubArrayRec(const vector<int>& nums, int left, int right)
{
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

// 54. Spiral Matrix
vector<int> ArrayImpl::spiralOrder54(vector<vector<int>>& matrix)
{
    vector<int> result;
    int left = 0, right = matrix[0].size() - 1;
    int up = 0, down = matrix.size() - 1;

    while (true) {
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[up][i]);
        }
        ++up;
        if (up > down) break;

        for (int j = up; j <= down; ++j) {
            result.push_back(matrix[j][right]);
        }
        --right;
        if (right < left) break;

        for (int m = right; m >= left; --m) {
            result.push_back(matrix[down][m]);
        }
        --down;
        if (down < up) break;

        for (int n = down; n >= up; --n) {
            result.push_back(matrix[n][left]);
        }
        ++left;
        if (left > right) break;
    }

    return result;
}

// 66. Plus One
vector<int> ArrayImpl::plusOne66(vector<int>& digits)
{
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