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

    // 218. The Skyline Problem Test
    void getSkyline218Test() {
        cout << "218. The Skyline Problem test starts.\n";
        vector<vector<int>> buildings = {
            {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
        };
        vector<vector<int>> result = implObj->getSkyline218(buildings);
        cout << "Pairs = [";
        for (int i = 0; i < result.size(); ++i) {
            cout << "(" << result[i][0] << ", " << result[i][1] << ")" 
                << (i == (result.size() - 1) ? "" : ", ");
        }
        cout << "]\n\n";
        return;
    }

    // 253. Meeting Rooms II Test
    void minMeetingRooms253Test() {
        cout << "253. Meeting Rooms II test starts.\n";
        vector<vector<int>> intervals = {
            {0, 30}, {5, 10}, {15, 20}
        };
        cout << "Number of rooms = [" << implObj->minMeetingRooms253(intervals) << "]\n\n";
        return;
    }

private:
    PriorityQueueImpl * implObj;
};

#endif