#include "linkedlist_test.h"

LinkedListTest::LinkedListTest() {
    cout << "Test object for Leetcode LinkedList problems constructed.\n";
    implObj = new LinkedListImpl();
}

void LinkedListTest::addTwoNumbers2Test() {
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
void LinkedListTest::removeNthFromEnd19Test() {
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
void LinkedListTest::mergeTwoLists21Test() {
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
void LinkedListTest::mergeKLists23Test() {
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
void LinkedListTest::swapPairs24Test() {
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