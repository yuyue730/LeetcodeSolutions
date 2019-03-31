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

private:
    MathImpl * implObj;
};

#endif