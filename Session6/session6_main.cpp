// Leetcode Session 6 Problems main function
#include <iostream>
#include "session6_test.h"
using namespace std;

int main() {
    cout << "Leetcode Session 6 Problem Solution Application starts.\n";
    Session6Test * testObj = new Session6Test();
    cout << "\nTest for problems starts.\n";

    testObj->StringIterator604Test();
    testObj->canPlaceFlowers605Test();
    testObj->triangleNumber611Test();
    testObj->addBoldTag616Test();
    testObj->mergeTrees617Test();
    testObj->leastInterval621Test();
    testObj->MyCircularQueue622Test();
    testObj->addOneRow623Test();
    testObj->maxDistance624Test();
    testObj->smallestFactorization625Test();
    testObj->kInversePairs629Test();

    return 0;
}