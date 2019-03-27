#include "stack_test.h"

#include <iostream>
using namespace std;

StackTest::StackTest() {
    cout << "Test object for Leetcode Stack problems constructed.\n";
    implObj = new StackImpl();
}

// 20. Valid Parentheses Test
void StackTest::isValid20Test() {
    cout << "20. Valid Parentheses test starts.\n";   
    string s = "([)]";
    cout << "([)] isValid = " << implObj->isValid20(s) << ".\n\n";
    return;
}