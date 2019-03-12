// Leetcode Math Problems main function
#include <iostream>
#include "math_test.h"
using namespace std;

int main() {
    cout << "Leetcode Math Problem Solution Application starts.\n";
    MathTest * testObj = new MathTest(); 
    cout << "\nTest for problems starts.\n";

    testObj->reverse7Test();
    testObj->myAtoi8Test();
    testObj->isPalindrome9Test();

    return 0;
}