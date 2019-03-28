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

private:
    LinkedListImpl * implObj;
};

#endif