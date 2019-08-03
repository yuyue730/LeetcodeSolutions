// Leetcode Design Problems main function
#include "design_test.h"

#include <iostream>
using namespace std;

int main() {
    cout << "Leetcode Design Problem Solution Application starts.\n";
    DesignTest * testObj = new DesignTest();
    cout << "\nTest for problems starts.\n";

    testObj->LRUCache146Test();
    testObj->MinStack155Test();
    testObj->TwoSum170Test();
    testObj->BSTIterator173Test();
    testObj->Trie208Test();
    testObj->MyStack225Test();
    testObj->MyQueue232Test();
    testObj->PeekingIterator284Test();

    return 0;
}