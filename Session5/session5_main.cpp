// Leetcode Session 5 Problems main function
#include <iostream>
#include "session5_test.h"
using namespace std;

int main() {
    cout << "Leetcode Session 5 Problem Solution Application starts.\n";
    Session5Test * testObj = new Session5Test();
    cout << "\nTest for problems starts.\n";

    testObj->nextGreaterElements503Test();
    testObj->shortestDistance505Test();
    testObj->findFrequentTreeSum508Test();
    testObj->fib509Test();
    testObj->inorderSuccessor510Test();
    testObj->findBottomLeftValue513Test();
    testObj->findRotateSteps514Test();
    testObj->largestValues515Test();
    testObj->longestPalindromeSubseq516Test();
    testObj->findMinMoves517Test();
    testObj->change518Test();
    testObj->Solution519Test();
    testObj->checkSubarraySum523Test();
    testObj->findLongestWord524Test();
    testObj->findMaxLength525Test();
    testObj->countArrangement526Test();
    testObj->wordsAbbreviation527Test();
    testObj->Solution528Test();

    return 0;
}