#ifndef _GRAPH_IMPL_H
#define _GRAPH_IMPL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GraphImpl {
public:
    GraphImpl();

    // 126. Word Ladder II
    vector<vector<string>> findLadders126(
        string beginWord, 
        string endWord, 
        vector<string>& wordList
    );
};

#endif