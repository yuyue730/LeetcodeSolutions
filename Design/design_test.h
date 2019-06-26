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
        cout << "Cur getMin = [" << minStack.getMin() << "]\n\n";
        return;
    }

    // 170. Two Sum III - Data structure design Test
    void TwoSum170Test() {
        cout << "170. Two Sum III - Data structure design test starts.\n";
        TwoSum170 twoSum;
        twoSum.add(1); twoSum.add(3); twoSum.add(5);
        cout << "Find 4 = " << (twoSum.find(4) ? "True" : "False") << "\n";
        cout << "Find 7 = " << (twoSum.find(7) ? "True" : "False") << "\n\n";
        return;
    }

    // 173. Binary Search Tree Iterator Test
    void BSTIterator173Test() {
        cout << "173. Binary Search Tree Iterator test starts.\n";
        TreeNode * root = new TreeNode(7);
        TreeNode * cur = root;
        cur->left = new TreeNode(3);
        cur->right = new TreeNode(15);
        cur = cur->right;
        cur->left = new TreeNode(9);
        cur->right = new TreeNode(20);

        BSTIterator173 iterator(root);
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "Next = [" << iterator.next() << "]\n";    // return 7
        cout << "hasNext = [" << iterator.hasNext() << "]\n"; // return true
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "hasNext = [" << iterator.hasNext() << "]\n"; // return true
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "hasNext = [" << iterator.hasNext() << "]\n"; // return true
        cout << "Next = [" << iterator.next() << "]\n";    // return 3
        cout << "hasNext = [" << iterator.hasNext() << "]\n\n"; // return true
        return;
    }
};

#endif