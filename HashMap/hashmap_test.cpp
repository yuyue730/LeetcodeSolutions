#include "hashmap_test.h"

HashMapTest::HashMapTest() {
    cout << "Test object for Leetcode HashMap problems constructed.\n";
    implObj = new HashMapImpl();
}

// 30. Substring with Concatenation of All Words Test
void HashMapTest::findSubstring30Test() {
    cout << "30. Substring with Concatenation of All Words test starts.\n";
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = implObj->findSubstring30(s, words);
    cout << "barfoothefoobarman and {foo, bar} will generate [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << ";";
    }
    cout << "].\n\n";
}