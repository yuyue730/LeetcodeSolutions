#ifndef _DESIGN_IMPL_H
#define _DESIGN_IMPL_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

// 146. LRU Cache
class LRUCache146 {
public:
    LRUCache146(int capacity) {
        d_capacity = capacity;
    }
    
    int get(int key) {
        if (d_keyIterMap.count(key) == 0) {
            return -1;
        }

        list<pair<int, int>>::iterator iter = d_keyIterMap[key];
        d_list.splice(d_list.begin(), d_list, iter);
        return iter->second;
    }
    
    void put(int key, int value) {
        if (d_keyIterMap.count(key) != 0) {
            d_list.erase(d_keyIterMap[key]);
        }

        d_list.push_front(pair<int, int>(key, value));
        d_keyIterMap[key] = d_list.begin();

        if (d_keyIterMap.size() > d_capacity) {
            int backKey = d_list.back().first;
            d_keyIterMap.erase(backKey);
            d_list.pop_back();
        }
    }

private:
    int d_capacity;
    list<pair<int, int>> d_list;
    unordered_map<int, list<pair<int, int>>::iterator> d_keyIterMap;
};

// 155. Min Stack
class MinStack155 {
public:
    MinStack155() { }
    
    void push(int x) {
        if (d_minStk.empty() || x <= d_minStk.top()) {
            d_minStk.push(x);
        }

        d_valStk.push(x);
    }
    
    void pop() {
        if (d_minStk.top() == d_valStk.top()) {
            d_minStk.pop();
        }
        d_valStk.pop();
    }
    
    int top() {
        return d_valStk.top();
    }
    
    int getMin() {
        return d_minStk.top();
    }

private:
    stack<int> d_valStk;
    stack<int> d_minStk;
};

// 170. Two Sum III - Data structure design
class TwoSum170 {
public:
    /** Initialize your data structure here. */
    TwoSum170() {}
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        numberFreqMap[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (unordered_map<int, int>::iterator iter = numberFreqMap.begin();
            iter != numberFreqMap.end(); ++iter) {
            int toFind = value - iter->first;
            if (toFind == iter->first && iter->second > 1) {
                return true;
            } else if (toFind != iter->first && numberFreqMap.count(toFind) > 0) {
                return true;
            }
        }

        return false;
    }

private:
    unordered_map<int, int> numberFreqMap;
};

// 173. Binary Search Tree Iterator
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator173 {
public:
    BSTIterator173(TreeNode* root) {
        while (root) {
            node_stk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode * next = node_stk.top();
        int result = next->val;
        node_stk.pop();
        if (next->right) {
            TreeNode * cur = next->right;
            while (cur) {
                node_stk.push(cur);
                cur = cur->left;
            }
        }
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node_stk.empty();
    }

private:
    stack <TreeNode *> node_stk;
};

// 208. Implement Trie (Prefix Tree)
struct TrieNode {
    TrieNode * child[26];
    bool is_word;

    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie208 {
public:
    /** Initialize your data structure here. */
    Trie208() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int next_idx = word[i] - 'a';
            if (!cur->child[next_idx]) {
                cur->child[next_idx] = new TrieNode();
            }
            cur = cur->child[next_idx];
        }

        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int next_idx = word[i] - 'a';
            if (!cur->child[next_idx]) {
                return false;
            }
            cur = cur->child[next_idx];
        }

        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int next_idx = prefix[i] - 'a';
            if (!cur->child[next_idx]) {
                return false;
            }
            cur = cur->child[next_idx];
        }

        return true;
    }

private:
    TrieNode * root;
};

// 225. Implement Stack using Queues
class MyStack225 {
public:
    /** Initialize your data structure here. */
    MyStack225() { }
    
    /** Push element x onto stack. */
    void push(int x) {
        front_queue.push(x);
        while (front_queue.size() > 1) {
            data_queue.push(front_queue.front());
            front_queue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int to_return = top();
        front_queue.pop();
        return to_return;
    }
    
    /** Get the top element. */
    int top() {
        if (front_queue.empty()) {
            for (int i = 0; i < data_queue.size() - 1; ++i) {
                data_queue.push(data_queue.front());
                data_queue.pop();
            }
            front_queue.push(data_queue.front());
            data_queue.pop();
        }
        return front_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return front_queue.empty() && data_queue.empty();
    }

private:
    queue<int> front_queue;
    queue<int> data_queue;
};

// 232. Implement Queue using Stacks
class MyQueue232 {
public:
    /** Initialize your data structure here. */
    MyQueue232() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!q_stack.empty()) {
            temp.push(q_stack.top());
            q_stack.pop();
        }

        temp.push(x);
        while (!temp.empty()) {
            q_stack.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = q_stack.top();
        q_stack.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return q_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q_stack.empty();
    }

private:
    stack<int> q_stack;
};

// 284. Peeking Iterator
class Iterator {
public:
    struct Data {
        vector<int> d_arr;

        Data(vector<int> nums) {
            d_arr.clear();
            for (auto i : nums) {
                d_arr.push_back(i);
            }
        }
    };

	Data* data;

    int d_idx;

public:
	Iterator(const vector<int>& nums) {
        data = new Data(nums);
        d_idx = 0;
    }

	Iterator(const Iterator& iter) { }

	virtual ~Iterator() { }

	// Returns the next element in the iteration.
	int next() {
        int result = data->d_arr[d_idx];
        d_idx++;
        return result;
    }

	// Returns true if the iteration has more elements.
	bool hasNext() const {
        return (d_idx < data->d_arr.size());
    }
};

class PeekingIterator284 : public Iterator {
public:
	PeekingIterator284(const vector<int>& nums) : Iterator(nums) {
        d_peek = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!d_peek) {
            d_cur_peek = Iterator::next();
            d_peek = true;
        }

        return d_cur_peek;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (d_peek) {
            d_peek = false;
            return d_cur_peek;
        } else {
            return Iterator::next();
        }
	}

	bool hasNext() const {
	    return d_peek || Iterator::hasNext();
	}

private:
    int d_cur_peek;
    bool d_peek;
};

// 295. Find Median from Data Stream
class MedianFinder295 {
public:
    MedianFinder295() { }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();

        while (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return 0.5 * (small.top() - large.top());
        } else {
            return small.top();
        }
    }

private:
    priority_queue<int> small, large;
};

#endif