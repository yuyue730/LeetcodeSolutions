    // Leetcode Array Problems main function
#include <iostream>
#include "priorityqueue_test.h"
using namespace std;

int main() {
    cout << "Leetcode Priority Queue Problem Solution Application starts.\n";
    PriorityQueueTest * testObj = new PriorityQueueTest();
    cout << "\nTest for problems starts.\n";

    testObj->findKthLargest215Test();
    testObj->getSkyline218Test();
    testObj->minMeetingRooms253Test();

    return 0;
}