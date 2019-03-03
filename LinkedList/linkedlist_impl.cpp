#include "linkedlist_impl.h"

ListNode* LinkedListImpl::addTwoNumbers2(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return NULL;

    ListNode * dummy = new ListNode(-1);
    ListNode * tmp = dummy;
    bool isPlusOne = false;

    while (l1 && l2) {
        int curNewVal = l1->val + l2->val + (isPlusOne ? 1 : 0);
        cout << "curVal = " << curNewVal << "\n";
        isPlusOne = curNewVal >= 10;
        tmp->next = new ListNode(curNewVal % 10);
        tmp = tmp->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    ListNode * remainListNode = l1 ? l1 : (l2 ? l2: NULL);
    while (remainListNode) {
        int curNewVal = remainListNode->val + (isPlusOne ? 1 : 0);
        isPlusOne = curNewVal >= 10;
        tmp->next = new ListNode(curNewVal % 10);
        tmp = tmp->next;
        remainListNode = remainListNode->next;
    }

    if (isPlusOne) tmp->next = new ListNode(1);
    ListNode * newHead = dummy->next;
    delete dummy;
    return newHead;
}