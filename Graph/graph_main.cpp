// Leetcode Graph Problems main function
#include <iostream>
#include "graph_test.h"
using namespace std;

int main() {
    cout << "Leetcode Graph Problem Solution Application starts.\n";
    GraphTest * testObj = new GraphTest();
    cout << "\nTest for problems starts.\n";

    testObj->findLadders126Test();
    testObj->ladderLength127Test();
    testObj->cloneGraph133Test();
    testObj->canFinish207Test();
    testObj->findOrder210Test();
    testObj->validTree261Test();
    testObj->alienOrder269Test();

    return 0;
}