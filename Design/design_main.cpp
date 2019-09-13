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
    testObj->WordDictionary211Test();
    testObj->MyStack225Test();
    testObj->MyQueue232Test();
    testObj->PeekingIterator284Test();
    testObj->MedianFinder295Test();
    testObj->Codec297Test();
    testObj->MovingAverage346Test();
    testObj->TicTacToe348Test();
    testObj->SnakeGame353Test();
    testObj->Twitter355Test();
    testObj->Logger359Test();
    testObj->HitCounter362Test();

    return 0;
}