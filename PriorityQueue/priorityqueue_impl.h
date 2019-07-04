#ifndef _PRIORITYQUEUE_IMPL_H
#define _PRIORITYQUEUE_IMPL_H

#include <iostream>
#include <queue>
using namespace std;

class PriorityQueueImpl {
public:
    PriorityQueueImpl() {
        cout << "Impl object for Leetcode Priority Queue problems constructed.\n";
    }

    // 215. Kth Largest Element in an Array
    int findKthLargest215(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }
        
        return pq.top();
    }
};

#endif