// Leetcode Session 3 Problems main function
#include <iostream>
#include "session4_test.h"
using namespace std;

int main() {
    cout << "Leetcode Session 4 Problem Solution Application starts.\n";
    Session4Test * testObj = new Session4Test();
    cout << "\nTest for problems starts.\n";

    testObj->removeKdigits402Test();
    testObj->canCross403Test();
    testObj->reconstructQueue406Test();
    testObj->splitArray410Test();
    testObj->fizzBuzz412Test();
    testObj->thirdMax414Test();

    return 0;
}