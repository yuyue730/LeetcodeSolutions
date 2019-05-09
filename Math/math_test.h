#ifndef _MATH_TEST_H
#define _MATH_TEST_H
#include "math_impl.h"

class MathTest {
public:
    MathTest();

    // 7. Reverse Integer Test
    void reverse7Test();

    // 8. String to Integer (atoi) Test
    void myAtoi8Test();

    // 9. Palindrome Number Test
    void isPalindrome9Test();

    // 12. Integer to Roman Test
    void intToRoman12Test();

    // 13. Roman to Integer Test
    void romanToInt13Test();

    // 29. Divide Two Integers Test
    void divide29Test();

    // 43. Multiply Strings Test
    void multiply43Test();

    // 50. Pow(x, n) Test
    void myPow50Test();

    // 65. Valid Number Test
    void isNumber65Test();

    // 67. Add Binary Test
    void addBinary67Test();

    // 69. Sqrt(x) Test
    void mySqrt69Test();

private:
    MathImpl * implObj;
};

#endif