// Leetcode Session 5 Problems main function
#include <iostream>
#include "session5_test.h"
using namespace std;

int main() {
    cout << "Leetcode Session 5 Problem Solution Application starts.\n";
    Session5Test * testObj = new Session5Test();
    cout << "\nTest for problems starts.\n";

    testObj->nextGreaterElements503Test();
}