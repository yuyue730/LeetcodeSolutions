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
    testObj->deleteDuplicates83Test();
    testObj->partition86Test();
    testObj->reverseBetween92Test();

    return 0;
}