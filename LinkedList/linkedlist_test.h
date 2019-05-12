#ifndef _LINKEDLIST_TEST_H
#define _LINKEDLIST_TEST_H

#include "linkedlist_impl.h"

#include <iostream>
using namespace std;

class LinkedListTest {
public: 
    LinkedListTest();

    // 2. Add Two Numbers Test
    void addTwoNumbers2Test();

    // 19. Remove Nth Node From End of List Test
    void removeNthFromEnd19Test();

    // 21. Merge Two Sorted Lists Test
    void mergeTwoLists21Test();

    // 23. Merge k Sorted Lists Test
    void mergeKLists23Test();

    // 24. Swap Nodes in Pairs Test
    void swapPairs24Test();

    // 25. Reverse Nodes in k-Group Test
    void reverseKGroup25Test();

    // 83. Remove Duplicates from Sorted List Test
    void deleteDuplicates83Test();

    // 86. Partition List Test
    void partition86Test();

    // 92. Reverse Linked List II Test
    void reverseBetween92Test();

private:
    LinkedListImpl * implObj;
};

#endif