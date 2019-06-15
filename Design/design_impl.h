#ifndef _DESIGN_IMPL_H
#define _DESIGN_IMPL_H

#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
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

#endif