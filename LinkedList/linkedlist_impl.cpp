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

// 24. Swap Nodes in Pairs
ListNode* LinkedListImpl::swapPairs24(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* cur = dummy;

    while (cur->next && cur->next->next) {
        ListNode* nextNext = cur->next->next;
        cur->next->next = nextNext->next;
        nextNext->next = cur->next;
        cur->next = nextNext;
        cur = nextNext->next;
    }

    return dummy->next;
}

// 25. Reverse Nodes in k-Group
ListNode* LinkedListImpl::reverseKGroup25(ListNode* head, int k) {
    if (!head || k == 1) {
        return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* cur = head;
    ListNode* prev = dummy;

    for (int i = 1; cur; ++i) {
        if (i % k == 0) {
            prev = reverseOneGroup(prev, cur->next);
            cur = prev->next;
        } else {
            cur = cur->next;
        }
    }

    return dummy->next;
}

ListNode* LinkedListImpl::reverseOneGroup(
    ListNode* prevEnd, ListNode* nextStart
) {
    ListNode* first = prevEnd->next;
    ListNode* cur = first->next;

    while (cur != nextStart) {
        first->next = cur->next;
        cur->next = prevEnd->next;
        prevEnd->next = cur;
        cur = first->next;
    }

    return first;
}

// 83. Remove Duplicates from Sorted List
ListNode* LinkedListImpl::deleteDuplicates83(ListNode * head)
{
    if (head == NULL) {
        return head;
    }

    ListNode *pre = head, *cur = head->next;
    while (cur != NULL) {
        if (cur->val == pre->val) {
            pre->next = cur->next;
            ListNode *tmp = cur;
            cur = cur->next;
            delete tmp;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

    return head;
}

// 86. Partition List
ListNode* LinkedListImpl::partition86(ListNode* head, int x)
{
    if (head == NULL) {
        return head;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *fast = dummy, *slow = dummy;

    while (slow->next && slow->next->val < x) {
        slow = slow->next;
    }
    fast = slow;

    while (fast->next != NULL) {
        if (fast->next->val < x) {
            ListNode *tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
            slow = slow->next;
        } else {
            fast = fast->next;
        }
    }

    return dummy->next;
}

// 92. Reverse Linked List II
ListNode* LinkedListImpl::reverseBetween92(ListNode* head, int m, int n)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy;

    for (int i = 1; i < m; ++i) {
        pre = pre->next;
    }

    ListNode *cur = pre->next;
    for (int i = m; i < n; ++i) {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
    }

    return dummy->next;
}

// 138. Copy List with Random Pointer
Node* LinkedListImpl::copyRandomList138(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    unordered_map<Node *, Node *> curNewMap;
    return copyRandomList138DFS(head, curNewMap);
}

Node* LinkedListImpl::copyRandomList138DFS(
    Node * cur, unordered_map<Node *, Node *> &curNewMap
) {
    if (cur == NULL) {
        return NULL;
    }

    if (curNewMap.count(cur)) {
        return curNewMap[cur];
    }
    Node * newNode = new Node(cur->val, NULL, NULL);
    curNewMap[cur] = newNode;
    newNode->next = copyRandomList138DFS(cur->next, curNewMap);
    newNode->random = copyRandomList138DFS(cur->random, curNewMap);
    return newNode;
}