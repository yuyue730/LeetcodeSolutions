#ifndef _LINKEDLIST_IMPL_H
#define _LINKEDLIST_IMPL_H

#include <iostream>
#include <vector>
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

    // 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd19(ListNode* head, int n);

    // 21. Merge Two Sorted Lists
    ListNode* mergeTwoLists21(ListNode* l1, ListNode* l2);

    // 23. Merge k Sorted Lists
    ListNode* mergeKLists23(vector<ListNode*>& lists);

    // 24. Swap Nodes in Pairs
    ListNode* swapPairs24(ListNode* head);

    // 25. Reverse Nodes in k-Group
    ListNode* reverseKGroup25(ListNode* head, int k);

    // 83. Remove Duplicates from Sorted List
    ListNode* deleteDuplicates83(ListNode* head);

private:
    // 25. Reverse Nodes in k-Group helper
    ListNode* reverseOneGroup(ListNode* prevEnd, ListNode* nextStart);
};

#endif