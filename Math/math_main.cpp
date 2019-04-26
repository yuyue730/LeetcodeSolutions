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
    testObj->intToRoman12Test();
    testObj->romanToInt13Test();
    testObj->divide29Test();
    testObj->multiply43Test();

    return 0;
}