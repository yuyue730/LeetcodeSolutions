#ifndef _ARRAY_IMPL_H
#define _ARRAY_IMPL_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

class ArrayImpl {
public:
    ArrayImpl() {
        cout << "Impl object for Leetcode Array problems constructed.\n";
    }

    // 4. Median of Two Sorted Arrays
    double findMedianSortedArrays4(
        vector<int>& nums1, vector<int>& nums2
    ) {
        int m = nums1.size(), n = nums2.size();
        double left = findKthInTwoArray(nums1, 0, nums2, 0, (m + n + 1) / 2);
        double right = findKthInTwoArray(nums1, 0, nums2, 0, (m + n + 2) / 2);

        return (left + right) / 2;
    }

    double findKthInTwoArray(
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
    int maxArea11(vector<int>& heights) {
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
    vector<vector<int>> threeSum15(vector<int>& nums) {
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
    int threeSumClosest16(vector<int>& nums, int target) {
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
    vector<vector<int>> fourSum18(vector<int>& nums, int target) {
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
    int removeDuplicates26(vector<int>& nums) {
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
    void nextPermutation31(vector<int>& nums) {
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
    int search33(vector<int>& nums, int target) {
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
    vector<int> searchRange34(vector<int>& nums, int target) {
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
    int searchInsert35(vector<int>& nums, int target) {
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
    int firstMissingPositive41(vector<int>& nums) {
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
    int jump45(vector<int>& nums)
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
    void rotate48(vector<vector<int>>& matrix)
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
    int maxSubArray53(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        return maxSubArrayRec(nums, 0, nums.size() - 1);
    }

    int maxSubArrayRec(const vector<int>& nums, int left, int right)
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
    vector<int> spiralOrder54(vector<vector<int>>& matrix)
    {
        vector<int> result;

        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }

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

    // 55. Jump Game
    bool canJump55(vector<int>& nums)
    {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach || maxReach >= nums.size() - 1) {
                break;
            } else {
                maxReach = max(maxReach, i + nums[i]);
            }
        }

        return (maxReach >= nums.size() - 1);
    }

    // 56. Merge Intervals
    vector<vector<int>> merge56(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            return result;
        }

        sort(intervals.begin(), intervals.end(), 
            [] (const vector<int> &a, const vector<int> &b){
                return a[0] < b[0];
            }
        );

        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > result.back()[1]) {
                result.push_back(intervals[i]);
            } else {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }

    // 57. Insert Interval
    vector<vector<int>> insert57(
        vector<vector<int>>& intervals, 
        vector<int>& newInterval
    ) {
        vector<vector<int>> results;
        int cur = 0;
        while (cur < intervals.size() && intervals[cur][1] < newInterval[0]) {
            results.push_back(intervals[cur]);
            cur++;
        }

        while (cur < intervals.size() && newInterval[1] >= intervals[cur][0]) {
            newInterval[0] = min(intervals[cur][0], newInterval[0]);
            newInterval[1] = max(intervals[cur][1], newInterval[1]);
            cur++;
        }
        results.push_back(newInterval);

        while (cur < intervals.size()) {
            results.push_back(intervals[cur]);
            cur++;
        }

        return results;
    }

    // 59. Spiral Matrix II
    vector<vector<int>> generateMatrix59(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int left = 0, right = n - 1, up = 0, down = n - 1;
        int curVal = 1;

        while (true) {
            for (int i = left; i <= right; ++i) {
                result[up][i] = curVal++;
            }
            if (++up > down) {
                break;
            }

            for (int j = up; j <= down; ++j) {
                result[j][right] = curVal++;
            }
            if (--right < left) {
                break;
            }

            for (int m = right; m >= left; --m) {
                result[down][m] = curVal++;
            }
            if (--down < up) {
                break;
            }

            for (int n = down; n >= up; --n) {
                result[n][left] = curVal++;
            }
            if (++left > right) {
                break;
            }
        }

        return result;
    }

    // 66. Plus One
    vector<int> plusOne66(vector<int>& digits)
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

    // 74. Search a 2D Matrix
    bool searchMatrix74(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1;

        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }

        while (up <= down) {
            int mid = (up + down) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                up = mid + 1;
            } else {
                down = mid - 1;
            }
        }

        int targetRow = down;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }

    // 75. Sort Colors
    void sortColors75(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return;
        }

        int left = 0, right = nums.size() - 1;
        int cur = 0;

        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[left]);
                ++left;
                ++cur;
            } else if (nums[cur] == 1) {
                ++cur;
            } else { // nums[cur] == 2
                swap(nums[cur], nums[right]);
                --right;
            }
        }

        return;
    }

    // 81. Search in Rotated Sorted Array II
    bool search81(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) {
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right--;
            }
        }
        return false;
    }

    // 88. Merge Sorted Array
    void merge88(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int mergeIdx = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[mergeIdx] = nums1[i];
                i--;
            } else {
                nums1[mergeIdx] = nums2[j];
                j--;
            }

            mergeIdx--;
        }

        while (j >= 0) {
            nums1[mergeIdx] = nums2[j];
            j--;
            mergeIdx--;
        }

        return;
    }

    // 118. Pascal's Triangle
    vector<vector<int>> generate118(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) {
            return result;
        }
        result.push_back({1});

        for (int i = 2; i <= numRows; ++i) {
            vector<int> curRow(i, 0);
            for (int j = 0; j < i; ++j) {
                if (j == 0) {
                    curRow[0] = result.back()[0];
                } else if (j == i - 1) {
                    curRow[i - 1] = result.back().back();
                } else {
                    curRow[j] = result.back()[j - 1] + result.back()[j];
                }
            }
            result.push_back(curRow);
        }

        return result;
    }

    // 121. Best Time to Buy and Sell Stock
    int maxProfit121(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }

    // 122. Best Time to Buy and Sell Stock II
    int maxProfit122(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] >= prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        
        return profit;
    }

    // 134. Gas Station
    int canCompleteCircuit134(vector<int>& gas, vector<int>& cost)
    {
        int total = 0, curMax = 0, curStart = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            curMax += gas[i] - cost[i];
            if (curMax < 0) {
                curMax = 0;
                curStart = i + 1;
            }
        }

        return (total < 0) ? -1 : curStart;
    }

    // 135. Candy
    int candy135(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }

        vector<int> candies(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i + 1] + 1, candies[i]);
            }
        }

        int result = 0;
        for (int i = 0; i < candies.size(); ++i) {
            result += candies[i];
        }

        return result;
    }

    // 153. Find Minimum in Rotated Sorted Array
    int findMin153(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        if (nums[left] > nums[right]) {
            while (left != right - 1) {
                int mid = (left + right) / 2;
                if (nums[mid] > nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return min(nums[left], nums[right]);
        } else {
            return nums[0];
        }     
    }

    // 162. Find Peak Element
    int findPeakElement162(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }

    // 163. Missing Ranges
    vector<string> findMissingRanges163(vector<int>& nums, int lower, int upper) {
        int left = lower;
        vector<string> result;
        for (int i = 0; i <= nums.size(); ++i) {
            long long right = (i != nums.size()) 
                ? nums[i] : static_cast<long long>(upper) + 1;
            if (left == right) {
                left = right + 1;
            } else if (right > left) {
                string curResult = (right - left == 1)
                    ? to_string(left) : (to_string(left) + "->" + to_string(right - 1));
                result.push_back(curResult);
                left = right + 1;
            }
        }
        return result;
    }

    // 164. Maximum Gap
    int maximumGap164(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }

        int g_max = INT_MIN, g_min = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            g_max = max(g_max, nums[i]);
            g_min = min(g_min, nums[i]);
        }

        int n_size = nums.size();
        int b_size = (g_max - g_min) / n_size + 1;
        int b_ct = (g_max - g_min) / b_size + 1;

        vector<pair<int, int>> b_minmax(b_ct, {INT_MAX, INT_MIN});
        for (int i = 0; i < n_size; ++i) {
            int b_id = (nums[i] - g_min) / b_size;
            b_minmax[b_id].first = min(b_minmax[b_id].first, nums[i]);
            b_minmax[b_id].second = max(b_minmax[b_id].second, nums[i]);
        }

        int pre = 0;
        int result = 0;
        for (int i = 1; i < b_ct; ++i) {
            if (b_minmax[i].first == INT_MAX || b_minmax[i].second == INT_MIN) {
                continue;
            }

            result = max(result, b_minmax[i].first - b_minmax[pre].second);
            pre = i;
        }

        return result;
    }

    // 167. Two Sum II - Input array is sorted
    vector<int> twoSum167(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            } else if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }

    // 169. Majority Element
    int majorityElement169(vector<int>& nums) {
        int count = 0, result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                result = nums[i];
                ++count;
            } else {
                (result == nums[i]) ? ++count : --count;
            }
        }

        return result;
    }

    // 189. Rotate Array
    void rotate189(vector<int>& nums, int k) {
        if (nums.empty()) {
            return;
        }

        k = k % nums.size();
        if (k == 0) {
            return;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    // 209. Minimum Size Subarray Sum
    int minSubArrayLen209(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int result = INT_MAX, arr_len = nums.size();
        int cur_sum = 0;

        while (right < arr_len) {
            while (right < arr_len && cur_sum < s) {
                cur_sum += nums[right];
                right++;
            }

            while (left <= right && cur_sum >= s) {
                result = min(result, right - left);
                cur_sum -= nums[left];
                left++;
            }
        }

        return (result > nums.size()) ? 0 : result;
    }

    // 228. Summary Ranges
    vector<string> summaryRanges228(vector<int>& nums) {
        vector<string> result;
        int i = 0;
        while (i < nums.size()) {
            int j = 1;
            while (i + j < nums.size() && 
                static_cast<long>(nums[i + j]) - static_cast<long>(nums[i]) == j
            ) {
                ++j;
            }

            if (j == 1) {
                result.push_back(to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            }
            i += j;
        }
        return result;
    }

    // 229. Majority Element II
    vector<int> majorityElement229(vector<int>& nums) {
        int m = -1, ct1 = 0, n = -1, ct2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == m) {
                ++ct1;
            } else if (nums[i] == n) {
                ++ct2;
            } else if (ct1 == 0) {
                m = nums[i];
                ct1 = 1;
            } else if (ct2 == 0) {
                n = nums[i];
                ct2 = 1;
            } else {
                ct1--;
                ct2--;
            }
        }

        vector<int> result;
        ct1 = 0;
        ct2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == m) {
                ct1++;
            } else if (nums[i] == n) {
                ct2++;
            }
        }
        if (ct1 > nums.size() / 3) {
            result.push_back(m);
        }
        if (ct2 > nums.size() / 3) {
            result.push_back(n);
        }
        return result;
    }

    // 238. Product of Array Except Self
    vector<int> productExceptSelf238(vector<int>& nums) {
        vector<int> forward(nums.size(), 1);
        vector<int> backward(nums.size(), 1);
        vector<int> result(nums.size(), 1);

        for (int i = 0; i < nums.size() - 1; ++i) {
            forward[i + 1] = forward[i] * nums[i];
        }
        for (int i = nums.size() - 1; i > 0; --i) {
            backward[i - 1] = backward[i] * nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = forward[i] * backward[i];
        }

        return result;
    }

    // 239. Sliding Window Maximum
    vector<int> maxSlidingWindow239(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            while (!heap.empty() && heap.top().second <= i - k) {
                heap.pop();
            }
            heap.push({nums[i], i});
            if (i >= k - 1) {
                result.push_back(heap.top().first);
            }
        }

        return result;
    }

    // 240. Search a 2D Matrix II
    bool searchMatrix240(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        if (target < matrix[0][0] || target > matrix.back().back()) {
            return false;
        }

        int i = matrix.size() - 1, j = 0;
        while (true) {
            if (target > matrix[i][j]) {
                j++;
            } else if (target < matrix[i][j]) {
                i--;
            } else {
                return true;
            }
            if (i < 0 || j >= matrix[0].size()) {
                break;
            }
        }
        return false;
    }

    // 243. Shortest Word Distance
    int shortestDistance243(vector<string>& words, string word1, string word2) {
        vector<int> idx1;
        vector<int> idx2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                idx1.push_back(i);
            }
            if (words[i] == word2) {
                idx2.push_back(i);
            }
        }

        int result = INT_MAX;
        for (int m = 0; m < idx1.size(); ++m) {
            for (int n = 0; n < idx2.size(); ++n) {
                result = min(result, abs(idx1[m] - idx2[n]));
            }
        }
        return result;
    }

    // 277. Find the Celebrity
    bool knows277(int a, int b) {
        vector<vector<bool>> knows = {
            {true, true, false},
            {false, true, false},
            {true, true, true}
        };
        return knows[a][b];
    }

    int findCelebrity277(int n) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (knows277(result, i)) {
                result = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != result) {
                if (knows277(result, i) || !knows277(i, result)) {
                    return -1;
                }
            }
        }
        return result;
    }

    // 278. First Bad Version
    bool isBadVersion(int version) {
        return (version >= 5);
    }

    int firstBadVersion278(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    // 280. Wiggle Sort
    void wiggleSort280(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || 
                (i % 2 == 0 && nums[i] > nums[i - 1])) 
            {
                swap(nums[i], nums[i - 1]);       
            }
        }
    }

    // 283. Move Zeroes
    void moveZeroes283(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                nums[left] = nums[right];
                ++left;
            }
            ++right;
        }

        while (left < nums.size()) {
            nums[left] = 0;
            ++left;
        }
    }

    // 287. Find the Duplicate Number
    int findDuplicate287(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int ct = 0;
            for (auto num: nums) {
                if (num <= mid) {
                    ++ct;
                }
            }

            if (ct <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }

    // 289. Game of Life
    void gameOfLife289(vector<vector<int>>& board) {
        const vector<pair<int, int>> direc = {
            {0, 1}, {1, 1}, {1, 0}, {1, -1},
            {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
        };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int live_cell_ct = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + direc[k].first;
                    int y = j + direc[k].second;
                    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                        continue;
                    }
                    if (board[x][y] == 1 || board[x][y] == 2) {
                        ++live_cell_ct;
                    }
                }

                if (board[i][j] == 1 && (live_cell_ct < 2 || live_cell_ct > 3)) {
                    board[i][j] = 2;
                } else if (board[i][j] == 0 && live_cell_ct == 3) {
                    board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] %= 2;
            }
        }
    }

    // 296. Best Meeting Point
    int minTotalDistance296(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return vector_min_dist(rows) + vector_min_dist(cols);
    }

    int vector_min_dist(vector<int> & arr) {
        sort(arr.begin(), arr.end());
        int i = 0, j = arr.size() - 1;
        int result = 0;
        while (i < j) {
            result += arr[j] - arr[i];
            j--;
            i++;
        }
        return result;
    }

    // 315. Count of Smaller Numbers After Self
    vector<int> countSmaller315(vector<int>& nums) {
        vector<int> sort_arr;
        vector<int> result(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; --i) {
            int left = 0;
            int right = sort_arr.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (sort_arr[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            result[i] = right;
            sort_arr.insert(sort_arr.begin() + right, nums[i]);
        }

        return result;
    }

    // 334. Increasing Triplet Subsequence
    bool increasingTriplet334(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        int n = nums.size();
        vector<int> forward(n, nums[0]);
        vector<int> backward(n, nums[n - 1]);

        for (int i = 1; i < n; ++i) {
            forward[i] = min(forward[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
            backward[i] = max(backward[i + 1], nums[i]);
        }

        for (int i = 1; i <= n - 1; ++i) {
            if (nums[i] > forward[i] && nums[i] < backward[i]) {
                return true;
            }
        }

        return false;
    }

    // 363. Max Sum of Rectangle No Larger Than K
    int maxSumSubmatrix363(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        int result = INT_MIN;
        for (int left = 0; left < n; ++left) {
            vector<int> sum(m, 0);
            for (int j = left; j < n; ++j) {
                for (int i = 0; i < m; ++i) {
                    sum[i] += matrix[i][j];
                }

                for (int i = 0; i < sum.size(); ++i) {
                    int curSum = 0;
                    for (int j = i; j < sum.size(); ++j) {
                        curSum += sum[j];
                        if (curSum <= k) {
                            result = max(result, curSum);
                        }
                    }
                }
            }
        }
        
        return result;
    }

    // 378. Kth Smallest Element in a Sorted Matrix
    int kthSmallest378(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if (count < k) {
                left = mid + 1;
            }
            else right = mid;
        }
        
        return left;
    }
};

#endif