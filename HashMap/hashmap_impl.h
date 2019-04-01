#ifndef _HASHMAP_IMPL_H
#define _HASHMAP_IMPL_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class HashMapImpl {
public:
    HashMapImpl();

    // 30. Substring with Concatenation of All Words
    vector<int> findSubstring30(string s, vector<string>& words);
};

#endif