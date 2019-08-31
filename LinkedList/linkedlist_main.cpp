#include "linkedlist_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode Linked List Problem Solution Application starts.\n";
    LinkedListTest * testObj = new LinkedListTest();
    cout << "\nTest for problems starts.\n";

    testObj->addTwoNumbers2Test();
    testObj->removeNthFromEnd19Test();
    testObj->mergeTwoLists21Test();
    testObj->mergeKLists23Test();
    testObj->swapPairs24Test();
    testObj->reverseKGroup25Test();
    testObj->rotateRight61Test();
    testObj->deleteDuplicates82Test();
    testObj->deleteDuplicates83Test();
    testObj->partition86Test();
    testObj->reverseBetween92Test();
    testObj->copyRandomList138Test();
    testObj->hasCycle141Test();
    testObj->detectCycle142Test();
    testObj->reorderList143Test();
    testObj->sortList148Test();
    testObj->getIntersectionNode160Test();
    testObj->removeElements203Test();
    testObj->reverseList206Test();
    testObj->isPalindrome234Test();

    return 0;
}