#ifndef _GRAPH_IMPL_H
#define _GRAPH_IMPL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// For Problem 133
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class GraphImpl {
public:
    GraphImpl();

    // 126. Word Ladder II
    vector<vector<string>> findLadders126(
        string beginWord, 
        string endWord, 
        vector<string>& wordList
    );

    // 127. Word Ladder
    int ladderLength127(
        string beginWord, 
        string endWord, 
        vector<string>& wordList
    );

    // 133. Clone Graph
    Node* cloneGraph133(Node* node);

private:
    // 133. Clone Graph helper
    Node* cloneGraph133DFS(
        Node *node, 
        unordered_map<Node *, Node *> & curNewMap
    );
};

#endif