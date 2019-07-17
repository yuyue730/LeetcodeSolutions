#ifndef _LINKEDLIST_IMPL_H
#define _LINKEDLIST_IMPL_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class LinkedListImpl {
public:
    // 2. Add Two Numbers (Reverse Order case)
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
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
    ListNode* removeNthFromEnd19(ListNode* head, int n) {
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
    ListNode* mergeTwoLists21(ListNode* l1, ListNode* l2) {
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
    ListNode* mergeKLists23(vector<ListNode*>& lists) {
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
    ListNode* swapPairs24(ListNode* head) {
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
    ListNode* reverseKGroup25(ListNode* head, int k) {
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

    ListNode* reverseOneGroup(
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
    ListNode* deleteDuplicates83(ListNode* head) {
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
    ListNode* partition86(ListNode* head, int x) {
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
    ListNode* reverseBetween92(ListNode* head, int m, int n) {
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
    Node* copyRandomList138(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        unordered_map<Node *, Node *> curNewMap;
        return copyRandomList138DFS(head, curNewMap);
    }

    Node* copyRandomList138DFS(
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

    // 141. Linked List Cycle
    bool hasCycle141(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }

    // 142. Linked List Cycle II
    ListNode *detectCycle142(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }

        if (!fast || !fast->next) {
            return NULL;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }

    // 143. Reorder List
    void reorderList143(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }

        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *pre = NULL, *cur = mid;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        while (head && pre) {
            ListNode *nextHead = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = nextHead;
            head = nextHead;
        }
    }

    // 148. Sort List
    ListNode* sortList148(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = NULL;
        return mergeSortList(sortList148(head), sortList148(slow));
    }

    ListNode * mergeSortList(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *dummy = new ListNode(-1), *cur = dummy;

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
        }
        if (l2) {
            cur->next = l2;
        }

        return dummy->next;
    }

    // 160. Intersection of Two Linked Lists
    ListNode * getIntersectionNode160(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        int lenA = getLinkedListLength(headA);
        int lenB = getLinkedListLength(headB);

        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; ++i) {
                headB = headB->next;
            }
        } else {
            for (int i = 0; i < lenA - lenB; ++i) {
                headA = headA->next;
            }
        }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return (headA == headB) ? headA : NULL;
    }

    int getLinkedListLength(ListNode *head) {
        int result = 0;
        ListNode * cur = head;
        while (cur) {
            ++result;
            cur = cur->next;
        }

        return result;
    }

    // 203. Remove Linked List Elements
    ListNode* removeElements203(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;

        while (cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }

    // 206. Reverse Linked List
    ListNode* reverseList206(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = head;
        dummy->next = head;
        while (cur->next) {
            ListNode * tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }

        return dummy->next;
    }

    // 234. Palindrome Linked List
    bool isPalindrome234(ListNode* head) {
        if (!head) {
            return true;
        }
        stack<int> val_stack;
        ListNode * cur = head;
        while (cur) {
            val_stack.push(cur->val);
            cur = cur->next;
        }

        while (head) {
            int cur_val = val_stack.top();
            val_stack.pop();
            if (cur_val != head->val) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};

#endif