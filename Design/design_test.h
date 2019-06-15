#ifndef _DESIGN_TEST_H
#define _DESIGN_TEST_H

#include "design_impl.h"

#include <iostream>
using namespace std;

class DesignTest {
public:
    DesignTest() {
        cout << "Test object for Leetcode Design problems constructed.\n";
    }

    // 146. LRU Cache Test
    void LRUCache146Test() {
        cout << "146. LRU Cache test starts.\n";
        LRUCache146 cache(2);

        cache.put(1, 1);
        cache.put(2, 2);
        cout << "get 1 = [" << cache.get(1) << "]\n";
        cache.put(3, 3);
        cout << "get 2 = [" << cache.get(2) << "]\n";
        cache.put(4, 4);
        cout << "get 1 = [" << cache.get(1) << "]\n";
        cout << "get 3 = [" << cache.get(3) << "]\n";
        cout << "get 4 = [" << cache.get(4) << "]\n";
        return;
    }

    // 155. Min Stack Test
    void MinStack155Test() {
        cout << "155. Min Stack test starts.\n";

        MinStack155 minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        cout << "Cur getMin = [" << minStack.getMin() << "]\n";
        minStack.pop();
        cout << "Cur getTop = [" << minStack.top() << "]\n";
        cout << "Cur getMin = [" << minStack.getMin() << "]\n";
        return;
    }
};

#endif