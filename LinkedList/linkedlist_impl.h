#ifndef _LINKEDLIST_IMPL_H
#define _LINKEDLIST_IMPL_H

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListImpl {
public:
    // 2. Add Two Numbers (Reverse Order case)
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);
};

#endif