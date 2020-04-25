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
    testObj->maximumProduct628Test();
    testObj->kInversePairs629Test();
    testObj->scheduleCourse630Test();
    testObj->judgeSquareSum633Test();
    testObj->smallestRange632Test();
    testObj->findDerangement634Test();
    testObj->LogSystem635Test();
    testObj->averageOfLevels637Test();
    testObj->shoppingOffers638Test();
    testObj->MyCircularDeque641Test();
    testObj->AutocompleteSystem642Test();

    return 0;
}