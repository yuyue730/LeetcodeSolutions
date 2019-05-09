#ifndef _MATH_IMPL_H
#define _MATH_IMPL_H

#include <iostream>
#include <vector>
using namespace std;

class MathImpl {
public:
    MathImpl();
    
    // 7. Reverse Integer
    int reverse7(int x);

    // 8. String to Integer (atoi)
    int myAtoi8(string str);

    // 9. Palindrome Number
    bool isPalindrome9(int x);

    // 12. Integer to Roman
    string intToRoman12(int num);

    // 13. Roman to Integer
    int romanToInt13(string s);

    // 29. Divide Two Integers
    int divide29(int dividend, int divisor);

    // 43. Multiply Strings
    string multiply43(string num1, string num2);

    // 50. Pow(x, n)
    double myPow50(double x, int n);

    // 65. Valid Number
    bool isNumber65(string s);

    // 67. Add Binary
    string addBinary67(string a, string b);

    // 69. Sqrt(x)
    int mySqrt69(int x);
};

#endif