#ifndef _GRAPH_TEST_H
#define _GRAPH_TEST_H

#include "graph_impl.h"

#include <iostream>
#include <vector>
using namespace std;

class GraphTest {
public:
    GraphTest();

    // 126. Word Ladder II Test
    void findLadders126Test();

    // 127. Word Ladder Test
    void ladderLength127Test();

    // 133. Clone Graph Test
    void cloneGraph133Test();

private:
    GraphImpl * implObj;
};

#endif