#include <iostream>
#include "math_test.h"
using namespace std;

MathTest::MathTest() {
    cout << "Test object for Leetcode Math problems constructed.\n";
    implObj = new MathImpl();
}

// 7. Reverse Integer Test
void MathTest::reverse7Test() {
    cout << "7. Reverse Integer test starts\n";
    cout << "Number 123 is reversed to be " << implObj->reverse7(123) << ".\n\n";
    return;
}

// 8. String to Integer (atoi) Test
void MathTest::myAtoi8Test() {
    cout << "8. String to Integer (atoi) test starts\n";
    cout << "String '     -43' can be atoi-ed to " << implObj->myAtoi8("     -43") << ".\n\n";
    return;
}

// 9. Palindrome Number
void MathTest::isPalindrome9Test() {
    cout << "9. Palindrome Number test starts\n";
    cout << "Number 121 isPalindrome = " << implObj->isPalindrome9(121) << ".\n\n";
    return;
}