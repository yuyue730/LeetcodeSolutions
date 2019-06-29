#ifndef _LINKEDLIST_TEST_H
#define _LINKEDLIST_TEST_H

#include "linkedlist_impl.h"

#include <iostream>
using namespace std;

class LinkedListTest {
public: 
    LinkedListTest() {
        cout << "Test object for Leetcode LinkedList problems constructed.\n";
        implObj = new LinkedListImpl();
    }

    // 2. Add Two Numbers Test
    void addTwoNumbers2Test() {
        cout << "2. Add Two Numbers test starts\n";

        ListNode * tmp = NULL;
        ListNode * l1 = new ListNode(2);
        tmp = l1; tmp->next = new ListNode(4); 
        tmp = tmp->next; tmp->next = new ListNode(3);
        ListNode * l2 = new ListNode(5);
        tmp = l2; tmp->next = new ListNode(6);
        tmp = tmp->next; tmp->next = new ListNode(7);

        ListNode * result = implObj->addTwoNumbers2(l1, l2);
        cout << "Result list: ";
        while (result) {
            cout << result->val << "->";
            result = result->next;
        }
        cout << "\n\n";

        return;
    }

    // 19. Remove Nth Node From End of List Test
    void removeNthFromEnd19Test() {
        cout << "19. Remove Nth Node From End of List test starts.\n";
        ListNode * head = new ListNode(1);
        ListNode * cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;

        ListNode * new_head = implObj->removeNthFromEnd19(head, 2);
        cur = new_head;

        cout << "Output linked list is [";
        while (cur) {
            cout << cur->val << "; ";
            cur = cur->next;
        }
        cout << "]\n\n";
        return;
    }

    // 21. Merge Two Sorted Lists Test
    void mergeTwoLists21Test() {
        cout << "21. Merge Two Sorted Lists test starts.\n";
        ListNode * head1 = new ListNode(1);
        ListNode * cur = head1; 
        cur->next = new ListNode(2);
        cur->next->next = new ListNode(4);

        ListNode * head2 = new ListNode(1);
        cur = head2;
        cur->next = new ListNode(3);
        cur->next->next = new ListNode(4);

        ListNode * head = implObj->mergeTwoLists21(head1, head2);
        cout << "Output linked list is [";
        while (head) {
            cout << head->val << "; ";
            head = head->next;
        }
        cout << "]\n\n";
        return;
    }

    // 23. Merge k Sorted Lists Test
    void mergeKLists23Test() {
        cout << "23. Merge k Sorted Lists test starts.\n";

        ListNode * head1 = new ListNode(1);
        ListNode * cur = head1; 
        cur->next = new ListNode(4);
        cur->next->next = new ListNode(5);

        ListNode * head2 = new ListNode(1);
        cur = head2; 
        cur->next = new ListNode(3);
        cur->next->next = new ListNode(4);

        ListNode * head3 = new ListNode(2);
        cur = head3; 
        cur->next = new ListNode(6);

        vector<ListNode *> lists = {head1, head2, head3};
        ListNode * head = implObj->mergeKLists23(lists);

        cout << "Output linked list is [";
        while (head) {
            cout << head->val << "; ";
            head = head->next;
        }
        cout << "]\n\n";
    }

    // 24. Swap Nodes in Pairs Test
    void swapPairs24Test() {
        cout << "24. Swap Nodes in Pairs test starts.\n";

        ListNode * head = new ListNode(1);
        ListNode * cur = head; 
        cur->next = new ListNode(2);  cur = cur->next;
        cur->next = new ListNode(3);  cur = cur->next;
        cur->next = new ListNode(4);

        ListNode* newHead = implObj->swapPairs24(head);

        cout << "Output linked list is [";
        while (newHead) {
            cout << newHead->val << "; ";
            newHead = newHead->next;
        }
        cout << "]\n\n";
    }

    // 25. Reverse Nodes in k-Group Test
    void reverseKGroup25Test() {
        cout << "25. Reverse Nodes in k-Group test starts.\n";

        ListNode * head = new ListNode(1);
        ListNode * cur = head; 
        cur->next = new ListNode(2);  cur = cur->next;
        cur->next = new ListNode(3);  cur = cur->next;
        cur->next = new ListNode(4);  cur = cur->next;
        cur->next = new ListNode(5);

        ListNode* result = implObj->reverseKGroup25(head, 3);
        cout << "Output linked list is [";
        while (result) {
            cout << result->val << "; ";
            result = result->next;
        }

        cout << "]\n\n";
    }

    // 83. Remove Duplicates from Sorted List Test
    void deleteDuplicates83Test() {
        cout << "83. Remove Duplicates from Sorted List test starts.\n";
        ListNode *head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(1); cur = cur->next;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(3);

        ListNode *result = implObj->deleteDuplicates83(head);
        cout << "Result LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 86. Partition List Test
    void partition86Test() {
        cout << "86. Partition List test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(1); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(2);

        ListNode *result = implObj->partition86(head, 3);
        cout << "Result LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 92. Reverse Linked List II Test
    void reverseBetween92Test()  {
        cout << "92. Reverse Linked List II test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        ListNode *result = implObj->reverseBetween92(head, 2, 4);
        cout << "Reversed LinkedList [";
        while (result) {
            cout << result->val << ((result->next == NULL) ? "" : "->");
            result = result->next;
        }
        cout << "]\n\n";
        return;
    }

    // 138. Copy List with Random Pointer Test
    void copyRandomList138Test() {
        cout << "138. Copy List with Random Pointer test starts.\n";
        Node * head = new Node(1, NULL, NULL);
        Node * next = new Node(2, NULL, NULL);

        head->next = next;
        head->random = next;
        next->next = NULL;
        next->random = next;
        Node * clone = implObj->copyRandomList138(head);
        cout << "Please exam the cloned linked list [" << clone->val << "]\n\n";
        return;
    }

    // 141. Linked List Cycle Test
    void hasCycle141Test() {
        cout << "141. Linked List Cycle test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); 
        ListNode * two = cur->next;
        cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next; 
        cur->next = two;

        cout << "has Cycle = [" << (implObj->hasCycle141(head) ? "True" : "False") << "]\n\n";
        return;
    }

    // 142. Linked List Cycle II Test
    void detectCycle142Test() {
        cout << "142. Linked List Cycle II test starts.\n";
        ListNode* head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); 
        ListNode * two = cur->next;
        cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next; 
        cur->next = two;

        cout << "Fist overlap node = [" << implObj->detectCycle142(head)->val << "].\n\n";
        return;
    }

    // 143. Reorder List Test
    void reorderList143Test() {
        cout << "143. Reorder List test starts.\n";
        ListNode *head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        implObj->reorderList143(head);
        cout << "Please exam linked list via debugger. [" << head->val << "]\n\n";
        return;
    }

    // 148. Sort List Test
    void sortList148Test() {
        cout << "148. Sort List test starts.\n";
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(0);

        ListNode *result = implObj->sortList148(head);
        cout << "Please exam linked list via debugger. [" << result->val << "]\n\n";
        return;
    }

    // 160. Intersection of Two Linked Lists Test
    void getIntersectionNode160Test() {
        cout << "160. Intersection of Two Linked Lists test starts.\n";
        ListNode *common = new ListNode(8);
        ListNode *cur = common;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        ListNode *headA = new ListNode(4);
        cur = headA; cur->next = new ListNode(1);
        cur = cur->next; cur->next = common;

        ListNode *headB = new ListNode(5);
        cur = headB; cur->next = new ListNode(0);
        cur = cur->next; cur->next = new ListNode(1);
        cur = cur->next; cur->next = common;

        ListNode *startPoint = implObj->getIntersectionNode160(headA, headB);
        cout << "Please exam start point in debugger\n";
        return;
    }

    // 203. Remove Linked List Elements Test
    void removeElements203Test() {
        cout << "203. Remove Linked List Elements test starts.\n";
        ListNode *head = new ListNode(1);
        ListNode *cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(6); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5); cur = cur->next;
        cur->next = new ListNode(6);

        ListNode *result = implObj->removeElements203(head, 6);
        cout << "Please exam result pointer [" << result->val << "]\n\n";
        return;
    }

    // 206. Reverse Linked List Test
    void reverseList206Test() {
        cout << "206. Reverse Linked List test starts.\n";
        ListNode * head = new ListNode(1);
        ListNode * cur = head;
        cur->next = new ListNode(2); cur = cur->next;
        cur->next = new ListNode(3); cur = cur->next;
        cur->next = new ListNode(4); cur = cur->next;
        cur->next = new ListNode(5);

        ListNode * result = implObj->reverseList206(head);
        cout << "Please exam result pointer [" << result->val << "]\n\n";
        return;
    }

private:
    LinkedListImpl * implObj;
};

#endif