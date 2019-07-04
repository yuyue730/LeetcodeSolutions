#ifndef _PRIORITYQUEUE_TEST_H
#define _PRIORITYQUEUE_TEST_H

#include <iostream>

#include "priorityqueue_impl.h"
using namespace std;

class PriorityQueueTest {
public:
    PriorityQueueTest() {
        cout << "Test object for Leetcode Priority Queue problems constructed.\n";
        implObj = new PriorityQueueImpl();
    }

    // 215. Kth Largest Element in an Array Test
    void findKthLargest215Test() {
        cout << "215. Kth Largest Element in an Array test starts.\n";
        vector<int> nums = {3,2,1,5,6,4};
        cout << "Top 2 = [" << implObj->findKthLargest215(nums, 2) << "]\n\n";
        return;
    }

private:
    PriorityQueueImpl * implObj;
};

#endif