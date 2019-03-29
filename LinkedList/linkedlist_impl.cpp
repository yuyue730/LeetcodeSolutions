#include "linkedlist_impl.h"

// 2. Add Two Numbers (Reverse Order case)
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

// 19. Remove Nth Node From End of List
ListNode* LinkedListImpl::removeNthFromEnd19(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }

    ListNode * cur = head, * prev = head;
    for (int i = 0; i < n; ++i) {
        if (cur == NULL) {
            return NULL;
        } else {
            cur = cur->next;
        }
    }

    if (cur == NULL) {
        return head->next;
    }

    while (cur->next) {
        prev = prev->next;
        cur = cur->next;
    }

    prev->next = prev->next->next;
    return head;
}

// 21. Merge Two Sorted Lists
ListNode* LinkedListImpl::mergeTwoLists21(ListNode* l1, ListNode* l2) {
    if (l1 == NULL || l2 == NULL) {
        return (l2 == NULL) ? l1 : l2;
    } 

    ListNode * dummy = new ListNode(-1);
    ListNode * cur = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }

        cur = cur->next;
    }

    if (l1) {
        cur->next = l1;
    } else if (l2) {
        cur->next = l2;
    }

    return dummy->next;
}

// 23. Merge k Sorted Lists
ListNode* LinkedListImpl::mergeKLists23(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return NULL;
    }

    int n = lists.size();
    while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; ++i) {
            lists[i] = mergeTwoLists21(lists[i], lists[i + k]);
        }
        n = k;
    }

    return lists[0];
}