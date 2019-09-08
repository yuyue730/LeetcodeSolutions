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
        cout << "get 4 = [" << cache.get(4) << "]\n\n";
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

    // 208. Implement Trie (Prefix Tree) Test
    void Trie208Test() {
        cout << "208. Implement Trie (Prefix Tree) test starts.\n";

        Trie208 trie;
        trie.insert("apple");
        cout << "Search apple = [" << trie.search("apple") << "]\n";
        cout << "Search app = [" << trie.search("app") << "]\n";
        cout << "Start with app = [" << trie.startsWith("app") << "]\n";
        trie.insert("app");   
        cout << "Search app = [" << trie.search("app") << "]\n\n";
        return;
    }

    // 211. Add and Search Word - Data structure design Test
    void WordDictionary211Test() {
        cout << "// 211. Add and Search Word - Data structure design test starts.\n";
        WordDictionary211 dict;
        dict.addWord("bad");
        dict.addWord("dad");
        dict.addWord("mad");
        cout << "find pad = [" << dict.search("pad") << "]\n";
        cout << "find bad = [" << dict.search("bad") << "]\n";
        cout << "find .ad = [" << dict.search(".ad") << "]\n";
        cout << "find b.. = [" << dict.search("b..") << "]\n\n";
        return;
    }

    // 225. Implement Stack using Queues Test
    void MyStack225Test() {
        cout << "225. Implement Stack using Queues test starts.\n";

        MyStack225 myStack;
        myStack.push(1);
        myStack.push(2);  
        cout << "top() = " << myStack.top() << "; ";   // returns 2
        cout << "pop() = " << myStack.pop() << "; ";   // returns 2
        cout << "empty() = " << myStack.empty() << "\n\n"; // returns false
        return;
    }

    // 232. Implement Queue using Stacks Test
    void MyQueue232Test() {
        cout << "232. Implement Queue using Stacks test starts.\n";

        MyQueue232 myQ;
        myQ.push(1);
        myQ.push(2); 
        cout << "peek = [" << myQ.peek() << "]\n";  // returns 1
        cout << "pop = [" << myQ.pop() << "]\n";   // returns 1
        cout << "empty = [" << myQ.empty() << "]\n\n"; // returns false 
        return;
    }

    // 284. Peeking Iterator Test
    void PeekingIterator284Test() {
        cout << "284. Peeking Iterator test starts.\n";
        PeekingIterator284 iter(vector<int>({1, 2, 3}));
        cout << "next = [" << iter.next() << "]\n";
        cout << "peek = [" << iter.peek() << "]\n";
        cout << "next = [" << iter.next() << "]\n";
        cout << "next = [" << iter.next() << "]\n";
        cout << "has_next = [" << (iter.hasNext() ? "True" : "False") << "]\n\n";
        return;
    }

    // 295. Find Median from Data Stream Test
    void MedianFinder295Test() {
        cout << "295. Find Median from Data Stream test starts.\n";
        MedianFinder295 finder;
        finder.addNum(1);
        cout << "median = [" << finder.findMedian() << "]\n";
        finder.addNum(2);
        cout << "median = [" << finder.findMedian() << "]\n";
        finder.addNum(3);
        cout << "median = [" << finder.findMedian() << "]\n\n";
        return;
    }

    // 297. Serialize and Deserialize Binary Tree Test
    void Codec297Test() {
        cout << "297. Serialize and Deserialize Binary Tree test.\n";
        Codec297 implObj;
        TreeNode * root = new TreeNode(1);
        TreeNode * cur = root;
        cur->left = new TreeNode(2);
        cur->right = new TreeNode(3);

        cur = cur->right;
        cur->left = new TreeNode(4);
        cur->right = new TreeNode(5);

        string code = implObj.serialize(root);
        cout << "Serialize result = [" << code << "].\n";
        TreeNode * result = implObj.deserialize(code);
        cout << "Please exam result = [" << result->val << "]\n\n";
        return;
    }

    // 346. Moving Average from Data Stream Test
    void MovingAverage346Test() {
        cout << "346. Moving Average from Data Stream test starts.\n";
        MovingAverage346 m(3);
        cout << "Push 1 = [" << (double)m.next(1) << "];\n";
        cout << "Push 10 = [" << (double)m.next(10) << "];\n";
        cout << "Push 3 = [" << (double)m.next(3) << "];\n";
        cout << "Push 5 = [" << (double)m.next(5) << "]\n\n";
        return;
    }

    // 348. Design Tic-Tac-Toe Test
    void TicTacToe348Test() {
        cout << "348. Design Tic-Tac-Toe test starts.\n";
        TicTacToe348 toe(3);
        cout << "Step 1 (0,0,1) = [" << toe.move(0, 0, 1) << "]\n";
        cout << "Step 2 (0,2,2) = [" << toe.move(0, 2, 2) << "]\n";
        cout << "Step 3 (2,2,1) = [" << toe.move(2, 2, 1) << "]\n";
        cout << "Step 4 (1,1,2) = [" << toe.move(1, 1, 2) << "]\n";
        cout << "Step 5 (2,0,1) = [" << toe.move(2, 0, 1) << "]\n";
        cout << "Step 6 (1,0,2) = [" << toe.move(1, 0, 2) << "]\n";
        cout << "Step 7 (2,1,1) = [" << toe.move(2, 1, 1) << "]\n\n";
    }
};

#endif