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