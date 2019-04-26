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

// 9. Palindrome Number tEST
void MathTest::isPalindrome9Test() {
    cout << "9. Palindrome Number test starts\n";
    cout << "Number 121 isPalindrome = " << implObj->isPalindrome9(121) << ".\n\n";
    return;
}

// 12. Integer to Roman Test
void MathTest::intToRoman12Test() {
    cout << "12. Integer to Roman test starts\n";
    cout << "Number 49 can be " << implObj->intToRoman12(49) << ".\n\n";
    return;
}

// 13. Roman to Integer Test
void MathTest::romanToInt13Test() {
    cout << "13. Roman to Integer test starts\n";
    cout << "Number XLIX is " << implObj->romanToInt13("XLIX") << ".\n\n";
    return;  
}

// 29. Divide Two Integers Test
void MathTest::divide29Test() {
    cout << "29. Divide Two Integers test starts\n";
    cout << "16 / 3 = " << implObj->divide29(16, 3) << ".\n\n";
    return;
}

// 43. Multiply Strings Test
void MathTest::multiply43Test() {
    cout << "43. Multiply Strings test starts\n";
    cout << "123 * 456 = [" << implObj->multiply43("123", "456") << "].\n\n";
    return;
}